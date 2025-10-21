cmake_minimum_required(VERSION 4.0)
project(2022604_LAB2_P1_25_2_)

set(CMAKE_CXX_STANDARD 20)

add_executable(2022604_LAB2_P1_25_2_ main.cpp
        BibliotecaLista/Lista.h
        BibliotecaLista/funcionesLista.cpp
        BibliotecaLista/funcionesLista.h
        BibliotecaLista/ElementoLista.h
        BibliotecaLista/NodoLista.h)
