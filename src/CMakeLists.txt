
ADD_LIBRARY(endian STATIC libendian.cpp read_char.cpp read_int.cpp
            read_short.cpp swap.cpp write_char.cpp write_int.cpp
            write_short.cpp)

#INSTALL(TARGETS endian DESTINATION lib)
#INSTALL(FILES DESTINATION /include/libsiedler2/libendian)

#################################################################################
