# Optional as only headers require it
FIND_PACKAGE(Boost 1.58.0)

get_filename_component(parentPath ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(LIBENDIAN_INCLUDE_DIRS ${parentPath}/include CACHE PATH "Path to libEndian includes")

INCLUDE_DIRECTORIES(${LIBENDIAN_INCLUDE_DIRS}/libendian)

FILE(GLOB SRC_FILES *.cpp)
FILE(GLOB HEADER_FILES ${LIBENDIAN_INCLUDE_DIRS}/libendian/*.* *.h)
# Optional. Build only when referenced as it can also be used as header-only library
ADD_LIBRARY(endian STATIC EXCLUDE_FROM_ALL ${SRC_FILES} ${HEADER_FILES})

target_include_directories(endian INTERFACE ${LIBENDIAN_INCLUDE_DIRS})
target_include_directories(endian SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})

if(ClangFormat_FOUND)
    add_clangFormat_files(${SRC_FILES} ${HEADER_FILES})
endif()
