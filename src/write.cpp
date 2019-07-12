//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (c) 2005 - 2019 Settlers Freaks (sf-team at siedler25.org)
//

#include "libendian/libendian.h"

#include <boost/endian/conversion.hpp>
#include <type_traits>

namespace libendian {

/**
 *  Writes raw chars to a FILE.
 *
 *  @param[out] from  source buffer
 *  @param[in]  count number of symbols to write
 *  @param[in]  file  file to write to
 *
 *  @return true on success
 */
bool write(const char* from, uint32_t count, FILE* file)
{
    return write((const uint8_t*)from, count, file);
}

bool write(const int8_t* from, uint32_t count, FILE* file)
{
    return write((const uint8_t*)from, count, file);
}

/**
 *  Writes raw unsigned chars to a FILE.
 *
 *  @param[out] from  source buffer
 *  @param[in]  count number of symbols to write
 *  @param[in]  file  file to write to
 *
 *  @return true on success
 */
bool write(const uint8_t* from, uint32_t count, FILE* file) //-V524
{
    if(from == nullptr || file == nullptr)
    {
        return false;
    }

    // no need to convert chars
    return fwrite(from, 1, count, file) == count;
}

template<typename T>
bool le_write(T value, FILE* file)
{
    static_assert(std::is_integral<T>::value, "Need integral");
    
    if(!file)
    {
        return false;
    }
    
    boost::endian::native_to_little_inplace(value);

    return fwrite(&value, sizeof(value), 1, file) == 1;
}

template<typename T>
bool be_write(T value, FILE* file)
{
    static_assert(std::is_integral<T>::value, "Need integral");
    
    if(!file)
    {
        return false;
    }
    
    boost::endian::native_to_big_inplace(value);

    return fwrite(&value, sizeof(value), 1, file) == 1;
}

/**
 *  Writes a Little-Endian encoded int16_t to a FILE.
 *
 *  @param[out] from  pointer to source int16_t
 *  @param[in]  file  file to write to
 *
 *  @return true on success
 */
bool le_write_s(int16_t from, FILE* file)
{
    return le_write(from, file);
}

/**
 *  Writes a Little-Endian encoded uint16_t to a FILE.
 *
 *  @param[out] from  pointer to source int16_t
 *  @param[in]  file  file to write to
 *
 *  @return true on success
 */
bool le_write_us(uint16_t from, FILE* file)
{
    return le_write(from, file);
}

/**
 *  Writes a Big-Endian encoded int16_t to a FILE.
 *
 *  @param[out] from  pointer to source int16_t
 *  @param[in]  file  file to write to
 *
 *  @return true on success
 */
bool be_write_s(int16_t from, FILE* file)
{
    return be_write(from, file);
}

/**
 *  Writes a Big-Endian encoded uint16_t to a FILE.
 *
 *  @param[out] from  pointer to source int16_t
 *  @param[in]  file  file to write to
 *
 *  @return true on success
 */
bool be_write_us(uint16_t from, FILE* file)
{
    return be_write(from, file);
}

/**
 *  Writes a Little-Endian encoded int32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool le_write_i(int32_t from, FILE* file)
{
    return le_write(from, file);
}

/**
 *  Writes a Little-Endian encoded uint32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool le_write_ui(uint32_t from, FILE* file)
{
    return le_write(from, file);
}

/**
 *  Writes a Big-Endian encoded int32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool be_write_i(int32_t from, FILE* file)
{
    return be_write(from, file);
}

/**
 *  Writes a Big-Endian encoded uint32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool be_write_ui(uint32_t from, FILE* file)
{
    return be_write(from, file);
}

} // namespace libendian
