// Arbol_binario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string.h>
using namespace std;
typedef enum [Tipo_Instruccion, Tipo_expresion] NodoTipo;
typedef enum [] Tipo_Instruccion;
typedef enum [Tipo_Operador, Tipo_Constante, Tipo_Identificador] Tipo_Expresion;
#define MAX_HIJOSPOR_NODO 4

/*struct Nodo {
    int dato;
    Nodo *der;
    Nodo *izq;
};*/

struct Nodo_string{
    string dato;
    Nodo_string * hijos [MAX_HIJOSPOR_NODO]; //areglo de hijos
    Nodo_string * hermano; //binario, por lo tanto se ocupa este?
    NodoTipo tipo_nodo;
    union tipo
    {
        Tipo_Instruccion instruccion;
        Tipo_Expresion expresion;
    };
    union atributos
    {
        int valor;
        char * nombre;
        Token operador;
    };
    
    
}

//Prototipos
/*Nodo *crearNodo(int);
void insertarNodo(Nodo*& arbol, int);
void mostrarArbol(Nodo*, int);*/

/*Nodo* arbol = NULL;*/
Nodo_string *crearNodo(string);
void insertarNodo(Nodo_string*& arbol, string)
void mostrarArbol(Nodo_string*, string);
//Funcion para crear un nodo
/*Nodo* crearNodo(int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;
}*/
Nodo_string* crearNodo(string n){
 Nodo_string* nuevo_nodo= new Nodo();
 nuevo_nodo->dato= n;
 nuevo_nodo->der=NULL;
  nuevo_nodo->izq=NULL;
  return nuevo_nodo;
}
//Funcion para insertar elementos en el arbol
/*void insertarNodo(Nodo*& arbol, int n) {
    if (arbol == NULL) { 
        Nodo* nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n);
        }
        else {
            insertarNodo(arbol->der, n);
        }
    }
}*/
    void insertarNodo(Nodo*& arbol, string n) {
    if (arbol == NULL) { 
        Nodo* nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else {
        int valorRaiz = arbol->dato;
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n);
        }
        else {
            insertarNodo(arbol->der, n);
        }
    }

//Funcion para mostrar el arbol
/*void mostrarArbol(Nodo *arbol, int cont) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, cont+1);
        for (int i = 0; i < cont; i++) {
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont+1);
        
    }
}*/

int main()
{                                                       
    cout << "Prueba arbol\n";
    /*int contador = 0;
    insertarNodo(arbol, 8);
    insertarNodo(arbol, 3);
    insertarNodo(arbol, 1);
    insertarNodo(arbol, 6);
    insertarNodo(arbol, 4);
    insertarNodo(arbol, 7);
    insertarNodo(arbol, 10);
    insertarNodo(arbol, 14);
    insertarNodo(arbol, 13);
    mostrarArbol(arbol,contador);*/
    
}

/*
Problematica: como se pasa lo que sigue del sintactico al arbol (if -> condicional??)
-switch + if??
-if anidados?
-Recorrer el arbol para crear el archvio txt de c++
*/