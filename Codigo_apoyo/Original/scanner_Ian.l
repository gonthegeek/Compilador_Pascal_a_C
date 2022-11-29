%{

#include <stdio.h>
#include <string.h>
#include <malloc.h> // para las definiciones de malloc, free que provocan warning
#include <stdlib.h> // para las definiciones de exit que provocan warning
#include "sintactico.tab.h"
#include "hashMap.h"

#pragma warning(disable: 4996 6011 6385 4013 4244 4267)

unsigned int numero_filas_max = 1;
unsigned int numero_columnas_max = 1;
unsigned int fila = 1;
unsigned int columna = 1;

%}

const_cadena \"[^\n]*\"
digito [0-9]
letra [A-Za-z]
identif {letra}({letra}|{digito})*
addop [\+]|[-]
mulop [\*]|[\/]
simbolo [\<\.\(\>\);=\[:,\]\"]
entero [+-]?[0-9]+
real [+-]?{entero}+\.{digito}+([eE]{addop}?{digito}+)?

%%

program             { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return PROGRAM;
                    }
integer             { 
                        // printf("Se encontro %s\n",yytext);
                        strcpy(yylval.tipo_identificador, "int");
                        columna = columna + strlen(yytext);
                        return INT_TIPO;
                    }
string              { 
                        // printf("Se encontro %s\n",yytext);
                        strcpy(yylval.tipo_identificador, "string");
                        columna = columna + strlen(yytext);
                        return STRING_TIPO;
                    }
boolean             { 
                        // printf("Se encontro %s\n",yytext);
                        strcpy(yylval.tipo_identificador, "bool");
                        columna = columna + strlen(yytext);
                        return BOOLEANO_TIPO;
                    }
real                { 
                        // printf("Se encontro %s\n",yytext);
                        strcpy(yylval.tipo_identificador, "float");
                        columna = columna + strlen(yytext);
                        return REAL_TIPO;
                    }
var                 { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return VAR;
                    }
array               { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return ARRAY;
                    }
const               { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return CONST;
                    }
of                  { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return OF;
                    }
function            { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return FUNCTION;
                    }
procedure           { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return PROCEDURE;
                    }
begin               { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return BEGN;
                    }
end                 { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return END;
                    }
while               { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return WHILE;
                    }
do                  { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return DO;
                    }
for                 { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return FOR;
                    }
to                  { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return TO;
                    }
downto              { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return DOWNTO;
                    }
read                { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return READ;
                    }
readln              { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return READLN;
                    }
write               { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return WRITE;
                    }
writeln             { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return WRITELN;
                    }
if                  { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return IF;
                    }
then                { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return THEN;
                    }
else                { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return ELSE;
                    }
not                 { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return NOT;
                    }
or                  { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return OR;
                    }
and                 { 
                        // printf("Se encontro %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return AND;
                    }
{entero}            {
                        // printf("Se encontro entero %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return CONSTANTE_ENTERA;
                    }
{real}              {
                        // printf("Se encontro real %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return CONSTANTE_REAL;
                    }
{identif}           {
                        // printf("Se encontro %s\n", yytext);
                        strcpy(yylval.temp.nombre_identificador, yytext);
                        yylval.temp.fila_de_declaracion = fila;
                        columna = columna + strlen(yytext);
                        return IDENTIFICADOR;
                    }
{const_cadena}      {
                        // printf("Se encontro const cadena %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return CONSTANTE_CADENA;
                    }
{simbolo}           {
                        // printf("Se encontro simbolo %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return *yytext;
                    }
{addop}             { 
                        // printf("Se encontro addop %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return ADDOP;
                    }
{mulop}             { 
                        // printf("Se encontro mulop %s\n",yytext);
                        columna = columna + strlen(yytext);
                        return MULOP;
                    }

\t                  { columna++; }

" "                 { columna++; }

\n                  {
                        numero_columnas_max = columna;
                        columna = 1;
                        fila++;
                        numero_filas_max = fila;
                    }

.                   yyerror(yytext);

%%

int yywrap() {
    return 1;
}