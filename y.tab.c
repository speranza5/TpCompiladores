
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
#line 1 ".\\sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

#define Int 1
#define Real 2
#define String 3
#define CteInt 4
#define CteFloat 5
#define CteString 6
#define TAM_TABLA 300
#define TAM_NOMBRE 33
#define CANT_TERCETOS 2000
#define TAM_PILA 120

int yylex();
int yystopparser=0;
FILE  *yyin;

  /*Para verificar el LET*/
  int cantVariables = 0;
  int cantValores = 0;

  /* Funciones */
  int yyerror(char* mensaje);
  void validarAsignacion(char *id,char *cadena);
  void validarAsignacionInt(char *cadena);
  void agregarVarATabla(char* nombre);
  void agregarTiposDatosATabla(void);
  void agregarCteStringATabla(char* nombre);
  void agregarCteIntATabla(int valor);
  void agregarCteFloatATabla(float valor);
  void chequearVarEnTabla(char* nombre);
  int buscarEnTabla(char * name);
  void escribirNombreEnTabla(char* nombre, int pos);
  void guardarTabla(void);
  void lineaEnTablaAuxSimbolo(char *cadena);
  void grabarLineaEnTablaAuxSimbolo();
  void agregarTipoVariableATabla(char *cadena);
  void formatearCadena(char *s);
  int esPalabra(char aux);
  void eliminarSubCadena(char *cad,char *subcad);
  void trim(char *v);
  int getTipoPorID(char* name);
  char* getValorPorID(char* name);

/*Tabla de simbolos*/
  typedef struct {
    char nombre[TAM_NOMBRE];
    int tipoDato;
    char valorSimbolo[TAM_NOMBRE];
    float valorFloat;
    int limite;
    int longitud;
  } t_simbolo;

  t_simbolo tablaSimbolo[TAM_TABLA];
  t_simbolo tablaParaStrings[TAM_TABLA];
  int finDeTabla = -1;

  /* Para la declaracion de variables y la tabla de simbolos*/
  int varADeclarar = 0;
  int cantVarsADeclarar = 0;
  int tipoDatoADeclarar = 0;
  int cantVariablesADeclarar = 0;
  int cantDeVariablesDeclaradas = 0;
  /* Struct para tercetos y un par de funciones para que funcionen bien*/
  	typedef struct 
  	{	
  		int numeroTerceto;
  		char * primerElemento; //primer elemento del terceto, duh
  		char * elementoIzquierda; //segundo elemento del terceto
  		char * elementoDerecha; //tercer elemento del terceto
  	}terceto;
 terceto vectorTercetos[CANT_TERCETOS];
void reverse(char* str, int len);
 int contadorTercetos = 0; //cada vez que metemos un tercetos aumentamos en uno este contadorcito
 char* crearIndice(int);//recibe un numero entero y lo convierte en un indice, por ejemplo le mando 12 y guarda en el char * "[12]"
 int crearTerceto (char *, char *,char *); //le mandamos los tres strings para crear el terceto. No reciben numeros ni nada, solo strings. 
 										   //la funcion tambien tiene que guardar el terceto creado en el vectorTercetos.
 										   //La posicion en el vector se lo da contadorTercetos. Variable que debe aumentar en 1.
 int crearTercetoNumero(char*, char *, char *, int);//Parecida a la anterior pero crea un terceto con un numero en especifico.
 											       //No aumenta en 1 contadorTercetos.
 												   //La funcion guarda el terceto en el vector en la posicion que recibe por argumento.
int itoaBienPiola(int x, char str[], int d); //recibe un numero y lo convierte a string cosa de que podamos hacer crearTerceto("=","id",itoa(cte));
void ftoa(float n, char* res, int afterpoint); //lo mismo que arriba perri
 void guardarTercetosEnArchivo(char *); //guarda los tercetos en un archivo con el nombre que nosotros le pasemos (creo que en un binaro queda mejor)
 void parsearCadena (char * origen, char * destino);//porque no me voy a poner a ver como anda bison
 /*Struct para usar la dichosa pila y las primitivas de pila*/
  typedef struct 
  {
  	int pila [TAM_PILA];
  	int tope;
  }t_pila;

  void crearPila(t_pila *);
  int pilaLLena(t_pila *);
  int pilaVacia(t_pila *);
  int apilar (t_pila *, int dato);
  int desapilar(t_pila*);

/*Indices y variables auxiliares de aca a abajo. Indiquen de que estructura es cada index o cada auxiliar o les pego un tiro en la rodilla. Atte carlos :D*/
/*punteros y esas mierdas para operaciones*/
int factorPointer;
int terminoPointer;
int operacionPointer;
int asigPointer;
char * cadenaAsigString;
t_pila pilaOperaciones;
t_pila pilaTerminos;



