//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

void construir(struct Lista & listaTAD) {
    listaTAD.inicio = nullptr;
}

bool esListaVacia(const struct Lista & listaTAD) {
    return listaTAD.inicio == nullptr;
}

/*Inserta los elementos al inicio de la lista*/
void insertarAlInicio(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->siguiente = listaTAD.inicio;
    listaTAD.inicio = nuevo;
}

/*Inserta un elemento siempre al final de la lista*/
void insertarAlFinal(struct Lista & listaTAD, const struct ElementoLista & elemento) {

    struct NodoLista * ultimoNodoLista = obtenerUltimoNodo(listaTAD);
    struct NodoLista * nuevo;
    nuevo = new struct NodoLista;
    nuevo->elemento = elemento;
    nuevo->siguiente = nullptr;

    if (ultimoNodoLista == nullptr) /*Si la lista está vacía*/
        listaTAD.inicio = nuevo; /*se inserta en la cabeza de la lista*/
    else //La lista ya tiene NodoListas
        ultimoNodoLista->siguiente = nuevo;
}

/*Obtiene el último NodoLista de la lista*/
struct NodoLista * obtenerUltimoNodo(const struct Lista & listaTAD) {
    struct NodoLista * ultimo = nullptr;
    struct NodoLista* recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }
    return ultimo;
}

void insertarEnOrden(struct Lista & listaTAD, const struct ElementoLista & elemento) {

}

void eliminaNodo(struct Lista & listaTAD, const struct ElementoLista & elemento) {

}

void destruir(struct Lista & listaTAD) {
    /*recorrido apunta al inicio del tad*/
    struct NodoLista * recorrido = listaTAD.inicio;

    while (recorrido != nullptr) {
        /*NodoLista auxiliar que va servir para eliminar los NodoListas*/
        struct NodoLista * NodoListaAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete NodoListaAEliminar;
    }
    /*la lista queda vacia*/
    listaTAD.inicio = nullptr;

}

/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprimir(const struct Lista & listaTAD) {

    if (esListaVacia(listaTAD)) {
        cout << "La lista esta vacia no se puede mostrar" << endl;
    } else {
        struct NodoLista * recorrido = listaTAD.inicio;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca las comas despuÃ©s de la cabeza*/
            if ( not estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
            cout << recorrido->elemento.dorsal;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}

void imprimeRecursivo(const struct Lista & lista) {
    cout << "Imprime recursivo... " << endl;
    if (not esListaVacia(lista)) {
        recorreRecursivo(lista.inicio);
    }
    cout << endl;
}

void recorreRecursivo(struct NodoLista * recorrido) {


}

void busquedaRecursivo(const struct Lista & lista, int elemento) {
    cout << "Busqqueda recursivo... " << endl;
    if (not esListaVacia(lista)) {
        seEncuentraRecursivo(lista.inicio, elemento);
    }
    cout << endl;
}

void seEncuentraRecursivo(struct NodoLista * recorrido, int elemento) {


}


void invierteLista(struct Lista & lista) {
    struct NodoLista * anterior = nullptr;
    struct NodoLista * actual = lista.inicio;
    struct NodoLista * posterior = nullptr;

    while (actual != nullptr) {
        posterior = actual->siguiente; //almacena el siguiente nodo
        actual->siguiente = anterior; //invierte el enlace
        anterior = actual; //avanza el puntero anterior
        actual = posterior; // avanza el puntero actual
    }
    lista.inicio = anterior;
}

void invierteListaRecursivo(struct Lista & lista) {
    cout << "Invierte lista recursivo... " << endl;
    invierteLaListaRecursivo(lista.inicio);
}

void invierteLaListaRecursivo(struct NodoLista *& inicio) {
    if ((inicio == nullptr) or (inicio->siguiente == nullptr)) {
        return;
    }

    struct NodoLista * recorrido = inicio->siguiente;
    invierteLaListaRecursivo(recorrido); // Invierte el resto de la lista

    inicio->siguiente->siguiente = inicio; // Coloca el nodo actual al final del resto
    inicio->siguiente = nullptr; // El nuevo Ãºltimo nodo debe apuntar a nullptr

    inicio = recorrido; // Actualiza la nueva cabeza
}

/*Elimina repetidos cuando son consecutivos*/
void eliminaRepetidos(struct Lista & lista) {


}

void completarLista(struct Lista & lista) {


}

/*metodo que ordena intercambiando elementos, para datos simples funciona
 para estructuras lo mejor es usar los punteros*/
void bubbleSort(struct Lista & lista) {
}