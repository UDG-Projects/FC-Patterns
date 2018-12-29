cmake_minimum_required(VERSION 3.13)
project(fc_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fc_3
        Alphabet.cpp
        Alphabet.h
        main.cpp
        MatrixPattern.cpp
        MatrixPattern.h
        TM.cpp
        TM.h
        Utils.cpp
        Utils.h)
