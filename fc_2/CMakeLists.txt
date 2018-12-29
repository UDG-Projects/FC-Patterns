cmake_minimum_required(VERSION 3.13)
project(fc_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fc_2
        Alphabet.cpp
        Alphabet.h
        main.cpp
        PDA.cpp
        PDA.h
        Utils.cpp
        Utils.h)
