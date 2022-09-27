/*Carga una matriz de nxn elementos enteros. Mostrarla. Calcular la suma de los elementos impares de la

diagonal principal en forma recursiva.*/
#include<stdio.h>
#include<stdlib.h>
#define N 10

void CargarMatriz(int [][N], int );
void MostrarMatriz(int [][N], int );
int SumaDiagonalImpar(int [][N], int);

int main() {
    int matriz[N][N], filas;

    printf("Ingrese el el valor N de la matriz: \n");
    scanf("%d", &filas);

    CargarMatriz(matriz, filas);
    MostrarMatriz(matriz, filas);
    printf("\nLa suma de los elementos impares de la diagonal es %d", SumaDiagonalImpar(matriz, filas-1));

    return 0;
}

void CargarMatriz(int mat[][N], int num_fila) {
    int i, j, num;
    for(i=0; i<num_fila; i++) {
        for(j=0; j<num_fila; j++) {
            printf("Inserte valor para [%d][%d]: \n", i+1, j+1);
            scanf("%d", &num);
            mat[i][j] = num;
        }
    }
}

void MostrarMatriz(int mat[][N], int num_fila) {
    int i, j;
    for(i=0; i<num_fila; i++) {
        printf("\n");
        for(j=0; j<num_fila; j++) {
            printf("%d\t", mat[i][j]);
        }
    }
}

int SumaDiagonalImpar(int mat[][N], int num_fila) {
    int sumador;
    if(num_fila < 0) {
        return 0;
    }
    if(mat[num_fila][num_fila] % 2 == 0) {
        sumador = 0;
    } else {
        sumador = mat[num_fila][num_fila];
    }

    return SumaDiagonalImpar(mat, num_fila-1) + sumador;
}