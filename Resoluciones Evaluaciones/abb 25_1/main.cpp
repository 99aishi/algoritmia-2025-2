/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 11/28/2025, 11:10 PM
 */

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesPila.h"
#include "BibliotecaArbolBinarioBusqueda/Pila.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
using namespace std;


NodoArbolBinarioBusqueda* buscar_nodo(NodoArbolBinarioBusqueda *raiz,ElementoArbolBinarioBusqueda elem) {
    NodoArbolBinarioBusqueda* nodo=raiz;
    while (nodo!=nullptr) {
        if (nodo->elemento.numero==elem.numero)
            return nodo;
        else
            if (nodo->elemento.numero<elem.numero) {
                nodo=nodo->derecha;
            }else {
                nodo=nodo->izquierda;
            }
    }
    return nullptr;
}

int main(int argc, char **argv) {

    ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol,{100});
    insertar(arbol,{50});
    insertar(arbol,{25});
    insertar(arbol,{75});
    insertar(arbol,{30});
    insertar(arbol,{28});
    insertar(arbol,{150});
    insertar(arbol,{125});
    insertar(arbol,{175});
    insertar(arbol,{200});

    // recorrerPreOrden(arbol);


    Pila pila;
    construir(pila);
    NodoArbolBinarioBusqueda* nodo=arbol.raiz;
    while (nodo!=nullptr or !esPilaVacia(pila)) {

        while (nodo!=nullptr) {
            apilar(pila,{nodo->elemento});
            nodo=nodo->derecha;
        }

        ElementoArbolBinarioBusqueda elem= desapilar(pila).elem;
        nodo = buscar_nodo(arbol.raiz,elem);

        if (nodo!=nullptr) {

            if (nodo->izquierda == nullptr and nodo->derecha == nullptr) {
                nodo=nodo->izquierda;
            }else {
                delete nodo;

            }

            cout << nodo->elemento.numero << " ";

        }
    }


    return 0;
}