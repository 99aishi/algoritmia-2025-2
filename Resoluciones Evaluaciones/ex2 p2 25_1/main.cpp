/* 
 * File:   ${NAME}.${EXTENSION}
 * Author: ${user}
 *
 * Created on 12/4/2025, 11:33 PM
 */

#include <iostream>
using namespace std;
int funcion(int * arr,int ini, int fin,int  alerta) {

    if (ini==fin) {
        if (arr[ini]==alerta) {
            return ini;
        }
        return -1;
    }
    int medio=(ini+fin)/2;

    if (arr[ini]<=arr[medio]) {
        if (alerta>=arr[ini] and alerta<=arr[medio]) {
            return funcion(arr,ini,medio,alerta);
        }
        return funcion(arr,medio+1,fin,alerta);
    }else {
        if (alerta>arr[medio] and alerta<=arr[fin]) {
            return funcion(arr,medio+1,fin,alerta);
        }
        return funcion(arr,ini,medio-1,alerta);
    }



}
int main(int argc, char **argv) {
    int arr[]={300, 350, 400, 450, 500, 550, 600, 650, 100, 145, 190, 235, 280};
               //0   1     2   3    4    5    6    7     8   9    10   11   12
    int n=sizeof(arr)/sizeof(arr[0]);
    int alerta=100;

    int pos = funcion(arr, 0, n-1, alerta);
    cout << pos+1 << endl;

    return 0;
}