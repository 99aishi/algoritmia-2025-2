cmake_minimum_required(VERSION 4.0)
project(ab_23_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(ab_23_1 main.cpp
        BibliotecaArbolBinario/ElementoArbolBinario.h
        BibliotecaArbolBinario/ArbolBinario.h
        BibliotecaArbolBinario/NodoArbolBinario.h
        BibliotecaArbolBinario/funcionesArbolBinario.cpp
        BibliotecaArbolBinario/funcionesArbolBinario.h
        BibliotecaCola/funcionesCola.cpp
        BibliotecaCola/funcionesCola.h
        BibliotecaCola/NodoCola.h
        BibliotecaCola/Cola.h
        BibliotecaCola/ElementoCola.h
)
