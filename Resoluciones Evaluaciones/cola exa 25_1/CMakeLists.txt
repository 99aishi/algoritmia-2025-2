cmake_minimum_required(VERSION 4.0)
project(cola_exa_25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(cola_exa_25_1 main.cpp
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h)
