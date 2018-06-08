cmake_minimum_required(VERSION 3.10)
project(ex00)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex00 main.cpp Sorcerer.cpp Sorcerer.hpp Victim.cpp Victim.hpp Peon.cpp Peon.hpp)