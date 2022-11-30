
#include <stdio.h>   // printf_s
#include <stdlib.h>  // malloc y free
#include <stdbool.h> // Booleanos
#include <string.h>

#include "pila.h"

int lenght(void) {
  int contador = 0;
  if (superior == NULL)
    return contador;
  struct nodo *temporal = superior;
  while (temporal != NULL) {
    contador++;
    temporal = temporal->siguiente;
  }
  return contador;
}

bool vacia(void) { return superior == NULL; }

void mostrarUltimo() {
  if (superior == NULL)
    printf("Esta vacio");
  printf_s( superior->nombre);
}

// Operación push
void push(char *nombre) {
  printf_s("Agregando %s\n", nombre);
  // El que se pushá; reservamos memoria
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
  // Le ponemos el dato
  strcpy_s(nuevoNodo->nombre, malloc(sizeof(nombre)),nombre);
  // Y ahora el nuevo nodo es el superior, y su siguiente
  // es el que antes era superior
  nuevoNodo->siguiente = superior;
  superior = nuevoNodo;
}

void imprimir(void) {
  printf_s("Imprimiendo...\n");
  struct nodo *temporal = superior;
  while (temporal != NULL) {
    printf_s("%s\n", temporal->nombre);
    temporal = temporal->siguiente;
  }
}

// Operación pop, eliminar el de hasta arriba
void pop(void) {
  printf_s("Eliminando el último\n");
  if (superior != NULL) {
    // Para liberar la memoria más tarde debemos
    // tener la referencia al que vamos a eliminar
    struct nodo *temporal = superior;
    // Ahora superior es a lo que apuntaba su siguiente
    superior = superior->siguiente;

    // Liberar memoria que estaba ocupando el que eliminamos
    free(temporal);
  }
}