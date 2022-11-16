#include<stdio.h>
#include<stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar(treenode *hoja);

int main() {
    treenode* arbol=NULL;
    crear(&arbol);
    printf("Se muestra el arbol finalizado: \n\n\n");
    mostrar(arbol);

    printf("\nLa cantidad de hojas es: %d", cantidadHojas(arbol));
    return 0;
}

void crear(treenode **hoja) {
    int numero;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);

    while (numero != -1) {
        insertar(&(*hoja), numero);
        printf("Ingrese un numero: \n");
        scanf("%d", &numero);
    }
}

void insertar(treenode **hoja, int elem) {
    int numero=elem;
    
    if(elem == -1) {
        return;
    }

    if(*hoja==NULL) {
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    } else {
        if(numero>(*hoja)->dato) {
            insertar(&(*hoja)->der, elem);
        } else {
            insertar(&(*hoja)->izq, elem);
        }
    }

    return;
}

void mostrar(treenode *hoja) {
    if (hoja != NULL) {
        mostrar(hoja->izq);
        printf("%d\n", hoja->dato);
        mostrar(hoja->der);
    }

    return;
}

int cantidadHojas(treenode *hoja) {
    if(hoja == NULL) {
        return 0;
    }

    if(hoja->der == NULL && hoja->izq == NULL && hoja->dato % 2 != 0) {
        return 1;
    }

    return cantidadHojas(hoja->izq) + cantidadHojas(hoja->der);
}