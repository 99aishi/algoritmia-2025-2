/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 9/23/2025, 11:07 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

//SOLUCION HECHA POR EL PROFESOR DAVID ALLASI
void fusionarListas(Lista &lista1, Lista &lista2) {

    NodoLista *ultimo1=obtenerUltimoNodo(lista1), *ultimo2=obtenerUltimoNodo(lista2);
    if (ultimo1->elemento.hora<lista2.inicio->elemento.hora) {
        ultimo1->siguiente=lista2.inicio;
    }else {
        if (ultimo2->elemento.hora<lista1.inicio->elemento.hora) {
            ultimo2->siguiente=lista1.inicio;
            lista1.inicio=lista2.inicio;
        }else {
            NodoLista *inicio=nullptr;
            NodoLista *fin=nullptr;
            while (!esListaVacia(lista1) and !esListaVacia(lista2)) {
                if (lista1.inicio->elemento.hora<=lista2.inicio->elemento.hora) {
                    if (inicio==nullptr) {
                        inicio=lista1.inicio;
                        fin = lista1.inicio;
                    }else {
                        fin->siguiente=lista1.inicio;
                        fin=lista1.inicio;
                    }
                    lista1.inicio=lista1.inicio->siguiente;
                }else {
                    if (inicio==nullptr) {
                        inicio=lista2.inicio;
                        fin=lista2.inicio;
                    }else {
                        fin->siguiente=lista2.inicio;
                        fin=lista2.inicio;
                    }
                    lista2.inicio=lista2.inicio->siguiente;
                }
            }
            if (esListaVacia(lista2)) {
                fin->siguiente=lista1.inicio;
            }else {
                fin->siguiente=lista2.inicio;
            }
            lista1.inicio=inicio;
        }
    }
}
int main(int argc, char **argv) {
    Lista lunes,martes,miercoles,jueves,viernes;
    construir(lunes);
    insertarAlFinal(lunes,{8,6,1});
    insertarAlFinal(lunes,{10,14,1});
    insertarAlFinal(lunes,{12,1,1});
    construir(martes);
    insertarAlFinal(martes,{9,3,2});
    insertarAlFinal(martes,{11,8,2});
    construir(miercoles);
    insertarAlFinal(miercoles,{8,2,3});
    insertarAlFinal(miercoles,{9,5,3});
    insertarAlFinal(miercoles,{10,10,3});
    construir(jueves);
    insertarAlFinal(jueves,{14,13,4});
    insertarAlFinal(jueves,{15,9,4});
    insertarAlFinal(jueves,{16,11,4});
    construir(viernes);
    insertarAlFinal(viernes,{17,4,5});
    insertarAlFinal(viernes,{18,12,5});
    insertarAlFinal(viernes,{19,7,5});


    fusionarListas(lunes,martes);
    imprimir(lunes);




    return 0;
}