/* Line 189 of yacc.c  */
#line 191 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CONSTINT = 259,
     CONSTREAL = 260,
     CONSTSTRING = 261,
     ENTERO = 262,
     STRING = 263,
     REAL = 264,
     PUNTO_COMA = 265,
     COMA = 266,
     DOS_PUNTOS = 267,
     ENDEF = 268,
     DEFVAR = 269,
     PALABRA = 270,
     TEXTO = 271,
     COMENTARIO = 272,
     OP_ASIG = 273,
     INICIO = 274,
     FIN = 275,
     P_A = 276,
     P_C = 277,
     OP_SUMA = 278,
     OP_RESTA = 279,
     OP_MUL = 280,
     OP_DIV = 281,
     IF = 282,
     ELSE = 283,
     LL_A = 284,
     LL_C = 285,
     OP_AND = 286,
     OP_OR = 287,
     OP_NOT = 288,
     WHILE = 289,
     OP_MENOR = 290,
     OP_MENORIGUAL = 291,
     OP_MAYOR = 292,
     OP_MAYORIGUAL = 293,
     OP_DISTINTO = 294,
     OP_IGUALDAD = 295,
     BETWEEN = 296,
     COR_A = 297,
     COR_C = 298,
     LET = 299,
     OP_IGUAL = 300,
     COM_CIERRE = 301,
     COM_APER = 302,
     GET = 303,
     DISPLAY = 304
   };
#endif
/* Tokens.  */
#define ID 258
#define CONSTINT 259
#define CONSTREAL 260
#define CONSTSTRING 261
#define ENTERO 262
#define STRING 263
#define REAL 264
#define PUNTO_COMA 265
#define COMA 266
#define DOS_PUNTOS 267
#define ENDEF 268
#define DEFVAR 269
#define PALABRA 270
#define TEXTO 271
#define COMENTARIO 272
#define OP_ASIG 273
#define INICIO 274
#define FIN 275
#define P_A 276
#define P_C 277
#define OP_SUMA 278
#define OP_RESTA 279
#define OP_MUL 280
#define OP_DIV 281
#define IF 282
#define ELSE 283
#define LL_A 284
#define LL_C 285
#define OP_AND 286
#define OP_OR 287
#define OP_NOT 288
#define WHILE 289
#define OP_MENOR 290
#define OP_MENORIGUAL 291
#define OP_MAYOR 292
#define OP_MAYORIGUAL 293
#define OP_DISTINTO 294
#define OP_IGUALDAD 295
#define BETWEEN 296
#define COR_A 297
#define COR_C 298
#define LET 299
#define OP_IGUAL 300
#define COM_CIERRE 301
#define COM_APER 302
#define GET 303
#define DISPLAY 304




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 118 ".\\sintactico.y"

    int intval;
    double val;
    char *str_val;



