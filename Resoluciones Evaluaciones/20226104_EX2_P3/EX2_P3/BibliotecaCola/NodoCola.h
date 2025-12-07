//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal 

#ifndef COLA_NODOCOLA_H
#define COLA_NODOCOLA_H
#include "../BibliotecaArbolBinario/NodoArbolBinario.h"
struct NodoCola {
    struct NodoArbolBinario * nodo; //nuevo elemento nodo Arbol
    NodoCola * siguiente;
};
#endif //COLA_NODOCOLA_H