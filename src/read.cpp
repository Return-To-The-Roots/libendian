// Copyright (c) 2005 - 2017 Settlers Freaks (sf-team at siedler25.org)
//
// This file is part of Return To The Roots.
//
// Return To The Roots is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Return To The Roots is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Return To The Roots. If not, see <http://www.gnu.org/licenses/>.

#include "libendian.h"
#include <boost/endian/conversion.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_integral.hpp>

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
    if(to == NULL || file == NULL)
        return false;

    // no need to convert chars
    return fread(to, 1, count, file) == count;
}

template<typename T>
bool le_read(T* value, FILE* file)
{
    BOOST_STATIC_ASSERT_MSG(boost::is_integral<T>::value, "Need integral");
    if(value == NULL || file == NULL)
        return false;

    T tmp;
    if(fread(&tmp, sizeof(T), 1, file) != 1)
        return false;
    *value = boost::endian::little_to_native(tmp);
    return true;
}

template<typename T>
bool be_read(T* value, FILE* file)
{
    BOOST_STATIC_ASSERT_MSG(boost::is_integral<T>::value, "Need integral");
    if(value == NULL || file == NULL)
        return false;

    T tmp;
    if(fread(&tmp, sizeof(T), 1, file) != 1)
        return false;
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
