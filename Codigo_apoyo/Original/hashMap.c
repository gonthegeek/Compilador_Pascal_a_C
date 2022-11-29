#include "hashMap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Función hash
unsigned int hash(char *nombre, char *ambito)
{
    char temp[MAX_CHAR];
    strcpy(temp, nombre);
    strcat(temp, ambito);
    int length = strlen(temp);
    unsigned int valor_hash = 0;
    for (int i = 0; i < length; i++)
        valor_hash += temp[i];
    return valor_hash % NUM_ELEMENTOS;
}

// Inicializar los valores de la tabla hash
void inicializar_tabla_hash()
{
    for (int i = 0; i < NUM_ELEMENTOS; i++)
    {
        tabla_hash[i] = NULL;
    }
}

// Imprimir los contenidos de la tabla, tanto vacíos como utilizados
void imprimir_tabla()
{
    printf("\nIDENTIFICADOR\t|\tTIPO\t|\tFILA DE DECLARACION\t|\tAMBITO\t\t|\tFILAS DE USO\n");
    printf("------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_ELEMENTOS; i++)
    {
        if (tabla_hash[i])
        {
            identificador *temp = tabla_hash[i];
            while (temp != NULL)
            {
                printf("%s\t\t\t%s\t\t\t%d\t\t\t%s\t\t\t", temp->nombre_identificador, temp->tipo_identificador, temp->fila_de_declaracion, temp->ambito);
                for (int i = 0; i < temp->ubicacion; i++)
                    printf("%d, ", temp->filas_de_uso[i]);
                printf("\n------------------------------------------------------------------------------------------------------------------\n");
                temp = temp->next;
            }
        }
    }
    printf("\n");
}

// Agregar a la tabla hash
void agregar(identificador *temp)
{
    if (temp == NULL)
        return;
    int indice = hash(temp->nombre_identificador, temp->ambito);
    identificador *nuevoNodo = malloc(sizeof(identificador));
    if (nuevoNodo)
    {
        memcpy(nuevoNodo, temp, sizeof(identificador));
        nuevoNodo->next = tabla_hash[indice];
        tabla_hash[indice] = nuevoNodo;
    }
}

// Buscar elementos en la tabla hash por nombre del identificador
identificador *buscar(char *nombre_identificador, char *ambito)
{
    int indice = hash(nombre_identificador, ambito);
    identificador *temp = tabla_hash[indice];
    while (temp && strcmp(temp->nombre_identificador, nombre_identificador) != 0 && temp->ambito != ambito)
    {
        temp = temp->next;
    }
    return temp;
}

// Eliminar elementos
identificador *eliminar(char *nombre_identificador, char* ambito)
{
    int indice = hash(nombre_identificador, ambito);
    identificador *temp = tabla_hash[indice];
    identificador *prev = NULL;
    while (temp && strcmp(temp->nombre_identificador, nombre_identificador) != 0 && temp->ambito != ambito)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return NULL;
    if (prev == NULL) // el primer elemento en la lista fue el buscado
        tabla_hash[indice] = temp->next;
    else
        prev->next = temp->next;
    return temp;
}