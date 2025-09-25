cmake_minimum_required(VERSION 4.0)
project(pilas_exa_22_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(pilas_exa_22_2 main.cpp
        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/ElementoPila.h)
