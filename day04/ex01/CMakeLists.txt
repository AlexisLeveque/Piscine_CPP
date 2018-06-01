cmake_minimum_required(VERSION 3.10)
project(ex01)

set(CMAKE_CXX_STANDARD 98)

add_executable(ex01 main.cpp Enemy.cpp Enemy.hpp
            AWeapon.cpp AWeapon.cpp PlasmaRifle.cpp PlasmaRifle.hpp PowerFist.cpp PowerFist.hpp
        SuperMutant.cpp SuperMutant.hpp RadScorpion.cpp RadScorpion.hpp Character.cpp Character.hpp)