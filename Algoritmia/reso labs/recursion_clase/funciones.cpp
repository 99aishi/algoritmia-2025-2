//
// Created by aishiteru on 26/08/2025.
//

#include <iostream>
#include "funciones.h"
using namespace std;


int suma(int n) {

    //caso base
    if (n == 1) return 1;

    return suma(n-1) + n;
}
int multiplica(int m,int n) {

    //caso base
    if (n == 1) return m;

    return multiplica(m,n-1) + m;
}
int hallarMayorRecursivo(int *arreglo,int cant) {
    int mayor;
    if (cant == 1 ) return arreglo[cant-1];
    else {
        return max(hallarMayorRecursivo(arreglo,cant-1),arreglo[cant-1]);
    }
}