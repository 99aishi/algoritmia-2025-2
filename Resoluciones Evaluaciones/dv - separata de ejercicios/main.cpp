/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 11/4/2025, 10:29 AM
 */

#include <iostream>
using namespace std;

int cantidad_ceros(int arr[],int ini,int fin,int cont) {
    //cuando esta a la izquierda los ceros
    if (ini>fin) return cont;
    int medio=(ini+fin)/2;
    if (arr[medio]==0)
        return cantidad_ceros(arr,medio+1,fin,medio+1);
    else
        return cantidad_ceros(arr,ini,medio-1,cont);
}
int cantidad_ceros_derecha(int arr[],int ini,int fin) {
    //cuando esta a la derecha los ceros
    int cont = 0;
    if (ini>fin) return cont;
    int medio=(ini+fin)/2;
    if (arr[medio]==1)
        return cantidad_ceros_derecha(arr,medio+1,fin);
    return fin - medio + 1 + cantidad_ceros_derecha(arr,ini,medio-1);
}
int elemento_minimo(int arr[],int ini ,int fin) {
    if (ini==fin) return arr[ini];
    int centro=(ini+fin)/2;
    if (arr[centro]<arr[centro-1]) {
        return arr[centro];
    }else {
        if (arr[centro]>arr[fin]) {
            return elemento_minimo(arr,centro+1,fin);
        }
        return elemento_minimo(arr,ini,centro-1);
    }
}
int valor_maximo(int arr[],int ini ,int fin) {
    if (ini == fin) return arr[ini];
    int centro=(ini+fin)/2;

    if (arr[centro]>arr[centro+1]) {
        return valor_maximo(arr,ini,centro);
    }
    return valor_maximo(arr,centro+1,fin);
}
void merge(int arr[],int ini,int medio,int fin) {
    int size=fin-ini+1;
    int temp[size];
    int j=0,p=ini,q=medio+1;

    while (p<=medio && q<=fin) {
        if (arr[p]<arr[q]) {
            temp[j]=arr[p];
            p++;
        }else {
            temp[j]=arr[q];
            q++;
        }
        j++;
    }
    while (p<=medio) temp[j++]=arr[p++];
    while (q<=fin) temp[j++]=arr[q++];

    for (int i=0;i<size;i++)
        arr[i+ini]=temp[i];
}
void merge_sort(int arr[],int ini ,int fin) {

    if (ini==fin) return;
    int medio=(ini+fin)/2;
    merge_sort(arr,ini,medio);
    merge_sort(arr,medio+1,fin);
    merge(arr,ini,medio,fin);
}
int max(int a,int b) {
    return a>b?a:b;
}
int sumaCentroConsecutiva(int arr[],int ini ,int medio, int fin) {
    int suma=0;
    int sumaIzq=-99;
    int sumaDer=-99;
    for (int i=medio;i>=ini;i--) {
        suma += arr[i];
        if (suma>sumaIzq) sumaIzq=suma;
    }
    suma=0;
    for (int i=medio+1;i<=fin;i++) {
        suma += arr[i];
        if (suma>sumaDer) sumaDer=suma;
    }
    return max(max(sumaIzq, sumaDer), sumaDer + sumaIzq);
}

int sumaMaxConsecutiva(int arr[],int ini ,int fin) {
    if (ini==fin) return arr[ini];

    int medio=(ini+fin)/2;
    int izq=sumaMaxConsecutiva(arr,ini,medio);
    int der=sumaMaxConsecutiva(arr,medio+1,fin);
    int sumaCentro=sumaCentroConsecutiva(arr,ini,medio,fin);

    return max(max(izq,der),sumaCentro);



}
int main(int argc, char **argv) {

    int arr[]={0,0,0,0,1,1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout << cantidad_ceros(arr,0,n-1,0)<<endl;
    int arr2[]={1,1,1,1,1,1,0};
    n=sizeof(arr2)/sizeof(arr2[0]);
    cout << cantidad_ceros_derecha(arr2,0,n-1)<<endl;

    int arr3[]={5,6,7,8,1,2,3,4};
    n=sizeof(arr3)/sizeof(arr3[0]);
    cout << elemento_minimo(arr3,0,n-1)<<endl;

    int arr4[]={8, 10, 20, 80, 700, 4, 3, 2, 1};
    n=sizeof(arr4)/sizeof(arr4[0]);
    cout << valor_maximo(arr4,0,n-1)<<endl;

    int arr5[]={5,10,44,1,2,7,8,32,75};
    n=sizeof(arr5)/sizeof(arr5[0]);
    merge_sort(arr5,0,n-1);
    for(int i=0;i<n;i++) {
        cout << arr5[i]<<" ";
    }
    cout << endl;

    int arr6[]={-2, -5, 6, -2, -3, 1, 5, -6};
    n=sizeof(arr6)/sizeof(arr6[0]);
    cout << sumaMaxConsecutiva(arr6,0,n)<<endl;




    return 0;
}