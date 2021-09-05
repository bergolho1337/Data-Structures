cmake_minimum_required(VERSION 2.8.12)

PROJECT(Queue)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

ADD_SUBDIRECTORY(src/queue)

ADD_EXECUTABLE(Queue src/main.cpp)
ADD_EXECUTABLE(QueueTest src/mainTest.cpp)

ADD_DEPENDENCIES(Queue queue)
ADD_DEPENDENCIES(QueueTest queue)

TARGET_LINK_LIBRARIES(Queue queue dl m)
TARGET_LINK_LIBRARIES(QueueTest queue dl m)
