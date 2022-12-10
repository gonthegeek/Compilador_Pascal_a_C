/*Define los tokens que serán utilizados por el lenguaje*/
%token PROGRAM ADDOP MULOP VAR CONST ARRAY OF FUNCTION PROCEDURE BEGINA END WHILE DO TO FOR READ DOWNTO READLN WRITE WRITELN IF ELSE THEN AND OR NOT CONSTANTE_CADENA CONSTANTE_ENTERA CONSTANTE_REAL
%{
    #include "hash.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #pragma warning(disable: 4996 4013 4244 4267)
    extern FILE * yyin;
    extern FILE * yyout;

   /* Crea dos arreglos global de 256 caracteres.*/
    char identificadores[256];
    char ambito[255];
%}

/*Le dice al parser que incluya el hash.h en el código generado.*/
%code requires {
    #include "hash.h"
}


/*Define una nueva unión con diferentes tipos de variables*/
%union {
        identidad aux;
        char ambito[15];
        char nombre[200];
        char nombre_lista[201];
        char tipo[16];
}

/*
Se declara un %token IDENTIFICADOR del tipo nombre.
La siguiente linea es una declaracion %tipo que lista los terminales de tipo .
Las siguientes lineas son las reglas de la gramática. Cada regla tiene la forma:
    <no terminal> : <producto>
    | <producto>
    | <producto>
    | <producto>*/
    
%token <nombre> IDENTIFICADOR 
%token <tipo> INT_TIPO REAL_TIPO STRING_TIPO BOOLEANO_TIPO
%type<tipo> TIPO ESTANDAR_TIPO
%type <nombre_lista> IDENTIFICADOR_LISTA PARAMETROS_LISTA ARGUMENTOS

/*Aquí va la gramatica completa*/
%%

PROGRAMA :  PROGRAM  IDENTIFICADOR 
        { 
                /*Añade una nueva entrada a la tabla hash*/
                identidad p = {.nombre="", .tipo ="", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito=""};
                strcpy(p.nombre, yylval.nombre);
                strcpy(ambito, yylval.nombre);
                strcpy(p.tipo, "N/A");
                strcpy(p.ambito,ambito);
                hash_table_insert(&p); 
                print_table();
        }  
        '('IDENTIFICADOR_LISTA')'';' DECLARACIONES SUBPROGRAMA_DECLARACIONES  INSTRUCCION_COMPUESTA'.';
INSTRUCCION_COMPUESTA : BEGINA INSTRUCCIONES_OPCIONALES END;

RELOP : AND | OR | '<' | '>' | '<''=' | '>''=' | '=';

IDENTIFICADOR_LISTA : {identificadores[0] = '\0'}  IDENTIFICADOR { 
    /*Crea una lista de indetificadores del programa.*/
    strcat(identificadores, yylval.nombre); // añadir a lista el identificador
    strcat(identificadores, " "); // poner separador
    strcpy($$, identificadores); } | IDENTIFICADOR_LISTA',' IDENTIFICADOR { 
    strcat(identificadores, yylval.nombre); // añadir a lista el identificador
    strcat(identificadores, " "); // poner separador
    strcpy($$, identificadores); }| ;

DECLARACIONES : DECLARACIONES_VARIABLES | DECLARACIONES_CONSTANTES ; 

