cmake_minimum_required(VERSION 4.0.2)
project(AvanceRapido)

set(CMAKE_CXX_STANDARD 20)

add_executable(AvanceRapido main.cpp
        Algoritmo/AvanceRapido.h
        Algoritmo/AvanceRapido.cpp
        Controlador/InputOuput.h
        Controlador/InputOuput.cpp
        Controlador/Controlador.h
        Controlador/Controlador.cpp)
