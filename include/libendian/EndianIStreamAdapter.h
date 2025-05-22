//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (C) 2005 - 2025 Settlers Freaks (sf-team at siedler25.org)
//

#pragma once

#include "EndianStreamAdapterBase.h"

#include <array>
#include <type_traits>
#include <vector>

namespace libendian {

/// Adapter that reads from streams with a given endianess
/// T_isBigEndian decides whether the stream endianess is big endian or little endian
/// T_Stream: Adapted class (may be a reference type) which should support:
///     bool operator!, bool eof(), ignore(size_t): See base stream
///     T_Stream& read(char*, size_t) for reading
///     size_t tellg for getting the read position
///     seekg(long, dir = T_Stream::beg) && T_Stream::cur for seeking
template<bool T_isBigEndian, class T_Stream>
class EndianIStreamAdapter : public EndianStreamAdapterBase<T_isBigEndian, T_Stream>
{
    using Base = EndianStreamAdapterBase<T_isBigEndian, T_Stream>;
    using Convert = typename Base::Convert;

public:
    explicit EndianIStreamAdapter(T_Stream stream) : Base(stream) {}

    template<typename T_InitType>
    explicit EndianIStreamAdapter(T_InitType& initArg) : Base(initArg)
    {}

    template<typename T_InitType>
    explicit EndianIStreamAdapter(const T_InitType& initArg) : Base(initArg)
    {}

    template<typename T_InitType, typename T_ArgType>
    explicit EndianIStreamAdapter(const T_InitType& initArg, const T_ArgType& arg) : Base(initArg, arg)
    {}

    /// Read a value and return true on success, false on error
    template<typename T>
    bool read(T& value)
    {
        return read(&value, 1);
    }

    /// Read a buffer with the given number of elements
    template<typename T>
    bool read(T* buffer, size_t numValues)
    {
        if(!readRaw(buffer, numValues))
        {
            return false;
        }

        if(sizeof(T) == 1)
        {
            return true;
        }

        for(size_t i = 0; i < numValues; ++i, ++buffer)
        {
            *buffer = Convert::toNative(*buffer);
        }

        return true;
    }

    template<typename T, size_t T_numValues>
    bool read(std::array<T, T_numValues>& buffer)
    {
        return read(buffer.data(), T_numValues);
    }

    /// Read a buffer with the given number of elements without converting it
    template<typename T>
    bool readRaw(T* buffer, size_t numValues)
    {
        return !!this->stream_.read(reinterpret_cast<char*>(buffer), numValues * sizeof(T));
    }

    template<typename T>
    std::enable_if_t<std::is_arithmetic_v<T>, EndianIStreamAdapter>& operator>>(T& value)
    {
        read(value);
        return *this;
    }

    template<typename T, size_t numValues>
    EndianIStreamAdapter& operator>>(T (&value)[numValues])
    {
        read(value, numValues);
        return *this;
    }

    template<typename T, size_t numValues>
    EndianIStreamAdapter& operator>>(std::array<T, numValues>& value)
    {
        read(value.data(), numValues);
        return *this;
    }

    long getPosition() { return static_cast<long>(this->stream_.tellg()); }

    void setPosition(long position) { this->stream_.seekg(position); }

    void setPositionRel(long position) { this->stream_.seekg(position, this->stream_.cur); }
};

} // namespace libendian

/// Overload for reading a vector of values
template<bool T_isBigEndian, class T_Stream, typename T>
libendian::EndianIStreamAdapter<T_isBigEndian, T_Stream>&
operator>>(libendian::EndianIStreamAdapter<T_isBigEndian, T_Stream>& is, std::vector<T>& vec)
{
    if(vec.empty())
    {
        return is;
    }

    is.read(&vec[0], vec.size());

    return is;
}
