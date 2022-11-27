#include<stdio.h>
#include<stdlib.h>

typedef struct listado {
    int num;
    struct listado *next;
} numero;

void crearLista(numero *nums);
void mostrarLista(numero *nums);
void crearListaMultiplos(numero *nums, numero *nuevoNums);
void sumarNodos();

int main() {
    return 0;
}

void crearLista(numero *nums) {
    printf("Ingrese un numero: \n");
    scanf("%d", &nums->num);

    if(nums->num == 1000) {
        nums->next = NULL;
    } else {
        nums->next = (numero*)malloc(sizeof(numero));
        crearLista(nums->next);
    }
}

void mostrarLista(numero *nums) {
    if(nums->next != NULL) {
        printf("Numero: \t%d\n", nums->num);
    }

    return;
}

void crearListaMultiplos(numero *nums, numero *nuevoNums) {
    while(nums->next != NULL) {
        if(nums->num % 3 == 0) {
            nuevoNums->num = nums->num;
            nuevoNums->next = (numero*)malloc(sizeof(numero));
            nuevoNums = nuevoNums->next;
        }
        nums=nums->next;
    }
    nuevoNums->next=NULL;
}

