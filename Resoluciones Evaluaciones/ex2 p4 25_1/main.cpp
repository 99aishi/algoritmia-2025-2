/*
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 12/4/2025, 11:33 PM
 */

#include <algorithm>
#include <iostream>
using namespace std;


int merge(int *arr, int ini,int mid, int fin) {
    int n = fin - ini +1;
    int * temp = new int[n];
    int p =ini, q = mid+1,j=0;
    int count=0;
    while(p<=mid && q<=fin) {
        if (arr[p]<=arr[q]) temp[j++] = arr[p++];
        else {
            temp[j++] = arr[q++];
            count+=(mid - p + 1);
        }
    }
    while (p<=mid) temp[j++] = arr[p++];
    while (q<=fin) temp[j++] = arr[q++];

    for (int i=0; i<n; i++)
        arr[i+ini] = temp[i];

    delete[] temp;
    return count;
}


int mergeSort(int * arr,int ini, int fin) {
    int count=0;
    if (ini==fin) return count;
    int mid=(ini+fin)/2;
    count += mergeSort(arr,ini,mid);
    count += mergeSort(arr,mid+1,fin);
    count += merge(arr,ini,mid,fin);

    return count;
}
int main(int argc, char **argv) {
    int arr[]={10, 12, 14, 13,11, 18,17,16,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int countador=mergeSort(arr,0,n-1);
    cout<<countador-1;
    return 0;
}