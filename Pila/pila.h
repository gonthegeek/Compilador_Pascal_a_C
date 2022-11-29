#pragma once
#include <iostream>
using namespace std;

struct elementoPila{
    int nro;
    struct elementoPila *sgte;
};

typedef elementoPila *ptrPila;

void push( ptrPila&, int);
int pop( ptrPila& );
void mostrar_pila( ptrPila);
void destruir_pila( ptrPila&);
