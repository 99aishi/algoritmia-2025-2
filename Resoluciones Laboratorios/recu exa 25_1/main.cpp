#include <iostream>
using namespace std;

int contar(char matriz[][9], int x, int y, int limX,int limY, char objetivo, int dire) {
    int total=0;
    if (x<0 or x>=limX or y<0 or y>=limY) return 0;

    if (matriz[x][y]==objetivo)
        total++;

    if (dire ==1)
        total+= contar(matriz,x,y-1,limX,limY,objetivo,dire); // izq
    else if (dire == 2)
        total+= contar(matriz,x,y+1,limX,limY,objetivo,dire); // der
    else if (dire == 3)
        total+= contar(matriz,x-1,y,limX,limY,objetivo,dire);//arriba
    else if (dire == 4)
        total+= contar(matriz,x+1,y,limX,limY,objetivo,dire);//abajo
    else if (dire == 5)
        total+= contar(matriz,x-1,y+1,limX,limY,objetivo,dire);//primer cuadrante
    else if (dire == 6)
        total+= contar(matriz,x-1,y-1,limX,limY,objetivo,dire);//segundo
    else if (dire == 7)
        total+= contar(matriz,x+1,y-1,limX,limY,objetivo,dire);//tercer
    else if (dire == 8)
        total+= contar(matriz,x+1,y+1,limX,limY,objetivo,dire);//cuarto
    return total;
}

void eliminar(char matriz[][9], int x, int y, int limX,int limY, char objetivo, int dire) {
    if (x<0 or x>=limX or y<0 or y>=limY) return;

    if (matriz[x][y]==objetivo)
        matriz[x][y]='.';

    if (dire ==1)
        eliminar(matriz,x,y-1,limX,limY,objetivo,dire); // izq
    else if (dire == 2)
        eliminar(matriz,x,y+1,limX,limY,objetivo,dire); // der
    else if (dire == 3)
        eliminar(matriz,x-1,y,limX,limY,objetivo,dire);//arriba
    else if (dire == 4)
        eliminar(matriz,x+1,y,limX,limY,objetivo,dire);//abajo
    else if (dire == 5)
        eliminar(matriz,x-1,y+1,limX,limY,objetivo,dire);//primer cuadrante
    else if (dire == 6)
        eliminar(matriz,x-1,y-1,limX,limY,objetivo,dire);//segundo
    else if (dire == 7)
        eliminar(matriz,x+1,y-1,limX,limY,objetivo,dire);//tercer
    else if (dire == 8)
        eliminar(matriz,x+1,y+1,limX,limY,objetivo,dire);//cuarto
}

void modificar_matriz(char matriz[][9], int x, int y, int limX,int limY, char objetivo) {
    int maximo=0, direccion;
    for (int i=1;i<=8;i++) {
        int actual=contar(matriz,x,y,limX,limY,objetivo,i);
        if (actual>maximo){
            maximo=actual;
            direccion=i;
        }
    }
    eliminar(matriz,x,y,limX,limY,objetivo,direccion);
    for (int i=0;i<9;i++) {
        for (int j=0;j<9;j++) {
            cout <<matriz[i][j]<<" ";
        }
        cout << endl;
    }
}

int main() {
    char matriz[9][9]=
        {  //1   2   3   4   5   6   7   8   9
        {'.','.','.','.','.','.','.','.','.'},
        {'.','A','.','.','.','B','.','.','.'},
        {'.','.','V','A','.','.','.','.','.'},
        {'.','B','.','D','.','V','B','A','.'},
        {'.','.','B','B','.','.','.','.','.'},
        {'.','A','.','B','.','.','.','.','.'},
        {'.','.','.','.','.','B','A','.','.'},
        {'.','.','.','V','.','.','.','.','.'},
        {'.','.','.','B','.','.','.','.','A'},
    };
    char objetivo='B';

    modificar_matriz(matriz,3,3,9,9,objetivo);




    return 0;
}