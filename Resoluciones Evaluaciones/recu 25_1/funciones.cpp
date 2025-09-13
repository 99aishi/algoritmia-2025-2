//
// Created by aishiteru on 9/09/2025.
//

#include "funciones.h"


void resultadoBusquedas(int matriz[6][7],int x,int y,int limX,int limY,int mov,char direccion) {

    //caso base

    if (mov<0) return;
    if (matriz[x][y]==2 or x < 0 or x==limX or y<0 or y == limY) {
        if (direccion=='R') direccion = 'L';
        else if (direccion=='L') direccion = 'R';
        else if (direccion=='U') direccion = 'D';
        else if (direccion=='D') direccion = 'U';
    }else {
        //hacia abajo
        for (int i=x;i<limX;i++) {
            if (matriz[i][y]==2) break;
            if (matriz[i][y]==1) {
                cout << "Oro: ("<< i <<","<< y<<")"<<endl;
                break;
            }
        }
        //hacia arriba
        for (int i=x;i>=0;i--) {
            if (matriz[i][y]==2) break;
            if (matriz[i][y]==1) {
                cout << "Oro: ("<< i<<","<< y<<")"<<endl;
                break;
            }
        }
        //hacia derecha
        for (int i=y;i<limY;i++) {
            if (matriz[i][y]==2) break;
            if (matriz[x][i]==1) {
                cout << "Oro: ("<< x<<","<< i<<")"<<endl;
                break;
            }
        }
        //hacia izquierda
        for (int i=y;i>=0;i--) {
            if (matriz[i][y]==2) break;
            if (matriz[x][i]==1) {
                cout << "Oro: ("<< x<<","<< i<<")"<<endl;
                matriz[x][i]=0;
                break;
            }
        }
    }
    if (direccion == 'R')
        resultadoBusquedas(matriz,x,y+1,limX,limY,mov-1,direccion);
    if (direccion == 'U')
        resultadoBusquedas(matriz,x-1,y,limX,limY,mov-1,direccion);
    if (direccion == 'D')
        resultadoBusquedas(matriz,x+1,y,limX,limY,mov-1,direccion);
    if (direccion == 'L')
        resultadoBusquedas(matriz,x,y-1,limX,limY,mov-1,direccion);
}