#include<stdio.h>
#include<stdlib.h>

int main() {
    int suma_perfectos;
    int contador_perfectos = 0;
    int num_actual = 1;
    int i;

    do {
        num_actual++;
        suma_perfectos=0;
        

        for (i=1;i<num_actual;i++) {
            if (num_actual % i == 0){
                suma_perfectos += i;
            }
        }
        if (num_actual == suma_perfectos){
                printf("%d es numero perfecto.\n", num_actual);
                contador_perfectos++;
            }
    } while (contador_perfectos < 4);
    
    return 0;
}