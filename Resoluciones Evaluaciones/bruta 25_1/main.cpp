
#include <iostream>
#include <cmath>
using namespace std;
#define MAX_TABLAS 6
#define MAX_DISCOS 3


void pasa_base(int *cromosoma,int base, int num, int N) {
    for (int i=0;i<N;i++) {
        cromosoma[i]=0;
    }
    int i=0;
    while (num>0) {
        cromosoma[i++]=num%base;
        num=num/base;
    }
}
int main() {

    int tablas[MAX_TABLAS]={150,100,80,50,120,10};
    int discos[MAX_DISCOS]={250,200,200};
    int solucion=0;
    int estados=3;
    int maximo=pow(3,MAX_TABLAS);
    int cromosoma[MAX_TABLAS];
    int menor_global=0;
    for (int i=0;i<maximo;i++) {
        pasa_base(cromosoma,estados,i,MAX_TABLAS);
        int acum1=0,acum2=0,acum3=0, discos_final[MAX_DISCOS];
        for (int j=0;j<MAX_TABLAS;j++) {
            if (cromosoma[j]==0) acum1+=tablas[j];
            if (cromosoma[j]==1) acum2+=tablas[j];
            if (cromosoma[j]==2) acum3+=tablas[j];
        }
        int menor_local=0, ml1,ml2,ml3;
        if (acum1<discos[0] and acum2<discos[1] and acum3<discos[2]
            and acum1>0 and acum2>0 and acum3>0) {
            ml1=discos[0]-acum1;
            ml2=discos[1]-acum2;
            ml3=discos[2]-acum3;
            if (ml1<=ml2 and ml1<=ml3) {
                menor_local=discos[0]-acum1;
            }else if (ml2<=ml3 and ml2<=ml1) {
                menor_local=discos[1]-acum2;
            }else {
                menor_local=discos[2]-acum3;
            }
            if (menor_local>menor_global) {
                menor_global=menor_local;
                // cout << menor_local<<endl;
                solucion=i;
                cout << menor_local<<" "<<solucion << endl;
                // if (menor_global==40) break;
                // break;
            }
        }

    }
    pasa_base(cromosoma,estados,solucion,MAX_TABLAS);
    //disco 1:
    cout << "Disco 1: ";
    for (int i=0;i<MAX_TABLAS;i++) {
        if (cromosoma[i]==0) cout << i+1<<" ";
    }
    cout << endl;
    cout << "Disco 2: ";
    for (int i=0;i<MAX_TABLAS;i++) {
        if (cromosoma[i]==1) cout << i+1<<" ";
    }
    cout << endl;
    cout << "Disco 3: ";
    for (int i=0;i<MAX_TABLAS;i++) {
        if (cromosoma[i]==2) cout << i+1<<" ";
    }
    cout << endl << "Esta solucion tiene una velocidad minima de "<< menor_global<<" IOPS"<<endl;;

    return 0;

}