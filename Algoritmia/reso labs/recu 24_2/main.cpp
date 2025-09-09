#include <iostream>
using namespace std;
#define N 5
#define M 5
#include "funciones.h"
int main() {
    int matriz[N][M]={
        {4,3,6,8,7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };
    int mayor=-1;
    imprimeRecursivo(matriz,0,0,N,M);
    buscarMayor(matriz,0,0,N,M,mayor);
    cout <<"El mayor numero de la matriz es:"<< mayor<<endl;
    imprimeModificadoRecursivo(matriz,0,0, N,M,mayor);




    return 0;
}