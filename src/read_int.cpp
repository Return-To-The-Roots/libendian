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
 *  Reads a Little-Endian encoded int32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool libendian::le_read_i(int32_t* to, FILE* file)
{
    return le_read_ui((uint32_t*)to, file);
}

/**
 *  Reads a Little-Endian encoded uint32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool libendian::le_read_ui(uint32_t* to, FILE* file)
{
    if(to == NULL || file == NULL)
        return false;

    if(fread(to, 1, 4, file) != 4)
        return false;

    if(BYTE_ORDER != LITTLE_ENDIAN)
    {
        *to = swap_ui(*to);
    }

    return true;
}

/**
 *  Reads a Big-Endian encoded int32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool libendian::be_read_i(int32_t* to, FILE* file)
{
    return be_read_ui((uint32_t*)to, file);
}

/**
 *  Reads a Big-Endian encoded uint32_t from a FILE.
 *
 *  @param[out] to    pointer to target int32_t
 *  @param[in]  file  file to read from
 *
 *  @return true on success
 */
bool libendian::be_read_ui(uint32_t* to, FILE* file)
{
    if(to == NULL || file == NULL)
        return false;

    if(fread(to, 1, 4, file) != 4)
        return false;

    if(BYTE_ORDER != BIG_ENDIAN)
    {
        *to = swap_ui(*to);
    }

    return true;
}
