

#include <iostream>
using namespace std;
#define N 3
#define M 10
// int max(int a, int b) {
//     return (a > b) ? a : b;
// }
// int buscaCentro(int * arr,int ini,int medio, int fin) {
//     int may=0;
//
//     for (int i=medio;i>=ini;i--) {
//         if (arr[i]>may) {
//             may=arr[i];
//         }
//     }
//     for (int i=medio;i<=fin;i++) {
//         if (arr[i]>may) {
//             may=arr[i];
//         }
//     }
//     return may;
// }
int busca_mayor(int * arr,int ini,int fin) {

    if (ini == fin) {
        return arr[ini];
    }

    int medio = (ini + fin) / 2;

    int maxIzquierda = busca_mayor(arr, ini, medio);
    int maxDerecha = busca_mayor(arr, medio + 1, fin);

    if (maxIzquierda > maxDerecha) {
        return maxIzquierda;
    } else {
        return maxDerecha;
    }

}
int contar(int * arr,int ini,int fin,int buscar) {

}
int main(int argc, char **argv) {

//NO TERMINADO
    int matriz[N][M]={
        {15,12,10,17,15,18,18,18,12,16},
        {14,17,17,17,17,12,14,14,12,12},
        {16,18,20,20,15,18,16,18,18,16}
    };
    int mayor=0;
    for (int i = 0; i < N; i++) {
        int mayor_local=busca_mayor(matriz[i],0,M-1);
        if (mayor_local>mayor) {
            mayor=mayor_local;
        }

    }
    cout << mayor << endl;


    return 0;
}