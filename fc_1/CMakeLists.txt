cmake_minimum_required(VERSION 3.13)
project(fc_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(fc_1
        Alphabet.cpp
        Alphabet.h
        DFA.cpp
        DFA.h
        main.cpp
        Utils.cpp
        Utils.h)
