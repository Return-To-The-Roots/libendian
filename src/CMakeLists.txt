#################################################################################
### $Id: CMakeLists.txt 7178 2011-04-17 15:53:20Z FloSoft $
#################################################################################

FILE(GLOB SRC_FILES *.cpp *.h)
ADD_LIBRARY(endian STATIC ${SRC_FILES})

#INSTALL(TARGETS endian DESTINATION lib)
#INSTALL(FILES DESTINATION /include/libsiedler2/libendian)

#################################################################################
