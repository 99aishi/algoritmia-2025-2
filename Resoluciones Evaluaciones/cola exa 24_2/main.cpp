/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 10/16/2025, 6:33 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
void encolar_vip(Cola &cola,int i,int n) {
    struct NodoCola * nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = {i,n};
    if (cola.VIPfin==nullptr) {
        nuevo->siguiente=cola.inicio;
        cola.inicio=nuevo;
        cola.VIPfin=nuevo;
    }else {
        nuevo->siguiente=cola.VIPfin->siguiente;
        cola.VIPfin->siguiente=nuevo;
        cola.VIPfin=nuevo;
        if (cola.VIPfin->siguiente==nullptr) {
            cola.fin=nuevo;
        }
    }
}
void desencolar_novip(Cola &cola) {
    struct NodoCola * elem;
    elem = cola.VIPfin->siguiente;
    cola.VIPfin->siguiente=elem->siguiente;
    if (elem->siguiente==nullptr) {
        cola.fin=cola.VIPfin;
    }
    // cout << elem->elemento.codigo<<"-"<<elem->elemento.llegada << endl;
}
void desencolarVIP(Cola &cola) {
    NodoCola * elem;
    elem=cola.inicio;
    if (cola.VIPfin==cola.inicio) {
        cola.VIPfin=nullptr;
    }
    cola.inicio=elem->siguiente;
    // cout << elem->elemento.codigo << "-"<<elem->elemento.llegada<< endl;
}
int main(int argc, char **argv) {

    Cola cola;
    construir(cola);

    int n=1,max=180,i=1,fin_atencion=0,seleccion,vip_atendidos=0,novip_atendidos=0,vip_retirados=0;
    while (n<=max) {
        if (fin_atencion==n) {
            // cout << "Fin "<< fin_atencion << endl;
            if (seleccion==0) {
                desencolar_novip(cola);
                novip_atendidos++;
            }
            if (seleccion==1) {
                desencolarVIP(cola);
                vip_atendidos++;
            }
            if (!esColaVacia(cola)) {
                fin_atencion=n+20;
                if (cola.VIPfin==nullptr)
                    seleccion=0;
                else {
                    seleccion=1;
                    if ((fin_atencion-20)-cola.inicio->elemento.llegada>30) {
                        cout << "VIP NO ATENDIDO: ";
                        desencolarVIP(cola);
                        vip_retirados++;
                        if (cola.VIPfin==nullptr)
                            seleccion=0;
                    }
                }

            }

        }
        if (n%15==0 and n%2!=0) {
            if (esColaVacia(cola)) {
                encolar(cola,{i,n});
                fin_atencion=n+20;
                seleccion=0;
            }else {
                encolar(cola,{i,n});
            }
            i++;
        }

        if (n%30==0) {
            if (esColaVacia(cola)) {
                encolar_vip(cola,i,n);
                fin_atencion=n+20;
                seleccion=1;
            }else {
                encolar_vip(cola,i,n);
            }
            i++;
        }
        n++;
    }

    cout << "VIP ATENDIDOS : "<<vip_atendidos << endl;
    cout << "VIP NO ATENDIDOS : "<<vip_retirados << endl;

    return 0;
}