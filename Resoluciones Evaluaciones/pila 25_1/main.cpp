/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 9/25/2025, 11:08 PM
 */

#include <iostream>
using namespace std;
#include "BibliotecaPila/Pila.h"
#include "BibliotecaPila/funcionesPila.h"
int main(int argc, char **argv) {
    int matriz[5][6]={
        {0,0,1,0,0,1},
        {0,0,0,0,0,0},
        {0,1,0,1,0,0},
        {0,1,0,0,1,0},
        {1,0,0,0,0,0}
    };

    Pila pila;
    construir(pila);
    int posactual=0, xpila,ypila;
    apilar(pila,{0,0,0});
    while (true) {
        xpila=cima(pila).x;
        ypila=cima(pila).y;
        if (xpila>=5 and ypila>=6) {
            break;
        }
        if (matriz[xpila][ypila]==1 or xpila>=5) {
            desapilar(pila);
            cout << "ERROR"<<endl;
        }else {
            if (matriz[xpila][ypila]==0) {
                matriz[xpila][ypila]=2;
                apilar(pila,{0,xpila+1,ypila});//siempre va a bajar
            }else {
                if (matriz[xpila][ypila]==2) {
                    if (matriz[xpila][ypila+1]!=1) {
                        apilar(pila,{0,xpila,ypila+1});
                    }else {
                        desapilar(pila);
                    }
                }
            }

        }
    }

    for (int i=0;i<5;i++) {
        for (int j=0;j<6;j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }






    return 0;
}