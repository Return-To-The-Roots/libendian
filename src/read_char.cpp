// $Id: read_char.cpp 7521 2011-09-08 20:45:55Z FloSoft $
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
 *  liest Little-Endian kodierte Chars aus einer Datei.
 *
 *  @param[out] to    Zielpuffer
 *  @param[in]  count Anzahl gewünschter Zeichen
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Anzahl der gelesenen Bytes, -1 bei Fehler, 0 bei EOF
 *
 *  @author FloSoft
 */
int libendian::le_read_c(char *const to, unsigned int count, FILE *file)
{
	return le_read_uc( (unsigned char*)to, count, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  liest Little-Endian kodierte Unsigned Chars aus einer Datei.
 *
 *  @param[out] to    Zielpuffer
 *  @param[in]  count Anzahl gewünschter Zeichen
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Anzahl der gelesenen Bytes, -1 bei Fehler, 0 bei EOF
 *
 *  @author FloSoft
 */
int libendian::le_read_uc(unsigned char *const to, unsigned int count, FILE *file)
{
	if(to == NULL || file == NULL)
		return -1;

	// chars können wir ohne Konvertierung einlesen
	return (int)fread(to, 1, count, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  liest Big-Endian kodierte Chars aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielchar(s)
 *  @param[in]  count Anzahl gewünschter Zeichen
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Anzahl der gelesenen Bytes, -1 bei Fehler, 0 bei EOF
 *
 *  @author FloSoft
 */
int libendian::be_read_c(char *const to, unsigned int count, FILE *file)
{
	return be_read_uc( (unsigned char*)to, count, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  liest Big-Endian kodierte Unsigned Chars aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielchar(s)
 *  @param[in]  count Anzahl gewünschter Zeichen
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Anzahl der gelesenen Bytes, -1 bei Fehler, 0 bei EOF
 *
 *  @author FloSoft
 */
int libendian::be_read_uc(unsigned char *const to, unsigned int count, FILE *file)
{
	if(to == NULL || file == NULL)
		return -1;

	// chars können wir ohne Konvertierung einlesen
	return (int)fread(to, 1, count, file);
}
