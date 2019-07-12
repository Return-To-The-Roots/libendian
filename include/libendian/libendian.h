//
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Copyright (c) 2005 - 2019 Settlers Freaks (sf-team at siedler25.org)
//

#pragma once
#ifndef libendian_include_libendian_libendian_h
#define libendian_include_libendian_libendian_h

#pragma once

#include <array>
#include <cstdint>
#include <cstdio>

/// Various Big and Little Endian functions.
namespace libendian {

/// Read raw chars from a FILE.
bool read(char* to, uint32_t count, FILE* file);
bool read(uint8_t* to, uint32_t count, FILE* file);
bool read(int8_t* to, uint32_t count, FILE* file);

template<typename T, size_t size>
bool read(std::array<T, size>& to, FILE* file)
{
    static_assert(sizeof(T) == 1, "Only for byte sized types!");
    return read(to.data(), to.size(), file);
}

/// Write raw chars to a FILE.
bool write(const char* from, uint32_t count, FILE* file);
bool write(const uint8_t* from, uint32_t count, FILE* file);
bool write(const int8_t* from, uint32_t count, FILE* file);

template<typename T, size_t size>
bool write(const std::array<T, size>& from, FILE* file)
{
    static_assert(sizeof(T) == 1, "Only for byte sized types!");
    return write(from.data(), from.size(), file);
}

/// Read an LE coded (uint32_t) int32_t from a FILE.
bool le_read_i(int32_t* to, FILE* file);
bool le_read_ui(uint32_t* to, FILE* file);

/// Write an LE coded (uint32_t) int32_t to a FILE.
bool le_write_i(int32_t from, FILE* file);
bool le_write_ui(uint32_t from, FILE* file);

/// Read a BE coded (uint32_t) int32_t from a FILE.
bool be_read_i(int32_t* to, FILE* file);
bool be_read_ui(uint32_t* to, FILE* file);

/// Write a BE coded (uint32_t) int32_t to a FILE.
bool be_write_i(int32_t from, FILE* file);
bool be_write_ui(uint32_t from, FILE* file);

/// Read an LE coded (uint32_t) int16_t from a FILE.
bool le_read_s(int16_t* to, FILE* file);
bool le_read_us(uint16_t* to, FILE* file);

/// Write an LE coded (uint32_t) int16_t to a FILE.
bool le_write_s(int16_t from, FILE* file);
bool le_write_us(uint16_t from, FILE* file);

/// Read a BE coded (uint32_t) int16_t from a FILE.
bool be_read_s(int16_t* to, FILE* file);
bool be_read_us(uint16_t* to, FILE* file);

/// Write a BE coded (uint32_t) int16_t to a FILE.
bool be_write_s(int16_t from, FILE* file);
bool be_write_us(uint16_t from, FILE* file);

} // namespace libendian

#endif // !!libendian_include_libendian_libendian_h
