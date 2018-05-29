cmake_minimum_required(VERSION 3.9)
project(ex06)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex06 main.cpp
        Weapon.cpp
        Weapon.hpp
        HumanA.cpp
        HumanA.hpp
        HumanB.cpp
        HumanB.hpp)