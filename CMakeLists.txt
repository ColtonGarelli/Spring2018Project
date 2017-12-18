cmake_minimum_required(VERSION 3.8)
project(pro_ject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES main.cpp Task.cpp LinkedNode.cpp ArrayLib.cpp TaskLinkedList.cpp TaskList.h ArrayList.cpp Controller.cpp)
add_executable(pro_ject ${SOURCE_FILES})