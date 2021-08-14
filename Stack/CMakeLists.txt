cmake_minimum_required(VERSION 2.8.12)

PROJECT(Stack)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

ADD_SUBDIRECTORY(src/stack)

ADD_EXECUTABLE(Stack src/main.cpp)
ADD_EXECUTABLE(StackTest src/mainTest.cpp)

ADD_DEPENDENCIES(Stack stack)
ADD_DEPENDENCIES(StackTest stack)

TARGET_LINK_LIBRARIES(Stack stack dl m)
TARGET_LINK_LIBRARIES(StackTest stack dl m)
