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
 *  Writes raw chars to a FILE.
 *
 *  @param[out] from  source buffer
 *  @param[in]  count number of symbols to write
 *  @param[in]  file  file to write to
 *
 *  @return number of written bytes, -1 on error
 */
int libendian::write(const char* const from, uint32_t count, FILE* file)
{
    return write((const unsigned char*)from, count, file);
}

/**
 *  Writes raw unsigned chars to a FILE.
 *
 *  @param[out] from  source buffer
 *  @param[in]  count number of symbols to write
 *  @param[in]  file  file to write to
 *
 *  @return number of written bytes, -1 on error
 */
int libendian::write(const unsigned char* const from, uint32_t count, FILE* file) //-V524
{
    if(from == NULL || file == NULL)
        return -1;

    // no need to convert chars
    return (int32_t)fwrite(from, 1, count, file);
}
