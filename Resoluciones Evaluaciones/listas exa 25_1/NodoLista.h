//
// Created by 999 on 9/21/2025.
//

#ifndef LISTAS_EXA_25_1_NODOLISTA_H
#define LISTAS_EXA_25_1_NODOLISTA_H
#include "ElementoLista.h"

struct NodoLista {
    struct ElementoLista elemento;
    struct NodoLista *siguiente;
};
#endif //LISTAS_EXA_25_1_NODOLISTA_H