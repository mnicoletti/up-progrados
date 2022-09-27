#include<stdio.h>
#include<stdlib.h>

int main() {
    int a = 1;
    int b = 1;
    int suma_amigo;
    int suma_otro_amigo;
    int total_amigos = 0;
    int i;

    printf("Ingrese el primer numero: \n");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &b);
    
    while(a != 0 && b !=0 ) {
        suma_amigo = 0;
        suma_otro_amigo = 0;

        for (i=1;i<a;i++) {
            if (a % i == 0){
                suma_amigo += i;
            }
        }

        for (i=1;i<b;i++) {
            if (b % i == 0){
                suma_otro_amigo += i;
            }
        }

        if (suma_amigo == b && suma_otro_amigo == a) {
            total_amigos++;
        }

        printf("Ingrese el primer numero: \n");
        scanf("%d", &a);
        printf("Ingrese el segundo numero: \n");
        scanf("%d", &b);
    }

    printf("El total de pares de numeros amigos fue: %d", total_amigos);

    return 0;
}