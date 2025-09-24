//
// Created by 999 on 9/21/2025.
//


#include <iostream>
#include <iomanip>
using namespace std;
#include "Lista.h"
#include "funcionesLista.h"

void construirLista(Lista & lista) {
    lista.inicio=nullptr;
}
bool esListaVacia(const Lista &lista) {
    return lista.inicio==nullptr;
}
void insertarInicio(Lista &lista, const struct ElementoLista &elemento) {
    struct NodoLista *nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento=elemento;
    nuevo->siguiente=lista.inicio;
    lista.inicio=nuevo;
}
void insertarFinal(Lista &lista, const struct ElementoLista &elemento) {
    struct NodoLista *ultimoNodoLista = obtenerUltimo(lista);
    struct NodoLista *nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento=elemento;
    nuevo->siguiente=nullptr;
    if (ultimoNodoLista==nullptr) {
        lista.inicio=nuevo;
    }else {
        ultimoNodoLista->siguiente=nuevo;
    }
}
struct NodoLista *obtenerUltimo(Lista &lista) {
    struct NodoLista *ultimo=nullptr;
    struct NodoLista *recorrido=lista.inicio;

    while (recorrido!=nullptr) {
        ultimo=recorrido;
        recorrido=recorrido->siguiente;
    }
    return ultimo;
}








