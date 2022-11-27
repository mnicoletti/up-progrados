#include<stdio.h>
#include<stdlib.h>

typedef struct arbol {
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

int crear(treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar(treenode *hoja);

int main() {
    treenode* arbol=NULL;
    int raiz;
    raiz = crear(&arbol);
    printf("Se muestra el arbol finalizado: \n\n\n");
    mostrar(arbol);

    printf("\nLa cantidad de hojas es: %d", cantidadHojas(arbol));
    return 0;
}

void crear(treenode **hoja) {
    int numero, raiz;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);

    raiz = numero;

    while (numero != -1) {
        insertar(&(*hoja), numero);
        printf("Ingrese un numero: \n");
        scanf("%d", &numero);
    }

    return raiz;
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

int mayorDivRaiz(treenode *hoja, int raiz, int mayor) {
    if(hoja != NULL) {
        
    }

    return mayor;
}