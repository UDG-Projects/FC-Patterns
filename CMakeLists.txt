<<<<<<< HEAD
cmake_minimum_required(VERSION 3.13)
project(TuringMachine)
=======
cmake_minimum_required(VERSION 3.12)
project(practicafinal)
>>>>>>> 8fae8c380e139a46c09f6ba9e2d5a667eb4b2a77

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

<<<<<<< HEAD
add_executable(TuringMachine
        main.cpp
        Matrix.cpp
        Matrix.h)
=======
add_executable(practicafinal
        main.cpp
        Matrix.cpp
        Matrix.h DFA.cpp DFA.h PDA.cpp PDA.h Alphabet.cpp Alphabet.h)
>>>>>>> 8fae8c380e139a46c09f6ba9e2d5a667eb4b2a77