DECLARACIONES_VARIABLES : DECLARACIONES_VARIABLES VAR IDENTIFICADOR_LISTA  ':' TIPO ';'  {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok($3, " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,nombres_identificadores);
                strcpy(p.tipo,$5);
                strcpy(yylval.ambito,"main");
                strcpy(p.ambito, yylval.ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        } | ;

DECLARACIONES_CONSTANTES : DECLARACIONES_CONSTANTES CONST IDENTIFICADOR '=' CONSTANTE_ENTERA ';' 
                                | DECLARACIONES_CONSTANTES CONST IDENTIFICADOR '=' CONSTANTE_REAL ';'
                                | DECLARACIONES_CONSTANTES CONST IDENTIFICADOR '=' CONSTANTE_CADENA ';' |  ;


TIPO : ESTANDAR_TIPO {
        strcpy($$,$1);
} | ARRAY '['CONSTANTE_ENTERA'.''.'CONSTANTE_ENTERA ']' OF ESTANDAR_TIPO ;

ESTANDAR_TIPO : INT_TIPO | REAL_TIPO | STRING_TIPO | BOOLEANO_TIPO ;

SUBPROGRAMA_DECLARACIONES : SUBPROGRAMA_DECLARACIONES SUBPROGRAMA_DECLARACION ';' |  ;

SUBPROGRAMA_DECLARACION : SUBPROGRAMA_ENCABEZADO  DECLARACIONES SUBPROGRAMA_DECLARACIONES INSTRUCCION_COMPUESTA ;

SUBPROGRAMA_ENCABEZADO : FUNCTION IDENTIFICADOR ARGUMENTOS ':' ESTANDAR_TIPO ';'  {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok($3, " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,$2);
                strcpy(p.tipo,$5);
                strcpy(ambito,$2);
                strcpy(yylval.ambito,ambito);
                strcpy(p.ambito, yylval.ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        } | PROCEDURE IDENTIFICADOR ARGUMENTOS';' {
        char *nombres_identificadores;
        nombres_identificadores = strtok($3, " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,nombres_identificadores);
                strcpy(p.tipo,"N/A");
                strcpy(yylval.ambito,$2);
                strcpy(p.ambito, yylval.ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        } ; 

ARGUMENTOS : '('PARAMETROS_LISTA')' |  ;

PARAMETROS_LISTA : IDENTIFICADOR_LISTA ':' TIPO {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok($3, " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,$1);
                strcpy(p.tipo,$3);
                strcpy(p.ambito,ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        } | PARAMETROS_LISTA ';' IDENTIFICADOR_LISTA ':' TIPO {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok($3, " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,nombres_identificadores);
                strcpy(p.tipo,$5);
                strcpy(p.ambito, ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        } ;

INSTRUCCIONES_OPCIONALES : INSTRUCCIONES_LISTA | ;

INSTRUCCIONES_LISTA : INSTRUCCIONES | INSTRUCCIONES_LISTA ';' INSTRUCCIONES ;

INSTRUCCIONES : VARIABLE_ASIGNACION  | PROCEDURE_INSTRUCCION  | INSTRUCCION_COMPUESTA | IF_INSTRUCCION 
                | REPETICION_INSTRUCCION | LECTURA_INSTRUCCION | ESCRITURA_INSTRUCCION ;

REPETICION_INSTRUCCION : WHILE RELOP_EXPRESION DO INSTRUCCIONES
                        | FOR FOR_ASIGNACION TO EXPRESION DO INSTRUCCIONES
	                | FOR FOR_ASIGNACION DOWNTO EXPRESION DO INSTRUCCIONES ;

LECTURA_INSTRUCCION : READ '('IDENTIFICADOR')' | READLN '('IDENTIFICADOR')' ;

ESCRITURA_INSTRUCCION : WRITE '('CONSTANTE_CADENA',' IDENTIFICADOR')' |WRITELN '('CONSTANTE_CADENA',' IDENTIFICADOR')'
		        | WRITE '('CONSTANTE_CADENA')' |WRITELN '('CONSTANTE_CADENA ')'
			| WRITE '('CONSTANTE_CADENA ',' EXPRESION ')' |WRITELN '('CONSTANTE_CADENA',' EXPRESION')' ;

IF_INSTRUCCION : IF RELOP_EXPRESION THEN INSTRUCCIONES
    		|IF RELOP_EXPRESION THEN INSTRUCCIONES ELSE INSTRUCCIONES ;

VARIABLE_ASIGNACION : VARIABLE ':''=' EXPRESION ;

FOR_ASIGNACION : VARIABLE_ASIGNACION | VARIABLE ;

VARIABLE : IDENTIFICADOR | IDENTIFICADOR '['EXPRESION']' ;

PROCEDURE_INSTRUCCION  : IDENTIFICADOR | IDENTIFICADOR '('EXPRESION_LISTA')' ;

RELOP_EXPRESION : RELOP_EXPRESION OR RELOP_AND | RELOP_AND ;

RELOP_AND : RELOP_AND AND RELOP_NOT | RELOP_NOT ;

RELOP_NOT : NOT RELOP_NOT | RELOP_PAREN ;

RELOP_PAREN : '('RELOP_EXPRESION')' | RELOP_EXPRESION_SIMPLE ; 

RELOP_EXPRESION_SIMPLE : EXPRESION RELOP EXPRESION ;

EXPRESION_LISTA : EXPRESION | EXPRESION_LISTA ',' EXPRESION ;

EXPRESION : TERMINO | EXPRESION ADDOP TERMINO ;

TERMINO : FACTOR | TERMINO MULOP FACTOR ;

LLAMADO_FUNCION : IDENTIFICADOR '('EXPRESION_LISTA')' ;

FACTOR : IDENTIFICADOR| IDENTIFICADOR'['EXPRESION']' | LLAMADO_FUNCION | CONSTANTE_ENTERA | CONSTANTE_REAL | ADDOP FACTOR | '('EXPRESION')' ;



%%

int yyerror(char *s) 
{
   printf("Alto: %s\n", s);
   exit(1); /* Sale del programa */
   return 0;
}

int main(int argc, char * argv[])
{ 
    	if (argc > 0) 
            {
                yyin = fopen( argv[1], "r" );
            }   
    	else
            yyin = stdin;
    
    	yyparse();


    	return(0);
}
