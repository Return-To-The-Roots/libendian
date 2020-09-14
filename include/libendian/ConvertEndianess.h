//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (c) 2005 - 2019 Settlers Freaks (sf-team at siedler25.org)
//

#pragma once

#include <boost/endian/conversion.hpp>

namespace libendian {

/// Static class providing the functions toNative/fromNative to convert
/// from/to big endian if isBigEndian is true, from/to little endian otherwise
template<bool T_isBigEndian = true>
struct ConvertEndianess
{
    template<typename T>
    static T toNative(T value)
    {
        return boost::endian::big_to_native(value);
    }

    template<typename T>
    static T fromNative(T value)
    {
        return boost::endian::native_to_big(value);
    }
};

template<>
struct ConvertEndianess<false>
{
    template<typename T>
    static T toNative(T value)
    {
        return boost::endian::little_to_native(value);
    }

    template<typename T>
    static T fromNative(T value)
    {
        return boost::endian::native_to_little(value);
    }
};

} // namespace libendian
