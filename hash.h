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

typedef struct identidad identidad;
unsigned int hash(char *nombre, char *ambito);
void init_hash_table();
void print_table();
bool hash_table_insert(identidad *p);
identidad *hash_table_lookup(char *nombre, char *ambito);
identidad *hash_table_delete(char *nombre, char *ambito);
identidad *hash_table[TABLE_SIZE];

struct identidad
{
    char nombre[MAX_NAME];
    char tipo[MAX_NAME];
    int fila_declaracion;
    int filas_uso[TABLE_SIZE];
    char ambito[MAX_NAME];
};






