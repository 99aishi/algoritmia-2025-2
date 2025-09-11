/*
* File:   main.cpp
 * Author: cueva.r
 *
 * Created on 14 de abril de 2025, 11:11 AM
 */

#include <iostream>
#define N 4
#define M 5

using namespace std;

void repintar(int matriz[][M], int x, int y, int limX, int limY, int actual, int pintura) {

    if (x<0 or x >= limX or y<0 or y>=limY ) return;
    if (matriz[x][y]!=actual) return;
    if (matriz[x][y]==actual) matriz[x][y]=pintura;
    repintar(matriz,x+1,y,limX,limY,actual,pintura);
    repintar(matriz,x-1,y,limX,limY,actual,pintura);
    repintar(matriz,x,y+1,limX,limY,actual,pintura);
    repintar(matriz,x,y-1,limX,limY,actual,pintura);
}

void imprime_recursivo(int matriz[][M],int x, int  y, int limX, int limY) {

    if (y<limY) {
        cout << matriz[x][y]<< " ";
        imprime_recursivo(matriz,x,y+1,limX,limY);
    }else {
        cout << endl;
        if (x<limX-1)
            imprime_recursivo(matriz,x+1,0,limX,limY);
    }


}
int main() {
    int matriz[N][M]={{1,1,1,0,1},
                        {1,0,1,0,3},
                        {1,1,1,0,1},
                        {1,0,0,1,0}};
    int x=2,y=1;
    int cambio=2;
    imprime_recursivo(matriz,0,0,N,M);
    repintar(matriz,x,y,N,M,matriz[x][y],cambio);
    cout << "-------"<<endl;
    imprime_recursivo(matriz,0,0,N,M);
}