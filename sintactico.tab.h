
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 20 ".\\sintactico.y"

    #include "hash.h"



/* Line 1676 of yacc.c  */
#line 46 "sintactico.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     ADDOP = 259,
     MULOP = 260,
     VAR = 261,
     CONST = 262,
     ARRAY = 263,
     OF = 264,
     FUNCTION = 265,
     PROCEDURE = 266,
     BEGINA = 267,
     END = 268,
     WHILE = 269,
     DO = 270,
     TO = 271,
     FOR = 272,
     READ = 273,
     DOWNTO = 274,
     READLN = 275,
     WRITE = 276,
     WRITELN = 277,
     IF = 278,
     ELSE = 279,
     THEN = 280,
     AND = 281,
     OR = 282,
     NOT = 283,
     CONSTANTE_CADENA = 284,
     CONSTANTE_ENTERA = 285,
     CONSTANTE_REAL = 286,
     IDENTIFICADOR = 287,
     INT_TIPO = 288,
     REAL_TIPO = 289,
     STRING_TIPO = 290,
     BOOLEANO_TIPO = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 26 ".\\sintactico.y"

        identidad aux;
        char ambito[15];
        char nombre[200];
        char nombre_lista[201];
        char tipo[16];



/* Line 1676 of yacc.c  */
#line 109 "sintactico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


