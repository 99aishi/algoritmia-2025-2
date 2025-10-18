cmake_minimum_required(VERSION 4.0)
project(pila_exa_24_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(pila_exa_24_2 main.cpp
        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/ElementoPila.h)

