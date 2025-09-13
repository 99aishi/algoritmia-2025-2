#include <iostream>
using namespace std;
int main() {
    char matriz[12][8]={
        {'C','E','N','Z','Y','X','A','U'},
        {'D','Y','X','A','B','A','Y','U'},
        {'A','Z','Y','A','X','B','C','U'},
        {'B','Z','Z','A','E','E','Y','A'},
        {'Y','Y','B','X','N','C','Z','Y'},
        {'U','U','Y','Y','B','N','C','Z'},
        {'Z','Y','A','A','U','Y','Y','E'},
        {'Y','U','E','D','Z','B','B','N'},
        {'Z','C','B','X','U','B','A','Z'},
        {'N','Z','B','C','Y','Y','A','Y'},
        {'X','A','E','Z','Z','A','U','Z'},
        {'A','C','Z','X','X','Y','Y','Z'}
    };
    char combi[3]{};
    cout << "Posibles exfiltraciones de datos (C,E,N):"<<endl;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 8; j++) {
            //horizontal hacia derecha
            bool hay_c=false,hay_e=false,hay_n=false;
            combi[0]=matriz[i][j];
            combi[1]=matriz[i][j+1];
            combi[2]=matriz[i][j+2];
            for (int k = 0; k < 3; k++) {
                if (combi[k]=='N' and !hay_n) {
                    hay_n=true;
                }
                if (combi[k]=='E' and !hay_e) {
                    hay_e=true;
                }
                if (combi[k]=='C' and !hay_c) {
                    hay_c=true;
                }
            }
            if (hay_n && hay_e && hay_c) {
                cout << i << ","<< j <<endl;
                cout << i << ","<< j+2 <<endl;
            }
            //vertical hacia abajo
            hay_c=false,hay_e=false,hay_n=false;
            combi[0]=matriz[i][j];
            combi[1]=matriz[i+1][j];
            combi[2]=matriz[i+2][j];
            for (int k = 0; k < 3; k++) {
                if (combi[k]=='N' and !hay_n) {
                    hay_n=true;
                }
                if (combi[k]=='E' and !hay_e) {
                    hay_e=true;
                }
                if (combi[k]=='C' and !hay_c) {
                    hay_c=true;
                }
            }
            if (hay_n && hay_e && hay_c) {
                cout << i << ","<< j <<endl;
                cout << i+2 << ","<< j <<endl;
            }
            //diagonal hacia la izquierda abajo
            hay_c=false,hay_e=false,hay_n=false;
            combi[0]=matriz[i][j];
            combi[1]=matriz[i+1][j-1];
            combi[2]=matriz[i+2][j-2];
            for (int k = 0; k < 3; k++) {
                if (combi[k]=='N' and !hay_n) {
                    hay_n=true;
                }
                if (combi[k]=='E' and !hay_e) {
                    hay_e=true;
                }
                if (combi[k]=='C' and !hay_c) {
                    hay_c=true;
                }
            }
            if (hay_n && hay_e && hay_c) {
                cout << i << ","<< j <<endl;
                cout << i+2<< ","<< j-2 <<endl;
            }
            //diagonal hacia la derecha abajo
            hay_c=false,hay_e=false,hay_n=false;
            combi[0]=matriz[i][j];
            combi[1]=matriz[i+1][j+1];
            combi[2]=matriz[i+2][j+2];
            for (int k = 0; k < 3; k++) {
                if (combi[k]=='N' and !hay_n) {
                    hay_n=true;
                }
                if (combi[k]=='E' and !hay_e) {
                    hay_e=true;
                }
                if (combi[k]=='C' and !hay_c) {
                    hay_c=true;
                }
            }
            if (hay_n && hay_e && hay_c) {
                cout << i << ","<< j <<endl;
                cout << i+2<< ","<< j+2 <<endl;
            }
        }
    }



    return 0;
}