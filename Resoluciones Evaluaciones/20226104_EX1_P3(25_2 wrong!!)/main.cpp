#include <iostream>
using namespace std;

#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"

void reordenar(Lista &lista) {
    NodoLista *recorrido=lista.inicio;
    NodoLista *ptrA=nullptr;
    NodoLista *ptrAfin=nullptr;
    NodoLista *ptrB=nullptr;
    NodoLista *ptrBfin=nullptr;
    NodoLista *ptrC=nullptr;
    NodoLista *ptrCfin=nullptr;
    while (recorrido) {
        if (recorrido->elemento.tipo == 'A') {
            if (ptrA==nullptr) {
                ptrA=recorrido;
                ptrAfin=recorrido;
            }else {
                ptrAfin->siguiente=recorrido;
                ptrAfin=recorrido;
            }
        }if (recorrido->elemento.tipo == 'B') {
            if (ptrB==nullptr) {
                ptrB=recorrido;
                ptrBfin=recorrido;
            }else {
                ptrBfin->siguiente=recorrido;
                ptrBfin=recorrido;
            }
        }if (recorrido->elemento.tipo == 'C') {
            if (ptrC==nullptr) {
                ptrC=recorrido;
                ptrCfin=recorrido;
            }else {
                ptrCfin->siguiente=recorrido;
                ptrCfin=recorrido;
            }
        }
        recorrido=recorrido->siguiente;
    }
    NodoLista *resultado=nullptr;
    NodoLista *resultadofin=nullptr;
    while (ptrA!=nullptr or ptrB!=nullptr or ptrC!=nullptr) {

        if (ptrA!=nullptr) {
            if (resultado==nullptr) {
                resultado=ptrA;
                resultadofin=ptrA;
            }else {
                resultadofin->siguiente=ptrA;
                resultadofin=ptrA;
            }
            if (ptrA==ptrAfin) ptrA=nullptr;
            else ptrA=ptrA->siguiente;
        }
        if (ptrB!=nullptr) {
            if (resultado==nullptr) {
                resultado=ptrB;
                resultadofin=ptrB;
            }else {
                resultadofin->siguiente=ptrB;
                resultadofin=ptrB;
            }
            if (ptrB==ptrBfin) ptrB=nullptr;
            else ptrB=ptrB->siguiente;
        }
        if (ptrC!=nullptr) {
            if (resultado==nullptr) {
                resultado=ptrC;
            }else {
                resultadofin->siguiente=ptrC;
                resultadofin=ptrC;
            }
            if (ptrC==ptrCfin) ptrC=nullptr;
            else    ptrC=ptrC->siguiente;
        }
    }
    resultadofin->siguiente=nullptr;
    lista.inicio=resultado;
}
//20226104
int main() {
    //[ (7,B) → (2,A) → (9,C) → (5,A) → (6,B) ]
    Lista lista;
    construir(lista);
    insertarAlFinal(lista,{7,'B'});
    insertarAlFinal(lista,{2,'A'});
    insertarAlFinal(lista,{9,'C'});
    insertarAlFinal(lista,{5,'A'});
    insertarAlFinal(lista,{6,'B'});
    insertarAlFinal(lista,{3,'C'});
    insertarAlFinal(lista,{1,'C'});
    imprimir(lista);
    reordenar(lista);
    imprimir(lista);
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}