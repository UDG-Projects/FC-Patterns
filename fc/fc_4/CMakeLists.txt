
cmake_minimum_required(VERSION 3.12)
project(practicafinal)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(practicafinal
        main.cpp
        MatrixPattern.cpp
        MatrixPattern.h DFA.cpp DFA.h PDA.cpp PDA.h Alphabet.cpp Alphabet.h Utils.cpp Utils.h TM.cpp TM.h)
