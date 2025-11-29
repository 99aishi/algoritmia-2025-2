cmake_minimum_required(VERSION 4.0)
project(abb_24_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(abb_24_2 main.cpp
        BibliotecaArbolBinarioBusqueda/ElementoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/NodoArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.cpp
        BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h
        BibliotecaArbolBinarioBusqueda/Pila.h
        BibliotecaArbolBinarioBusqueda/funcionesPila.cpp
        BibliotecaArbolBinarioBusqueda/funcionesPila.h
        BibliotecaArbolBinarioBusqueda/NodoPila.h
        BibliotecaArbolBinarioBusqueda/ElementoPila.h)
