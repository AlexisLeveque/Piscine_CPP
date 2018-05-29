cmake_minimum_required(VERSION 3.9)
project(ex05)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex05 main.cpp
        human.cpp
        Human.hpp
        Brain.cpp
        brain.hpp)