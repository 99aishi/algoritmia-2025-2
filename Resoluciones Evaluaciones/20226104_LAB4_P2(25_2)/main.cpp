#include <iostream>
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;
void intercambiar_recursivo(NodoArbolBinario *hijo,NodoArbolBinario *padre) {
    if (padre==nullptr)
        return;
    if (hijo->elemento.numero<padre->elemento.numero) {
        ElementoArbolBinario aux=hijo->elemento;
        hijo->elemento=padre->elemento;
        padre->elemento=aux;
    }
    intercambiar_recursivo(padre,padre->padre);
}
void plantar_arreglo_ordenado(ArbolBinario &arbol,int *arr,int size) {
    Cola cola;
    construir(cola);
    int i=0;
    if (esArbolVacio(arbol)) {
        plantarNodoArbolBinario(arbol.raiz,nullptr,{arr[0]},nullptr);
        arbol.raiz->padre=nullptr;
        i=1;
        encolar(cola,{arbol.raiz});
    }
    while (true) {
            NodoArbolBinario *nodo=desencolar(cola).nodo;
        if (nodo->izquierda==nullptr) {
            plantarNodoArbolBinario(nodo->izquierda,nullptr,{arr[i++]},nullptr);
            nodo->izquierda->padre=nodo;
            encolar(cola,{nodo->izquierda});
            NodoArbolBinario *izq=nodo->izquierda;
            // if (izq->elemento.numero<izq->padre->elemento.numero) { ; no hace falta la condición porque en la funcion intercambio tambien valida
            intercambiar_recursivo(izq,nodo);
            // }
        }

            if (i>size) break;
        if (nodo->derecha==nullptr) {
            plantarNodoArbolBinario(nodo->derecha,nullptr,{arr[i++]},nullptr);
            nodo->derecha->padre=nodo;
            encolar(cola,{nodo->derecha});
            NodoArbolBinario *der=nodo->derecha;
            // if (der->elemento.numero<der->padre->elemento.numero) { ; no hace falta la condición porque en la funcion intercambio tambien valida
            intercambiar_recursivo(der,nodo);
            // }
        }
            if (i>size) break;
    }
}
void imprimir_niveles(ArbolBinario &arbol) {
    Cola cola;
    construir(cola);
    if (!esArbolVacio(arbol)) {
        encolar(cola,{arbol.raiz});
        encolar(cola,{nullptr});
        while (!esColaVacia(cola)) {
            NodoArbolBinario *nodo= desencolar(cola).nodo;
            if (nodo==nullptr) {
                cout << endl;
                if (!esColaVacia(cola)) {
                    encolar(cola,{nullptr});
                }
            }else {
                cout << nodo->elemento.numero<<" ";
                if (nodo->izquierda!=nullptr) {
                    encolar(cola,{nodo->izquierda});
                }
                if (nodo->derecha!=nullptr) {
                    encolar(cola,{nodo->derecha});
                }
            }
        }
    }
}

//20226104 - CORDOVA FABRICIO
int main() {
    int arr[]={20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(arr)/sizeof(int);

    ArbolBinario arbol;
    construir(arbol);
    plantar_arreglo_ordenado(arbol,arr,size-1);
    // recorrerPreOrden(arbol);
    imprimir_niveles(arbol); // no pide el enunciado.
    return 0;
}