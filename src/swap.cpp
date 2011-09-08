// $Id: swap.cpp 7521 2011-09-08 20:45:55Z FloSoft $
//
// Copyright (c) 2005 - 2011 Settlers Freaks (sf-team at siedler25.org)
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

///////////////////////////////////////////////////////////////////////////////
// Header
#include "main.h"
#include "libendian.h"

///////////////////////////////////////////////////////////////////////////////
/** 
 *  Vertauscht die Bytes eines Shorts.
 *
 *  @param[in] s der Short der umgedreht werden soll
 *
 *  @return den vertauschten Short
 *
 *  @author FloSoft
 */
short libendian::swap_s(short s)
{
	return swap_us((unsigned short)s);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  Vertauscht die Bytes eines Unsigned Shorts.
 *
 *  @param[in] us der Unsigned Short der umgedreht werden soll
 *
 *  @return den vertauschten Unsigned Short
 *
 *  @author FloSoft
 */
unsigned short libendian::swap_us(unsigned short us)
{
	static unsigned short z = 0;
	unsigned char *zz = (unsigned char*)&z;
	unsigned char *ss = (unsigned char*)&us;

	zz[0] = ss[1];
	zz[1] = ss[0];

	return z;
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  Vertauscht die Bytes eines Ints.
 *
 *  @param[in] s der Int der umgedreht werden soll
 *
 *  @return den vertauschten Int
 *
 *  @author FloSoft
 */
int libendian::swap_i(int i)
{
	return swap_ui((unsigned short)i);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  Vertauscht die Bytes eines Unsigned Ints.
 *
 *  @param[in] us der Unsigned Int der umgedreht werden soll
 *
 *  @return den vertauschten Unsigned Int
 *
 *  @author FloSoft
 */
unsigned int libendian::swap_ui(unsigned int ui)
{
	static unsigned int z = 0;
	unsigned char *zz = (unsigned char*)&z;
	unsigned char *ss = (unsigned char*)&ui;

	zz[3] = ss[0];
	zz[2] = ss[1];
	zz[1] = ss[2];
	zz[0] = ss[3];

	return z;
}
