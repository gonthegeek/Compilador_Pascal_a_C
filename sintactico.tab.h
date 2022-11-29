
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
#line 14 "sintactico.y"

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
     INT_TIPO = 259,
     REAL_TIPO = 260,
     STRING_TIPO = 261,
     BOOLEANO_TIPO = 262,
     ADDOP = 263,
     MULOP = 264,
     VAR = 265,
     CONST = 266,
     ARRAY = 267,
     OF = 268,
     FUNCTION = 269,
     PROCEDURE = 270,
     BEGINA = 271,
     END = 272,
     WHILE = 273,
     DO = 274,
     TO = 275,
     FOR = 276,
     READ = 277,
     DOWNTO = 278,
     READLN = 279,
     WRITE = 280,
     WRITELN = 281,
     IF = 282,
     ELSE = 283,
     THEN = 284,
     AND = 285,
     OR = 286,
     NOT = 287,
     CONSTANTE_CADENA = 288,
     CONSTANTE_ENTERA = 289,
     CONSTANTE_REAL = 290,
     IDENTIFICADOR = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 19 "sintactico.y"

        identidad aux;
        char nombre[127];
        char tipo [15];



/* Line 1676 of yacc.c  */
#line 107 "sintactico.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


