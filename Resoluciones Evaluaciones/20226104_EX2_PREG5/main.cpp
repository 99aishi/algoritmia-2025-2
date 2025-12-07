#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"

using namespace std;

void reordenar(Cola &cola, int k) {
    if (k==0) return;
    ElementoCola elem=desencolar(cola);
    reordenar(cola,k-1);
    encolar(cola,elem);
}
int main() {
    Cola cola;
    construir(cola);
    encolar(cola,{1});
    encolar(cola,{2});
    encolar(cola,{3});
    encolar(cola,{4});
    encolar(cola,{5});
    int k =3;
    int n = cola.longitud;
    reordenar(cola,k);
    imprimir(cola);
    for (int i = 0; i < n-k; i++) {
        ElementoCola elem= desencolar(cola);
        encolar(cola,elem);
    }
    imprimir(cola);

    return 0;
}