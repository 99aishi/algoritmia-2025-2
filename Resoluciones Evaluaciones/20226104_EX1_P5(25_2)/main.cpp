#include <iostream>
#include <fstream>
#include <cstring>

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;
void nuevo_desencolar (Cola &cola,ofstream &rep) {
    NodoCola *nodo_BORRAR;
    ElementoCola elem;
    nodo_BORRAR=cola.inicio;
    elem=nodo_BORRAR->elemento;
    cola.inicio=cola.inicio->siguiente;

    rep << "Atendido "<< elem.codigo;
    if (cola.preferente!=nullptr) {
        if (nodo_BORRAR==cola.preferente) {
            cola.preferente=nullptr;
        }
        rep << " P1"<<endl;
    }else {
        rep << " P2"<<endl;
    }

}
void desencolar_por_cantidad(Cola &cola,int por_atender, ofstream &rep) {
    while (por_atender>0) {
        nuevo_desencolar(cola,rep);
        por_atender--;
    }
}

void encolar_preferente(Cola &cola,int codigo) {
    ElementoCola elem={codigo};
    NodoCola *nodo=new NodoCola;
    nodo->elemento=elem;
    nodo->siguiente=nullptr;
    if (esColaVacia(cola)) {
        cola.inicio=nodo;
        cola.fin=nodo;
        cola.preferente=nodo;
    }else {
        if (cola.preferente==nullptr) {
            nodo->siguiente=cola.inicio;
            cola.inicio=nodo;
            cola.preferente=nodo;
        }else {
            nodo->siguiente=cola.preferente->siguiente;
            cola.preferente=nodo;
            if (cola.preferente->siguiente==nullptr) {
                cola.fin=nodo;
            }
        }
    }
}
void encolar_regular(Cola &cola,int codigo) {
    ElementoCola elem={codigo};
    NodoCola *nodo=new NodoCola;
    nodo->elemento=elem;
    nodo->siguiente=nullptr;
    if (esColaVacia(cola)) {
        cola.inicio=nodo;
        cola.fin=nodo;
    }else {
        cola.fin->siguiente=nodo;
        cola.fin=nodo;
    }
}

int main() {
    Cola cola;
    construir(cola);


    ifstream texto("eventos.txt",ios::in);
    if (!texto) cout << "NO "<<endl;
    ofstream rep("salida.txt",ios::out);
    char instruccion[10], tipo[15];
    int id,por_atender=0;
    while (true) {
        if (texto.peek()=='l' or texto.peek()=='a')
        texto.getline(instruccion,9,' ');
        else texto.getline(instruccion,9,'\n');
        if (texto.eof()) break;
        if (strcmp(instruccion,"llegada")==0) {
            texto >> id>>ws;
            texto.getline(tipo,15,'\n');
            if (strcmp(tipo,"preferente")==0) {
                encolar_preferente(cola,id);
            }else {
                encolar_regular(cola,id);
            }
        }
        if (strcmp(instruccion,"atender")==0) {
            texto >> por_atender;
            texto.get();
            desencolar_por_cantidad(cola,por_atender,rep);
        }
        if (strcmp(instruccion,"imprimir")==0) {
            imprimir(cola,rep);
        }
    }
    return 0;
}
/*
* llegada 1001 regular
llegada 1002 preferente
atender 1
llegada 1004 regular
llegada 1005 preferente
imprimir
atender 3
imprimi
 */