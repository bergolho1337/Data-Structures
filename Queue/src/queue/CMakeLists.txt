set(SOURCE_FILES_QUEUE queue.h queue.cpp)

ADD_LIBRARY(queue STATIC ${SOURCE_FILES_QUEUE})

if(NOT MSVC)
    set_property(TARGET queue PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()