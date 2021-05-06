//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (C) 2005 - 2021 Settlers Freaks (sf-team at siedler25.org)
//

#include "libendian/libendian.h"

#include <boost/endian/conversion.hpp>
#include <type_traits>

namespace libendian {

/**
 *  Reads Little-Endian encoded chars from a FILE.
 *
 *  @param[out] to    target buffer
 *  @param[in]  count number of symbols to read
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool read(char* to, uint32_t count, FILE* file)
{
    return read((uint8_t*)to, count, file);
}

bool read(int8_t* to, uint32_t count, FILE* file)
{
    return read((uint8_t*)to, count, file);
}

/**
 *  Reads Little-Endian encoded uint8_t chars from a FILE.
 *
 *  @param[out] to    target buffer
 *  @param[in]  count number of symbols to read
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool read(uint8_t* to, uint32_t count, FILE* file)
{
    if(to == nullptr || file == nullptr)
        return false;

    // no need to convert chars
    return fread(to, 1, count, file) == count;
}

template<typename T>
bool le_read(T* value, FILE* file)
{
    static_assert(std::is_integral<T>::value, "Need integral");

    if(value == nullptr || file == nullptr)
    {
        return false;
    }

    T tmp;
    if(fread(&tmp, sizeof(T), 1, file) != 1)
    {
        return false;
    }

    *value = boost::endian::little_to_native(tmp);

    return true;
}

template<typename T>
bool be_read(T* value, FILE* file)
{
    static_assert(std::is_integral<T>::value, "Need integral");

    if(value == nullptr || file == nullptr)
    {
        return false;
    }

    T tmp;
    if(fread(&tmp, sizeof(T), 1, file) != 1)
    {
        return false;
    }

    *value = boost::endian::big_to_native(tmp);

    return true;
}

/**
 *  Reads a Little-Endian encoded int16_t from a FILE.
 *
 *  @param[out] to    pointer to target int16_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool le_read_s(int16_t* to, FILE* file)
{
    return le_read(to, file);
}

/**
 *  Reads a Little-Endian encoded uint16_t from a FILE.
 *
 *  @param[out] to    pointer to target int16_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool le_read_us(uint16_t* to, FILE* file)
{
    return le_read(to, file);
}

/**
 *  Reads a Big-Endian encoded int16_t from a FILE.
 *
 *  @param[out] to    pointer to target int16_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool be_read_s(int16_t* to, FILE* file)
{
    return be_read(to, file);
}

/**
 *  Reads a Big-Endian encoded uint16_t from a FILE.
 *
 *  @param[out] to    pointer to target int16_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool be_read_us(uint16_t* to, FILE* file)
{
    return be_read(to, file);
}

/**
 *  Reads a Little-Endian encoded int32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool le_read_i(int32_t* to, FILE* file)
{
    return le_read(to, file);
}

/**
 *  Reads a Little-Endian encoded uint32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool le_read_ui(uint32_t* to, FILE* file)
{
    return le_read(to, file);
}

/**
 *  Reads a Big-Endian encoded int32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool be_read_i(int32_t* to, FILE* file)
{
    return be_read(to, file);
}

/**
 *  Reads a Big-Endian encoded uint32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool be_read_ui(uint32_t* to, FILE* file)
{
    return be_read(to, file);
}

} // namespace libendian
