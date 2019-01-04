FIND_PACKAGE(Boost 1.58.0 REQUIRED)

FILE(GLOB SRC_FILES src/*.cpp)
FILE(GLOB HEADER_FILES include/libendian/*.*)

add_library(endian_interface INTERFACE)
add_library(endian::interface ALIAS endian_interface)
target_include_directories(endian_interface INTERFACE include)
target_link_libraries(endian_interface INTERFACE Boost::boost)
target_compile_features(endian_interface INTERFACE cxx_std_14)

# Optional. Build only when referenced as it can also be used as header-only library
add_library(endian_static STATIC EXCLUDE_FROM_ALL ${SRC_FILES} ${HEADER_FILES})
add_library(endian::static ALIAS endian_static)
target_include_directories(endian_static PRIVATE include/libendian)
target_link_libraries(endian_static PUBLIC endian_interface)
set_target_properties(endian_static PROPERTIES CXX_EXTENSIONS OFF)

include(EnableWarnings)
enable_warnings(endian_interface)

if(ClangFormat_FOUND)
    add_clangFormat_files(${SRC_FILES} ${HEADER_FILES})
endif()
