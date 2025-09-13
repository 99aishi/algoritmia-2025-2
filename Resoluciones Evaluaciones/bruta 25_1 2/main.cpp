
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_RECURSOS 10

void pasa_base(int num,int base,int *combinacion,int N) {
    for (int i=0;i<N;i++) {
        combinacion[i]=0;
    }
    int i=0;
    while (num>0) {
        combinacion[i++]=num%base;
        num=num/base;
    }
}
int main() {

    int presupuesto=100;
    int min_seguridad=600;
    int recursos[MAX_RECURSOS][5]={{50,120,0,0,0},
                                {40,110,0,0,0},
                                {80,140,0,0,0},
                                {70,130,1,0,0},
                                {85,160,1,0,0},
                                {140,250,1,2,0},
                                {55,100,2,0,0},
                                {130,240,2,3,0},
                                {30,90,0,0,0},
                                {150,300,1,2,5}};
    int combinacion[MAX_RECURSOS];
    int estados=2;
    bool solucionado=false;
    int maximo=pow(2,MAX_RECURSOS);
    cout << "COMBINACIONES VALIDAS (COSTO ENTRE "<< (0.8)*presupuesto<<" y "<<presupuesto <<" y NIVEL DE SEGURIDAD >=" <<min_seguridad<< endl;
    //RESPUESTA
    for (int i=0; i<maximo;i++) {
        pasa_base(i,estados,combinacion,MAX_RECURSOS);
        int gasto_acumulado=0,seg_acumulado=0;
        bool valido1=true;
        for (int j=0; j<MAX_RECURSOS; j++) {
            if (combinacion[j]==1) {
                for (int k=2; k<5; k++) {
                    if (recursos[j][k]==0) {
                        break;
                    }else {
                        if (combinacion[recursos[j][k]-1]==0) {
                            valido1=false;
                            break;
                        }
                    }
                }
                if (valido1) {
                    gasto_acumulado+=recursos[j][0];
                    seg_acumulado+=recursos[j][1];
                }
            }
        }
        if (gasto_acumulado<=presupuesto and gasto_acumulado>=(0.8*presupuesto) and valido1 and seg_acumulado>=min_seguridad) {
            cout <<"Combinacion "<< i<<": ";;
            for (int j=0; j<MAX_RECURSOS; j++) {
                if (combinacion[j]==1) {
                    cout<<" R"<<j+1;
                }
            }
            cout <<" | Costo: "<<gasto_acumulado<<" miles | Nivel de Seguridad: "<<seg_acumulado<<endl;
            solucionado=true;
        }
    }
    if (!solucionado) {
        cout << "No se encontraron combinaciones que cumplan con lo solicitado."<<endl;
    }
    return 0;
}