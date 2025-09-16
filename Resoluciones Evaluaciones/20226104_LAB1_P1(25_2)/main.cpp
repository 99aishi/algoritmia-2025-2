#include <iostream>
#include <cmath>
using namespace std;
#define C 8
/*
 * FABRICIO CORDOVA RAMOS
 * 20226104
 */

void pasa_base(int num,int base, int combinacion[],int MAX) {
    for (int i=0;i<MAX;i++) {
        combinacion[i]=0;
    }
    int i=0;
    while (num>0) {
        combinacion[i++]=num%base;
        num/=base;
    }
}
int main() {
    int P, B, F;
    cout << "Ingrese P:";
    cin >> P;
    cout << "Ingrese B:";
    cin >> B;
    cout << "Ingrese F:";
    cin >> F;



    int matriz[C][3]={
        {35000,80,1},
        {24000,60,3},
        {30000,70,2},
        {27000,48,1},
        {10000,20,1},
        {7000,35,2},
        {6000,10,1},
        {40000,40,3}
    };
    int estados=2;
    int combinacion[C];
    int maximo=pow(estados,C);
    int solucionado=false;

    for (int i=0;i<maximo;i++) {
        pasa_base(i,estados,combinacion,C);
        int costo_acumulado=0, beneficio_acumulado=0,falsos_acumulado=0,
        contador=0;
        for (int j=0;j<C;j++) {
            if (combinacion[j]==1) {
                costo_acumulado+=matriz[j][0];
                beneficio_acumulado+=matriz[j][1];
                falsos_acumulado+=matriz[j][2];
                contador++;
            }
        }
        if (costo_acumulado<=P and beneficio_acumulado>= B and
            falsos_acumulado<=F) {
            cout<< "Recursos: {";
            for (int j=0;j<C;j++) {
                if (combinacion[j]==1) {
                    cout <<j+1;
                    contador--;
                    if (contador>0) {
                        cout << ",";
                    }
                }
            }
            cout << "}, Costo total: "<<costo_acumulado<<", Beneficio: "<<beneficio_acumulado<<", Falsos Negativos: "
            <<falsos_acumulado<<endl;
            solucionado=true;
        }

    }
    if (!solucionado) {
        cout << "No se pueden seleccionar controles de seguridad que cumplan todas las restricciones."<<endl;
    }
    return 0;
}