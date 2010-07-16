// $Id: read_short.cpp 6581 2010-07-16 11:16:34Z FloSoft $
//
// Copyright (c) 2005 - 2010 Settlers Freaks (sf-team at siedler25.org)
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
 *  liest einen Little-Endian kodierten Short aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielshort
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_read_s(short *to, FILE *file)
{
	return le_read_us( (unsigned short*)to, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  liest einen Little-Endian kodierten Unsigned Short aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielshort
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_read_us(unsigned short *to, FILE *file)
{
	if(to == NULL || file == NULL)
		return -1;

	// Integer einlesen
	if(fread(to, 1, 2, file) != 2)
		return 1;

	// müssen wir konvertieren?
	if(BYTE_ORDER != LITTLE_ENDIAN)
	{
		// ja, dann tauschen
		*to = swap_us(*to);
	}

	// alles ok
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  liest einen Big-Endian kodierten Short aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielshort
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_read_s(short *to, FILE *file)
{
	return be_read_us( (unsigned short*)to, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  liest einen Big-Endian kodierten Unsigned Short aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielshort
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_read_us(unsigned short *to, FILE *file)
{
	if(to == NULL || file == NULL)
		return -1;

	// Integer einlesen
	if(fread(to, 1, 2, file) != 2)
		return 1;

	// müssen wir konvertieren?
	if(BYTE_ORDER != BIG_ENDIAN)
	{
		// ja, dann tauschen
		*to = swap_us(*to);
	}

	// alles ok
	return 0;
}
