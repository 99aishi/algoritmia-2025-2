#include <iostream>
using namespace std;
#define N 6
#define M 7
#define C 4
#include "funciones.h"
int main() {
    int matriz[N][M]={
        {0,1,1,1,1,1,1},
        {0,1,1,0,0,0,0},
        {0,1,0,0,0,0,0},
        {1,0,0,0,2,0,0},
        {1,1,0,0,0,0,0},
        {1,1,0,1,1,0,0}};
    int x=3, y=2, mov=6;
    resultadoBusquedas(matriz,x,y,N,M,mov,'R');
    return 0;
}