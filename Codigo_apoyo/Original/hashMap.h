#pragma once

#pragma warning(disable : 4996 4013 4244 4267)

#define MAX_CHAR 127
#define NUM_ELEMENTOS 97 // Usar numero primo para reducir probabilidad de colision

typedef struct identificador identificador;
unsigned int hash(char *nombre, char *ambito);
void inicializar_tabla_hash();
void imprimir_tabla();
void agregar(identificador *temp);
identificador *buscar(char *nombre_identificador, char *ambito);
identificador *eliminar(char *nombre_identificador, char *ambito);
identificador *tabla_hash[NUM_ELEMENTOS];

// Tabla hash implementada como arreglo de listas (Chaining Hash Table)
struct identificador
{
    char nombre_identificador[MAX_CHAR];
    char tipo_identificador[MAX_CHAR];
    int fila_de_declaracion;
    int filas_de_uso[NUM_ELEMENTOS];
    int ubicacion;
    char ambito[MAX_CHAR];
    identificador *next;
};