#include <iostream>
#include <math.h>
using namespace std;

void pasa_base(int num,int base,int cromosoma[8],int N) {
    int i;
    // for (int i = 0; i < N; ++i) {
    //     cromosoma[i] = 0;
    // }
    i=0;
    while (num>0) {
        cromosoma[i++] = num%base;
        num/=base;
        //i++;
    }
}


int main() {
    int presupuestoMax=250, costo=0,N=8;
    int proyectos[8][5] {
        {80,150,0,0,0},
        {20,80,0,0,0},
        {100,300,1,2,0},
        {100,150,0,0,0},
        {50,80,0,0,0},
        {10,50,2,0,0},
        {50,120,6,0,0},
        {50,150,6,0,0}
    };

    int estados = 2 ;//dentro o fuera
    int maximo= pow(2,N);
    int ganancia_max=0;
    int solucion;
    for (int i = 0; i < maximo; ++i) {
        int costo_acumulativo=0, ganancia_acumulativo=0;
        bool predecesores=true;
        int cromosoma[N]{};
        pasa_base(i,estados,cromosoma,N);
        for (int j = 0; j < N; ++j) {
            if (cromosoma[j]!=0) {
                for (int k = 2; proyectos[j][k]!=0; ++k) {
                    if (cromosoma[proyectos[j][k]-1]!=1)
                        predecesores=false;
                }
                if (!predecesores) break;

                costo_acumulativo += proyectos[j][0];
                ganancia_acumulativo+=proyectos[j][1];
            }
            if (j==N-1) {
                if (ganancia_max<ganancia_acumulativo and presupuestoMax>=costo_acumulativo) {
                    ganancia_max=ganancia_acumulativo;
                    solucion = i;
                }
            }
        }

    }
    int cromo1[8]{};
    pasa_base(solucion,estados,cromo1,N);
    cout<<solucion<<": ";
    for (int i = 0; i < N; ++i) {
        //if (cromosoma[i])
        //   cout <<"Proyecto"<< i++ << endl;
        cout  <<cromo1[i] << " ";
    }
    cout <<endl<<ganancia_max<<endl;

}