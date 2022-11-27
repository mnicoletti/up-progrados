#include<stdio.h>
#include<stdlib.h>

#define CANT 3

typedef struct nodocola {
    int a;
    struct nodocola *next;
} nodo;

nodo* crear_nodo(int);
void apilar(nodo**, nodo*);
nodo desapilar(nodo**);
void mostrar(nodo , int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int*, int);


int main() {
    int i, num, buscador, posmax, posmin, prim;
    int multres=0, promdivtot=0, contprom=0, promdiv=0, sumamul=0, max=0, cont=0, buscado = 0;
    int min = 999;
    nodo* p=NULL;

    for(i=0; i<CANT; i++) {
        printf("Ingrese un numero: \n");
        scanf("%d", &num);

        if(p == NULL) {
            prim = num;
        }
        apilar(&p, crear_nodo(num));
    }

    printf("Ingrese un numero a buscar: \n");
    scanf("%d", &buscador);

    while(*p!=NULL) {
        mostrar(desapilar(&p), &multres, &promdivtot, &contprom, &promdiv, &sumamul, &max, &posmax, &min, &posmin, &buscado, &buscador, &cont, &prim);
    }

    if(buscado == 0) {
        printf("No se encontró el numero %d\n", buscador);
    } else {
        printf("Se encontro %d veces el numero %d.\n", buscado, buscador);
    }

    printf("La cantidad de numeros multiplos de 3: %d\n", multres);
    printf("El promedio de los divisores de 4: %d\n", promdiv);
    printf("La sumatoria de multiplos de %d es: %d\n", prim, sumamul);
    printf("El numero maximo fue: %d y lo encontramos en la posicion con indice %d\n", max, posmax);
    printf("El numero minimo fue: %d y lo encontramos en la posicion con indice %d\n", min, posmin);


    return 0;
}

nodo* crear_nodo(int dato) {
    nodo* u;
    u = (nodo*)malloc(sizeof(nodo));
    u->a = dato;
    
    u->next = NULL;

    return u;
}

void apilar(nodo** p, nodo* u) {
    u->next = *p;
    *p = u;
}

nodo desapilar(nodo** p) {
    nodo* aux;
    nodo datos;

    datos=**p;
    aux=*p;

    *p=(*p)->next;
    free(aux);

    return datos;
}

void mostrar(nodo aux, int *multres, int *promdivtot, int *contprom, int *promdiv, int *sumamul, int *max, int *posmax, int *min, int *posmin, int *buscado, int *buscador, int *cont, int prim) {
    if(aux.a % 3 == 0) {
        multres++;
    }

    if(4 % aux.a == 0) {
        promdivtot += aux.a;
        contprom++;
    }

    if(aux.a % prim == 0) {
        sumamul++;
    }

    if(aux.a > *max) {
        *max = aux.a;
        posmax = cont;
    }

    if(aux.a < *min) {
        *min = aux.a;
        posmin = cont;
    }

    if(aux.a == *buscador) {
        buscado++;
    }

    promdiv = *promdivtot / *contprom;
    cont++;
}