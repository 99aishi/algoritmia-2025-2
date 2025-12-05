/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 12/4/2025, 10:49 PM
 */

#include <iostream>
#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
using namespace std;

NodoArbolBinarioBusqueda *crearNodo(int num) {
    NodoArbolBinarioBusqueda *nodo= new NodoArbolBinarioBusqueda();
    nodo->izquierda=nullptr;
    nodo->derecha=nullptr;
    nodo->elemento.numero=num;
    return nodo;
}
NodoArbolBinarioBusqueda * funcion(int * arr,int ini, int fin) {

    if ( ini > fin ) return nullptr;
    int medio=(ini+fin)/2;

    NodoArbolBinarioBusqueda * aux=crearNodo(arr[medio]);
    aux->izquierda=funcion(arr,ini,medio-1);
    aux->derecha=funcion(arr,medio+1,fin);
    return aux;
}

int main(int argc, char **argv) {

    int arr[]={2,4,6,8,10,12,14};
    int n=sizeof(arr)/sizeof(int);

    ArbolBinarioBusqueda arbol;
    construir(arbol);
    arbol.raiz= funcion(arr,0,n-1);
    recorrerPreOrden(arbol);
    return 0;
}