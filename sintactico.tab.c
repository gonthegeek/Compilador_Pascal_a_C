
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 ".\\sintactico.y"

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


/* Line 189 of yacc.c  */
#line 90 "sintactico.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 20 ".\\sintactico.y"

    #include "hash.h"



/* Line 209 of yacc.c  */
#line 120 "sintactico.tab.c"

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

/* Line 214 of yacc.c  */
#line 26 ".\\sintactico.y"

        identidad aux;
        char ambito[15];
        char nombre[200];
        char nombre_lista[201];
        char tipo[16];



/* Line 214 of yacc.c  */
#line 183 "sintactico.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 195 "sintactico.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   208

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  196

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      37,    38,     2,     2,    44,     2,    40,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    39,
      41,    43,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    16,    20,    22,    24,    26,    28,
      31,    34,    36,    37,    40,    44,    45,    47,    49,    56,
      57,    64,    71,    78,    79,    81,    91,    93,    95,    97,
      99,   103,   104,   109,   116,   121,   125,   126,   130,   136,
     138,   139,   141,   145,   147,   149,   151,   153,   155,   157,
     159,   164,   171,   178,   183,   188,   195,   202,   207,   212,
     219,   226,   231,   238,   243,   245,   247,   249,   254,   256,
     261,   265,   267,   271,   273,   276,   278,   282,   284,   288,
     290,   294,   296,   300,   302,   306,   311,   313,   318,   320,
     322,   324,   327
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    -1,     3,    32,    50,    37,    53,    38,
      39,    55,    60,    51,    40,    -1,    12,    65,    13,    -1,
      26,    -1,    27,    -1,    41,    -1,    42,    -1,    41,    43,
      -1,    42,    43,    -1,    43,    -1,    -1,    54,    32,    -1,
      53,    44,    32,    -1,    -1,    56,    -1,    57,    -1,    56,
       6,    53,    45,    58,    39,    -1,    -1,    57,     7,    32,
      43,    30,    39,    -1,    57,     7,    32,    43,    31,    39,
      -1,    57,     7,    32,    43,    29,    39,    -1,    -1,    59,
      -1,     8,    46,    30,    40,    40,    30,    47,     9,    59,
      -1,    33,    -1,    34,    -1,    35,    -1,    36,    -1,    60,
      61,    39,    -1,    -1,    62,    55,    60,    51,    -1,    10,
      32,    63,    45,    59,    39,    -1,    11,    32,    63,    39,
      -1,    37,    64,    38,    -1,    -1,    53,    45,    58,    -1,
      64,    39,    53,    45,    58,    -1,    66,    -1,    -1,    67,
      -1,    66,    39,    67,    -1,    72,    -1,    75,    -1,    51,
      -1,    71,    -1,    68,    -1,    69,    -1,    70,    -1,    14,
      76,    15,    67,    -1,    17,    73,    16,    82,    15,    67,
      -1,    17,    73,    19,    82,    15,    67,    -1,    18,    37,
      32,    38,    -1,    20,    37,    32,    38,    -1,    21,    37,
      29,    44,    32,    38,    -1,    22,    37,    29,    44,    32,
      38,    -1,    21,    37,    29,    38,    -1,    22,    37,    29,
      38,    -1,    21,    37,    29,    44,    82,    38,    -1,    22,
      37,    29,    44,    82,    38,    -1,    23,    76,    25,    67,
      -1,    23,    76,    25,    67,    24,    67,    -1,    74,    45,
      43,    82,    -1,    72,    -1,    74,    -1,    32,    -1,    32,
      46,    82,    47,    -1,    32,    -1,    32,    37,    81,    38,
      -1,    76,    27,    77,    -1,    77,    -1,    77,    26,    78,
      -1,    78,    -1,    28,    78,    -1,    79,    -1,    37,    76,
      38,    -1,    80,    -1,    82,    52,    82,    -1,    82,    -1,
      81,    44,    82,    -1,    83,    -1,    82,     4,    83,    -1,
      85,    -1,    83,     5,    85,    -1,    32,    37,    81,    38,
      -1,    32,    -1,    32,    46,    82,    47,    -1,    84,    -1,
      30,    -1,    31,    -1,     4,    85,    -1,    37,    82,    38,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    51,    63,    65,    65,    65,    65,    65,
      65,    65,    67,    67,    71,    74,    76,    76,    78,    94,
      96,    97,    98,    98,   101,   103,   105,   105,   105,   105,
     107,   107,   109,   111,   128,   145,   145,   147,   162,   179,
     179,   181,   181,   183,   183,   183,   183,   184,   184,   184,
     186,   187,   188,   190,   190,   192,   192,   193,   193,   194,
     194,   196,   197,   199,   201,   201,   203,   203,   205,   205,
     207,   207,   209,   209,   211,   211,   213,   213,   215,   217,
     217,   219,   219,   221,   221,   223,   225,   225,   225,   225,
     225,   225,   225
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "ADDOP", "MULOP", "VAR",
  "CONST", "ARRAY", "OF", "FUNCTION", "PROCEDURE", "BEGINA", "END",
  "WHILE", "DO", "TO", "FOR", "READ", "DOWNTO", "READLN", "WRITE",
  "WRITELN", "IF", "ELSE", "THEN", "AND", "OR", "NOT", "CONSTANTE_CADENA",
  "CONSTANTE_ENTERA", "CONSTANTE_REAL", "IDENTIFICADOR", "INT_TIPO",
  "REAL_TIPO", "STRING_TIPO", "BOOLEANO_TIPO", "'('", "')'", "';'", "'.'",
  "'<'", "'>'", "'='", "','", "':'", "'['", "']'", "$accept", "PROGRAMA",
  "$@1", "INSTRUCCION_COMPUESTA", "RELOP", "IDENTIFICADOR_LISTA", "$@2",
  "DECLARACIONES", "DECLARACIONES_VARIABLES", "DECLARACIONES_CONSTANTES",
  "TIPO", "ESTANDAR_TIPO", "SUBPROGRAMA_DECLARACIONES",
  "SUBPROGRAMA_DECLARACION", "SUBPROGRAMA_ENCABEZADO", "ARGUMENTOS",
  "PARAMETROS_LISTA", "INSTRUCCIONES_OPCIONALES", "INSTRUCCIONES_LISTA",
  "INSTRUCCIONES", "REPETICION_INSTRUCCION", "LECTURA_INSTRUCCION",
  "ESCRITURA_INSTRUCCION", "IF_INSTRUCCION", "VARIABLE_ASIGNACION",
  "FOR_ASIGNACION", "VARIABLE", "PROCEDURE_INSTRUCCION", "RELOP_EXPRESION",
  "RELOP_AND", "RELOP_NOT", "RELOP_PAREN", "RELOP_EXPRESION_SIMPLE",
  "EXPRESION_LISTA", "EXPRESION", "TERMINO", "LLAMADO_FUNCION", "FACTOR", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    40,    41,    59,
      46,    60,    62,    61,    44,    58,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    50,    49,    51,    52,    52,    52,    52,    52,
      52,    52,    54,    53,    53,    53,    55,    55,    56,    56,
      57,    57,    57,    57,    58,    58,    59,    59,    59,    59,
      60,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    83,    84,    85,    85,    85,    85,
      85,    85,    85
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    11,     3,     1,     1,     1,     1,     2,
       2,     1,     0,     2,     3,     0,     1,     1,     6,     0,
       6,     6,     6,     0,     1,     9,     1,     1,     1,     1,
       3,     0,     4,     6,     4,     3,     0,     3,     5,     1,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     6,     6,     4,     4,     6,     6,     4,     4,     6,
       6,     4,     6,     4,     1,     1,     1,     4,     1,     4,
       3,     1,     3,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     4,     1,     4,     1,     1,
       1,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,    15,     0,     0,     0,
       0,    13,    19,    14,    31,    16,    17,     0,    15,     0,
       0,     0,    40,     0,     0,    19,     0,     0,    36,    36,
       0,     0,     0,     0,     0,     0,     0,    68,    45,     0,
      39,    41,    47,    48,    49,    46,    43,     0,    44,     3,
      30,    31,     0,     0,    15,     0,     0,     0,     0,    89,
      90,    86,     0,     0,    71,    73,    75,    77,     0,    81,
      88,    83,    66,    64,     0,    65,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     0,    26,    27,
      28,    29,     0,    24,     0,     0,     0,     0,     0,     0,
      34,     0,    91,    74,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,    42,
       0,    32,     0,    18,    22,    20,    21,     0,    35,    15,
       0,     0,     0,     0,    76,    92,    50,    70,    72,    82,
       9,    10,    78,    84,     0,     0,    53,    54,    57,     0,
      58,     0,    61,    69,     0,    67,    63,     0,    37,     0,
      33,    85,    87,     0,     0,    86,     0,    86,     0,     0,
      80,     0,     0,    51,    52,    55,    59,    56,    60,    62,
       0,    38,     0,     0,     0,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,    38,   117,     7,     8,    14,    15,    16,
      92,    93,    17,    24,    25,    55,    98,    39,    40,    41,
      42,    43,    44,    45,    46,    74,    47,    48,    63,    64,
      65,    66,    67,   126,    68,    69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
      11,   -15,    24,  -132,  -132,     1,    10,    30,    22,    28,
      39,  -132,    68,  -132,  -132,    84,   128,   135,    10,    86,
     105,   106,   102,   117,   120,    68,   107,   115,   123,   123,
      51,   129,   125,   126,   127,   130,    51,   -11,  -132,   152,
     131,  -132,  -132,  -132,  -132,  -132,  -132,   121,  -132,  -132,
    -132,  -132,    93,   119,    10,   124,   132,    33,    51,  -132,
    -132,    59,    51,    -2,   142,  -132,  -132,  -132,     6,   167,
    -132,  -132,   133,  -132,    73,   121,   141,   143,   145,   147,
      77,    33,    33,  -132,   102,   134,   135,   136,  -132,  -132,
    -132,  -132,   139,  -132,   144,   146,   148,   109,    -8,   108,
    -132,    33,  -132,  -132,    33,    33,   -16,    35,   102,    51,
      51,    33,  -132,  -132,   137,   138,  -132,    33,    33,    33,
      33,   150,   151,    47,    71,   102,    92,   180,     3,  -132,
      33,  -132,   156,  -132,  -132,  -132,  -132,    93,  -132,    10,
     153,     8,    95,     5,  -132,  -132,  -132,   142,  -132,   167,
    -132,  -132,   180,  -132,    12,    14,  -132,  -132,  -132,    76,
    -132,    80,   166,  -132,    33,  -132,   180,   154,  -132,   111,
    -132,  -132,  -132,   102,   102,    49,    15,    94,    19,   102,
     180,   155,    93,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
     161,  -132,   149,   184,   108,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,   -14,  -132,   -18,  -132,   172,  -132,  -132,
    -131,   -97,   157,  -132,  -132,   169,  -132,  -132,  -132,   -80,
    -132,  -132,  -132,  -132,   168,  -132,   170,  -132,   -21,    91,
     -50,  -132,  -132,    98,   -61,    96,  -132,   -52
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -67
static const yytype_int16 yytable[] =
{
      26,   107,   140,    23,   129,   102,   168,   111,   103,   111,
     111,   109,   111,   108,     1,    80,   111,     3,   111,   111,
     127,   128,   144,   111,     4,   109,    81,   173,   146,   174,
     138,   139,   112,   113,   -66,    82,    97,    57,     6,   111,
     141,   106,   -12,   127,   143,   162,   145,   114,   115,   116,
     165,   191,   172,   186,    11,    57,   152,   188,   154,   155,
     148,   112,   113,    59,    60,    61,   153,    12,     9,   166,
     101,    13,   131,   145,    10,   -23,   114,   115,   116,    58,
      57,    59,    60,    61,    57,   158,   104,   185,    62,   119,
      18,   159,   120,   183,   184,   105,   104,   195,   176,   189,
     178,    87,   125,   180,   109,   105,    59,    60,   175,   160,
      59,    60,   177,   101,    22,   161,    30,   101,    27,    31,
      32,   169,    33,    34,    35,    36,    88,    89,    90,    91,
     163,   104,   187,   171,    37,    19,   164,    28,    29,   164,
     105,    88,    89,    90,    91,    20,    21,    22,    94,    95,
      96,    10,    52,    10,   137,    10,   182,    49,    53,    50,
      54,    72,    76,    77,    78,    83,    85,    79,   110,    99,
      84,   100,   118,   121,   123,   122,   124,   130,   133,    82,
     150,   151,   132,   134,   111,   135,   167,   136,   156,   157,
     179,   192,   170,   194,   181,   190,   193,    51,    56,    73,
     147,    75,   142,     0,     0,     0,     0,   149,    86
};

