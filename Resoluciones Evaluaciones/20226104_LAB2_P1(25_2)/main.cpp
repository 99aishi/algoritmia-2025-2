/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 10/17/2025, 7:29 PM
 */

#include <cstring>
#include <iostream>
#include <cstring>
using namespace std;
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

void ordenarLista(Lista &lista,char pos1[],char pos2[],char pos3[],char pos4[]) {

    NodoLista *pos1Ini=nullptr;
    NodoLista *pos2Ini=nullptr;
    NodoLista *pos3Ini=nullptr;
    NodoLista *pos4Ini=nullptr;
    NodoLista *pos1Final=nullptr;
    NodoLista *pos2Final=nullptr;
    NodoLista *pos3Final=nullptr;
    NodoLista *pos4Final=nullptr;
    NodoLista *recorrido=lista.inicio;

    while (recorrido) {
        if (strcmp(recorrido->elemento.posicion,pos1)==0) {
            if (pos1Ini==nullptr) {
                pos1Ini=recorrido;
                pos1Final=recorrido;
            }else {
                pos1Final->siguiente=recorrido;
                pos1Final=recorrido;
            }
        }
        if (strcmp(recorrido->elemento.posicion,pos2)==0) {
            if (pos2Ini==nullptr) {
                pos2Ini=recorrido;
                pos2Final=recorrido;
            }else {
                pos2Final->siguiente=recorrido;
                pos2Final=recorrido;
            }
        }
        if (strcmp(recorrido->elemento.posicion,pos3)==0) {
            if (pos3Ini==nullptr) {
                pos3Ini=recorrido;
                pos3Final=recorrido;
            }else {
                pos3Final->siguiente=recorrido;
                pos3Final=recorrido;
            }
        }
        if (strcmp(recorrido->elemento.posicion,pos4)==0) {
            if (pos4Ini==nullptr) {
                pos4Ini=recorrido;
                pos4Final=recorrido;
            }else {
                pos4Final->siguiente=recorrido;
                pos4Final=recorrido;
            }
        }
        recorrido=recorrido->siguiente;

    }

    pos1Final->siguiente=pos2Ini;
    pos2Final->siguiente=pos3Ini;
    pos3Final->siguiente=pos4Ini;
    pos4Final->siguiente=nullptr;
    lista.inicio=pos1Ini;


}
int main(int argc, char **argv) {
    char pos1[20],pos2[20],pos3[20],pos4[20];
    Lista lista;
    construir(lista);
    insertarAlFinal(lista,{7,"Martinez","Delantero"});
    insertarAlFinal(lista,{1,"Ramírez","Portero"});
    insertarAlFinal(lista,{5,"Pérez","Defensa"});
    insertarAlFinal(lista,{8,"Torres","Mediocampo"});
    insertarAlFinal(lista,{9,"López","Delantero"});
    insertarAlFinal(lista,{3,"Gómez","Defensa"});
    cin >> pos1 >> pos2 >> pos3 >> pos4;
    cout << pos1 << endl;
    cout << pos2 << endl;
    cout << pos3 << endl;
    cout << pos4 << endl;

    ordenarLista(lista,pos1,pos2,pos3,pos4);
    imprimir(lista);


    return 0;
}