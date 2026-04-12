cmake_minimum_required(VERSION 4.1)
project(Backtracking)

set(CMAKE_CXX_STANDARD 20)

add_executable(Backtracking main.cpp
        Algoritmo/Backtracking.cpp
        Algoritmo/Backtracking.h
        Controlador/Controlador.cpp
        Controlador/Controlador.h
)
