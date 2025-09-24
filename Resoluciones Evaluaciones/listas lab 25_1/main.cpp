/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 9/21/2025, 1:57 PM
 */

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;


void reordenar(Lista &lista) {
    NodoLista *recorrido=lista.inicio;
    NodoLista *parInicio=nullptr;
    NodoLista *parFinal=nullptr;
    NodoLista *imparInicio=nullptr;
    NodoLista *imparFinal=nullptr;

    while (recorrido !=nullptr) {
        if (recorrido->elemento.codigo%2==0) {
            if (parInicio==nullptr) {
                parInicio=recorrido;
                parFinal=recorrido;
            }else {
                parFinal->siguiente=recorrido;
                parFinal=recorrido;
            }
        }else {
            if (imparInicio==nullptr) {
                imparInicio=recorrido;
                imparFinal=recorrido;
            }else {
                imparFinal->siguiente=recorrido;
                imparFinal=recorrido;
            }
        }
        recorrido=recorrido->siguiente;
    }
    parFinal->siguiente=imparInicio;
    lista.inicio=parInicio;
}
int main(int argc, char **argv) {

    Lista lista;
    construir(lista);

    ElementoLista uno,dos,tres,cuatro;
    uno.codigo=17;
    dos.codigo=4;
    tres.codigo=12;
    cuatro.codigo=7;
    insertarAlFinal(lista, uno);
    insertarAlFinal(lista, dos);
    insertarAlFinal(lista, tres);
    insertarAlFinal(lista, cuatro);

    imprimir(lista);

    reordenar(lista);
    imprimir(lista);


    return 0;
}