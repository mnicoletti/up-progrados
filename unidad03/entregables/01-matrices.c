#include<stdio.h>
#include<stdlib.h>
#define N 10

void CargarMatriz(int [][N], int );
void MostrarMatriz(int [][N], int );
int MatrizSimetrica(int [][N], int );
int CalculoProducto(int [][N], int );
void GeneraTranspuesta(int [][N], int [][N], int);

int main() {
    int matriz[N][N], matriz_t[N][N], filas;
    int producto_simetrica;

    printf("Ingrese el el valor N de la matriz: \n");
    scanf("%d", &filas);

    CargarMatriz(matriz, filas);
    MostrarMatriz(matriz, filas);
    printf("\n");
    if(MatrizSimetrica(matriz, filas) == 0) {
        producto_simetrica = CalculoProducto(matriz, filas);
        printf("\nLa matriz es simetrica. El producto de su triangular inferior es: %d", producto_simetrica);
    } else {
        GeneraTranspuesta(matriz, matriz_t, filas);
        printf("# Matrices generadas:\n## Matriz original:\n");
        MostrarMatriz(matriz, filas);
        printf("\n## Matriz transpuesta:\n");
        MostrarMatriz(matriz_t, filas);
    }

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

int MatrizSimetrica(int mat[][N], int num_fila) {
    int es_simetrica = 0; // 0 = True; 1 = False;
    int i, j;

    for(i=0; i<num_fila; i++) {
        for(j=0; j<num_fila; j++) {
            if(j != i && mat[i][j] != mat[j][i]) {
                es_simetrica = 1;
            }
        }
    }

    return es_simetrica;
}

int CalculoProducto(int mat[][N], int num_fila) {
    int i, j, producto = 1;

    for(i=0; i<num_fila; i++) {
        for(j=0; j<num_fila; j++) {
            if(i > j) {
                producto = producto * mat[i][j];
            }
        }
    }

    return producto;
}

void GeneraTranspuesta(int mat[][N], int transpuesta[][N], int num_fila) {
    int i, j;

    for(i=0; i<num_fila; i++) {
        for(j=0; j<num_fila; j++) {
            transpuesta[i][j] = mat[j][i];
        }
    }
}