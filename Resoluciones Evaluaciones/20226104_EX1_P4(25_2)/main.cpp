#include <iostream>
using namespace std;
#define N 4
#define M 5
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
int main() {
    int n=N,m=M;
    int matriz[N][M]={
        {1,1,1,0,0},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {1,1,0,0,0}};
    Pila pila;
    construir(pila);
    bool inicio=false;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (matriz[i][j]==1) {
                   if (!inicio) {
                       apilar(pila,)
                       inicio=true;
                   }else {

                   }
            }
        }
    }



    return 0;
}