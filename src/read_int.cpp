// $Id: read_int.cpp 9358 2014-04-25 15:36:21Z FloSoft $
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
 *  liest einen Little-Endian kodierten Integer aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielinteger
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_read_i(int* to, FILE* file)
{
    return le_read_ui( (unsigned int*)to, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  liest einen Little-Endian kodierten Unsigned Integer aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielinteger
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_read_ui(unsigned int* to, FILE* file)
{
    if(to == NULL || file == NULL)
        return -1;

    // Integer einlesen
    if(fread(to, 1, 4, file) != 4)
        return 1;

    // müssen wir konvertieren?
    if(BYTE_ORDER != LITTLE_ENDIAN)
    {
        // ja, dann tauschen
        *to = swap_ui(*to);
    }

    // alles ok
    return 0;
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  liest einen Big-Endian kodierten Integer aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielinteger
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_read_i(int* to, FILE* file)
{
    return be_read_ui( (unsigned int*)to, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  liest einen Big-Endian kodierten Unsigned Integer aus einer Datei.
 *
 *  @param[out] to    Pointer auf Zielinteger
 *  @param[in]  file  Datei aus der gelesen werden soll
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::be_read_ui(unsigned int* to, FILE* file)
{
    if(to == NULL || file == NULL)
        return -1;

    // Integer einlesen
    if(fread(to, 1, 4, file) != 4)
        return 1;

    // müssen wir konvertieren?
    if(BYTE_ORDER != BIG_ENDIAN)
    {
        // ja, dann tauschen
        *to = swap_ui(*to);
    }

    // alles ok
    return 0;
}
