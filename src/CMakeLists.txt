# Optional as only headers require it
FIND_PACKAGE(Boost 1.58.0)

get_filename_component(parentPath ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

FILE(GLOB SRC_FILES *.cpp)
FILE(GLOB HEADER_FILES ${parentPath}/include/libendian/*.* *.h)

add_library(endian_interface INTERFACE)
add_library(endian::interface ALIAS endian_interface)
target_include_directories(endian_interface INTERFACE ${parentPath}/include)
target_link_libraries(endian_interface INTERFACE Boost::boost)

# Optional. Build only when referenced as it can also be used as header-only library
add_library(endian_static STATIC EXCLUDE_FROM_ALL ${SRC_FILES} ${HEADER_FILES})
add_library(endian::static ALIAS endian_static)
target_include_directories(endian_static PRIVATE ${parentPath}/include/libendian)
target_link_libraries(endian_static PUBLIC endian_interface)

include(EnableWarnings)
enable_warnings(endian_interface)

if(ClangFormat_FOUND)
    add_clangFormat_files(${SRC_FILES} ${HEADER_FILES})
endif()
