#pragma once

#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#pragma warning(disable : 4996 4013 4244 4267)

#define MAX_NAME 127
#define TABLE_SIZE 97 // Numeros primo reducen probabilidad de Hash-colision

// cualquier puntero que tenga este valor sabremos fue eliminado y puedes decir si seguir buscando
#define DELETED_NODE (identidad *)(0xFFFFFFFFFFFFFFFFUL)

//Define la estructura 'identidad'.
typedef struct identidad identidad;
//Realiza hash con el nombre de la variable y el nombre del ambito.
unsigned int hash(char *nombre, char *ambito);
//Inicializa la tabla hash
void init_hash_table();
//Imprime todo el contenido de la tabla 
void print_table();
//Inserta una variable en la tabla.
bool hash_table_insert(identidad *p);
//Busca una variable en la tabla.
identidad *hash_table_lookup(char *nombre, char *ambito);
//Elimina una variable de la tabla.
identidad *hash_table_delete(char *nombre, char *ambito);
//Inicializa un puntero a una instancia de la estructura.
identidad *hash_table[TABLE_SIZE];

//Crea una estructura que almacena la información de la variable.
struct identidad
{
    char nombre[MAX_NAME];
    char tipo[MAX_NAME];
    int fila_declaracion;
    int filas_uso[TABLE_SIZE];
    char ambito[MAX_NAME];
};






