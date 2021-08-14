cmake_minimum_required(VERSION 2.8.12)

PROJECT(LinkedList)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

ADD_SUBDIRECTORY(src/linked-list)

ADD_EXECUTABLE(LinkedList src/main.cpp)
ADD_EXECUTABLE(LinkedListTest src/mainTest.cpp)

ADD_DEPENDENCIES(LinkedList linkedlist)
ADD_DEPENDENCIES(LinkedListTest linkedlist)

TARGET_LINK_LIBRARIES(LinkedList linkedlist dl m)
TARGET_LINK_LIBRARIES(LinkedListTest linkedlist dl m)
