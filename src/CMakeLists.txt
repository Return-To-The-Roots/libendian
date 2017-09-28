# Optional as only headers require it
FIND_PACKAGE(Boost 1.58.0)

get_filename_component(parentPath ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(includePath ${parentPath}/include)

INCLUDE_DIRECTORIES(${includePath}/libendian)

FILE(GLOB SRC_FILES *.cpp)
FILE(GLOB HEADER_FILES ${includePath}/libendian/*.*)
# Optional. Build only when referenced
ADD_LIBRARY(endian STATIC EXCLUDE_FROM_ALL ${SRC_FILES} ${HEADER_FILES})
# Header only library
ADD_LIBRARY(endianStreams INTERFACE)

target_include_directories(endian PUBLIC ${includePath})
target_include_directories(endian SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(endianStreams INTERFACE ${includePath})
target_include_directories(endianStreams SYSTEM INTERFACE ${Boost_INCLUDE_DIRS})

if(ClangFormat_FOUND)
    add_clangFormat_files(${SRC_FILES} ${HEADER_FILES})
endif()
