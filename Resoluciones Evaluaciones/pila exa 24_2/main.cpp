/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 10/16/2025, 8:39 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
int main(int argc, char **argv) {
    Pila pila;
    Pila aux;
    construir(pila);
    construir(aux);
    int i=0;
    int arr[7]={6,2,5,4,5,1,6};
    while (i<7) {
        if (esPilaVacia(pila)) {

        }
        apilar(pila,{arr[i]});
        i++;
    }


    return 0;
}