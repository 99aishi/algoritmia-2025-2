cmake_minimum_required(VERSION 4.0)
project(ab_2a_24_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ab_2a_24_2 main.cpp
        BibliotecaArbolBinario/ElementoArbolBinario.h
        BibliotecaArbolBinario/ArbolBinario.h
        BibliotecaArbolBinario/NodoArbolBinario.h
        BibliotecaArbolBinario/funcionesArbolBinario.cpp
        BibliotecaArbolBinario/funcionesArbolBinario.h)
