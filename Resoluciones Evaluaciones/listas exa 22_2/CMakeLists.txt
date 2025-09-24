cmake_minimum_required(VERSION 4.0)
project(listas_exa_24_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(listas_exa_24_2 main.cpp
        BibliotecaLista/Lista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/NodoLista.h)
