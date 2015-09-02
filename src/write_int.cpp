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

///////////////////////////////////////////////////////////////////////////////
// Header
#include "main.h"
#include "libendian.h"

///////////////////////////////////////////////////////////////////////////////
/**
 *  Writes a Little-Endian encoded int to a FILE.
 *
 *  @param[in] from  pointer to source int
 *  @param[in] file  file to write to
 *
 *  @return liefert Null bei Erfolg, ein Wert ungleich Null bei Fehler
 *
 *  @author FloSoft
 */
int libendian::le_write_i(int from, FILE* file)
{
    return le_write_ui( (unsigned int)from, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  Writes a Little-Endian encoded unsigned int to a FILE.
 *
 *  @param[in] from  pointer to source int
 *  @param[in] file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::le_write_ui(unsigned int from, FILE* file)
{
    if(file == NULL)
        return -1;

    if(BYTE_ORDER != LITTLE_ENDIAN)
    {
        from = swap_ui(from);
    }

    if(fwrite(&from, 1, 4, file) != 4)
        return 1;

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  Writes a Big-Endian encoded int to a FILE.
 *
 *  @param[in] from  pointer to source int
 *  @param[in] file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::be_write_i(int from, FILE* file)
{
    return be_write_ui( (unsigned int)from, file);
}

///////////////////////////////////////////////////////////////////////////////
/**
 *  Writes a Big-Endian encoded unsigned int to a FILE.
 *
 *  @param[in] from  pointer to source int
 *  @param[in] file  file to write to
 *
 *  @return 0 on success, other values on error
 *
 *  @author FloSoft
 */
int libendian::be_write_ui(unsigned int from, FILE* file)
{
    if(file == NULL)
        return -1;

    if(BYTE_ORDER != BIG_ENDIAN)
    {
        from = swap_ui(from);
    }

    if(fwrite(&from, 1, 4, file) != 4)
        return 1;

    return 0;
}
