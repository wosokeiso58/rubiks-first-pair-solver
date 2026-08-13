cmake_minimum_required(VERSION 3.26)
project(Keibe)

set(CMAKE_CXX_STANDARD 20)

add_executable(Keibe main.cpp
        cmake-build-debug/Cube.cpp
        cmake-build-debug/Cube.h)
