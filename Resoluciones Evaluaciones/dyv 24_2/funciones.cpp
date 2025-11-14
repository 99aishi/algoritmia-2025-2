//
// Created by 999 on 11/13/2025.
//
#include <iostream>
#include "funciones.h"
using namespace std;

void merge(int *arr,int ini,int medio,int fin) {
    int n=fin-ini+1;
    int *temp=new int[n];
    int p=ini,q=medio+1,j=0;

    while (p<=medio and q<=fin) {
        if (arr[p]<=arr[q]) {
            temp[j++]=arr[p++];
        }else {
            temp[j++]=arr[q++];
        }
    }

    while (p<=medio)
        temp[j++]=arr[p++];
    while (q<=fin)
        temp[j++]=arr[q++];

    for (int i=0;i<n;i++)
        arr[i+ini]=temp[i];

    delete[] temp;


}
void merge_sort(int *arr,int ini,int fin) {

    if (ini==fin) return;
    int mid=(ini+fin)/2;
    merge_sort(arr,ini,mid);
    merge_sort(arr,mid+1,fin);
    merge(arr,ini,mid,fin);

}
int buscar(int *arr,int ini,int fin) {

    if (ini==fin) return ini;
    int medio=(ini+fin)/2;
    if (arr[medio]==arr[medio+1]) {
        if (medio%2==0) {
            if (arr[medio]==arr[medio-1])
                return buscar(arr,ini,medio-1);
            else
                return buscar(arr,medio+1,fin);
        }else {
            return buscar(arr,ini,medio);
        }
    }else {
        if (medio%2==0) {
            return buscar(arr,ini,medio-1);
        }else {
            return buscar(arr,medio+1,fin);
        }
    }
}

void merge2(int *matriz,int ini,int medio,int fin) {
    int size= fin-ini+1;
    int *temp=new int[size];
    int j=0,p=ini,q=medio+1;

    while (p<=medio and q<=fin) {
        if (matriz[p]<=matriz[q]) {
            temp[j++]=matriz[p++];
        }else {
            temp[j++]=matriz[q++];
        }
    }
    while (p<=medio) temp[j++]=matriz[p++];
    while (q<=fin) temp[j++]=matriz[q++];
    for (int i=0;i<size;i++)
        matriz[i+ini]=temp[i];
    delete[] temp;

}
void mergesort2(int *matriz,int ini,int fin) {
    if (ini==fin) return;
    int mid=(ini+fin)/2;
    mergesort2(matriz,ini,mid);
    mergesort2(matriz,mid+1,fin);
    merge2(matriz,ini,mid,fin);
}
int encuentra_mayor(int *arr,int ini,int fin) {
    if (ini==fin) return arr[ini];
    int medio=(ini+fin)/2;
    if (arr[medio]>=arr[medio-1]) {
        return encuentra_mayor(arr,medio+1,fin);
    }
}
int busca_mayor(int *arr,int ini,int fin) {

    mergesort2(arr,ini,fin);
    // for (int i=0;i<fin+1;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;
    return encuentra_mayor(arr,ini,fin);
}
int contar_estratos(int *arr,int ini,int fin) {

    if (ini==fin) return ini;
    int medio=(ini+fin)/2;

    if (arr[medio]!=0) {
        return contar_estratos(arr,ini,medio-1);
    }else {
        if (arr[medio]==arr[medio+1]) {
            return contar_estratos(arr,medio+1,fin);
        }
        return contar_estratos(arr,ini,medio);
    }
}