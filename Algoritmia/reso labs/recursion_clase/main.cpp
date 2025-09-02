#include <iostream>
#include "funciones.h"
using namespace std;
#define N 8
int main() {
    int n=5;
    int sumatoria = suma(n);
    cout<<sumatoria<<endl;
    int produto = multiplica(7,4);
    cout<<produto<<endl;
    int arreglo[N]= {9,8,7,6,10,1,4,3};
    int mayor = hallarMayorRecursivo(arreglo,N);
    cout << mayor << endl;
    return 0;
}