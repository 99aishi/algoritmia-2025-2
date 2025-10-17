/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 10/16/2025, 4:58 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/Cola.h"

void agregarTemperatura(int temperatura, Cola &cola) {
    ElementoCola elemento;
    elemento.temperatura = temperatura;
    if (cola.inicio==nullptr) elemento.anterior=0;
    else
        elemento.anterior=cola.fin->elemento.temperatura;
    encolar(cola, elemento);
}
double calcularPromedio(Cola &cola,int n) {
    if (n==0) return cola.inicio->elemento.temperatura;
    if (n==1) return (cola.fin->elemento.temperatura+cola.fin->elemento.anterior)/2;
    else
        return (cola.inicio->elemento.temperatura+cola.fin->elemento.temperatura+cola.fin->elemento.anterior)/3;
}
int main(int argc, char **argv) {

    Cola cola;
    construir(cola);
    int n=0;
    int temperatura,k;
    cin>>k;
    while (true) {
        if (n>=k) {
            desencolar(cola);
        }
        cout << "Ingrese temperatura: ";
        cin >> temperatura;
        if (temperatura== -1) break;
        agregarTemperatura(temperatura,cola);
        imprimir(cola);
        cout << "Promedio:" << calcularPromedio(cola,n)<<endl;
        n++;
    }

    return 0;
}