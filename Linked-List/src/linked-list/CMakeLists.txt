set(SOURCE_FILES_LINKED_LIST linked_list.h linked_list.cpp)

ADD_LIBRARY(linkedlist STATIC ${SOURCE_FILES_LINKED_LIST})

if(NOT MSVC)
    set_property(TARGET linkedlist PROPERTY POSITION_INDEPENDENT_CODE ON)
endif()