//
// Created by aishiteru on 9/09/2025.
//

#ifndef LAB_24_2_FUNCIONES_H
#define LAB_24_2_FUNCIONES_H

#include <iostream>
using namespace std;

void imprimeRecursivo(int matriz[5][5], int x, int y, int limX, int limY);
void buscarMayor(int matriz[5][5], int x, int y, int limX, int limY, int &mayor);
void imprimeModificadoRecursivo(int matriz[5][5], int x, int y, int limX, int limY, int mayor);
#endif //LAB_24_2_FUNCIONES_H