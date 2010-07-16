// $Id: main.h 6581 2010-07-16 11:16:34Z FloSoft $
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
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#pragma once

#ifdef HAVE_CONFIG_H
#	include "../config.h"
#endif // HAVE_CONFIG_H

#include <cstdio>

#if defined _WIN32 || defined __CYGWIN__
#	undef LITTLE_ENDIAN
#	undef BIG_ENDIAN
#	undef BYTE_ORDER
#	define LITTLE_ENDIAN 1234
#	define BIG_ENDIAN    4321
#	define BYTE_ORDER    LITTLE_ENDIAN
#else
#	include <sys/param.h>
#endif // !_WIN32

#if BYTE_ORDER != LITTLE_ENDIAN && BYTE_ORDER != BIG_ENDIAN
#	error "Sorry your Byteorder is not supported by this Library"
#endif // BYTE_ORDER != LITTLE_ENDIAN && BYTE_ORDER != BIG_ENDIAN

#endif // MAIN_H_INCLUDED
