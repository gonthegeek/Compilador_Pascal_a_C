%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "hashMap.h"
    #include "stack.h"
    #pragma warning(disable: 4996 4013 4244 4267)

    extern FILE * yyin;
    extern FILE * yyout;

    char identificadores[256];
    struct stack *ambito;
%}


%union {
    char nombre_identificador[127];
    char tipo_identificador[10];
    char identificadores_agrupacion[500];
    identificador temp;
}

%token PROGRAM INT_TIPO STRING_TIPO BOOLEANO_TIPO REAL_TIPO ADDOP MULOP VAR ARRAY CONST OF FUNCTION PROCEDURE BEGN END WHILE DO FOR TO DOWNTO READ READLN WRITE WRITELN IF THEN ELSE NOT OR AND CONSTANTE_CADENA CONSTANTE_REAL CONSTANTE_ENTERA 

%token<nombre_identificador> IDENTIFICADOR

%type <tipo_identificador> tipo
%type <identificadores_agrupacion> indentificador_lista parametros_lista

%%  

programa : PROGRAM IDENTIFICADOR { 
    ambito = newStack();
    push(ambito, yylval.temp.nombre_identificador);
} '(' indentificador_lista ')' ';' declaraciones subprograma_declaraciones instruccion_compuesta '.';

instruccion_compuesta : BEGN instrucciones_opcionales END { pop(ambito) };

relop : AND | OR | '<' | '>' | '<''=' | '>''=' | '=';

indentificador_lista : {identificadores[0] = '\0'} IDENTIFICADOR { 
    strcat(identificadores, yylval.temp.nombre_identificador); // añadir a lista el identificador
    strcat(identificadores, " "); // poner separador
    strcpy($$, identificadores); } // actualizar valor en identificador_lista
| indentificador_lista ',' IDENTIFICADOR { 
    strcat(identificadores, yylval.temp.nombre_identificador); 
    strcat(identificadores, " "); 
    strcpy($$, identificadores);
}
| {} ;

declaraciones : declaraciones_variables | declaraciones_constantes;

declaraciones_variables : declaraciones_variables VAR indentificador_lista ':' tipo ';' { 
    char *token;
    token = strtok($3, " ");
    while (token)
    {
        identificador temp;
        strcpy(temp.nombre_identificador, token);
        strcpy(temp.tipo_identificador, $5);
        temp.fila_de_declaracion = yylval.temp.fila_de_declaracion;
        temp.ambito = top(ambito);
        agregar(&temp);
        token = strtok(NULL, " ");
    }
 } | ;

declaraciones_constantes : declaraciones_constantes CONST IDENTIFICADOR '=' CONSTANTE_ENTERA ';'
|                          declaraciones_constantes CONST IDENTIFICADOR '=' CONSTANTE_REAL ';'
|                          declaraciones_constantes CONST IDENTIFICADOR '=' CONSTANTE_CADENA ';' | ;

tipo :  estandar_tipo { strcpy($$, yylval.tipo_identificador) }
|       ARRAY '[' CONSTANTE_ENTERA '.''.' CONSTANTE_ENTERA ']' OF estandar_tipo { strcpy($$, yylval.tipo_identificador) };

estandar_tipo : INT_TIPO | REAL_TIPO | STRING_TIPO | BOOLEANO_TIPO ;

subprograma_declaraciones : subprograma_declaraciones subprograma_declaracion ';' | ;

subprograma_declaracion : subprograma_encabezado declaraciones subprograma_declaraciones instruccion_compuesta;

subprograma_encabezado : FUNCTION IDENTIFICADOR { push(ambito, yylval.temp.nombre_identificador) } argumentos ':' estandar_tipo ';' {
    identificador temp;
    strcpy(temp.nombre_identificador, $2);
    strcpy(temp.tipo_identificador, yylval.tipo_identificador);
    temp.fila_de_declaracion = yylval.temp.fila_de_declaracion;
    temp.ambito = top(ambito);
    agregar(&temp);
}
| PROCEDURE IDENTIFICADOR { 
    identificador temp;
    strcpy(temp.nombre_identificador, $2);
    strcpy(temp.tipo_identificador, "void"); // Procedure no tiene return por lo que es tipo void
    temp.fila_de_declaracion = yylval.temp.fila_de_declaracion;
    temp.ambito = top(ambito);
    agregar(&temp);
    push(ambito, yylval.temp.nombre_identificador);
} argumentos ';' ;

