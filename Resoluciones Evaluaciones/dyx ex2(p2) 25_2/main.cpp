/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 11/14/2025, 1:36 AM
 */

#include <iostream>
using namespace std;
int buscar_codigo(int arr[], int ini, int fin, int cod) {

    if (ini==fin) {
        if (arr[ini]==cod) return ini;
        return -1;
    }
    int medio = (ini+fin)/2;

    // if (arr[medio]==cod) return medio;

    if (arr[ini]<=arr[medio]) { // bien ordenado de izq a derecha (tdv no se ha llegado al punto de rotacion)
        if (cod>=arr[ini] and cod<=arr[medio]) {
            return buscar_codigo(arr, ini, medio, cod);
        }
        return buscar_codigo(arr, medio+1, fin, cod);
    }else {
        if (cod>arr[medio] and cod <= arr[fin]) {
            return buscar_codigo(arr, medio+1, fin, cod);
        }
        return buscar_codigo(arr, ini, medio-1, cod);
    }

}

int main(int argc, char **argv) {
    int arr[]={300, 350, 400, 450, 500, 550, 600, 650, 100, 145, 190, 235, 280};//n=12
    int n=sizeof(arr)/sizeof(int);
    int codigo;
    // cout << " Ingrese el codigo de alerta a buscar: ";
    // cin >>codigo;
    codigo=600;
    int pos=buscar_codigo(arr,0,n-1,codigo);
    cout << pos+1 << endl;

    return 0;
}