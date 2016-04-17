// Copyright (c) 2005 - 2015 Settlers Freaks (sf-team at siedler25.org)
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

#include "main.h" // IWYU pragma: keep
#include "libendian.h"

/**
 *  Reads a Little-Endian encoded short from a FILE.
 *
 *  @param[out] to    pointer to target short
 *  @param[in]  file  file to read from
 *
 *  @return 0 on success, other values on error
 */
int libendian::le_read_s(short* to, FILE* file)
{
    return le_read_us( (unsigned short*)to, file);
}

/**
 *  Reads a Little-Endian encoded unsigned short from a FILE.
 *
 *  @param[out] to    pointer to target short
 *  @param[in]  file  file to read from
 *
 *  @return 0 on success, other values on error
 */
int libendian::le_read_us(unsigned short* to, FILE* file)
{
    if(to == NULL || file == NULL)
        return -1;

    if(fread(to, 1, 2, file) != 2)
        return 1;

    if(BYTE_ORDER != LITTLE_ENDIAN)
    {
        *to = swap_us(*to);
    }

    return 0;
}

/**
 *  Reads a Big-Endian encoded short from a FILE.
 *
 *  @param[out] to    pointer to target short
 *  @param[in]  file  file to read from
 *
 *  @return 0 on success, other values on error
 */
int libendian::be_read_s(short* to, FILE* file)
{
    return be_read_us( (unsigned short*)to, file);
}

/**
 *  Reads a Big-Endian encoded unsigned short from a FILE.
 *
 *  @param[out] to    pointer to target short
 *  @param[in]  file  file to read from
 *
 *  @return 0 on success, other values on error
 */
int libendian::be_read_us(unsigned short* to, FILE* file)
{
    if(to == NULL || file == NULL)
        return -1;

    if(fread(to, 1, 2, file) != 2)
        return 1;

    if(BYTE_ORDER != BIG_ENDIAN)
    {
        *to = swap_us(*to);
    }

    return 0;
}
