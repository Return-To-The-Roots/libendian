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
#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#pragma once

#ifdef HAVE_CONFIG_H
#   include "../config.h"
#endif // HAVE_CONFIG_H

#ifdef _WIN32
#    define WIN32_LEAN_AND_MEAN
#    ifdef _MSC_VER
#        include <crtdbg.h>
#        ifndef assert
#            define assert _ASSERT
#        endif
#    else
#        include <assert.h>
#    endif
#    ifdef _DEBUG
#        include <crtdbg.h>
#    endif // _WIN32 && _DEBUG
#else
#    include <assert.h>
#endif // !_WIN32

#endif // MAIN_H_INCLUDED
