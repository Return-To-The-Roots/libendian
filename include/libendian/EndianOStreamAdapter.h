//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (c) 2005 - 2019 Settlers Freaks (sf-team at siedler25.org)
//

#pragma once
#ifndef libendian_include_libendian_EndianOStreamAdapter_h
#define libendian_include_libendian_EndianOStreamAdapter_h

#include "EndianStreamAdapterBase.h"

#include <array>
#include <type_traits>
#include <vector>

namespace libendian {

/// Adapter that writes to streams with a given endianess
/// T_isBigEndian decides whether the stream endianess is big endian or little endian
/// T_Stream: Adapted class (may be a reference type) which should support:
///     bool operator!, bool eof(), ignore(size_t): See base stream
///     T_Stream& write(char*, size_t) for writing
///     size_t tellp for setting the write position
///     seekp(long, dir = T_Stream::beg) && T_Stream::cur for seeking
template<bool T_isBigEndian, class T_Stream>
class EndianOStreamAdapter : public EndianStreamAdapterBase<T_isBigEndian, T_Stream>
{
    using Base = EndianStreamAdapterBase<T_isBigEndian, T_Stream>;
    using Convert = typename Base::Convert;

public:
    explicit EndianOStreamAdapter(T_Stream stream) : Base(stream) {}

    template<typename T_InitType>
    explicit EndianOStreamAdapter(T_InitType& initArg) : Base(initArg)
    {}

    template<typename T_InitType>
    explicit EndianOStreamAdapter(const T_InitType& initArg) : Base(initArg)
    {}

    template<typename T_InitType, typename T_ArgType>
    explicit EndianOStreamAdapter(const T_InitType& initArg, const T_ArgType& arg) : Base(initArg, arg)
    {}

    /// Write a value and return true on success, false on error
    template<typename T>
    bool write(const T& value)
    {
        return write(&value, 1);
    }

    /// Write a buffer with the given number of elements
    template<typename T>
    bool write(const T* buffer, size_t numValues)
    {
        // Optimization for single byte values -> no endianess change, just write it
        if(sizeof(T) == 1)
        {
            return writeRaw(buffer, numValues);
        }

        for(size_t i = 0; i < numValues; ++i, ++buffer)
        {
            const T tmp = Convert::fromNative(*buffer);
            if(!writeRaw(&tmp, 1))
            {
                return false;
            }
        }

        return true;
    }

    /// Write a buffer with the given number of elements without conversion
    template<typename T>
    bool writeRaw(const T* buffer, size_t numValues)
    {
        return !!this->stream_.write(reinterpret_cast<const char*>(buffer), numValues * sizeof(T));
    }

    template<typename T>
    std::enable_if_t<std::is_arithmetic<T>::value, EndianOStreamAdapter>& operator<<(const T& value)
    {
        write(value);
        return *this;
    }

    template<typename T, size_t numValues>
    EndianOStreamAdapter& operator<<(const T (&value)[numValues])
    {
        write(value, numValues);
        return *this;
    }

    template<typename T, size_t numValues>
    EndianOStreamAdapter& operator<<(const std::array<T, numValues>& value)
    {
        write(value.data(), numValues);
        return *this;
    }

    long getPosition() { return static_cast<long>(this->stream_.tellp()); }

    void setPosition(long position) { this->stream_.seekp(position); }

    void setPositionRel(long position) { this->stream_.seekp(position, this->stream_.cur); }
};

/// Overload for reading a vector of values
template<bool T_isBigEndian, class T_Stream, typename T>
EndianOStreamAdapter<T_isBigEndian, T_Stream>& operator<<(EndianOStreamAdapter<T_isBigEndian, T_Stream>& os, const std::vector<T>& vec)
{
    if(vec.empty())
    {
        return os;
    }

    os.write(&vec[0], vec.size());

    return os;
}

} // namespace libendian

#endif // !libendian_include_libendian_EndianOStreamAdapter_h
