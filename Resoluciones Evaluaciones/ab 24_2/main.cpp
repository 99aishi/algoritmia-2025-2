/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 11/14/2025, 4:16 PM
 */

#include <iostream>
#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"
using namespace std;

void recorrerPreOrder(NodoArbolBinario *nodo, char *arr,int pos) {

    if (nodo!=nullptr) {
        arr[pos]=nodo->elemento.letra;
        pos++;
        if (nodo->izquierda==nullptr and nodo->derecha==nullptr) {
            arr[pos]='\0';
            cout << arr << endl;
        }
        recorrerPreOrder(nodo->izquierda,arr,pos);
        recorrerPreOrder(nodo->derecha,arr,pos);
    }

}
void preOrder(ArbolBinario &arbol) {
    char arr[50]{};
    recorrerPreOrder(arbol.raiz, arr,0);
}


int main(int argc, char **argv) {

    ArbolBinario arbol,arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,arbol7,arbol8, arbol9
    , arbol10, arbol11, arbol12,arbol13,arbol14,arbol15;
    construir(arbol);
    ArbolBinario arbolvacio;
    construir(arbolvacio);

    plantarArbolBinario(arbol1,arbolvacio,{'N'},arbolvacio);
    plantarArbolBinario(arbol4,arbol1,{'E'},arbolvacio); // arbol 4 = E-N


    plantarArbolBinario(arbol2,arbolvacio,{'O'},arbolvacio);
    plantarArbolBinario(arbol5,arbol2,{'A'},arbolvacio);
    plantarArbolBinario(arbol7,arbol5,{'B'},arbolvacio);
    plantarArbolBinario(arbol8,arbol7,{'L'},arbolvacio);// AB8= LBAO
    plantarArbolBinario(arbol9,arbol4,{'I'},arbol8); // I - EN Y LBAO

    plantarArbolBinario(arbol3,arbolvacio,{'S'},arbolvacio); // arbol 3 es S;
    plantarArbolBinario(arbol6,arbolvacio,{'A'},arbolvacio);//arbol6 es A;

    plantarArbolBinario(arbol10,arbolvacio,{'O'},arbol3);// AB10 = OS
    plantarArbolBinario(arbol11,arbol6,{'N'},arbol10);// N - A Y OS

    plantarArbolBinario(arbol12,arbol11,{'E'},arbolvacio); //E - NA Y NOS

    plantarArbolBinario(arbol13,arbol6,{'R'},arbol10); //R A Y OS
    plantarArbolBinario(arbol14,arbolvacio,{'R'},arbol13);

    plantarArbolBinario(arbol15,arbol12,{'U'},arbol14);
    plantarArbolBinario(arbol,arbol9,{'B'},arbol15);


    preOrder(arbol);



    return 0;
}