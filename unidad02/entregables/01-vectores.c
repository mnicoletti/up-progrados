#include<stdio.h>
#include<stdlib.h>

int cargarArray(int []);
void mostrarArray(int [], int);
int eliminarPromedio(int [], int);
void insertarCeros(int [], int);
void ordenarArray(int [], int);
void desplazar(int [], int, int); // Esto me lo copie de una de las soluciones.
void obtenerPromedio(int [], int);
int obtenerMinimo(int [], int);


// Main
int main() {
    int arr[100], len=0;

    len = cargarArray(arr, len);
    
    if(len == 0) {
        printf("El vector no posee elementos pares.")
        return 0;
    }

    mostrarArray(arr, len);
    len = eliminarPromedio(arr, len);
    
    insertarCeros(arr, len);
    ordenarArray(arr, len);
    return 0;
}

// Funciones
int cargarArray(int arr[]) {
    int cargados = 0, num = 1, dim = 0;

    while(cargados < 100 && num != 0) {
        printf("Ingrese un numero entero: \n");
        scanf("%d", &num);

        if(num%2 == 0) {
            arr[len] = num;
            dim++;
        }
    }

    return dim;
}

void mostrarArray(int arr[], int len) {
    int i;

    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int obtenerPromedio(int arr[], int len) {
    int prom, i, sumador = 0;

    for(i = 0; i < len; i++) {
        sumador += arr[i];
    }
    prom = sumador / len;

    return prom;
}

int eliminarPromedio(int arr[], int len) {
    int prom, num, i = 0;

    prom = obternerPromedio(arr, len);

    printf("Ingrese un numero, se eliminaran todos los valores entre ese numero y el promedio: \n");
    scanf("%d", &num);

    while(i < len) {
        if(prom > num) {
            if(arr[i] > num && arr[i] < prom) {
                desplazar(arr, i, len);
                len--;
            } else {
                i++;
            }
        } else if(num > prom) {
            if(arr[i] > prom && arr[i] < num) {
                desplazar(arr, i, len);
                len--;
            } else {
                i++;
            }
        }
    }

    return len;
}

void desplazar(int arr[], int i, int len) {
    int j;

    for(j=i; j < len; j++) {
        arr[j] = arr[j + 1];
    }
}

int obtenerMinimo(int arr[], int len) {
    int min = 35000, i;

    for(i=0; i<len; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void insertarCeros(int arr[], int len) {
    int prom, min, i;

    prom = obtenerPromedio(arr, len);
    min = obtenerMinimo(arr, len);

    for(i=0; i<len; i++) {
        if(arr[i] > min && arr[i] < prom) {
            arr[i-1] = 0;
        }
    }

    mostrarArray(arr, len);
}

void ordenarArray(int arr[], int len) {
    int i, j, aux;

    for(i=0; i < len; i++) {
        for(j=i+1; j<len; j++) {
            if(arr[i] < arr[j]) {
                aux = arr[j];
                arr[j] = arr[i];
                arr[i] = aux;
            }
        }
    }

    mostrarArray(arr, len);
}