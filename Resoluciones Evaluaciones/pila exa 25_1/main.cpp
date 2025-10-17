/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 10/16/2025, 5:38 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
void nuevoapilar(Pila &pila, int numero) {
    apilar(pila,{numero});
}

struct ElementoPila calcMin(Pila &pila,Pila &aux) { // pasa pila recursivo
    ElementoPila min={999999};
    if (esPilaVacia(pila)) {
        return min;
    }
    ElementoPila elem=desapilar(pila);
    min=calcMin(pila,aux);
    if (min.numero>elem.numero) {
        min=elem;
    }
    apilar(aux,elem);

    return min;
}
void minimo(Pila &pila,Pila &aux) {
    ElementoPila antiguo=calcMin(pila,aux);
    cout << antiguo.numero << endl;
    calcMin(aux,pila);
}
int main(int argc, char **argv) {
    Pila pila, aux;
    construir(pila);
    construir(aux);
    nuevoapilar(pila, 201809);
    nuevoapilar (pila, 202010);
    nuevoapilar (pila, 202109);
    nuevoapilar (pila, 201510);
    nuevoapilar (pila, 202409);
    cout << "PILA:";
    imprimir(pila);
    minimo(pila,aux);
    cout << "PILA:";
    imprimir(pila);
    cout << "AUX:";
    imprimir(aux);
    desapilar(pila);
    desapilar(pila);
    minimo(pila,aux);

    return 0;
}