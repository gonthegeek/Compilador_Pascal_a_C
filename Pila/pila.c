#include <stdio.h>   // printf
#include <stdlib.h>  // malloc y free
#include <stdbool.h> // Booleanos

struct elementoPila{
    int numero;
    struct elementoPila *siguiente;
};

struct elementoPila *superior = NULL;


void agregar(int numero);  // push
void eliminarUltimo(void); // pop
void imprimir(void);
int tamanio(void); // El tamaño de la pila
bool vacia(void);  // Indica si la pila está vacía
int ultimo(void);

int tamanio(void) {
  int contador = 0;
  if (superior == NULL)
    return contador;
  struct siguiente *temporal = superior;
  while (temporal != NULL) {
    contador++;
    temporal = temporal->siguiente;
  }
  return contador;
}

bool vacia(void) { return superior == NULL; }

int ultimo() {
  if (superior == NULL)
    return -1;
  return superior->numero;
}

void agregar(int numero) {
  printf("Agregando %d\n", numero);
  // El que se agregará; reservamos memoria
  struct siguiente *nuevoElemento = malloc(sizeof(struct siguiente));
  // Le ponemos el dato
  nuevoElemento->numero = numero;
  // Y ahora el nuevo siguiente es el superior, y su siguiente
  // es el que antes era superior
  nuevoElemento->siguiente = superior;
  superior = nuevoElemento;
}

void imprimir(void) {
  printf("Imprimiendo...\n");
  struct siguiente *temporal = superior;
  while (temporal != NULL) {
    printf("%d\n", temporal->numero);
    temporal = temporal->siguiente;
  }
}

void eliminarUltimo(void) {
  printf("Eliminando el último\n");
  if (superior != NULL) {
    // Para liberar la memoria más tarde debemos
    // tener la referencia al que vamos a eliminar
    struct siguiente *temporal = superior;
    // Ahora superior es a lo que apuntaba su siguiente
    superior = superior->siguiente;

    // Liberar memoria que estaba ocupando el que eliminamos
    free(temporal);
  }
}