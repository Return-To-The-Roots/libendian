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
 *  Swaps the bytes of a int16_t.
 *
 *  @param[in] s int16_t to swap
 *
 *  @return swapped int16_t
 */
int16_t libendian::swap_s(int16_t s)
{
    return swap_us((uint16_t)s);
}

/**
 *  Swaps the bytes of an uint16_t.
 *
 *  @param[in] us uint16_t to swap
 *
 *  @return swapped uint16_t
 */
uint16_t libendian::swap_us(uint16_t us)
{
    static uint16_t z = 0;
    unsigned char* zz = (unsigned char*)&z;
    unsigned char* ss = (unsigned char*)&us;

    zz[0] = ss[1];
    zz[1] = ss[0];

    return z;
}

/**
 *  Swaps the bytes of an int32_t.
 *
 *  @param[in] i int32_t to swap
 *
 *  @return swapped int32_t
 */
int32_t libendian::swap_i(int32_t i)
{
    return swap_ui((uint32_t)i);
}

/**
 *  Swaps the bytes of an uint32_t.
 *
 *  @param[in] ui uint32_t to swap
 *
 *  @return swapped uint32_t
 */
uint32_t libendian::swap_ui(uint32_t ui)
{
    static uint32_t z = 0;
    unsigned char* zz = (unsigned char*)&z;  //-V206
    unsigned char* ss = (unsigned char*)&ui; //-V206

    zz[3] = ss[0];
    zz[2] = ss[1];
    zz[1] = ss[2];
    zz[0] = ss[3];

    return z;
}
