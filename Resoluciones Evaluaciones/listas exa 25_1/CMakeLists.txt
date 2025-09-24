cmake_minimum_required(VERSION 4.0)
project(listas_exa_25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(listas_exa_25_1 main.cpp
        funcionesLista.cpp
        funcionesLista.h
        Lista.h
        NodoLista.h
        ElementoLista.h)
