%{

    /*Inluye el header lex.yy.h, que contiene la definición del lexer.
    Inluye el header sintactico.tab.h que contiene la definición del parser.
    Se define contador_fila and total_filas, que se ocupa para mantener cuenta del número de línea acttual.
    Define la función yyerror(), que se llama cuando ocurre un error.
    Deefine la función yylex(), que se llama cuando el parser necesita el siguiente token.
    Define la función yyparse(), que se llama cuando el parser necesita parsear el siguiente token.*/
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
/*Se define el nombre para el archivo de salida.*/
%option outfile="scanner.c"

/*Se definen los elementos terminales de la gramática.*/
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

/*Se definen las acciones a tomar cuando se encuentren coincidencias con las reglas*/
%%
{PROGRAM}	    {
                   printf("Encontre: %s\n",yytext); /*Imprime el valor del token encontrado por Flex */
                   return PROGRAM;
                }

{INT_TIPO}      {
                    printf("Encontre: %s\n",yytext); 
                    strcpy(yylval.tipo, "int"); /*Copia el string entre comillas la variable yyval.tipo*/
                    return  INT_TIPO;
                }

{STRING_TIPO}   {
                    printf("Encontre: %s\n",yytext);
                    strcpy(yylval.tipo, "string"); /*Copia el string entre comillas la variable yyval.tipo*/
 
                    return STRING_TIPO;
                }

{BOOLEANO_TIPO} {
                    printf("Encontre: %s\n",yytext); 
                    strcpy(yylval.tipo, "bool"); /*Copia el string entre comillas la variable yyval.tipo*/

                    return BOOLEANO_TIPO;
                }

{REAL_TIPO}     {
                    printf("Encontre: %s\n",yytext); 
                    strcpy(yylval.tipo, "float"); /*Copia el string entre comillas la variable yyval.tipo*/

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
                    strcpy(yylval.nombre, yytext);  /*Copia el valor del token de yytext a la variable yyval.tipo*/
                    yylval.aux.fila_declaracion = contador_fila; /*Asigna el valor de contador_fila a la variable yylval.aux.fila_declaracion*/
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
                    contador_fila++; /*Aumenta valor actual*/
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


