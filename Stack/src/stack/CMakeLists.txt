set(SOURCE_FILES_STACK stack.h stack.cpp)

ADD_LIBRARY(stack STATIC ${SOURCE_FILES_STACK})

if(NOT MSVC)
    set_property(TARGET stack PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()