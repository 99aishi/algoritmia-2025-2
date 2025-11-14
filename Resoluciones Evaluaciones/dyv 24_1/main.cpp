

#include <iostream>
#include "funciones.h"
using namespace std;



int main(int argc, char **argv) {

    //PREGUNTA1
    //2, -3, 4, -5, -7 == -12
    //2, 5, -6, 2, 3, -1, -5, 6 == -7
    //-4, 5, 6, -4, 3, -1, -5, 6 == -7
    int marcas[]={2, -3, 4, -5, -7};
    int size=sizeof(marcas)/sizeof(int);

    int acum=minSuma(marcas,0,size-1);
    cout << "ACUMULACIÓN NEGATIVA MÁS ALTA: "<< acum<<endl;


    //PREGUNTA 2 OPPENHEIMER
    //0,-1,0,-1,0,1,1,2,2,3,2,2,1,1 == 5 y 3
    //-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1 == 4 y 4
    int opp[]={-1,0,-1,0,1,1,2,2,3,3,4,3,3,2,2,1,1};
    int n=sizeof(opp)/sizeof(int), km=inicio_rad(opp,0,n-1);
    cout << "La radiación empieza a "<< km<<"km."<<endl;
    cout << "Potencia máxima "<<encuentra_mayor(opp,km,n-1)<<" megatones."<<endl;
    return 0;
}