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

#include "libendianDefines.h" // IWYU pragma: keep
#include "libendian.h"

/**
 *  Reads Little-Endian encoded chars from a FILE.
 *
 *  @param[out] to    target buffer
 *  @param[in]  count number of symbols to read
 *  @param[in]  file  file to read from
 *
 *  @return number of read bytes, -1 on error, 0 on EOF
 */
int libendian::le_read_c(char* const to, unsigned count, FILE* file)
{
    return le_read_uc((unsigned char*)to, count, file);
}

/**
 *  Reads Little-Endian encoded unsigned chars from a FILE.
 *
 *  @param[out] to    target buffer
 *  @param[in]  count number of symbols to read
 *  @param[in]  file  file to read from
 *
 *  @return number of read bytes, -1 on error, 0 on EOF
 */
int libendian::le_read_uc(unsigned char* const to, unsigned count, FILE* file)
{
    if(to == NULL || file == NULL)
        return -1;

    // no need to convert chars
    return (int)fread(to, 1, count, file);
}

/**
 *  Reads Big-Endian encoded chars from a FILE.
 *
 *  @param[out] to    pointer to target buffer
 *  @param[in]  count number of symbols to read
 *  @param[in]  file  file to read from
 *
 *  @return number of read bytes, -1 on error, 0 on EOF
 */
int libendian::be_read_c(char* const to, unsigned count, FILE* file)
{
    return le_read_c(to, count, file);
}

/**
 *  Reads Big-Endian encoded unsigned chars from a FILE.
 *
 *  @param[out] to    pointer to target buffer
 *  @param[in]  count number of symbols to read
 *  @param[in]  file  file to read from
 *
 *  @return number of read bytes, -1 on error, 0 on EOF
 */
int libendian::be_read_uc(unsigned char* const to, unsigned count, FILE* file)
{
    return le_read_uc(to, count, file);
}
