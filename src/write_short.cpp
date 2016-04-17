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
 *  Writes a Little-Endian encoded short to a FILE.
 *
 *  @param[out] from  pointer to source short
 *  @param[in]  file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::le_write_s(short from, FILE* file)
{
    return le_write_us( (unsigned short)from, file);
}

/**
 *  Writes a Little-Endian encoded unsigned short to a FILE.
 *
 *  @param[out] from  pointer to source short
 *  @param[in]  file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::le_write_us(unsigned short from, FILE* file)
{
    if(file == NULL)
        return -1;

    if(BYTE_ORDER != LITTLE_ENDIAN)
    {
        from = swap_us(from);
    }

    if(fwrite(&from, 1, 2, file) != 2)
        return 1;

    return 0;
}

/**
 *  Writes a Big-Endian encoded short to a FILE.
 *
 *  @param[out] from  pointer to source short
 *  @param[in]  file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::be_write_s(short from, FILE* file)
{
    return be_write_us( (unsigned short)from, file);
}

/**
 *  Writes a Big-Endian encoded unsigned short to a FILE.
 *
 *  @param[out] from  pointer to source short
 *  @param[in]  file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::be_write_us(unsigned short from, FILE* file)
{
    if(file == NULL)
        return -1;

    if(BYTE_ORDER != BIG_ENDIAN)
    {
        from = swap_us(from);
    }

    if(fwrite(&from, 1, 2, file) != 2)
        return 1;

    return 0;
}
