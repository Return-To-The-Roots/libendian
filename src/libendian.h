// $Id: libendian.h 6581 2010-07-16 11:16:34Z FloSoft $
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
#ifndef LIBENDIAN_H_INCLUDED
#define LIBENDIAN_H_INCLUDED

#pragma once

/// Die verschiedenen Big und ihre entsprechenden Little-Endian-Funktionen.
namespace libendian
{
	/// Vertauscht die Bytes eines Shorts.
	short swap_s(short s);

	/// Vertauscht die Bytes eines Unsigned Shorts.
	unsigned short swap_us(unsigned short us);

	/// Vertauscht die Bytes eines Ints.
	int swap_i(int i);

	/// Vertauscht die Bytes eines Unsigned Ints.
	unsigned int swap_ui(unsigned int ui);


	/// liest Little-Endian kodierte Chars aus einer Datei.
	int le_read_c(char *const to, unsigned int count, FILE *file);

	/// liest Little-Endian kodierte Unsigned Chars aus einer Datei.
	int le_read_uc(unsigned char *const to, unsigned int count, FILE *file);

	/// schreibt Little-Endian kodierte Chars aus einer Datei.
	int le_write_c(const char *const from, unsigned int count, FILE *file);

	/// schreibt Little-Endian kodierte Unsigned Chars aus einer Datei.
	int le_write_uc(const unsigned char *const from, unsigned int count, FILE *file);


	/// liest Big-Endian kodierte Chars aus einer Datei.
	int be_read_c(char *const to, unsigned int count, FILE *file);

	/// liest Big-Endian kodierte Unsigned Chars aus einer Datei.
	int be_read_uc(unsigned char *const to, unsigned int count, FILE *file);

	/// schreibt Big-Endian kodierte Chars aus einer Datei.
	int be_write_c(const char *const from, unsigned int count, FILE *file);

	/// schreibt Big-Endian kodierte Unsigned Chars aus einer Datei.
	int be_write_uc(const unsigned char *const from, unsigned int count, FILE *file);


	/// liest einen Little-Endian kodierten Integer aus einer Datei.
	int le_read_i(int *to, FILE *file);

	/// liest einen Little-Endian kodierten Unsigned Integer aus einer Datei.
	int le_read_ui(unsigned int *to, FILE *file);

	/// schreibt einen Little-Endian kodierten Integer in eine Datei.
	int le_write_i(int from, FILE *file);

	/// schreibt einen Little-Endian kodierten Unsigned Integer in eine Datei.
	int le_write_ui(unsigned int from, FILE *file);


	/// liest einen Big-Endian kodierten Integer aus einer Datei.
	int be_read_i(int *to, FILE *file);

	/// liest einen Big-Endian kodierten Unsigned Integer aus einer Datei.
	int be_read_ui(unsigned int *to, FILE *file);

	/// schreibt einen Big-Endian kodierten Integer in eine Datei.
	int be_write_i(int to, FILE *file);

	/// schreibt einen Big-Endian kodierten Unsigned Integer in eine Datei.
	int be_write_ui(unsigned int to, FILE *file);


	/// liest einen Little-Endian kodierten Short aus einer Datei.
	int le_read_s(short *to, FILE *file);

	/// liest einen Little-Endian kodierten Unsigned Short aus einer Datei.
	int le_read_us(unsigned short *to, FILE *file);

	/// schreibt einen Little-Endian kodierten Short in eine Datei.
	int le_write_s(short from, FILE *file);

	/// schreibt einen Little-Endian kodierten Unsigned Short in eine Datei.
	int le_write_us(unsigned short from, FILE *file);


	/// liest einen Big-Endian kodierten Short aus einer Datei.
	int be_read_s(short *to, FILE *file);

	/// liest einen Big-Endian kodierten Unsigned Short aus einer Datei.
	int be_read_us(unsigned short *to, FILE *file);

	/// schreibt einen Big-Endian kodierten Short in eine Datei.
	int be_write_s(short from, FILE *file);

	/// schreibt einen Big-Endian kodierten Unsigned Short in eine Datei.
	int be_write_us(unsigned short from, FILE *file);
}

#endif // !LIBENDIAN_H_INCLUDED
