cmake_minimum_required(VERSION 3.26)
project(HW4)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(sources)

add_executable(HW4
        include/classes.h
        sources/class_functions.cpp
        sources/main.cpp
)
add_executable(Test_1
        include/classes.h
        sources/class_functions.cpp)
