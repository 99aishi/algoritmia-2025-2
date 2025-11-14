#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
using namespace std;
int main() {

    Pila aux;
    construir(aux);
    Cola cola;
    construir(cola);

    int n=0, arr[7]={1, 2, 3, 5, 4};
    while (1) {
        if (n==7) break;
        encolar(cola,{arr[n]});
        n++;
    }

    bool cambio=true;
    while (!esColaVacia(cola)){
        ElementoCola elem1 = desencolar(cola);
        NodoCola * inicio=cola.inicio;
        if (esColaVacia(cola)) {
            if (!esPilaVacia(aux)) {
                if (cima(aux).numero>elem1.codigo) {
                    cout << "Si se puede encolar ordenado"<<endl;
                }else {
                    cout << "No se puede encolar ordenado"<<endl;
                }
            }else {
                cout << "Si se puede encolar ordenado"<<endl;
            }
            break;
        }
        if (esPilaVacia(aux)) {
            if (elem1.codigo>inicio->elemento.codigo) {
                apilar(aux,{elem1.codigo});
            }else {
                // cout << "Sale "<<elem1.codigo<<endl;
            }
            // apilar(aux,{elem2.codigo});
        }else {
            if (elem1.codigo>inicio->elemento.codigo) {
                if (cima(aux).numero>elem1.codigo) {
                    apilar(aux,{elem1.codigo});
                }else {
                    cout << "No se puede "<< endl;
                    break;
                }
                // cambio=true;
            }else {
                // if (cambio) {
                    if (elem1.codigo-cima(aux).numero==-1) {
                        desapilar(aux);
                    // }
                }
                // cout << "Sale "<<elem1.codigo<<endl;
            }
        }
    }

    // imprimir(aux);

}