/* Line 214 of yacc.c  */
#line 333 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 345 "y.tab.c"

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    14,    17,    19,    20,
      25,    26,    31,    32,    37,    41,    43,    44,    49,    51,
      54,    56,    58,    60,    62,    64,    66,    68,    69,    74,
      75,    80,    84,    88,    90,    94,    98,   100,   102,   104,
     106,   107,   112,   120,   132,   134,   138,   142,   143,   148,
     149,   154,   155,   160,   161,   166,   167,   172,   173,   178,
     179,   185,   186,   192,   193,   199,   200,   206,   207,   213,
     214,   220,   222,   230,   241,   248,   252,   254,   256,   260,
     262,   265,   268
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    52,    53,    61,    -1,    -1,    14,
      54,    55,    13,    -1,    55,    56,    -1,    56,    -1,    -1,
       7,    57,    12,    60,    -1,    -1,     9,    58,    12,    60,
      -1,    -1,     8,    59,    12,    60,    -1,    60,    10,     3,
      -1,     3,    -1,    -1,    62,    19,    63,    20,    -1,    64,
      -1,    63,    64,    -1,    65,    -1,    72,    -1,    87,    -1,
      89,    -1,    92,    -1,    93,    -1,    94,    -1,    -1,     3,
      18,    66,    68,    -1,    -1,     3,    18,    67,     6,    -1,
      68,    23,    69,    -1,    68,    24,    69,    -1,    69,    -1,
      69,    25,    70,    -1,    69,    26,    70,    -1,    70,    -1,
       3,    -1,     4,    -1,     5,    -1,    -1,    21,    71,    68,
      22,    -1,    27,    21,    73,    22,    29,    63,    30,    -1,
      27,    21,    73,    22,    29,    63,    30,    28,    29,    63,
      30,    -1,    74,    -1,    74,    31,    74,    -1,    74,    32,
      74,    -1,    -1,    68,    35,    75,    68,    -1,    -1,    68,
      36,    76,    68,    -1,    -1,    68,    37,    77,    68,    -1,
      -1,    68,    38,    78,    68,    -1,    -1,    68,    39,    79,
      68,    -1,    -1,    68,    40,    80,    68,    -1,    -1,    33,
      68,    35,    81,    68,    -1,    -1,    33,    68,    36,    82,
      68,    -1,    -1,    33,    68,    37,    83,    68,    -1,    -1,
      33,    68,    38,    84,    68,    -1,    -1,    33,    68,    39,
      85,    68,    -1,    -1,    33,    68,    40,    86,    68,    -1,
      88,    -1,    34,    21,    73,    22,    29,    63,    30,    -1,
      41,    21,     3,    11,    42,    68,    10,    68,    43,    22,
      -1,    44,    90,    45,    21,    91,    22,    -1,    90,    11,
       3,    -1,     3,    -1,    68,    -1,    91,    10,    68,    -1,
      17,    -1,    48,     3,    -1,    49,     6,    -1,    49,     3,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   140,   140,   140,   142,   142,   144,   144,   146,   146,
     147,   147,   148,   148,   151,   155,   160,   160,   162,   162,
     164,   164,   164,   164,   164,   164,   164,   166,   166,   174,
     174,   185,   188,   191,   195,   198,   201,   203,   204,   208,
     213,   213,   222,   223,   225,   225,   225,   227,   227,   228,
     228,   229,   229,   230,   230,   231,   231,   232,   232,   233,
     233,   234,   234,   235,   235,   236,   236,   237,   237,   238,
     238,   239,   241,   243,   245,   247,   249,   251,   253,   255,
     257,   259,   259
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CONSTINT", "CONSTREAL",
  "CONSTSTRING", "ENTERO", "STRING", "REAL", "PUNTO_COMA", "COMA",
  "DOS_PUNTOS", "ENDEF", "DEFVAR", "PALABRA", "TEXTO", "COMENTARIO",
  "OP_ASIG", "INICIO", "FIN", "P_A", "P_C", "OP_SUMA", "OP_RESTA",
  "OP_MUL", "OP_DIV", "IF", "ELSE", "LL_A", "LL_C", "OP_AND", "OP_OR",
  "OP_NOT", "WHILE", "OP_MENOR", "OP_MENORIGUAL", "OP_MAYOR",
  "OP_MAYORIGUAL", "OP_DISTINTO", "OP_IGUALDAD", "BETWEEN", "COR_A",
  "COR_C", "LET", "OP_IGUAL", "COM_CIERRE", "COM_APER", "GET", "DISPLAY",
  "$accept", "programa", "$@1", "declaracion", "$@2",
  "declaraciones_variables", "declaracion_variable", "$@3", "$@4", "$@5",
  "variables", "algoritmo", "$@6", "bloque", "sentencia", "asignacion",
  "$@7", "$@8", "operacion", "termino", "factor", "$@9", "decision",
  "condicion", "comparacion", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "repeticion",
  "between", "asignacionlet", "lista_var", "lista_valores", "comentarios",
  "ingreso", "egreso", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    54,    53,    55,    55,    57,    56,
      58,    56,    59,    56,    60,    60,    62,    61,    63,    63,
      64,    64,    64,    64,    64,    64,    64,    66,    65,    67,
      65,    68,    68,    68,    69,    69,    69,    70,    70,    70,
      71,    70,    72,    72,    73,    73,    73,    75,    74,    76,
      74,    77,    74,    78,    74,    79,    74,    80,    74,    81,
      74,    82,    74,    83,    74,    84,    74,    85,    74,    86,
      74,    74,    87,    88,    89,    90,    90,    91,    91,    92,
      93,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     4,     2,     1,     0,     4,
       0,     4,     0,     4,     3,     1,     0,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       0,     4,     7,    11,     1,     3,     3,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       5,     0,     5,     0,     5,     0,     5,     0,     5,     0,
       5,     1,     7,    10,     6,     3,     1,     1,     3,     1,
       2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     4,    16,     0,     3,     0,     8,
      12,    10,     0,     7,     0,     0,     0,     0,     5,     6,
       0,    79,     0,     0,     0,     0,     0,     0,    18,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
       0,     0,    76,     0,    80,    82,    81,    17,    19,    15,
       9,    13,    11,     0,     0,    37,    38,    39,    40,     0,
       0,     0,    33,    36,     0,    44,    71,     0,     0,     0,
       0,    28,    30,     0,     0,     0,     0,     0,    47,    49,
      51,    53,    55,    57,     0,     0,     0,     0,     0,     0,
      75,     0,    14,     0,    59,    61,    63,    65,    67,    69,
       0,    31,    32,     0,     0,     0,     0,     0,     0,    34,
      35,     0,    45,    46,     0,    77,     0,    41,     0,     0,
       0,     0,     0,     0,     0,    48,    50,    52,    54,    56,
      58,     0,     0,     0,    74,    60,    62,    64,    66,    68,
      70,     0,    42,    72,    78,     0,     0,     0,     0,     0,
       0,     0,    43,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    12,    13,    15,    17,    16,
      50,     7,     8,    27,    28,    29,    53,    54,    61,    62,
      63,    73,    30,    64,    65,   103,   104,   105,   106,   107,
     108,   118,   119,   120,   121,   122,   123,    31,    66,    32,
      43,   116,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -109
