//Fecha:  jueves 30 Octubre 2025 
//Autor: Ana Roncal

#include <iostream>

#include "BibliotecaArbolBinario/ArbolBinario.h"
#include "BibliotecaArbolBinario/funcionesArbolBinario.h"

using namespace std;

int main(int argc, char **argv) {

    struct ArbolBinario cumulo;
    construir(cumulo);
    int arregloDatos[]{3, 5, 7, 9, 8, 6, 2};
    int n = sizeof(arregloDatos) / sizeof(arregloDatos[0]);
    for (int i = 0; i < n; i++)
        insertarEnCumulo(cumulo, arregloDatos[i]);
    cout << endl << endl;
    cout << "Imprimir por niveles: " << endl;
    recorridoPorNivelCambioLinea(cumulo);



    eliminarMinimo(cumulo);
    recorridoPorNivelCambioLinea(cumulo);
    /* Coloque aquí la llamada a la función  --> eliminarMinimo(cumulo)
     * La función eliminarMinimo para que se corrija debe ser implementada
     * en el directorio BibliotecaArbolBinario dentro de funcionesArbolBinario.cpp
     * Llame a la función recorridoPorNivelCambioLinea(cumulo); para probar su desarrollo */



    return 0;
}
