// $Id: write_int.cpp 6581 2010-07-16 11:16:34Z FloSoft $
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
 *  schreibt einen Little-Endian kodierten Integer in eine Datei.
 *
 *  @param[in] from  Pointer auf Quellinteger
 *  @param[in] file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_write_i(int from, FILE *file)
{
	return le_write_ui( (unsigned int)from, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  schreibt einen Little-Endian kodierten Unsigned Integer in eine Datei.
 *
 *  @param[in] from  Pointer auf Quellinteger
 *  @param[in] file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_write_ui(unsigned int from, FILE *file)
{
	if(file == NULL)
		return -1;

	// müssen wir konvertieren?
	if(BYTE_ORDER != LITTLE_ENDIAN)
	{
		// ja, dann tauschen
		from = swap_ui(from);
	}

	// Integer schreiben
	if(fwrite(&from, 1, 4, file) != 4)
		return 1;

	// alles ok
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  schreibt einen Big-Endian kodierten Integer in eine Datei.
 *
 *  @param[in] from  Pointer auf Quellinteger
 *  @param[in] file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_write_i(int from, FILE *file)
{
	return be_write_ui( (unsigned int)from, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  schreibt einen Big-Endian kodierten Unsigned Integer in eine Datei.
 *
 *  @param[in] from  Pointer auf Quellinteger
 *  @param[in] file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_write_ui(unsigned int from, FILE *file)
{
	if(file == NULL)
		return -1;

	// müssen wir konvertieren?
	if(BYTE_ORDER != BIG_ENDIAN)
	{
		// ja, dann tauschen
		from = swap_ui(from);
	}

	// Integer schreiben
	if(fwrite(&from, 1, 4, file) != 4)
		return 1;

	// alles ok
	return 0;
}