static const yytype_int16 yycheck[] =
{
      18,    62,    99,    17,    84,    57,   137,     4,    58,     4,
       4,    27,     4,    15,     3,    36,     4,    32,     4,     4,
      81,    82,    38,     4,     0,    27,    37,    15,   108,    15,
      38,    39,    26,    27,    45,    46,    54,     4,    37,     4,
     101,    62,    32,   104,   105,   125,    38,    41,    42,    43,
      47,   182,    47,    38,    32,     4,   117,    38,   119,   120,
     110,    26,    27,    30,    31,    32,   118,    39,    38,   130,
      37,    32,    86,    38,    44,     7,    41,    42,    43,    28,
       4,    30,    31,    32,     4,    38,    37,    38,    37,    16,
       6,    44,    19,   173,   174,    46,    37,   194,   159,   179,
     161,     8,    25,   164,    27,    46,    30,    31,    32,    38,
      30,    31,    32,    37,    12,    44,    14,    37,    32,    17,
      18,   139,    20,    21,    22,    23,    33,    34,    35,    36,
      38,    37,    38,    38,    32,     7,    44,    32,    32,    44,
      46,    33,    34,    35,    36,    10,    11,    12,    29,    30,
      31,    44,    45,    44,    45,    44,    45,    40,    43,    39,
      37,    32,    37,    37,    37,    13,    45,    37,    26,    45,
      39,    39,     5,    32,    29,    32,    29,    43,    39,    46,
      43,    43,    46,    39,     4,    39,    30,    39,    38,    38,
      24,    30,    39,     9,    40,    40,    47,    25,    29,    31,
     109,    31,   104,    -1,    -1,    -1,    -1,   111,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    49,    32,     0,    50,    37,    53,    54,    38,
      44,    32,    39,    32,    55,    56,    57,    60,     6,     7,
      10,    11,    12,    51,    61,    62,    53,    32,    32,    32,
      14,    17,    18,    20,    21,    22,    23,    32,    51,    65,
      66,    67,    68,    69,    70,    71,    72,    74,    75,    40,
      39,    55,    45,    43,    37,    63,    63,     4,    28,    30,
      31,    32,    37,    76,    77,    78,    79,    80,    82,    83,
      84,    85,    32,    72,    73,    74,    37,    37,    37,    37,
      76,    37,    46,    13,    39,    45,    60,     8,    33,    34,
      35,    36,    58,    59,    29,    30,    31,    53,    64,    45,
      39,    37,    85,    78,    37,    46,    76,    82,    15,    27,
      26,     4,    26,    27,    41,    42,    43,    52,     5,    16,
      19,    32,    32,    29,    29,    25,    81,    82,    82,    67,
      43,    51,    46,    39,    39,    39,    39,    45,    38,    39,
      59,    82,    81,    82,    38,    38,    67,    77,    78,    83,
      43,    43,    82,    85,    82,    82,    38,    38,    38,    44,
      38,    44,    67,    38,    44,    47,    82,    30,    58,    53,
      39,    38,    47,    15,    15,    32,    82,    32,    82,    24,
      82,    40,    45,    67,    67,    38,    38,    38,    38,    67,
      40,    58,    30,    47,     9,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 52 ".\\sintactico.y"
    { 
                /*Añade una nueva entrada a la tabla hash*/
                identidad p = {.nombre="", .tipo ="", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito=""};
                strcpy(p.nombre, yylval.nombre);
                strcpy(ambito, yylval.nombre);
                strcpy(p.tipo, "N/A");
                strcpy(p.ambito,ambito);
                hash_table_insert(&p); 
                print_table();
        ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 67 ".\\sintactico.y"
    {identificadores[0] = '\0';}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 67 ".\\sintactico.y"
    { 
    /*Crea una lista de indetificadores del programa.*/
    strcat(identificadores, yylval.nombre); // añadir a lista el identificador
    strcat(identificadores, " "); // poner separador
    strcpy((yyval.nombre_lista), identificadores); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 71 ".\\sintactico.y"
    { 
    strcat(identificadores, yylval.nombre); // añadir a lista el identificador
    strcat(identificadores, " "); // poner separador
    strcpy((yyval.nombre_lista), identificadores); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 78 ".\\sintactico.y"
    {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok((yyvsp[(3) - (6)].nombre_lista), " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,nombres_identificadores);
                strcpy(p.tipo,(yyvsp[(5) - (6)].tipo));
                strcpy(yylval.ambito,"main");
                strcpy(p.ambito, yylval.ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 101 ".\\sintactico.y"
    {
        strcpy((yyval.tipo),(yyvsp[(1) - (1)].tipo));
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 111 ".\\sintactico.y"
    {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok((yyvsp[(3) - (6)].nombre_lista), " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,(yyvsp[(2) - (6)].nombre));
                strcpy(p.tipo,(yyvsp[(5) - (6)].tipo));
                strcpy(ambito,(yyvsp[(2) - (6)].nombre));
                strcpy(yylval.ambito,ambito);
                strcpy(p.ambito, yylval.ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 128 ".\\sintactico.y"
    {
        char *nombres_identificadores;
        nombres_identificadores = strtok((yyvsp[(3) - (4)].nombre_lista), " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,nombres_identificadores);
                strcpy(p.tipo,"N/A");
                strcpy(yylval.ambito,(yyvsp[(2) - (4)].nombre));
                strcpy(p.ambito, yylval.ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 147 ".\\sintactico.y"
    {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok((yyvsp[(3) - (3)].tipo), " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,(yyvsp[(1) - (3)].nombre_lista));
                strcpy(p.tipo,(yyvsp[(3) - (3)].tipo));
                strcpy(p.ambito,ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 162 ".\\sintactico.y"
    {
        /*Añade una nueva entrada a la tabla hash*/
        char *nombres_identificadores;
        nombres_identificadores = strtok((yyvsp[(3) - (5)].nombre_lista), " ");
        while (nombres_identificadores)
        {
                identidad p = {.nombre="", .tipo = "", .fila_declaracion=yylval.aux.fila_declaracion, .filas_uso = yylval.aux.fila_declaracion, .ambito= ""};
                strcpy(p.nombre,nombres_identificadores);
                strcpy(p.tipo,(yyvsp[(5) - (5)].tipo));
                strcpy(p.ambito, ambito);
                hash_table_insert(&p); 
                print_table();
                nombres_identificadores=strtok(NULL, " ");
        }
       
        ;}
    break;



/* Line 1455 of yacc.c  */
#line 1733 "sintactico.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 229 ".\\sintactico.y"


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

