//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (c) 2005 - 2019 Settlers Freaks (sf-team at siedler25.org)
//

#pragma once
#ifndef libendian_include_libendian_EndianStreamAdapterBase_h
#define libendian_include_libendian_EndianStreamAdapterBase_h

#include "ConvertEndianess.h"

#include <type_traits>

namespace libendian {

/// Adapter for binary stream like classes that converts to/from the native endianess to the streams endianess
/// Base class for common functionality
/// T_isBigEndian decides whether the stream endianess is big endian or little endian
/// T_Stream: Adapted class (may be a reference type) which should support:
///     bool operator! for validity
///     bool eof() return true iff at end of stream/file
///     ignore(size_t) for skipping the given number of bytes
template<bool T_isBigEndian, class T_Stream>
class EndianStreamAdapterBase
{
protected:
    T_Stream stream_;
    using Convert = ConvertEndianess<T_isBigEndian>;

public:
    using StreamType = T_Stream;
    using StreamRefType = std::add_lvalue_reference_t<T_Stream>;

    EndianStreamAdapterBase();

    explicit EndianStreamAdapterBase(T_Stream stream) : stream_(stream) {}

    /// Initialize stream with one argument (e.g. filepath)
    template<typename T_InitType>
    explicit EndianStreamAdapterBase(T_InitType& initArg) : stream_(initArg)
    {}

    template<typename T_InitType>
    explicit EndianStreamAdapterBase(const T_InitType& initArg) : stream_(initArg)
    {}

    template<typename T_InitType, typename T_ArgType>
    explicit EndianStreamAdapterBase(const T_InitType& initArg, const T_ArgType& arg) : stream_(initArg, arg)
    {}

    /// Return the underlying stream as a reference
    StreamRefType getStream() { return stream_; }

    bool operator!() const { return !stream_; }

    bool eof() { return stream_.eof(); }

    /// Skip the number of bytes and return *this for chaining
    EndianStreamAdapterBase& ignore(size_t size)
    {
        stream_.ignore(size);
        return *this;
    }
};

} // namespace libendian

#endif // !libendian_include_libendian_EndianStreamAdapterBase_h
