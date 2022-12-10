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
    /*
    1. La funcion toma un string y un string literal como argumentos.
    2. Copia el valor de string como una variable local llamda 'aux'.
    3. Concatena el string literal a la variable 'aux'.
    4. Calcula la longitud de aux string.
    5. Inicializa una variable llamada hash_value en 0.
    6. Itera a través de aux string y agrega cada caracter al hash_value.
    7. Regresa el hash_value modulo TABLE_SIZE.
    */
    char aux [MAX_NAME];
    strcpy(aux, nombre);
    strcat(aux,ambito);
    int longitud = strnlen(aux, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < longitud; i++)
    {
        hash_value += aux[i];
        //Table_size sirve para ajustar los números al tamaño de la tabla -1
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
    /*
    1. El primer loop itera la tabla hash.
    2. The el segundo loop itera a través de la hash table.
    3. El tercer loop iterata en el arreglo 'filas_uso' de la tabla hash.
    */
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
    /*
    1. La función hash se usa para determinar el index en el hash table que es donde el nuevo nodo debe ser insertado.
    2. El loop for se usa para encontrar un espacio vacío en la tabla.
    3. Si se tiene un espacio vacio, el nuevo nodo se inserta.
    4. Si el espacio no está vacío, el for no se usa para buscar el siguiente espacio vacio.
    5. Si todos los espacios estan llenos, el nuevo nodo no se  inserta.
    */
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
    /*
    1. Primero, calcula el index de la entrada que se buscará en la tabla.
    2. Después, busca sobre la tabla, empezando por el indice, hasta que se encuentre la variabe o se llegue al final de la tabla.
    3. Si se encuentra la variable, se regresa la entrada de la tabla hash.
    4. Si la variable no se encuentra, se regresa 'NULL'.
    */
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
    /*
    1. Primero, calcula el index de la entrada que se buscará en la tabla, es decir el nodo con el mismo nombre y ambito.
    2. Después, busca sobre la tabla, empezando por el indice, hasta que se encuentre el nodo que corresponda con el mismo nombre y ambito.
    3. Si encuentra el nodo, lo elimina de la tabla hash y lo regresa.
    4. Si no se encuentra el nodo, continua con el siguiente elemento de la tabla hash.
    5. Si se llega al final de los elementos sin encontrar el nodo, regresa 'NULL'.
    */
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
