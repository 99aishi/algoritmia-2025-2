#include <iostream>
using namespace std;
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

void recorreNiveles(ArbolBinario &arbol) {
    Cola cola;
    construir(cola);
    encolar(cola,{arbol.raiz});
    while (!esColaVacia(cola)) {
        ElementoCola elem = desencolar(cola);
        cout << elem.nodo->elemento.numero<<" ";
        if (elem.nodo->izquierda!=nullptr) {
            encolar(cola,{elem.nodo->izquierda});
        }
        if (elem.nodo->derecha!=nullptr) {
            encolar(cola,{elem.nodo->derecha});
        }

    }
    cout << endl;
}
void plantarNiveles(ArbolBinario& arbol,int *arr) {
    plantarNodoArbolBinario(arbol.raiz,nullptr,{arr[0]},nullptr);
    Cola cola;
    construir(cola);
    encolar(cola,{{arbol.raiz}});
    int i=1;
    while (i<7){
        ElementoCola elem = desencolar(cola);
        if (elem.nodo->izquierda==nullptr) {
            plantarNodoArbolBinario(elem.nodo->izquierda,nullptr,{arr[i++]},nullptr);
            encolar(cola,{elem.nodo->izquierda});
        }
        if (elem.nodo->derecha==nullptr) {
            plantarNodoArbolBinario(elem.nodo->derecha,nullptr,{arr[i++]},nullptr);
            encolar(cola,{elem.nodo->derecha});
        }
    }
}
int main() {
    struct ArbolBinario arbol;
    struct ArbolBinario arbol1, arbol2, arbol3, arbol4, arbolVacio;
    struct ArbolBinario hijoIzquierdo, hijoDerecho;
    int arr[7]={100,50,150,25,80,120,200};
    /*               100
     *             /     \
     *           50      150
     *         /   \    /   \
     *       25    80  120   200
     */
    construir(arbol);
    construir(arbol1);

    construir(arbolVacio); // para plantar con nullptr

    //Una forma de crear un arbol es plantando desde el nivel mÃ¡s bajo pero no es la Ãºnica
    //los Ã¡rboles binarios tienen criterios para plantar los nodos
    plantarArbolBinario(arbol1, arbolVacio, {25}, arbolVacio);
    plantarArbolBinario(arbol2, arbolVacio, {80}, arbolVacio);
    plantarArbolBinario(arbol3, arbolVacio, {120}, arbolVacio);
    plantarArbolBinario(arbol4, arbolVacio, {200}, arbolVacio);
    plantarArbolBinario(hijoIzquierdo, arbol1, {50}, arbol2);
    plantarArbolBinario(hijoDerecho, arbol3, {150}, arbol4);
    plantarArbolBinario(arbol, hijoIzquierdo, {100}, hijoDerecho);

    cout << "Esta vacio el arbol: " << esArbolVacio(arbol) << endl;
    cout << "Recorrer en En orden: " << endl;
    //  25   50   80  100  120  150  200
    recorrerEnOrden(arbol);
    cout << endl;

    cout << "Recorrer en pre orden: " << endl;
    //   100   50   25   80  150  120  200
    recorrerPreOrden(arbol);
    cout << endl;

    cout << "Recorrer en Post orden: " << endl;
    //   25   80   50  120  200  150  100
    recorrerPostOrden(arbol);
    cout << endl;

    cout << "Numero de hojas: " << numeroHojas(arbol) << endl;
    cout << "Numero de nodos: " << numeroNodos(arbol) << endl;
    cout << "Altura arbol: " <<  altura(arbol)  << endl;
    cout<<"Es equilibrado: "<<esEquilibrado(arbol)<<endl;

    recorreNiveles(arbol);

    destruirArbolBinario(arbol);
    // cout << "Esta vacio el arbol: " << esArbolVacio(arbol) << endl;

    plantarNiveles(arbol,arr);

    recorreNiveles(arbol);

    return 0;
}