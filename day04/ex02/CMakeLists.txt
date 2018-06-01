cmake_minimum_required(VERSION 3.10)
project(ex02)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex02 main.cpp Squad.cpp Squad.hpp TacticalMarine.cpp TacticalMarine.hpp AssaultTerminator.cpp AssaultTerminator.hpp ISpaceMarine.hpp ISquad.hpp)