#include "hash.h"
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


// La función hash se encarga de generar el indice o key para el elemento a guardar en la tabla
unsigned int hash(char *nombre, char *ambito)
{
    // Checksum en hash_value
    char aux [MAX_NAME];
    strcpy(aux, nombre);
    strcat(aux,ambito);
    int longitud = strnlen(aux, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < longitud; i++)
    {
        hash_value += aux[i];
        // el table_size sirve para ajustar los números al tamaño de la tabla -1
    }
    return hash_value % TABLE_SIZE;
}

void init_hash_table()
{
    //Establecer la tabla como vacía
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

// Imprime la tabla
void print_table()
{
    printf("\tIdentificador\tTipo\tAmbito\tFila Declaracion\tFilas Uso\n"); // para saber cuando inician las hash
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%i\t---<deleted>\n", i);
        }
        else
        {
            printf("\t%i\t%s\t%s\t%s\t%i\t", i, hash_table[i]->nombre, hash_table[i]->tipo, hash_table[i]->ambito, hash_table[i]->fila_declaracion);
            for (int j = 0; j < MAX_NAME; j++)
            {
                if (hash_table[i]->filas_uso[j] != '\0'){
                    printf("%i, ",hash_table[i]->filas_uso[j]);
                }
               
            }
             printf("\n");
        }
    }
    printf("End\n"); 
}

// Insertar es booleano, si se inserta será true si no, será false
bool hash_table_insert(identidad *p)
{
    if (p == NULL)
        return false;                   // para no llamarlo por error

    int index = hash(p->nombre, p ->ambito); // index o localización para insertar se inicia la tabla y se irá bajando hasta encontrar un espacio
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            identidad *temp = malloc(sizeof(identidad));
            memcpy(temp, p, sizeof(identidad));
            return true;
        }
    }
    return false;
}
// Busca dentro de la tabla hash 
identidad *hash_table_lookup(char *nombre, char *ambito)
{
    int index = hash(nombre, ambito);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
        {
            return false; // no está aquí
        }
        if (hash_table[try] == DELETED_NODE)
            continue;
        if ((strncmp(hash_table[try]->nombre, nombre, TABLE_SIZE) == 0)&&(strncmp(hash_table[try]->ambito, ambito, TABLE_SIZE) == 0))
        {
            return hash_table[try];
        }
    }
    return NULL;
}


// Elimina de la tabla 
identidad *hash_table_delete(char *nombre, char *ambito)
{
    int index = hash(nombre, ambito);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return NULL;
        if (hash_table[try] == DELETED_NODE)
            continue;
        if ((strncmp(hash_table[try]->nombre, nombre, TABLE_SIZE) == 0)&&(strncmp(hash_table[try]->ambito, ambito, TABLE_SIZE) == 0))
        {
            identidad *tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}
