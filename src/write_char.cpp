// $Id: write_char.cpp 6581 2010-07-16 11:16:34Z FloSoft $
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
 *  schreibt Little-Endian kodierte Chars aus einer Datei.
 *
 *  @param[out] from  Quellpuffer
 *  @param[in]  count Anzahl zu schreibende Zeichen
 *  @param[in]  file  Datei in die geschrieben werden soll
 *
 *  @return liefert Anzahl der geschriebenen Bytes, -1 bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_write_c(const char *const from, unsigned int count, FILE *file)
{
	return le_write_uc( (const unsigned char*)from, count, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  schreibt Little-Endian kodierte Unsigned Chars aus einer Datei.
 *
 *  @param[out] from  Quellpuffer
 *  @param[in]  count Anzahl zu schreibende Zeichen
 *  @param[in]  file  Datei in die geschrieben werden soll
 *
 *  @return liefert Anzahl der geschriebenen Bytes, -1 bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_write_uc(const unsigned char *const from, unsigned int count, FILE *file)
{
	if(from == NULL || file == NULL)
		return -1;

	// chars können wir ohne Konvertierung einlesen
	return (int)fwrite(from, 1, count, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  schreibt Big-Endian kodierte Chars aus einer Datei.
 *
 *  @param[out] from  Quellpuffer
 *  @param[in]  count Anzahl zu schreibende Zeichen
 *  @param[in]  file  Datei in die geschrieben werden soll
 *
 *  @return liefert Anzahl der geschriebenen Bytes, -1 bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_write_c(const char *const from, unsigned int count, FILE *file)
{
	return be_write_uc( (const unsigned char*)from, count, file);
}

///////////////////////////////////////////////////////////////////////////////
/** 
 *  schreibt Big-Endian kodierte Unsigned Chars aus einer Datei.
 *
 *  @param[out] from  Quellpuffer
 *  @param[in]  count Anzahl zu schreibende Zeichen
 *  @param[in]  file  Datei in die geschrieben werden soll
 *
 *  @return liefert Anzahl der geschriebenen Bytes, -1 bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_write_uc(const unsigned char *const from, unsigned int count, FILE *file)
{
	if(from == NULL || file == NULL)
		return -1;

	// chars können wir ohne Konvertierung einlesen
	return (int)fwrite(from, 1, count, file);
}
