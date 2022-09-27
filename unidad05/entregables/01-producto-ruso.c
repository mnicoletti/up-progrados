#include<stdio.h>
#include<stdlib.h>

int MultiplicadorRuso(int, int);

int main() {
    int A, B;

    printf("Ingrese el valor A (multiplicador): \n");
    scanf("%d", &A);
    printf("Ingrese el valor B (multiplicando): \n");
    scanf("%d", &B);

    printf("El resultado de multiplicar %d por %d es: %d", A, B, MultiplicadorRuso(A, B));
    return 0;
}

int MultiplicadorRuso(int plicador, int plicando) {
    if (plicador == 1)
        return plicando;

    if (plicador % 2 != 0) {
        return plicando + MultiplicadorRuso(plicador/2, plicando*2);
    } else {
        return MultiplicadorRuso(plicador/2, plicando*2);
    }
}