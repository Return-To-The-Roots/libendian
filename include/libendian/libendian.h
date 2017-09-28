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
#ifndef LIBENDIAN_H_INCLUDED
#define LIBENDIAN_H_INCLUDED

#pragma once

#include "endianess.h"
#include <cstdio>

/// Various Big and Little Endian functions.
namespace libendian {
/// Swap the bytes of (unsigned) shorts and ints.
short swap_s(short s);
unsigned short swap_us(unsigned short us);
int swap_i(int i);
unsigned swap_ui(unsigned ui);

/// Read LE coded (unsigned) chars from a FILE.
int le_read_c(char* const to, unsigned count, FILE* file);
int le_read_uc(unsigned char* const to, unsigned count, FILE* file);

/// Write LE coded (unsigned) chars to a FILE.
int le_write_c(const char* const from, unsigned count, FILE* file);
int le_write_uc(const unsigned char* const from, unsigned count, FILE* file);

/// Read BE coded (unsigned) chars from a FILE.
int be_read_c(char* const to, unsigned count, FILE* file);
int be_read_uc(unsigned char* const to, unsigned count, FILE* file);

/// Write BE coded (unsigned) chars to a FILE.
int be_write_c(const char* const from, unsigned count, FILE* file);
int be_write_uc(const unsigned char* const from, unsigned count, FILE* file);

/// Read an LE coded (unsigned) int from a FILE.
int le_read_i(int* to, FILE* file);
int le_read_ui(unsigned* to, FILE* file);

/// Write an LE coded (unsigned) int to a FILE.
int le_write_i(int from, FILE* file);
int le_write_ui(unsigned from, FILE* file);

/// Read a BE coded (unsigned) int from a FILE.
int be_read_i(int* to, FILE* file);
int be_read_ui(unsigned* to, FILE* file);

/// Write a BE coded (unsigned) int to a FILE.
int be_write_i(int to, FILE* file);
int be_write_ui(unsigned to, FILE* file);

/// Read an LE coded (unsigned) short from a FILE.
int le_read_s(short* to, FILE* file);
int le_read_us(unsigned short* to, FILE* file);

/// Write an LE coded (unsigned) short to a FILE.
int le_write_s(short from, FILE* file);
int le_write_us(unsigned short from, FILE* file);

/// Read a BE coded (unsigned) short from a FILE.
int be_read_s(short* to, FILE* file);
int be_read_us(unsigned short* to, FILE* file);

/// Write a BE coded (unsigned) short to a FILE.
int be_write_s(short from, FILE* file);
int be_write_us(unsigned short from, FILE* file);
} // namespace libendian

#endif // !LIBENDIAN_H_INCLUDED
