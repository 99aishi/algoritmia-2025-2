/*
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 9/24/2025, 8:48 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
//ALGORITMO CREADO POR DAVID ALLASI
//NO ENTIENDO PILAAAS

void calcularFreqTiemMax(int arrFreq[],int n) {
    int freqMax, tiempoMax;
    int tiempo=0,duracion,duracionMax=0,tiempoPila,freqPila;
    ElementoPila elemento;
    Pila pila;
    construir (pila);

    while (tiempo<n) {
        if (esPilaVacia(pila) or arrFreq[tiempo]>=arrFreq[cima(pila).numero]) {
            elemento.numero = tiempo;
            apilar(pila,elemento);
            tiempo++;
        }else {
            elemento=desapilar(pila);
            tiempoPila=elemento.numero;
            freqPila=arrFreq[tiempoPila];
            duracion=freqPila*(tiempo-tiempoPila);
            if (duracion>duracionMax) {
                duracionMax=duracion;
                freqMax=freqPila;
                tiempoMax=tiempo-tiempoPila;
            }
        }
    }
    cout << "Frecuencia Maxima: " << freqMax << endl;
    cout << "Tiempo Maximo: " << tiempoMax << endl;

}
//despues de entenderlo
void intento(int arr[],int n) {
    Pila pila;
    int t=0, t_pila,f_pila,f_max=0,duracion=0,dMax=0,t_max=0;
    construir(pila);
    while (t<n) {
        if (esPilaVacia(pila) or arr[t]>=arr[cima(pila).numero]) {
            apilar(pila,{t});
            t++;
        }else {
            t_pila=desapilar(pila).numero;
            f_pila=arr[t_pila];
            duracion=f_pila*(t-t_pila);
            if (duracion > dMax) {
                dMax=duracion;
                t_max=t-t_pila;
                f_max=f_pila;
            }
        }
    }
    cout << "Frecuencia Maxima: " << f_max << endl;
    cout << "Tiempo Maximo: " << t_max << endl;
}
int main(int argc, char **argv) {

    int arrFreq[11]={1,2,1,4,5,6,4,5,2,2,1};
    int n=11, freqMax,tiempoMax;
    // calcularFreqTiemMax(arrFreq,n);
    intento(arrFreq,n);


    return 0;
}