/*
A partir de lo visto en el modulo, se pide desarrollar un programa en C utilizando funciones que permita:

Crear una lista simplemente enlazada con el número de legajo, 
nombre y apellido, 
sector (codificado entre 1 y 3), antigüedad y sueldo. 
La carga de datos finaliza cuando el número de legajo es igual a cero. Se pide:

    Mostrar la lista con los datos cargados
    Calcular el promedio de sueldos del sector 2 y cuyos apellidos tengan mas de 4 caracteres.
    Generar una nueva lista con los empleados que pertenecen al sector que mas empleados tenga y 
    que además tengan al menos 3 años de antigüedad.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct empleados {
    char nombre[20], apellido[20];
    int legajo, antig, sector;
    float sueldo;
    struct empleados *next;
}listado;

void crearLista(listado *empleado);
void mostrarLista(listado *empleado);
float calcularPromedioSueldos(listado *empleado, int, float);
int contarEmpleados(int, int, listado *empleado);
void nuevoListado(int, listado *empleado, listado *nuevoEmpleado);

int main() {
    listado *primero;
    listado *nuevoPrimero;
    int contador=0, maximo=0, sector=0, i;
    float promedio=0;

    primero=(listado*)malloc(sizeof(listado));
    crearLista(primero);
    mostrarLista(primero);
    promedio = calcularPromedioSueldos(primero, 0, 0);
    printf("El promedio de sueldos para el sector 2 es: \t%.2f\n", promedio);
    
    for(i=0; i<3; i++) {
        contador = contarEmpleados(i+1, 0, primero);
        if (contador > maximo) {
            maximo = contador;
            sector = i+1;
        }
    }

    nuevoListado(sector, primero, nuevoPrimero);
    mostrarLista(nuevoPrimero);
    
    return 0;
}

void crearLista(listado *empleado) {
    printf("Ingrese un legajo: \n");
    scanf("%d", &empleado->legajo);

    if (empleado->legajo == 0) {
        empleado->next = NULL;
    } else {
        printf("Ingrese el nombre: \n");
        scanf("%s", empleado->nombre);
        printf("Ingrese el apellido: \n");
        scanf("%s", empleado->apellido);
        printf("Ingrese su sueldo: \n");
        scanf("%f", &empleado->sueldo);
        printf("Ingrese antiguedad: \n");
        scanf("%d", &empleado->antig);

        do {
            printf("Ingrese sector: \n");
            scanf("%d", &empleado->sector);
        } while( empleado->sector < 1 && empleado->sector > 3 );

        empleado->next = (listado*)malloc(sizeof(listado));
        crearLista(empleado->next);
    }

    return;
}

void mostrarLista(listado *empleado) {
    if (empleado->next != NULL ) {
        printf("Legajo: \t%d", empleado->legajo);
        printf("Nombre y Apellido: \t%s %s", empleado->nombre, empleado->apellido);
        printf("Sueldo: \t%.2f", empleado->sueldo);
        printf("Antiguedad: \t%d", empleado->antig);
        printf("Sector: \t%d", empleado->sector);
    }

    return;
}

float calcularPromedioSueldos(listado *empleado, int contador, float sumador) {
    if(empleado->next != NULL) {
        if (empleado->sector == 2 && strlen(empleado->apellido) > 4) {
            calcularPromedioSueldos(empleado->next, contador+1, sumador + empleado->sueldo);
        } else {
            calcularPromedioSueldos(empleado->next, contador, sumador);
        }
    }

    return sumador/contador;
}

int contarEmpleados(int sect, int contador, listado *empleado) {
    if (empleado->next != NULL) {
        if (empleado->sector == sect) {
            contarEmpleados(sect, contador+1, empleado->next);
        }
    }

    return contador;
}

void nuevoListado(int sect, listado *empleado, listado *nuevoEmpleado) {
    while (empleado->next != NULL) {
        if (empleado->antig > 3 && empleado->sector == sect) {
            nuevoEmpleado->legajo=empleado->legajo;
            strcpy(nuevoEmpleado->nombre,empleado->nombre);
            strcpy(nuevoEmpleado->apellido,empleado->apellido);
            nuevoEmpleado->antig=empleado->antig;
            nuevoEmpleado->sueldo=empleado->sueldo;
            nuevoEmpleado->sector=empleado->sector; // Esto podria simplemente insertar el sector que traje por parametro.
            nuevoEmpleado->next=(listado*)malloc(sizeof(listado));
            nuevoEmpleado=nuevoEmpleado->next;
        }
        empleado=empleado->next;
    }
    nuevoEmpleado->next=NULL;
}