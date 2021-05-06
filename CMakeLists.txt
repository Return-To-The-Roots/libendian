# Copyright (C) 2005 - 2021 Settlers Freaks <sf-team at siedler25.org>
#
# SPDX-License-Identifier: GPL-2.0-or-later

cmake_minimum_required(VERSION 3.8)
if(POLICY CMP0074)
    cmake_policy(SET CMP0074 NEW)
endif()
project(libendian)

include(RttrBoostCfg)
find_package(Boost 1.64.0 REQUIRED)

include(EnableWarnings)

file(GLOB _sources src/*.cpp)
file(GLOB_RECURSE _headers include/*.*)

add_library(endian_interface INTERFACE)
add_library(endian::interface ALIAS endian_interface)

target_include_directories(endian_interface INTERFACE include)
target_link_libraries(endian_interface INTERFACE Boost::boost)
target_compile_features(endian_interface INTERFACE cxx_std_14)

enable_warnings(endian_interface)

# Optional. Build only when referenced as it can also be used as header-only library

add_library(endian_static STATIC EXCLUDE_FROM_ALL ${_sources} ${_headers})
add_library(endian::static ALIAS endian_static)

target_link_libraries(endian_static PUBLIC endian_interface)
set_target_properties(endian_static PROPERTIES CXX_EXTENSIONS OFF)

enable_warnings(endian_static)

if(ClangFormat_FOUND)
    add_clangFormat_files(${_sources} ${_headers})
endif()
