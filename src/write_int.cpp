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

#include "libendianDefines.h" // IWYU pragma: keep
#include "libendian.h"

/**
 *  Writes a Little-Endian encoded int32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool libendian::le_write_i(int32_t from, FILE* file)
{
    return le_write_ui((uint32_t)from, file);
}

/**
 *  Writes a Little-Endian encoded uint32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool libendian::le_write_ui(uint32_t from, FILE* file)
{
    if(file == NULL)
        return false;

    if(BYTE_ORDER != LITTLE_ENDIAN)
    {
        from = swap_ui(from);
    }

    if(fwrite(&from, 1, 4, file) != 4)
        return false;

    return true;
}

/**
 *  Writes a Big-Endian encoded int32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool libendian::be_write_i(int32_t from, FILE* file)
{
    return be_write_ui((uint32_t)from, file);
}

/**
 *  Writes a Big-Endian encoded uint32_t to a FILE.
 *
 *  @param[in] from  pointer to source int32_t
 *  @param[in] file  file to write to
 *
 *  @return true on success
 */
bool libendian::be_write_ui(uint32_t from, FILE* file)
{
    if(file == NULL)
        return false;

    if(BYTE_ORDER != BIG_ENDIAN)
    {
        from = swap_ui(from);
    }

    if(fwrite(&from, 1, 4, file) != 4)
        return false;

    return true;
}
