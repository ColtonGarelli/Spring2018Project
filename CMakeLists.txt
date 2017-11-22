cmake_minimum_required(VERSION 3.8)
project(pro_ject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Task.cpp TaskTest.cpp TaskTest.h TaskTime.cpp TaskTime.h)
add_executable(pro_ject ${SOURCE_FILES})