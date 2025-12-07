cmake_minimum_required(VERSION 4.0)
project(EX2_P3)

set(CMAKE_CXX_STANDARD 20)

add_executable(EX2_P3 main.cpp
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

        BibliotecaPila/Pila.h
        BibliotecaPila/funcionesPila.cpp
        BibliotecaPila/funcionesPila.h
        BibliotecaPila/NodoPila.h
        BibliotecaPila/ElementoPila.h
)
