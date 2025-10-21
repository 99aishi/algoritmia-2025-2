/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 10/17/2025, 7:45 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"


void hanoi(int n,Pila &desde,Pila &aux, Pila &hacia) {
    if (n==0) {
        // apilar(hacia,desapilar(desde));
        return;
    }
    hanoi(n-1,desde,hacia,aux);
    apilar(hacia,desapilar(desde));
    hanoi(n-1,aux,desde,hacia);
}
void Hanoi4(Pila &origen,Pila &aux1,Pila &aux2,Pila &destino,int n){
    if(n==0)return;
    if(n==1){
        apilar(destino,desapilar(origen));
        return;
    }
    int t=n/2;
    Hanoi4(origen,destino,aux2,aux1,t);
    // Hanoi3(origen,aux2,destino,n-t);
    Hanoi4(aux1,origen,aux2,destino,t);
}

void fusionarPilas(struct Pila& pilaA,struct Pila& pilaB,struct Pila& pilaC,struct Pila& auxiliar,int numPaquetesA) {
    struct ElementoPila ele,aux;
    int i;
    hanoi(numPaquetesA,pilaA,auxiliar,pilaC);
    while (!esPilaVacia(pilaB)) {
        i=0;
        ele=desapilar(pilaB);
        if (ele.numero<=cima(pilaC).numero) {
            apilar(pilaC,ele);
        }
        if (ele.numero>cima(pilaC).numero) {

            while (!esPilaVacia(pilaC) and ele.numero>cima(pilaC).numero) {
                aux=desapilar(pilaC);
                apilar(pilaB,aux);
                if (i>0) {
                    hanoi(i,auxiliar,pilaC,pilaB);
                }
                i++;
                hanoi(i,pilaB,pilaC,auxiliar);
            }
            apilar(pilaC,ele);
            hanoi(i,auxiliar,pilaB,pilaC);
        }
    }

}



int main(int argc, char **argv) {

    Pila pilaA, pilaB, pilaC,pilaAux;
    construir(pilaA);
    construir(pilaB);
    construir(pilaC);
    construir(pilaAux);
    apilar(pilaA,{20});
    apilar(pilaA,{15});
    apilar(pilaA,{5});
    apilar(pilaB,{18});
    apilar(pilaB,{12});
    apilar(pilaB,{10});
    apilar(pilaB,{2});
    imprimir(pilaA);
    fusionarPilas(pilaA,pilaB,pilaC,pilaAux,3);
    imprimir(pilaC);
    return 0;
}