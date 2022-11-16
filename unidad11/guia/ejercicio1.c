#include<stdio.h>
#include<stdlib.h>

#define CANT 10

typedef struct nodoentero {
    int a;
    struct nodoentero *next;
} entero;

entero* create_next(int);
void stack(entero**, entero*);
entero pop(entero**);
entero pop_dos(entero*);
void operador(entero*, int);

int main() {
    int i, num, buscador, primero;
    entero* nodo=NULL;

    for(i=0; i<CANT; i++) {
        printf("Ingrese un numero: \n");
        scanf("%d", &num);
        if (nodo == NULL) {
            primero = num;
        }
        printf("Estoy en crear un nodo\n");
        stack(&nodo, create_next(num));
    }

    operador(&nodo, primero);
    // End
    return 0;
}

entero* create_next(int dato) {
    printf("Entre a crear el nodo con create_next.\n");
    entero* u;
    u = (entero*)malloc(sizeof(entero));
    u->a = dato;
    u->next = NULL;

    return u;
}

void stack(entero** p, entero* u) {
    printf("Entre a hacer el stack del nodo.\n");
    u->next = *p;
    *p = u;
}

entero pop(entero** p) {
    printf("Entre a hacer un pop.\n");
    entero* aux;
    entero datos;

    printf("Asigno datos = **p\n");
    datos = **p;
    printf("Asigno aux = *p\n");
    aux = &p;

    printf("Asigno *p=(*p)->next\n");
    *p=(*p)->next;
    printf("Hago un free de aux.\n");
    free(aux);

    return datos;
}

void operador(entero* p, int primero) {
    printf("Ya estoy operando.\n");
    int mul_tres, div_cuatro, sum_primero, max, busqueda = 0;
    int min = 999;
    int num, buscador;

    printf("Ingrese un numero para busqueda: \n");
    scanf("%d", &buscador);

    while(p != NULL) {
        num = p->a;
        if (num % 3 == 0) {
            mul_tres++;
        }

        if (4 % num == 0) {
            div_cuatro++;
        }

        if (num % primero == 0) {
            sum_primero+=num;
        }

        if (num > max) {
            max = num;
        }

        if (num < min) {
            min = num;
        }

        if (num == buscador) {
            busqueda++;
        }

        *p = pop(&p);

        printf("Multiplos de 3: %d\nDivisores de 4: %d\nSumatoria de multiplos de %d: %d\nMaximo: %d\nMinimo: %d\nOcurrencias de %d: %d\n", mul_tres, div_cuatro, primero, sum_primero,max,min, buscador, busqueda);
    }
}