static const yytype_int16 yypact[] =
{
    -109,    11,     6,  -109,  -109,  -109,    70,  -109,    -4,  -109,
    -109,  -109,    50,  -109,    81,    12,    15,    20,  -109,  -109,
      23,  -109,    25,    41,    31,    35,    19,    -1,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,    57,    57,    57,    38,
     106,   106,  -109,    -3,  -109,  -109,  -109,  -109,  -109,  -109,
      66,    66,    66,     9,    74,  -109,  -109,  -109,  -109,     9,
      76,    96,    39,  -109,    65,    42,  -109,    90,   111,    95,
     121,    59,  -109,     9,   114,   123,     9,     9,  -109,  -109,
    -109,  -109,  -109,  -109,     9,     9,    99,   106,   106,   115,
    -109,     9,  -109,   118,  -109,  -109,  -109,  -109,  -109,  -109,
     132,    39,    39,     9,     9,     9,     9,     9,     9,  -109,
    -109,    81,  -109,  -109,    81,    59,    -5,  -109,     9,     9,
       9,     9,     9,     9,   103,    59,    59,    59,    59,    59,
      59,     1,    58,     9,  -109,    59,    59,    59,    59,    59,
      59,     9,   120,  -109,    59,    13,   117,     9,    81,   -14,
      69,   133,  -109,  -109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,  -109,  -109,   144,  -109,  -109,  -109,
      53,  -109,  -109,  -108,   -27,  -109,  -109,  -109,   -52,    17,
      16,  -109,  -109,   116,    34,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -30
static const yytype_int16 yytable[] =
{
      48,    71,    20,   131,    20,   133,   132,    74,    68,    76,
      77,     3,    55,    56,    57,    14,    21,   134,    21,    47,
       4,    93,    45,   147,    36,    46,    22,    37,    22,   151,
      58,   142,    38,    23,    42,    23,    76,    77,    44,   115,
     150,    39,    69,    24,   -29,    24,    40,    25,    26,    25,
      26,   125,   126,   127,   128,   129,   130,     9,    10,    11,
      49,    20,    41,    18,    84,    85,   135,   136,   137,   138,
     139,   140,    20,    87,    88,    21,    70,     9,    10,    11,
      72,   144,    76,    77,    20,    22,    21,    86,   143,   145,
      51,    52,    23,   101,   102,   149,    22,    75,    21,   152,
     109,   110,    24,    23,    48,    48,    25,    26,    22,    55,
      56,    57,    89,    24,    90,    23,    91,    25,    26,    76,
      77,   112,   113,    48,    92,    24,   100,    58,   111,    25,
      26,    78,    79,    80,    81,    82,    83,    76,    77,    59,
     117,    76,    77,   124,   114,   141,   148,    60,   146,    94,
      95,    96,    97,    98,    99,   153,    19,    67
};

static const yytype_uint8 yycheck[] =
{
      27,    53,     3,   111,     3,    10,   114,    59,    11,    23,
      24,     0,     3,     4,     5,    19,    17,    22,    17,    20,
      14,    73,     3,    10,    12,     6,    27,    12,    27,    43,
      21,    30,    12,    34,     3,    34,    23,    24,     3,    91,
     148,    18,    45,    44,     6,    44,    21,    48,    49,    48,
      49,   103,   104,   105,   106,   107,   108,     7,     8,     9,
       3,     3,    21,    13,    25,    26,   118,   119,   120,   121,
     122,   123,     3,    31,    32,    17,    10,     7,     8,     9,
       6,   133,    23,    24,     3,    27,    17,    22,    30,   141,
      37,    38,    34,    76,    77,   147,    27,    21,    17,    30,
      84,    85,    44,    34,   131,   132,    48,    49,    27,     3,
       4,     5,    22,    44,     3,    34,    21,    48,    49,    23,
      24,    87,    88,   150,     3,    44,     3,    21,    29,    48,
      49,    35,    36,    37,    38,    39,    40,    23,    24,    33,
      22,    23,    24,    11,    29,    42,    29,    41,    28,    35,
      36,    37,    38,    39,    40,    22,    12,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,    14,    53,    54,    61,    62,     7,
       8,     9,    55,    56,    19,    57,    59,    58,    13,    56,
       3,    17,    27,    34,    44,    48,    49,    63,    64,    65,
      72,    87,    89,    92,    93,    94,    12,    12,    12,    18,
      21,    21,     3,    90,     3,     3,     6,    20,    64,     3,
      60,    60,    60,    66,    67,     3,     4,     5,    21,    33,
      41,    68,    69,    70,    73,    74,    88,    73,    11,    45,
      10,    68,     6,    71,    68,    21,    23,    24,    35,    36,
      37,    38,    39,    40,    25,    26,    22,    31,    32,    22,
       3,    21,     3,    68,    35,    36,    37,    38,    39,    40,
       3,    69,    69,    75,    76,    77,    78,    79,    80,    70,
      70,    29,    74,    74,    29,    68,    91,    22,    81,    82,
      83,    84,    85,    86,    11,    68,    68,    68,    68,    68,
      68,    63,    63,    10,    22,    68,    68,    68,    68,    68,
      68,    42,    30,    30,    68,    68,    28,    10,    29,    68,
      63,    43,    30,    22
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
#line 140 ".\\sintactico.y"
    {printf("Inicio compilador\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 140 ".\\sintactico.y"
    {guardarTabla(); guardarTercetosEnArchivo("tercetos.txt"); printf("fin compilador\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 142 ".\\sintactico.y"
    {printf("Inicio de declaraciones:\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 142 ".\\sintactico.y"
    {printf("fin de declaraciones\n"); agregarTiposDatosATabla();}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 146 ".\\sintactico.y"
    {tipoDatoADeclarar = Int;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 146 ".\\sintactico.y"
    {printf("Declaracion de variables enteras\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 147 ".\\sintactico.y"
    {tipoDatoADeclarar = Real;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 147 ".\\sintactico.y"
    {printf("Declaracion de variables reales\n"); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 148 ".\\sintactico.y"
    {tipoDatoADeclarar = String;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 148 ".\\sintactico.y"
    {printf("Declaracion de variables string\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 151 ".\\sintactico.y"
    {printf("Variable a declarar recursivamente: %s\n",yylval.str_val );
                                        lineaEnTablaAuxSimbolo((yyvsp[(3) - (3)].str_val));
                                        grabarLineaEnTablaAuxSimbolo();
                                        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 155 ".\\sintactico.y"
    {printf("Variable a declarar: %s\n",yylval.str_val );
                                        lineaEnTablaAuxSimbolo((yyvsp[(1) - (1)].str_val));
                                        grabarLineaEnTablaAuxSimbolo();
                                        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 160 ".\\sintactico.y"
    {printf("Inicio del programa\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 160 ".\\sintactico.y"
    {printf("fin del programa\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 166 ".\\sintactico.y"
    {
 
              cadenaAsigString = malloc(sizeof(char) * strlen((yyvsp[(1) - (2)].str_val)));
              parsearCadena((yyvsp[(1) - (2)].str_val),cadenaAsigString);
            }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 171 ".\\sintactico.y"
    {printf("asignacion a operacion\n");
            asigPointer = crearTerceto("=",cadenaAsigString,crearIndice(operacionPointer));
            }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 174 ".\\sintactico.y"
    {
 
              cadenaAsigString = malloc(sizeof(char) * strlen((yyvsp[(1) - (2)].str_val)));
              parsearCadena((yyvsp[(1) - (2)].str_val),cadenaAsigString);
            }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 178 ".\\sintactico.y"
    {
            
              printf( "asignacion a STRING: %s\n", yylval.str_val); agregarCteStringATabla(yylval.str_val);
                                    asigPointer=crearTerceto("=",cadenaAsigString,yylval.str_val);
                                   }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 185 ".\\sintactico.y"
    {printf("Suma OK\n");
                                      operacionPointer = crearTerceto("+",crearIndice(operacionPointer),crearIndice(terminoPointer));
                                     }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 188 ".\\sintactico.y"
    {printf("Resta OK\n");
                                       operacionPointer = crearTerceto("-",crearIndice(operacionPointer),crearIndice(terminoPointer));
                                      }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 191 ".\\sintactico.y"
    {printf("Operacion es termino\n");
                    operacionPointer = terminoPointer;
           }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 195 ".\\sintactico.y"
    {printf("Termino es multiplicacion OK\n");
                                terminoPointer = crearTerceto("*",crearIndice(terminoPointer),crearIndice(factorPointer));
         }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 198 ".\\sintactico.y"
    {printf("Termino es division\n");
         terminoPointer= crearTerceto("/",crearIndice(terminoPointer),crearIndice(factorPointer));
         }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 201 ".\\sintactico.y"
    {printf("termino es factor\n"); terminoPointer = factorPointer;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 203 ".\\sintactico.y"
    {printf("factor es ID: %s\n",(yyvsp[(1) - (1)].str_val) ); factorPointer=crearTerceto((yyvsp[(1) - (1)].str_val),"","");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 204 ".\\sintactico.y"
    {printf("factor es entero: %d \n",(yyvsp[(1) - (1)].intval));agregarCteIntATabla(yylval.intval); 
                      char *cadena = (char *)malloc (sizeof (int));
                      itoa((yyvsp[(1) - (1)].intval),cadena,10);
                      factorPointer=crearTerceto(cadena,"","");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 208 ".\\sintactico.y"
    {printf("Factor es real: %f \n",(yyvsp[(1) - (1)].val)); agregarCteFloatATabla(yylval.val);
                       char*cadena = (char *)malloc(sizeof(float));
                       ftoa((yyvsp[(1) - (1)].val),cadena,4);
                       factorPointer=crearTerceto(cadena,"","");
                      }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 213 ".\\sintactico.y"
    {
             apilar(&pilaOperaciones,operacionPointer);
             apilar(&pilaTerminos,terminoPointer);
           }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 216 ".\\sintactico.y"
    {printf("factor es operacion entre parentesis\n");
                            factorPointer = crearTerceto(crearIndice(operacionPointer),"","");
                            operacionPointer = desapilar(&pilaOperaciones);
                            terminoPointer = desapilar(&pilaTerminos);
           }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 222 ".\\sintactico.y"
    {printf("IF sin rama falsa\n");}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 223 ".\\sintactico.y"
    {printf("IF con rama falsa\n");}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 225 ".\\sintactico.y"
    {printf("Comparacion unica");}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 225 ".\\sintactico.y"
    {printf("Comparacion con and");}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 225 ".\\sintactico.y"
    {printf("comparacion por or");}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 227 ".\\sintactico.y"
    {printf("Comparacion por menor\n");}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 228 ".\\sintactico.y"
    {printf("comparacion por menor o igual\n");}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 229 ".\\sintactico.y"
    {printf("comparacion por mayor\n");}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 230 ".\\sintactico.y"
    {printf("comparacion por mayor o igual\n");}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 231 ".\\sintactico.y"
    {printf("comparacion por distinto\n");}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 232 ".\\sintactico.y"
    {printf("comparacion por igual\n");}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 233 ".\\sintactico.y"
    {printf("Comparacion por menor negada\n");}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 234 ".\\sintactico.y"
    {printf("comparacion por menor o igual negada\n");}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 235 ".\\sintactico.y"
    {printf("comparacion por mayor negada\n");}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 236 ".\\sintactico.y"
    {printf("comparacion por mayor o igual negada \n");}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 237 ".\\sintactico.y"
    {printf("comparacion por distinto negada\n");}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 238 ".\\sintactico.y"
    {printf("comparacion por igual negada\n");}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 241 ".\\sintactico.y"
    {printf("bucle while\n");}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 243 ".\\sintactico.y"
    {printf("comparacion con between\n");}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 245 ".\\sintactico.y"
    { if(cantValores != cantVariables){yyerror("Error, no coinciden los argumentos del let con las variables");} printf("lista let\n");}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 247 ".\\sintactico.y"
    {cantVariables++;printf("Item de la lista del let %s\n",yylval.str_val);}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 249 ".\\sintactico.y"
    {cantVariables++;printf("Item de la lista del let %s\n",yylval.str_val);}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 251 ".\\sintactico.y"
    {cantValores++;printf("argumento del let es operacion \n");}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 253 ".\\sintactico.y"
    {cantValores++;printf("argumento del let es operacion \n");}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 255 ".\\sintactico.y"
    {printf("Se muestra un comentario: \n");}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 257 ".\\sintactico.y"
    {printf("Ingreso de datos\n");}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 259 ".\\sintactico.y"
    {printf("Salida de string por pantalla\n");agregarCteStringATabla(yylval.str_val);}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 259 ".\\sintactico.y"
    {printf("Salida de variable por pantalla\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2130 "y.tab.c"
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
#line 260 ".\\sintactico.y"



int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
    crearPila(&pilaOperaciones);
    crearPila(&pilaTerminos);
	yyparse();
  }
  fclose(yyin);
  return 0;
}

int yyerror(char* mensaje)
 {
  printf("Syntax Error: %s\n", mensaje);
  system ("Pause");
  exit (1);
 }

  /* Tabla de simbolos */
int buscarEnTabla(char * name){
   int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return i;
     }
     i++;
   }
   return -1;
}

void escribirNombreEnTabla(char* nombre, int pos){
  strcpy(tablaSimbolo[pos].nombre, nombre);
}

 void agregarVarATabla(char* nombre){

   if(finDeTabla >= TAM_TABLA - 1){
     printf("Error: No hay mas espacio en la tabla de simbolos.\n");
     system("Pause");
     exit(2);
   }
   if(buscarEnTabla(nombre) == -1){
     finDeTabla++;
     escribirNombreEnTabla(nombre, finDeTabla);
   }
 }

void agregarTiposDatosATabla(){
  int i;
  for(i = 0; i < cantVarsADeclarar; i++){
    tablaSimbolo[varADeclarar + i].tipoDato = tipoDatoADeclarar;
  }
}

void guardarTabla(){
  if(finDeTabla == -1)
    yyerror("No se encontro la tabla de simbolos");

  FILE* arch = fopen("ts.txt", "w+");
  if(!arch){
    printf("No se pudo crear el archivo ts.txt\n");
    return;
  }
  
  int i;
  //printf("ANTES DEL archivo\n");
  fprintf(arch, "%-30s|%-30s|%-30s|%-30s\n","NOMBRE","TIPO","VALOR","LONGITUD");
  fprintf(arch, ".........................................................................................................\n");
  for(i = 0; i <= finDeTabla; i++){
    fprintf(arch, "%-30s", &(tablaSimbolo[i].nombre) );

    if(tablaSimbolo[i].tipoDato == Real)
      fprintf(arch, "|%-30s|%-30s|%-30s","REAL"," -"," -");
        else if(tablaSimbolo[i].tipoDato == Int)
         fprintf(arch, "|%-30s|%-30s|%-30s","INT"," -"," -");
          else if(tablaSimbolo[i].tipoDato == String)
           fprintf(arch, "|%-30s|%-30s|%-30s","STRING"," -"," -");
            else if(tablaSimbolo[i].tipoDato == CteFloat)
             fprintf(arch, "|%-30s|%-30f|%-30s", "CTE_REAL",tablaSimbolo[i].valorFloat," -");
               else if(tablaSimbolo[i].tipoDato == CteInt)
                fprintf(arch, "|%-30s|%-30d|%-30s", "CTE_INT",tablaSimbolo[i].limite," -");
                 else if(tablaSimbolo[i].tipoDato == CteString)
                  fprintf(arch, "|%-30s|%-30s|%-30d", "CTE_STRING",&(tablaSimbolo[i].valorSimbolo), tablaSimbolo[i].longitud);

    fprintf(arch, "\n");
  }
  fclose(arch);
}

void agregarCteStringATabla(char* nombre){
  if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  if(buscarEnTabla(nombre) == -1){
    finDeTabla++;
    escribirNombreEnTabla(nombre, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = CteString;
    int length = strlen(nombre);
    char auxiliar[length];
    strcpy(auxiliar,nombre);
    auxiliar[strlen(auxiliar)-1] = '\0';
    strcpy(tablaSimbolo[finDeTabla].valorSimbolo, auxiliar+1); 
    tablaSimbolo[finDeTabla].longitud = strlen(nombre) - 2;
  }
}

void agregarCteFloatATabla(float valor){
  if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  char nombre[12];
  sprintf(nombre, "_%f", valor);
  if(buscarEnTabla(nombre) == -1){
    finDeTabla++;
    escribirNombreEnTabla(nombre, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = CteFloat;
    tablaSimbolo[finDeTabla].valorFloat = valor;
  }
}

void agregarCteIntATabla(int valor){
  if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  char nombre[30];
  sprintf(nombre, "_%d", valor);
  if(buscarEnTabla(nombre) == -1){
    finDeTabla++;
    escribirNombreEnTabla(nombre, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = CteInt;
    tablaSimbolo[finDeTabla].limite = valor;
  }
}

void lineaEnTablaAuxSimbolo(char *cadena)
{
  strcpy(tablaParaStrings[cantVariablesADeclarar].nombre,cadena); 
  //printf("SE VA A GUARDAR LA CADENA:%s. y su tipo de dato es %d",tablaParaStrings[cantVariablesADeclarar].nombre,tipoDatoADeclarar);
  cantVariablesADeclarar++;
}

void grabarLineaEnTablaAuxSimbolo()
{
  //printf("\n\n\nTIPO DE DATO A DECLARAR ES:%d.\n\n\n",tipoDatoADeclarar);
  //printf("A GUARDAR:%s:\n",tablaParaStrings[cantVariablesADeclarar-1].nombre);

  char *token = strtok(tablaParaStrings[cantVariablesADeclarar-1].nombre,";");

  int j;
  for(j = 0; token != NULL; j++){

    strcpy(tablaParaStrings[cantDeVariablesDeclaradas].nombre,token);
   //printf("Token: %s---%d\n", token,j);
    token = strtok(NULL, ";");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"ENDEF");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"STRING");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"FLOAT");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"INT");
    agregarTipoVariableATabla(tablaParaStrings[cantDeVariablesDeclaradas].nombre);

    cantDeVariablesDeclaradas++;
    }
  cantVariablesADeclarar=0;
}

void agregarTipoVariableATabla(char *cadena){
 if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  trim(cadena);
  formatearCadena(cadena);
  if(buscarEnTabla(cadena) == -1){
    finDeTabla++;
    escribirNombreEnTabla(cadena, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = tipoDatoADeclarar;
    int length = strlen(cadena);
    char auxiliar[length];
    strcpy(auxiliar,cadena);
    auxiliar[strlen(auxiliar)-1] = '\0';
    strcpy(tablaSimbolo[finDeTabla].valorSimbolo, auxiliar+1); 
    tablaSimbolo[finDeTabla].longitud = strlen(cadena) - 2;
  }
}

void formatearCadena(char *s) {
  
char *aux;
char *aux2;
aux = aux2 = s;

    while(*aux=*aux2++)
        if(esPalabra(*aux) || *aux == ' ')
            aux++;
}   

int esPalabra(char aux)
{
    return ((aux >= 'A' && aux <= 'Z')||(aux >= 'a' && aux <= 'z')||(aux >= '0' && aux <= '9'))? 1 : 0 ;
}

void trim(char *v)
{
    char *aux;
    aux = v;
    int i=0;

    while (*aux)
    {
    if((*aux ==' '))
    {
    *aux='.';

    }
    aux++;
    }
}

void eliminarSubCadena(char *cad,char *subcad)
{
    char *pl1=cad;
    char *pl2=subcad;
    char *dest=cad;
    char*ant;

    while(*pl1)
    {
        ant=subcad;
        while(*pl1==*pl2&&*pl2)
        {
            pl1++;
            pl2++;
        }
        if(*pl2=='\0')
            subcad=ant;
        *dest=*pl1;
        dest++;
        pl1++;
    }
}

//Las funciones de pila:

void crearPila( t_pila *p){
    p->tope = 0;
}

int pilaLLena( t_pila *p ){
    return p->tope == TAM_PILA;
}

int pilaVacia( t_pila *p){
    return p->tope == 0; //Verificar
}

int apilar(t_pila *p, int dato){
    if( p->tope == TAM_PILA){
        return 0;
    }
    p->pila[p->tope] = dato;
    p->tope++;
    return 1;
}

int desapilar(t_pila *p){
    if( p->tope == 0){
        return 0;
    }
    p->tope--;
    return p->pila[p->tope];
}

//TERCETOS

char* crearIndice(int num){

char * resultado = (char*)malloc(sizeof(char)*7);
char numeroTexto [4];

	strcpy(resultado,"[");
	itoa(num,numeroTexto,10);
    strcat(resultado,numeroTexto);
	strcat(resultado,"]");
    return resultado;
}

int crearTerceto (char * primero, char *izquierda,char *derecha){//le mandamos los tres strings para crear el terceto. No reciben numeros ni nada, solo strings. 
                                            //la funcion tambien tiene que guardar el terceto creado en el vectorTercetos.
                                           //La posicion en el vector se lo da contadorTercetos. Variable que debe aumentar en 1.
  terceto nuevo;
  nuevo.primerElemento = malloc(sizeof(char)*strlen(primero)+1);
  strcpy(nuevo.primerElemento,primero);
  nuevo.elementoIzquierda = malloc(sizeof(char)*strlen(izquierda)+1);
  strcpy(nuevo.elementoIzquierda,izquierda);
  nuevo.elementoDerecha = malloc(sizeof(char)*strlen(derecha)+1);
  strcpy(nuevo.elementoDerecha,derecha);
  nuevo.numeroTerceto = contadorTercetos;
  //printf("%d %s %s %s\n",nuevo.numeroTerceto,nuevo.primerElemento,nuevo.elementoIzquierda,nuevo.elementoDerecha);
  vectorTercetos[contadorTercetos] = nuevo;
  contadorTercetos++;
  return nuevo.numeroTerceto;
} 
int crearTercetoNumero(char* primero, char * izquierda, char *derecha, int numero){
  terceto nuevo;
  nuevo.primerElemento = malloc(sizeof(char)*strlen(primero)+1);
  strcpy(nuevo.primerElemento,primero);
  nuevo.elementoIzquierda = malloc(sizeof(char)*strlen(izquierda)+1);
  strcpy(nuevo.elementoIzquierda,izquierda);
  nuevo.elementoDerecha = malloc(sizeof(char)*strlen(derecha)+1);
  strcpy(nuevo.elementoDerecha,derecha);
  nuevo.numeroTerceto = numero;
  vectorTercetos[numero] = nuevo;
  return nuevo.numeroTerceto;
}//Parecida a la anterior pero crea un terceto con un numero en especifico.
                             //No aumenta en 1 contadorTercetos.
                           //La funcion guarda el terceto en el vector en la posicion que recibe por argumento.

void reverse(char* str, int len) 
{ 
    int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
} 
  
// Convierte el entero dado a un string str[].  
// d es el numero de digitos requridos en la salida.  
// Si d es mas que el numero de digitos en x entonces ceros son agregados al principio. 
int itoaBienPiola(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
  
    // Si un numero de digitos es mayor entonces agrega ceros al principio 
    while (i < d) 
        str[i++] = '0'; 
  
    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 
  
// Convierte un float/double a un string 
void ftoa(float n, char* res, int afterpoint) 
{ 
    // Saca la parte entera 
    int ipart = (int)n; 
  
    // Extrae la parte flotante
    float fpart = n - (float)ipart; 
  
    // Convierte la parte entera en string
    int i = itoaBienPiola(ipart, res, 0); 
  
    if (afterpoint != 0) { 
        res[i] = '.'; // add dot 
        fpart = fpart * pow(10, afterpoint); 
  
        itoaBienPiola((int)fpart, res + i + 1, afterpoint); 
    } 
} 
void guardarTercetosEnArchivo(char *nombreArchivo){//guarda los tercetos en un archivo con el nombre que nosotros le pasemos (creo que en un binaro queda mejor)
  int i;
  FILE * fp;
  fp = fopen(nombreArchivo,"w+t");
  terceto aux;
  for (i=0;i<contadorTercetos;i++){
    aux = vectorTercetos[i];
    fprintf(fp,"%d (%s,%s,%s) \n",aux.numeroTerceto,aux.primerElemento,aux.elementoIzquierda,aux.elementoDerecha);
  }
  fclose(fp);
} 

char * devolverSalto(int numero){
	switch (numero){
  
		case 1:
			return "JNAE";
			break;
		case 2:
			return "JNBE";
			break;
		case 3:
			return "JNE";
			break;
		case 4:
			return "JNB";
			break;
		case 5:
			return "JNA";
			break;
		case 6:
			return "JE";
			break;
	}
}

 

//Función para buscar por el nombre de la variable, devuelve un int correspondiente al tipo de dato si lo encuentra
/*
#define Int 1
#define Real 2
#define String 3
#define CteInt 4
#define CteFloat 5
#define CteString 6
*/
//devuelve -1 si no
int getTipoPorID(char* name)
{
   int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return tablaSimbolo[i].tipoDato;
     }
     i++;
   }
   return -1;
}

//Función para buscar por el nombre de la variable, devuelve el valor si lo encuentra, devuelve -1 si no. 
char* getValorPorID(char* name)
{
 int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return tablaSimbolo[i].valorSimbolo; // No devuelve el float, ojo
     }
     i++;
   }
   return NULL;
}

void parsearCadena (char * origen, char * destino){
  int i=0,contDestino=0;
  while(origen[i]!=' ' && origen[i]!=':'){
    destino[i]=origen[i];
    i++;
  }
  destino[i]='\0';
}