argumentos : '(' parametros_lista ')' | ;

parametros_lista : indentificador_lista ':' tipo {
    char *token;
    token = strtok($1, " ");
    while (token)
    {
        identificador temp;
        strcpy(temp.nombre_identificador, token);
        strcpy(temp.tipo_identificador, $3);
        temp.fila_de_declaracion = yylval.temp.fila_de_declaracion;
        temp.ambito = top(ambito);
        agregar(&temp);
        token = strtok(NULL, " ");
    }
}
| parametros_lista ';' indentificador_lista ':' tipo { 
    char *token;
    token = strtok($3, " ");
    while (token)
    {
        identificador temp;
        strcpy(temp.nombre_identificador, token);
        strcpy(temp.tipo_identificador, $5);
        temp.fila_de_declaracion = yylval.temp.fila_de_declaracion;
        temp.ambito = top(ambito);
        agregar(&temp);
        token = strtok(NULL, " ");
    }
};

instrucciones_opcionales : instrucciones_lista | ;

instrucciones_lista : instrucciones | instrucciones ';' instrucciones_lista ;

instrucciones : variable_asignacion | procedure_instruccion | instruccion_compuesta | if_instruccion | repeticion_instruccion | lectura_instruccion | escritura_instruccion;

repeticion_instruccion : WHILE relop_expresion DO instrucciones
|                        FOR for_asignacion TO expresion DO instrucciones
|                        FOR for_asignacion DOWNTO expresion DO instrucciones;

lectura_instruccion : READ '(' IDENTIFICADOR ')' {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
}
| READLN '(' IDENTIFICADOR ')' { 
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
};

escritura_instruccion : WRITE '(' CONSTANTE_CADENA ',' IDENTIFICADOR ')' { 
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
} 
| WRITELN '(' CONSTANTE_CADENA ',' IDENTIFICADOR ')' { 
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
}
|                       WRITE '(' CONSTANTE_CADENA ')' | WRITELN '(' CONSTANTE_CADENA ')'
|                       WRITE '(' CONSTANTE_CADENA ',' expresion ')' | WRITELN '(' CONSTANTE_CADENA ',' expresion ')'
|                       WRITE '(' expresion ')' | WRITELN '(' expresion ')';

if_instruccion : IF relop_expresion THEN instrucciones | IF relop_expresion THEN instrucciones ELSE instrucciones;

variable_asignacion : variable ':''=' expresion;

for_asignacion : variable_asignacion | variable;

variable : IDENTIFICADOR {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
} 
| IDENTIFICADOR '[' expresion ']' {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
};

procedure_instruccion : IDENTIFICADOR {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
}
| IDENTIFICADOR '(' expresion_lista ')' {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
};

relop_expresion : relop_expresion OR relop_and | relop_and;

relop_and : relop_and AND relop_not | relop_not;

relop_not : NOT relop_not | relop_paren;

relop_paren : '(' relop_expresion ')' | relop_expresion_simple;

relop_expresion_simple : expresion relop expresion;

expresion_lista : expresion | expresion_lista ',' expresion;

expresion : termino | expresion ADDOP termino;

termino : factor | termino MULOP factor;

llamado_funcion : IDENTIFICADOR '(' expresion_lista ')' {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
};

factor : IDENTIFICADOR {
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
}
| IDENTIFICADOR { 
    identificador* temp = buscar(yylval.temp.nombre_identificador, top(ambito));
    if (temp) {
        temp->filas_de_uso[temp->ubicacion++] = yylval.temp.fila_de_declaracion;
    }
 } '[' expresion ']' | llamado_funcion | CONSTANTE_ENTERA | CONSTANTE_REAL | ADDOP factor | '(' expresion ')';

%%

int yyerror(char *s) 
{
   printf("Error %s\n", s);
   exit(1); /* Sale del programa */
   return 0;
}

int main(int argc, char * argv[])
{
   ++argv;
   --argc;
   if (argc > 0)
       yyin = fopen( argv[0], "r" );
   else
       yyin = stdin;
  
   yyparse();
   imprimir_tabla();
   printf("Reconocido correctamente\n");
   return 0;
}