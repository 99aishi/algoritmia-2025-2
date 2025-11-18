#include <algorithm>
#include <iostream>
#define N 6
using namespace std;
void merge(int *arr,int ini,int medio,int fin) {
    int size=fin-ini+1;
    int p=ini,q=medio+1,j=0;
    int *temp=new int[size];
    while (p<=medio && q<=fin) {
        if (arr[p]>=arr[q]) {
            temp[j++]=arr[p++];
        }else {
            temp[j++]=arr[q++];
        }
    }
    while (p<=medio) temp[j++]=arr[p++];
    while (q<=fin) temp[j++]=arr[q++];
    for (int i=0;i<size;i++) arr[i+ini]=temp[i];

    delete[] temp;
}
void merge_sort(int *arr,int ini,int fin) {
    if (ini==fin) return;
    int medio=(ini+fin)/2;

    merge_sort(arr,ini,medio);
    merge_sort(arr,medio+1,fin);
    merge(arr,ini,medio,fin);
}

int buscar_faltante(int *arr,int ini,int fin) {
    if (ini==fin) return ini;
    int medio=(ini+fin)/2;
    if (medio%2==0) {
        if (arr[medio]==arr[medio+1])
            return buscar_faltante(arr,medio+1,fin);
        return buscar_faltante(arr,ini,medio);
    }else {
        if (arr[medio]==arr[medio-1])
            return buscar_faltante(arr,medio+1,fin);
        return buscar_faltante(arr,ini,medio);
    }
}
//20226104 - CORDOVA FABRICIO
int main() {
    //las aves seran números del 1 al 7;
    int matriz[N][N]={
        {0,3,7,2,2,7},
        {5,0,3,1,5,3},
        {7,7,3,6,6,3},
        {7,4,0,7,2,4},
        {5,1,2,5,1,2},
        {6,0,7,4,7,4}
    };
    int arr[N]{};
    //n2logn
    for (int i = 0; i < N; i++) {//n

        merge_sort(matriz[i],0,N-1);//nlogn; ordenado de mayor a menor para que la variacion de indices
                                            //no exista debido a que sean menos aves,sino que sea debido a la falta de un par.

        int faltante=buscar_faltante(matriz[i],0,N-1);//logn
        if (faltante==N-1) {
            cout << "Sin faltante"<<endl;
        }else {
            cout << "Falta el ave:" << matriz[i][faltante]<<endl;
        }
        //nlogn + logn = nlogn
    }
    //n*nlogn= n^2logn




    return 0;
}