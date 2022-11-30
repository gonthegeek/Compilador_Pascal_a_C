#pragma once
#include <stdio.h>   // printf
#include <stdlib.h>  // malloc y free
#include <stdbool.h> // Booleanos
#include <string.h>


struct nodo {
   char nombre[100];
  struct nodo *siguiente;
} ;

struct nodo *superior = NULL;

void push(char *nombre);  // push
void pop(void); // pop
void imprimir(void);
int lenght(void); // El tamaño de la pila
bool vacia(void);  // Indica si la pila está vacía
void mostrarUltimo(void);

