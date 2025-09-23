#include <iostream>
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
using namespace std;

int main() {
    Pila pila;
    construir(pila);

    int n=5;
    char orden[5]={'S','S','S','B','S'};


    int i=0,nivel=2;

    while (i<n) {
        if (esPilaVacia(pila)) {
            ElementoPila elemento;
            elemento.numero=1;
            apilar(pila,elemento);
        }
        // else {
            if (orden[i]=='S') {
                while (!esPilaVacia(pila)) {
                    ElementoPila elemento_pila;
                    elemento_pila=desapilar(pila);
                    cout << elemento_pila.numero << " ";
                }
                apilar(pila,{nivel,0});
                nivel++;
            }else {
                apilar(pila,{nivel,0});
                nivel++;
            }
        // }
        i++;
    }
    while (!esPilaVacia(pila)) {
        ElementoPila elemento_pila;
        elemento_pila=desapilar(pila);
        cout << elemento_pila.numero << " ";
    }
    return 0;
}