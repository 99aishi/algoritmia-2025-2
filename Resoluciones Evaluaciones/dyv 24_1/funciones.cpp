//
// Created by 999 on 11/14/2025.
//
#include "funciones.h"

int min(int a,int b) {
    return a<b?a:b;
}
int sumaCentro(int *arr,int ini,int medio, int fin) {
    int suma=0;
    int sumaIzq=100;
    int sumaDer=100;
    //{2, 5, -6, 2, 3, -1, -5, 6};
    for (int i=medio;i>=ini;i--) {
        suma+=arr[i];
        if (suma<sumaIzq) sumaIzq=suma;
    }
    suma=0;
    for (int i=medio+1;i<=fin;i++) {
        suma+=arr[i];
        if (suma<sumaDer) sumaDer=suma;
    }
    return min(min(sumaIzq,sumaDer),sumaIzq+sumaDer);
}
int minSuma(int * arr, int ini, int fin) {
    if (ini==fin) return arr[ini];
    int medio=(ini+fin)/2;
    int izq=minSuma(arr,ini,medio);
    int der=minSuma(arr,medio+1,fin);
    int centro=sumaCentro(arr,ini,medio,fin);

    return min(min(izq,der),centro);
}


int inicio_rad(int * arr, int ini, int fin) {
    if (ini==fin) return ini;
    int medio = (ini + fin) / 2;
    if (arr[medio] < 1) {
        if (arr[medio+1]<1) {
            return inicio_rad(arr,medio+1,fin);
        }
        return inicio_rad(arr,medio+1,fin);
    }
    return inicio_rad(arr,ini,medio-1);
}
int encuentra_mayor(int * arr, int ini, int fin) {

    if (ini==fin) return arr[ini];

    int medio = (ini + fin) / 2;
    if (arr[medio]>arr[medio+1]) {
        return encuentra_mayor(arr,ini,medio);
    }else {
        return encuentra_mayor(arr,medio+1,fin);
    }
}