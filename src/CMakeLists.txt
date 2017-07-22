# Optional as only headers require it
FIND_PACKAGE(Boost 1.58.0)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

FILE(GLOB SRC_FILES *.cpp *.h)
ADD_LIBRARY(endian STATIC ${SRC_FILES})

#INSTALL(TARGETS endian DESTINATION lib)
#INSTALL(FILES DESTINATION /include/libsiedler2/libendian)

#################################################################################
