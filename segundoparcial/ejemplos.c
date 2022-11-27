#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void resultado (treenode *arbol, int raiz, int* maximo, int* cont, int* suma)
{
  if (arbol != NULL)
  {
    resultado (arbol->izq, raiz, maximo, cont, suma);
    //printf("%d ",arbol->dato);
    if (arbol->dato % raiz == 0 && arbol->dato > *maximo)
      *maximo = arbol->dato;
      
   if(arbol->dato % raiz == 0 && arbol->der == NULL && arbol->izq == NULL )
      *cont = *cont + 1;
   
    if (arbol->dato % 2 == 0 && ((arbol->der != NULL && arbol->izq == NULL) || (arbol->der == NULL && arbol->izq != NULL)))
      *suma = *suma + arbol->dato;
    
      resultado (arbol->der, raiz, maximo, cont, suma);
  }
  return;
}

void mostrarPreOrden(treenode * arbol)
{
  if (arbol != NULL)
  {
    printf("%d \t", arbol->dato);
    mostrarPreOrden(arbol->izq);
    mostrarPreOrden(arbol->der);
  }
}

void mostrarPostOrden(treenode * arbol)
{
  if (arbol != NULL)
  {
    mostrarPostOrden(arbol->izq);
    mostrarPostOrden(arbol->der);
    printf("%d \t", arbol->dato);
  }
}

void mostrarOrden(treenode * arbol)
{
  if (arbol != NULL)
  {
    mostrarOrden(arbol->izq);
    printf("%d \t", arbol->dato);
    mostrarOrden(arbol->der);
  }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }
    else
    {
      if (numero>(*hoja)->dato)
      {
          insertar (&(*hoja)->der,elem);
      }
      else
      {
          insertar (&(*hoja)->izq,elem);
      }
    }
  return;
}

void crear (treenode **hoja)
{
    int numero;
    printf ("ingrese numero: ");
    scanf ("%d",&numero);
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero: ");
        scanf ("%d",&numero);
    }
}

int main ()
{
  int cont = 0, suma = 0, maximo, raiz;
  treenode* arbol=NULL;

  crear (&arbol);
  if (arbol != NULL)
  { 
    printf ("\n****** Recorrido en Pre Orden ******\n");
    mostrarPreOrden(arbol);
    printf ("\n****** Recorrido en Post Orden ******\n");
    mostrarPostOrden(arbol);
    printf ("\n****** Recorrido en Orden ******\n");
    mostrarOrden(arbol);
    printf ("\n***************\n");  
    maximo = arbol->dato;
    raiz = arbol->dato;
    resultado (arbol, raiz, &maximo, &cont, &suma);
    printf("\nEl valor mÃ¡ximo mÃºltiplo de la raÃ­z: %d", maximo);
    printf("\nLa cantidad de nodos hojas mÃºltiplos de la raÃ­z: %d", cont);
    printf("\nLa sumatoria de aquellos nodos pares con un hijo.: %d", suma);
  }
  else 
    printf("El arbol esta vacio");
  return 0;
}