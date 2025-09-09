#include <iostream>
using namespace std;
#define N 6
#define M 6

int contar(int matriz[N][M],int x, int y, int limX, int limY, int nivel) {
    int cont =0;
    if (limX>=N or limY >=M or x<0 or y<0 ) return cont;

    if (x==limX and y== limY) {
        cout << "Nivel: "<< nivel <<": "<< matriz[x][y] << endl;
        return matriz[x][y] + contar(matriz, x-1,y-1,limX+1,limY+1,nivel+1);
    }
    for (int i=x;i<limX;i++) cont+=matriz[i][y];
    for (int i=y;i<limY;i++) cont+=matriz[limX][i];
    for (int i=limX;i>x;i--) cont+=matriz[i][limY];
    for (int i=limY;i>y;i--) cont+=matriz[x][i];

    cout << nivel <<": "<< cont << endl;
    return cont+contar(matriz,x-1,y-1,limX+1,limY+1,nivel+1);
}
int main(int argc, char** argv) {

    int matriz[6][6]={
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0}
    };
    int x=4,y=4,limX=4,limY=4;

    int cant= contar(matriz,x,y,limX,limY,1);
    cout << "Total:"<<cant<<endl;
    return 0;
}
