
#include <iostream>
#include "funciones.h"
using namespace std;
#define N 10


int main(int argc, char **argv) {

//PREGUNTA1
    int datos[]={1,6,3,4,5,6,3,7,5,4,3,1,7};
    int n=sizeof(datos)/sizeof(int);

    merge_sort(datos,0,n-1);
    for (int i=0;i<n;i++)
        cout<<datos[i]<<" ";
    cout<<endl;

    int pos=buscar(datos,0,n-1);
    cout<< datos[pos] << endl;

//PREGUNTA2
    int matriz[N][N]={
        {0, 0, 0, 3, 3, 7, 5, 5, 1, 1},
        {8, 8, 10, 9, 9, 5, 4, 4, 2, 0},
        {3, 5, 8, 9, 7, 6, 4, 2, 0, 0},
        {9, 7, 7, 4, 4, 4, 2, 0, 0, 0},
        {0, 2, 2, 3, 3, 4, 4, 5, 3, 3},
        {0, 0, 0, 0, 0, 0, 2, 3, 4, 5},
        {1, 2, 2, 3, 3, 4, 3, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 5, 5, 7},
        {6, 5, 5, 2, 2, 1, 0, 0, 0, 0},
        {3, 2, 2, 0, 0, 0, 0, 0, 0, 0}
    };

    int arreglito[N]{};
    int max=0,max_estratos=0;
    // CON ESTE FOR LA COMPLEJIDAD ES N2LOGN
    for (int i=0;i<N;i++) {
        int mayor_local=busca_mayor(matriz[i],0,N-1);//ESTO ES NLOGN
        if (mayor_local>max)
            max=mayor_local;
        int cantidad_estratos=N-1- contar_estratos(matriz[i],0,N-1);//ESTE ES LOGN
        if (cantidad_estratos>=max_estratos) {
            max_estratos=cantidad_estratos;
        }
        arreglito[i]=cantidad_estratos;
        //DENTRO DEL FOR ES NLOGN
    }
    //ACA EL MAIN YA ES N2LOGN
    cout <<"La máxima pureza de las muestras es: "<< max<<endl;
    cout << "Las muestras con mayor cantidad de niveles con minerales son: ";
    for (int i=0;i<N;i++) {
        if (arreglito[i]==max_estratos)
            cout << i+1 <<" ";
    }
    cout << endl;
    return 0;
}