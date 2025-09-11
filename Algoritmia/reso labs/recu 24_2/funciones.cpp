//
// Created by aishiteru on 9/09/2025.
//

#include "funciones.h"



void imprimeRecursivo(int matriz[5][5], int x, int y, int limX, int limY) {
    if (y<limY) {
        cout << matriz[x][y]<< " ";
        imprimeRecursivo(matriz,x,y+1,limX,limY);
    }else {
        cout<<endl;
        if (x<limX-1)
            imprimeRecursivo(matriz,x+1,0,limX,limY);
    }
}

void buscarMayor(int matriz[5][5], int x, int y, int limX, int limY, int &mayor) {
    if (y<limY) {
        if (matriz[x][y]>mayor) mayor=matriz[x][y];
        buscarMayor(matriz,x,y+1,limX,limY,mayor);
    }else {

        if (x<limX-1)
            buscarMayor(matriz,x+1,0,limX,limY,mayor);
    }
}

void imprimeModificadoRecursivo(int matriz[5][5], int x, int y, int limX, int limY, int mayor) {
    if (y<limY) {
        cout << mayor-matriz[x][y]<< " ";
        imprimeModificadoRecursivo(matriz,x,y+1,limX,limY,mayor);
    }else {
        cout<<endl;
        if (x<limX-1)
            imprimeModificadoRecursivo(matriz,x+1,0,limX,limY,mayor);
    }
}