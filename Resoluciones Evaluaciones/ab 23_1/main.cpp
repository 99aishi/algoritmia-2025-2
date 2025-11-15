/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 11/14/2025, 6:43 PM
 */

#include <iostream>
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;

int buscar_skynerd(ArbolBinario &arbol) {
    Cola cola;
    int i = 1;
    construir(cola);
    encolar(cola, {arbol.raiz});
    encolar(cola, {nullptr});
    while (!esColaVacia(cola)) {
        NodoArbolBinario *nodo = desencolar(cola).nodo;
        if (nodo == nullptr) {
            i++;
            if (not esColaVacia(cola)) {
                encolar(cola, {nullptr});
            }
        } else {
            if (nodo->izquierda != nullptr) {
                encolar(cola, {nodo->izquierda});
            }
            if (nodo->derecha != nullptr) {
                encolar(cola, {nodo->derecha});
            }
            if (nodo->elemento.numero == 200) {
                if (nodo->izquierda!=nullptr and nodo->derecha!=nullptr) {
                    if ((nodo->derecha->elemento.numero == 200 and nodo->derecha->elemento.tipo == 'S')
                    or (nodo->izquierda->elemento.numero == 200 and nodo->izquierda->elemento.tipo == 'S')) {
                        // cout << "Nivel: " << i << endl;
                        return i+1;
                    }
                }
            }
        }
    }
    return -1;
}


int main(int argc, char **argv) {
    ArbolBinario arbol, arbolvacio, a1, a2, a3, a4, a5, a6, a7;
    construir(arbol);
    construir(arbolvacio);
    plantarArbolBinario(a1, arbolvacio, {50, 'E'}, arbolvacio);
    plantarArbolBinario(a2, a1, {50, 'S'}, arbolvacio);

    plantarArbolBinario(a3, arbolvacio, {100, 'E'}, arbolvacio);
    plantarArbolBinario(a4, a3, {200, 'Z'}, arbolvacio);

    plantarArbolBinario(a5, a2, {100, 'E'}, a4);

    plantarArbolBinario(a6, arbolvacio, {50, 'S'}, arbolvacio);
    plantarArbolBinario(a7, a5, {50, 'Z'}, a6); // hijo izq

    ArbolBinario a8, a9, a10, a11, a12;
    plantarArbolBinario(a8, arbolvacio, {100, 'S'}, arbolvacio);
    plantarArbolBinario(a9, arbolvacio, {100, 'E'}, arbolvacio);
    plantarArbolBinario(a10, a8, {200, 'E'}, a9);

    plantarArbolBinario(a11, arbolvacio, {150, 'S'}, arbolvacio);
    plantarArbolBinario(a12, a10, {200, 'E'}, a11);

    plantarArbolBinario(arbol, a7, {100, 'Z'}, a12);
    // cout<< altura(arbol);

    int validar = buscar_skynerd(arbol);
    if (validar!=-1) {
        cout << "Existe Skynerd en el nivel " << validar << endl;
    }else {
        cout << "No Skynerd "<<endl;
    }
    //     cout << " Si existe Skynerd. "<<endl;
    return 0;
}
