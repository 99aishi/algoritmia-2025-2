#include <iostream>
using namespace std;
#define N 6
#define M 11
/*
 * FABRICIO CORDOVA RAMOS
 * 20226104
 */
void especificar_galerias(int matriz[][M], int x, int y, int limX, int limY, int nivel, bool libre, bool tope) {
    if (x < 0 or y < 0 or y > limY or x > limX) return;

    if (matriz[x][y] == 0) {
        matriz[x][y] = nivel;
        if (matriz[x][y + 1] != 0 and y + 1 < limY) libre = false;
        else libre = true;
        if (libre) {
            if (matriz[x + 1][y] == 0 and x + 1 <= limX - nivel) {
                if (x == 0) tope = true;
                especificar_galerias(matriz, x + 1, y, limX, limY, nivel, libre, tope);
            } else {
                especificar_galerias(matriz, x, y + 1, limX, limY, nivel, libre, tope);
                if (y == limY - 1) {
                    if (tope)
                        return;
                    especificar_galerias(matriz, x - 1, 0, limX, limY, nivel + 1, true, tope);
                }
            }
        } else {
            especificar_galerias(matriz, x - 1, y, limX, limY, nivel, libre, tope);
        }
    }
}

int main() {
    int matriz[N][M] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    especificar_galerias(matriz,N - 1, 0,N,M, 1, true, false);
    // libre = se puede seguir a la derecha, tope = se modifico en la ultima fila y ya no continua despues del final de ese recorrido
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
