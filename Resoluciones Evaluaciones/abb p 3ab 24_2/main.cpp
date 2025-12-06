/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 12/5/2025, 2:12 PM
 */

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"

using namespace std;
void encolarTodaDerecha(Cola &cola,NodoArbolBinarioBusqueda * nodo) {
    if (nodo==nullptr) return;

    while (nodo!=nullptr) {
        encolar(cola,{nodo->elemento});
        nodo=nodo->derecha;
    }


}
NodoArbolBinarioBusqueda *buscarNodoElemento(ElementoArbolBinarioBusqueda buscar, NodoArbolBinarioBusqueda *raiz) {
    if (raiz==nullptr) return nullptr;

    while (raiz!=nullptr) {
        if (raiz->elemento.numero<buscar.numero) {
            raiz=raiz->derecha;
        }else {
            if (raiz->elemento.numero>buscar.numero) {
                raiz=raiz->izquierda;
            }else {
                return raiz;
            }
        }
    }
    return nullptr;
}
void imprimirDiagonalAzul(ArbolBinarioBusqueda arbol) {
    Cola cola;
    construir(cola);

    encolarTodaDerecha(cola,arbol.raiz);
    // encolar(cola,{arbol.raiz->elemento});

    while (!esColaVacia(cola)) {
        ElementoArbolBinarioBusqueda elem= desencolar(cola).elem;
        cout << elem.codigo << "-"<<elem.numero<<" ";
        NodoArbolBinarioBusqueda *nodo=buscarNodoElemento(elem,arbol.raiz);
        if (nodo->izquierda!=nullptr) {
            encolar(cola,{nodo->izquierda->elemento});
            encolarTodaDerecha(cola,nodo->izquierda->derecha);
        }
    }
}
void apilar_derecha(Pila &pila,NodoArbolBinarioBusqueda *raiz) {
    if (raiz==nullptr) return;
    while (raiz!=nullptr) {
        apilar(pila,{raiz->elemento});
        raiz=raiz->derecha;
    }
}
void imprimirDiagonalNaranja(ArbolBinarioBusqueda arbol) {
    Cola cola;
    construir(cola);
    encolarTodaDerecha(cola,arbol.raiz);
    Pila pila1;
    construir(pila1);
    // apilar_derecha(pila1,arbol.raiz);
    // Pila pila2;
    // construir(pila2);
    while (!esColaVacia(cola)) {
        ElementoArbolBinarioBusqueda elem= desencolar(cola).elem;
        apilar(pila1,{elem});
        NodoArbolBinarioBusqueda *nodo=buscarNodoElemento(elem,arbol.raiz);
        if (nodo->izquierda!=nullptr) {
            encolar(cola,{nodo->izquierda->elemento});
            encolarTodaDerecha(cola,nodo->izquierda->derecha);
        }
    }
    while (!esPilaVacia(pila1)) {
        ElementoArbolBinarioBusqueda elem= desapilar(pila1).elem;
        NodoArbolBinarioBusqueda *nodo=buscarNodoElemento(elem,arbol.raiz);
        imprimirNodo(nodo);

    }
}

int main(int argc, char **argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,{100,0});
    insertar(arbol,{50,0});
    insertar(arbol,{150,0});
    insertar(arbol,{25,0});
    insertar(arbol,{75,0});
    insertar(arbol,{40,0});
    insertar(arbol,{125,1});
    insertar(arbol,{175,0});
    insertar(arbol,{200,0});

    imprimirDiagonalAzul(arbol);
    cout << endl;
    imprimirDiagonalNaranja(arbol);


    return 0;
}