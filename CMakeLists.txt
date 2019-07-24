cmake_minimum_required(VERSION 3.14)
project(Aluminium CXX)
add_definitions("-Wall -Wextra -std=c++17")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR})
add_executable(a.out
    test.cpp
)
