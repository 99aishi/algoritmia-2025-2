#include <iostream>
#define N 8
#define M 2
using namespace std;

int encontrarPuntoRotacion(int arr[N][M], int ini, int fin) {
    if (ini == fin) return ini;
    int medio = (ini + fin) / 2;
    if (arr[medio][0]>arr[fin][0]) {
        return encontrarPuntoRotacion(arr, medio+1,fin);
    }else {
        return encontrarPuntoRotacion(arr, ini,medio);
    }
}
void merge(int arr[N][M], int ini, int medio, int fin) {
    int n = fin - ini + 1;
    int temp[n][2];
    int p = ini, q = medio+1, j=0;

    while (p<=medio and q<=fin) {
        if (arr[p][0] <= arr[q][0]) {
            temp[j][0] = arr[p][0];
            temp[j][1] = arr[p][1];
            j++;
            p++;
        }else {
            temp[j][0] = arr[q][0];
            temp[j][1] = arr[q][1];
            j++;
            q++;
        }
    }
    while (p<=medio) {
        temp[j][0] = arr[p][0];
        temp[j][1] = arr[p][1];
        j++;
        p++;
    }
    while (q<=fin) {
        temp[j][0] = arr[q][0];
        temp[j][1] = arr[q][1];
        j++;
        q++;
    }

    for (int i = 0; i < n; i++) {
        arr[i+ini][0]= temp[i][0];
        arr[i+ini][1] = temp[i][1];
    }
}
void mergeSort(int arr[N][M], int ini, int fin) {
    if (ini == fin) return;

    int medio = (ini + fin) / 2;
    mergeSort(arr, ini, medio);
    mergeSort(arr, medio + 1, fin);
    merge(arr, ini, medio, fin);
}
int max (int a,int b) {
    return (a>b)?a:b;
}
int sumaCentroConsecutivo(int arr[N][M], int ini, int medio,int fin) {
    int sumaIzq=-99;
    int sumaDer=-99;
    int suma = 0;
    for (int i=medio; i>=ini; i--) {
        suma+=arr[i][1];
        if (suma>sumaIzq) {
            sumaIzq=suma;
        }
    }
    suma=0;
    for (int i=medio+1; i<=fin; i++) {
        sumaDer+=arr[i][1];
        if (suma>sumaDer) {
            sumaDer=suma;
        }
    }


    return max(max(sumaIzq, sumaDer), sumaDer + sumaIzq);
}
int sumaMaxConsecutiva(int arr[N][M], int ini, int fin) {

    if (ini==fin) return arr[ini][1];
    int medio = (ini + fin) / 2;
     int sumaIzq=sumaMaxConsecutiva(arr,ini,medio);
     int sumaDer=sumaMaxConsecutiva(arr,medio+1,fin);
     int sumaCentro=sumaCentroConsecutivo(arr, ini, medio, fin);


    return max(max(sumaIzq,sumaDer),sumaCentro);
}



int main() {
    int n = 8;
    int arr[8][2] =
        {{50,4},
        {60,-1},
        {70,3},
        {80,-2},
        {10,-4},
        {20,5},
        {30,1},
        {40,-2}};


    int pos = encontrarPuntoRotacion(arr,0,n-1); //logn
    cout << "Posición inicial original: "<< pos << endl;
    mergeSort(arr,0,n-1); // nlogn

    int max = sumaMaxConsecutiva(arr, 0, n-1); // nlogn
    cout << max;
    //nlogn + nlogn + logn = logn ;


    return 0;
}