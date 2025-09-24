/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 9/18/2025, 11:31 PM
 */

#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void crearElemento(ElementoLista &elemento, int codigo, int cantidad, int prioridad) {
    elemento.cantidad = cantidad;
    elemento.codigo = codigo;
    elemento.prioridad = prioridad;
}
void mostrarLista(Lista &lista) {
    struct NodoLista *recorrido=lista.inicio;
    while (recorrido!=nullptr) {
        cout << recorrido->elemento.codigo << " " << recorrido->elemento.cantidad << " "<<recorrido->elemento.prioridad<<endl;
        recorrido=recorrido->siguiente;
    }
}
void reordenarLista(Lista &lista) {
    bool agrupar=false;
    struct NodoLista *actual=lista.inicio;
    struct NodoLista *posterior=nullptr;


    struct NodoLista *iniA=nullptr;
    struct NodoLista *finA=nullptr;

    struct NodoLista *grupoIni=nullptr;
    struct NodoLista *grupoFin=nullptr;
    struct NodoLista *ultimoGrupo=nullptr;

    struct NodoLista *soloIni=nullptr;
    struct NodoLista *soloFin=nullptr;
    int i=0;
    while (actual!=nullptr) {
        posterior=actual->siguiente;
        if(actual->elemento.prioridad==1) {
            if (iniA==nullptr) {
                iniA=actual;
                finA=actual;
            }else {
                finA->siguiente=actual;
                finA=actual;
            }
        }else {
            if (posterior !=nullptr){
                if (actual->elemento.prioridad==posterior->elemento.prioridad) {
                    if (grupoIni==nullptr) {
                        grupoIni=actual;
                        grupoFin=actual;
                    }else {
                        grupoFin->siguiente=actual;
                        grupoFin=actual;
                    }
                    agrupar=true;
                }else {
                    if (agrupar) {
                        grupoFin->siguiente=actual;
                        grupoFin=actual;
                        agrupar=false;
                    }else {
                        if (soloIni==nullptr) {
                            soloIni=actual;
                            soloFin=actual;
                        }else {
                            soloFin->siguiente=actual;
                            soloFin=actual;
                        }
                    }

                }
            }else {
                if (agrupar) {
                    grupoFin->siguiente=actual;
                    grupoFin=actual;
                    agrupar=false;
                }else {
                    if (soloIni==nullptr) {
                        soloIni=actual;
                        soloFin=actual;
                    }else {
                        soloFin->siguiente=actual;
                        soloFin=actual;
                    }
                }
            }
        }
        cout << actual->elemento.codigo << endl;
        actual=actual->siguiente;

    }

    finA->siguiente=grupoIni;
    grupoFin->siguiente=soloIni;
    soloFin->siguiente=nullptr;
    lista.inicio=iniA;

    mostrarLista(lista);



}


int main(int argc, char **argv) {
    Lista lista;
    construirLista(lista);
    ElementoLista uno,dos,tres,cuatro,cinco,seis,siete,ocho,nueve;
    crearElemento(uno,1,10,2);
    insertarFinal(lista,uno);
    crearElemento(dos,2,20,1);
    insertarFinal(lista,dos);
    crearElemento(tres,3,15,2);
    insertarFinal(lista,tres);
    crearElemento(cuatro,4,12,2);
    insertarFinal(lista,cuatro);
    crearElemento(cinco,5,5,3);
    insertarFinal(lista,cinco);
    crearElemento(seis,6,6,1);
    insertarFinal(lista,seis);
    crearElemento(siete,7,8,3);
    insertarFinal(lista,siete);
    crearElemento(ocho,8,4,3);
    insertarFinal(lista,ocho);
    crearElemento(nueve,9,2,3);
    insertarFinal(lista,nueve);

    //mostrarLista(lista);

    reordenarLista(lista);
















    return 0;
}