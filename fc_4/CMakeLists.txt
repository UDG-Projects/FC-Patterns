cmake_minimum_required(VERSION 3.13)
project(fc_4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fc_4
        Alphabet.cpp
        Alphabet.h
        DFA.cpp
        DFA.h
        main.cpp
        MatrixPattern.cpp
        MatrixPattern.h
        PDA.cpp
        PDA.h
        TM.cpp
        TM.h
        Utils.cpp
        Utils.h)
