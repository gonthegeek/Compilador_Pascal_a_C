%{

    #pragma warning(disable: 4996 6011 6385 4013 4244 4267)
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <wchar.h>
    #include <locale.h>
    #include <malloc.h>
    #include "sintactico.tab.h"

    unsigned int contador_fila = 1;
    unsigned int total_filas = 1;

%}
%option outfile="scanner.c"
/*%option noyywrap*/

CONSTANTE_CADENA         \"[^\n]*\"
PROGRAM         		 [p][r][o][g][r][a][m]
LETRA 					 [A-Za-z]
DIGITO 					 [0-9]
IDENTIFICADOR            {LETRA}({LETRA}|{DIGITO})*  
ALPHA    			     [\<\.\(\>\);=\[,:\]\"\$\&\/\%\#]
INT_TIPO        		 [i][n][t][e][g][e][r]
REAL_TIPO       		 [r][e][a][l]
STRING_TIPO     		 [s][t][r][i][n][g]
BOOLEANO_TIPO   		 [b][o][o][l][e][a][n]
/*RELOP           		 [a][n][d]|[o][r]*/
ADDOP           		 [+]|[-] 
MULOP           		 [*]|[/]
VAR 					 [v][a][r]
CONST					 [c][o][n][s][t]
ARRAY 					 [a][r][r][a][y]
OF                  	 [o][f]
FUNCTION 				 [f][u][n][c][t][i][o][n]
PROCEDURE 				 [p][r][o][c][e][d][u][r][e]
BEGIN 					 [b][e][g][i][n]
END 					 [e][n][d]	
WHILE                    [w][h][i][l][e]
DO                       [d][o]
TO                       [t][o]
FOR                      [f][o][r]
READ                     [r][e][a][d]
DOWNTO 				     [d][o][w][n][t][o]
READLN        			 [r][e][a][d][l][n]
WRITE 					 [w][r][i][t][e]
WRITELN					 [w][r][i][t][e][l][n]
IF 						 [i][f]
ELSE 					 [e][l][s][e]
THEN                     [t][h][e][n]	
AND                      [a][n][d]
OR                       [o][r]
NOT 					 [n][o][t]
ENTERO                   [+-]?[0-9]+
REAL                     [+-]?{ENTERO}+\.{DIGITO}+([eE]{ADDOP}?{DIGITO}+)?


%%

{PROGRAM}	    {
                    printf("Encontre: %s\n",yytext); 
                   return PROGRAM;
                }

{INT_TIPO}      {
                    printf("Encontre: %s\n",yytext); 
                    strcpy(yylval.tipo, "int");
                    return  INT_TIPO;
                }

{STRING_TIPO}   {
                    printf("Encontre: %s\n",yytext);
                    strcpy(yylval.tipo, "string");
 
                    return STRING_TIPO;
                }

{BOOLEANO_TIPO} {
                    printf("Encontre: %s\n",yytext); 
                                        strcpy(yylval.tipo, "bool");

                    return BOOLEANO_TIPO;
                }

{REAL_TIPO}     {
                    printf("Encontre: %s\n",yytext); 
                                        strcpy(yylval.tipo, "float");

                    return REAL_TIPO;
                }

{VAR} 			{
                    printf("Encontre: %s\n",yytext); 
                     
                    return VAR;
                }

{ARRAY} 		{
                    printf("Encontre: %s\n",yytext); 
                     
                    return ARRAY;
                }

{CONST}			{
                    printf("Encontre: %s\n",yytext); 
                     
                    return CONST;
                }


{OF}            {
                    printf("Encontre: %s\n",yytext); 
                     
                    return OF;
                }

{FUNCTION} 		{
                    printf("Encontre: %s\n",yytext); 
                     
                    return FUNCTION;
                }

{PROCEDURE} 	{
                    printf("Encontre: %s\n",yytext); 
                     
                    return PROCEDURE;
                }

{BEGIN} 		{
                    printf("Encontre: %s\n",yytext); 
                     
                    return BEGINA;
                }

{END} 			{
                    printf("Encontre: %s\n",yytext); 
                     
                    return END;
                }

{WHILE}         {
                    printf("Encontre: %s\n",yytext); 
                     
                    return WHILE;
                }

{DO}            {
                    printf("Encontre: %s\n",yytext); 
                     
                    return DO;
                }

{FOR}           {
                    printf("Encontre: %s\n",yytext); 
                     
                    return FOR;
                }

{TO}            {
                    printf("Encontre: %s\n",yytext); 
                     
                    return TO;
                }

{DOWNTO} 		{
                    printf("Encontre: %s\n",yytext); 
                     
                    return DOWNTO;
                }
                 
{READ}           {
                    printf("Encontre: %s\n",yytext); 
                     
                    return READ;
                }

{READLN}        {
                    printf("Encontre: %s\n",yytext); 
                     
                    return READLN;
                }

{WRITE} 		{
                    printf("Encontre: %s\n",yytext); 
                     
                    return WRITE;
                }

{WRITELN}		{
                    printf("Encontre: %s\n",yytext); 
                     
                    return WRITELN;
                }

{IF}			{
                    printf("Encontre: %s\n",yytext); 
                     
                    return IF;
                }

{THEN}          {
                    printf("Encontre: %s\n",yytext); 
                     
                    return THEN;
                }

{ELSE}			{
                    printf("Encontre: %s\n",yytext); 
                     
                    return ELSE;
                }

{NOT} 			{
                    printf("Encontre: %s\n",yytext); 
                     
                    return NOT;
                }

{OR}            {
                    printf("Encontre: %s\n",yytext); 
                     
                    return OR;
                }

{AND}           {
                    printf("Encontre: %s\n",yytext); 
                     
                    return AND;
                }

{ENTERO}	    {
                    printf("Encontre: %s\n",yytext); 
                     
                    return CONSTANTE_ENTERA;
                }

{REAL}              {
                        printf("Encontre: %s\n",yytext); 
                        return CONSTANTE_REAL;
                    }

{IDENTIFICADOR}	{
                   printf("Encontre: %s\n", yytext); 
                    strcpy(yylval.nombre, yytext);  
                    yylval.aux.fila_declaracion = contador_fila;
                    return IDENTIFICADOR;                
                }		 		 


{CONSTANTE_CADENA} {
                        printf("Encontre: %s\n",yytext); 
                        return CONSTANTE_CADENA;
                    }


{ALPHA}         {
                    printf("Encontre: %s\n",yytext); 
                     
                    return *yytext;
                }

{ADDOP}         {
                    printf("Encontre: %s\n",yytext); 
                     
                    return ADDOP;
                } 

{MULOP}         {
                    printf("Encontre: %s\n",yytext); 
                     
                    return MULOP;
                }
                
" "             {
                    //printf("Encontre: un espacio en blanco \n");
                    
                }

\n              {
                    //printf("Encontre un salto de linea \n");
                    contador_fila++;
                    total_filas = contador_fila;     
                }

\t              {
                   //printf("Encontre: un espacio en blanco \n");
                }
.			    {
                    printf("Caracter no valido:");
                     
                
                 }

%%


int yywrap(void) 
{
    return 1;
}


