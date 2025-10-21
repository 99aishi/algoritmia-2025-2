// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
#include <iostream>
#include <cmath>
using namespace std;
void cargar_combinacion(int n,int combinacion[],int base, int size) {
    for (int i=0;i<size;i++)
        combinacion[i]=0;
    int i=0;
    while (n>0) {
        combinacion[i]=n%base;
        n=n/base;
        i++;
    }
}
//20226104 Cordova
int main() {
    int matriz[][4]={
        {1801, 2, 8, 1},
        {1802, 1, 8, 1},
        {1803, 1, 9, 1},
        {1804, 3, 9, 3},
        {1805, 1, 10, 1},
        {1806, 1, 11, 1},
        {1807, 3, 12, 1},
        {1808, 1, 14, 1},
        {1809, 2, 14, 2},
        {1810, 3, 14, 1},
        {1811, 2, 15, 1},
        {1812, 3, 16, 1},
        {1813, 2, 16, 2}
    };
    int p1,p2,p3;//1010001001110
    cout << "Indique la cantidad de alertas por prioridad : "<<endl;
    cout << "P1 : "; cin>>p1;
    cout << "P2 : " ; cin>>p2;
    cout << "P3 : " ; cin>>p3;
    int  size=13, base=2;
    int max = pow(base,size);
    // cout << pow(2,2)+pow(2,5)+pow(2,7)+pow(2,11)+1 <<endl;
    for (int i=0;i<max;i++) {
        int combinacion[size];
        cargar_combinacion(i,combinacion,base,size);
        int jornada=8,fin_jornada=17,tiempo_acumulado=0,
        p1_acum=0,p2_acum=0,p3_acum=0;
        bool encontro=true, post_almuerzo=false;


        for (int j=0;j<size;j++) {
            if (jornada==13) {
                jornada = 14;
                post_almuerzo=true;
            }
            if (combinacion[j]==1) {
                if (jornada<=matriz[j][2]) { // esta falto pq pueden haber horas que no haya atendido ni una.
                    jornada=matriz[j][2]; // si es menor a la hora de inicio se actualiza su jornada ya que no puede
                                            //atenderlo antes de la hora de inicio indicada.
                    if (jornada + matriz[j][3]>13 and !post_almuerzo) {
                        encontro=false;
                        break;
                    }
                    jornada+= matriz[j][3];
                    if (matriz[j][1]==1) {
                        if (jornada+1>13 and !post_almuerzo) {
                            encontro=false;
                            break;
                        }
                        jornada++;
                        p1_acum++;
                    }else {
                        if (matriz[j][1]==2) {
                            p2_acum++;
                        }
                        if (matriz[j][1]==3) {
                            p3_acum++;
                        }
                    }
                }else {
                    encontro=false;
                }

            }
        }
        if (p1_acum==p1 and p2_acum==p2 and p3_acum==p3 and jornada<=fin_jornada and encontro) {
            for (int j=0;j<size;j++) {
                if (combinacion[j]==1) {
                    cout << matriz[j][0]<< " P"<<matriz[j][1]<<"|";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
