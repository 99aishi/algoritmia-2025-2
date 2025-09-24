cmake_minimum_required(VERSION 4.0)
project(listas_lab_25_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(listas_lab_25_1  main.cpp
        BibliotecaLista/Lista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/NodoLista.h)
