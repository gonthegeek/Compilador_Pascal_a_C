#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10 //TAMAÑO HASH
//cualquier puntero que tenga este valor sabremos fue eliminado y puedes decir si seguir buscando
#define DELETED_NODE (person*)(0xFFFFFFFFFFFFFFFFUL)


typedef struct {
    char name[MAX_NAME];
    int age;
    // más cosas que quieras agregar
}person;

//hash table un array de pointers a las personas
person * hash_table[TABLE_SIZE];

//función hash para buscar personas por su nommbre
unsigned int hash(char *name){
    //checksum (method)
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i=0; i<length;i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;//multiplicar los valores de sum por el valor del carácter
        //el table_size sirve para ajustar los números al tamaño de la tabla -1
    }
    //localizacióbn dentro de la tabla que sea toda igual return 5
    return hash_value;
    //valores hash random
    // int length = strnlen(name, MAX_NAME);
    //unsigned int hash_value = 0;
    //for (int i=0; i<length;i++){
    //hash_value += name[i];
    //return hash_value
}

void init_hash_table(){
    for(int i=0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }

    //table vacio
}

//para saber el status de la tabla
void print_table(){
    printf("Start\n"); //para saber cuando inician las hash
    for(int i=0; i<TABLE_SIZE; i++){
        if (hash_table[i] == NULL){
            printf("\t%i\t---\n",i);
        }else if (hash_table[i] == DELETED_NODE){
            printf("\t%i\t---<deleted>\n",i);
        } else {
            printf("\t%i\t%s\n",i,hash_table[i]->name);
        }
    }
    printf("End\n"); // para saber cuando terminan las hash
}

//introducir persona en booleano, si lo mete es true si no será false
bool hash_table_insert(person *p){
    if(p == NULL) return false; //para no llamarlo por error
    int index = hash(p->name); //index o localización para intentar meter el nombre
    //se inicia en la 1 de la tabla y se irá bajando hasta encontrar un espacio
    for (int i = 0; i<TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL ||
            hash_table[try] == DELETED_NODE){
            hash_table[try]  = p;
            return true;
        }
    }
    return false; //en caso de poder meterlo se hace puntero a la nueva persona nueva
}

//busqueda dentro de la tabla hash , si la persona está en la tabla regresa un puntero, en este caso se buscará por el nombre
person *hash_table_lookup (char *name){
    int index = hash(name);
    for (int i = 0; i<TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL){
            return false; // no está aquí
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)==0){
            return hash_table[try];
        }
    }
    return NULL;
}

//eliminación de una persona
person *hash_table_delete(char *name){
    int index = hash(name);
    for (int i = 0; i<TABLE_SIZE; i++){
        int try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[try]->name, name, TABLE_SIZE)==0){
            person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL;
}

int main(){

    init_hash_table();
    print_table();

    person jacob = {.name="Jacob", .age=25};
    person kate = {.name="Kate", .age=30};
    person mpho = {.name="Mpho", .age=21};
    person sarah = {.name="Sarah", .age=21};
    person edna = {.name="Edna", .age=21};
    person maren = {.name="Maren", .age=21};
    person eliza = {.name="Eliza", .age=21};
    person robert = {.name="Robert", .age=21};
    person jane = {.name="Jane", .age=21};

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&mpho);
    hash_table_insert(&sarah);
    hash_table_insert(&edna);
    hash_table_insert(&maren);
    hash_table_insert(&eliza);
    hash_table_insert(&robert);
    hash_table_insert(&jane); //hay gente que no se agrego y hay dos soluciones para esto
    //open adressing - mantiene todo en la tabla, si la primera ya se uso te debe dar otra, se hace por medio de usar la función hash 
    //de nuevo, la más sencilla se llama linear probing

    print_table();

    person *tmp = hash_table_lookup("Jacob"); //búsqueda a partir de tmp
    if (tmp == NULL){
        printf("Not Found!\n");
    } else{
        printf("Found %s.\n",tmp -> name);
    }

    tmp = hash_table_lookup("Java");
    if (tmp == NULL){
        printf("Not Found!\n");
    } else{
        printf("Found %s.\n",tmp -> name);
    }

    hash_table_delete("Kate");

    tmp = hash_table_lookup("Kate");
    if (tmp == NULL){
        printf("Not Found!\n");
    } else{
        printf("Found %s.\n",tmp -> name);
    }

    print_table();

    /* pruebas antes para mostrar el random del número para meterlos en tabla hash
    printf("Jacob => %u\n",hash("Jacob"));
    printf("Peter => %u\n",hash("Peter"));
    printf("Olie => %u\n",hash("Olie"));
    printf("Natalie => %u\n",hash("Natalie"));
    printf("Fernand => %u\n",hash("Fernand"));
    printf("Julie => %u\n",hash("Julie"));*/
    return 0;
}