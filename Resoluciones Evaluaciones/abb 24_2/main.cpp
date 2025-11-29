/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 11/28/2025, 3:30 PM
 */

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/Pila.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesPila.h"

using namespace std;

void ingresa_recursivo(NodoArbolBinarioBusqueda *nodo, ElementoArbolBinarioBusqueda &elem) {

    if (nodo == nullptr) {
        return;
    }
    if (nodo->elemento.numero==elem.numero) {
        nodo->elemento.cantidad+=elem.cantidad;
        elem.numero=0;
    }else {
        if (nodo->elemento.numero<elem.numero) {
            ingresa_recursivo(nodo->derecha, elem);
            if (elem.numero!=0) {
                plantarNodoArbolBinario(nodo->derecha,nullptr,elem,nullptr);
                elem.numero=0;
            }
        }else {
            ingresa_recursivo(nodo->izquierda, elem);
            if (elem.numero!=0) {
                plantarNodoArbolBinario(nodo->izquierda,nullptr,elem,nullptr);
                elem.numero=0;
            }
        }
    }


}
void ingresa_lote(NodoArbolBinarioBusqueda *raiz, ElementoArbolBinarioBusqueda elem) {
    ingresa_recursivo(raiz,elem);
}

NodoArbolBinarioBusqueda* buscarNodo(NodoArbolBinarioBusqueda* raiz, ElementoArbolBinarioBusqueda elem) {
    NodoArbolBinarioBusqueda* actual = raiz;
    while (actual != nullptr) {
        if (elem.numero == actual->elemento.numero) {
            return actual;
        } else if (elem.numero < actual->elemento.numero) {
            actual = actual->izquierda;
        } else {
            actual = actual->derecha;
        }
    }
    return nullptr;
}
void imprimeDescendenteIterativo(ArbolBinarioBusqueda arbol) {

    Pila pila;
    construir(pila);
    NodoArbolBinarioBusqueda *nodo=arbol.raiz;
    while (nodo != nullptr or !esPilaVacia(pila)) {
        while (nodo!=nullptr) {
            apilar(pila,{nodo->elemento});
            nodo=nodo->derecha;
        }
        ElementoArbolBinarioBusqueda elem=desapilar(pila).elem;
        // desapilar(pila);
        nodo=buscarNodo(arbol.raiz,elem);
        if (nodo!=nullptr) {
            cout << nodo->elemento.numero << "-"<<nodo->elemento.cantidad << " ";
            nodo=nodo->izquierda;
        }
    }
}
int main(int argc, char **argv) {

    ArbolBinarioBusqueda arbol;
    construir(arbol);

    insertar(arbol,{2018,100});
    insertar(arbol,{2011,150});
    insertar(arbol,{2010,175});
    insertar(arbol,{2017,25});
    insertar(arbol,{2022,50});
    insertar(arbol,{2019,125});
    insertar(arbol,{2023,200});
    insertar(arbol,{2020,75});

    // recorrerPreOrden(arbol);
    // cout << endl;
    ingresa_lote(arbol.raiz,{2013,100});
    // recorrerPreOrden(arbol);


    imprimeDescendenteIterativo(arbol);


    return 0;
}