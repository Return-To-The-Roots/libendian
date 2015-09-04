
FILE(GLOB SRC_FILES *.cpp *.h)
ADD_LIBRARY(endian STATIC ${SRC_FILES})

#INSTALL(TARGETS endian DESTINATION lib)
#INSTALL(FILES DESTINATION /include/libsiedler2/libendian)

#################################################################################
