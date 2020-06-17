
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
#line 1 "sintactico.y"

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
  int vectorLetTipoDatos[999];

  /* Funciones */
  int yyerror(char* mensaje);
  void validarAsignacionDeTipos();
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
/*punteros y esas cosas para operaciones*/
int factorPointer;
int terminoPointer;
int operacionPointer;
int asigPointer;
char * cadenaAsigString;
t_pila pilaOperaciones;
t_pila pilaTerminos;
t_pila pilaSaltosAnd;

/*punteros y esas cosas para el LET*/
int tercetoID;
int tercetoOperacion;
t_pila pilaIdsLet;
t_pila pilaOperacionesLet;
void crearTercetosLet();

/*punteros y esas cosas para GET*/
int numeroGET;

/*punteros y esas cosas para comparaciones y ANDS y todas esas cosas*/
int esBetween=0;
int vectorComparaciones [999];
int contadorComparaciones = 0;
int tipoSaltoPalOr;
int posicionACompletarOr;
char * cadenaIDBetween;
int cmpPointer;
t_pila condPila; //pila para los numeros de tercetos donde tendriamos que completar con las condiciones
t_pila pilaSaltos;
t_pila pilaBtw;
int condicionPointer;
int tipoSaltoPalOr;
int posicionACompletarOrFalso;
int posicionAcompletarOrVerdadero;
int izqPointer;
int derPointer;
void completarTercetosAnd(int);
char * devolverSalto(int );
void completarTercetosBtw();
/*punteros y esas cosas para el IF */
int salto;
int numeroCondicion;
int numeroSalto;
t_pila pilaCompletarAnds;
/*punteros y esas cosas para el while*/
int etiqueta;
int etiquetaWhile;
int numeroTercetoWhile;
int saltoWhile;
char * cadenaEtiq;
char numeroTextoWhile[5];

/*Validación de tipos*/
int ultimoTipoLeido;

/*Cosas para Assembler */
void generaAsm();
void pasarTsAssembler(FILE* fp);
int devolverIndice(char * cadena);
terceto devolverTerceto (char* posicion);


int tipoDatoActual;



/* Line 189 of yacc.c  */
#line 247 "y.tab.c"

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
#line 174 "sintactico.y"

    int intval;
    double val;
    char *str_val;



/* Line 214 of yacc.c  */
#line 389 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 401 "y.tab.c"

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
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

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
     106,   107,   112,   120,   121,   134,   136,   137,   142,   143,
     148,   149,   150,   156,   157,   158,   164,   165,   166,   172,
     173,   174,   180,   181,   182,   188,   189,   190,   196,   197,
     198,   205,   206,   207,   214,   215,   216,   223,   224,   225,
     232,   233,   234,   241,   242,   243,   250,   252,   253,   262,
     263,   264,   265,   279,   286,   290,   292,   293,   296,   297,
     302,   304,   307,   310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    52,    53,    61,    -1,    -1,    14,
      54,    55,    13,    -1,    55,    56,    -1,    56,    -1,    -1,
       7,    57,    12,    60,    -1,    -1,     9,    58,    12,    60,
      -1,    -1,     8,    59,    12,    60,    -1,    60,    10,     3,
      -1,     3,    -1,    -1,    62,    19,    63,    20,    -1,    64,
      -1,    63,    64,    -1,    65,    -1,    72,    -1,   102,    -1,
     108,    -1,   113,    -1,   114,    -1,   115,    -1,    -1,     3,
      18,    66,    68,    -1,    -1,     3,    18,    67,     6,    -1,
      68,    23,    69,    -1,    68,    24,    69,    -1,    69,    -1,
      69,    25,    70,    -1,    69,    26,    70,    -1,    70,    -1,
       3,    -1,     4,    -1,     5,    -1,    -1,    21,    71,    68,
      22,    -1,    27,    21,    74,    22,    29,    63,    30,    -1,
      -1,    27,    21,    74,    22,    29,    63,    30,    28,    73,
      29,    63,    30,    -1,    77,    -1,    -1,    77,    75,    31,
      77,    -1,    -1,    77,    76,    32,    77,    -1,    -1,    -1,
      68,    78,    35,    79,    68,    -1,    -1,    -1,    68,    80,
      36,    81,    68,    -1,    -1,    -1,    68,    82,    37,    83,
      68,    -1,    -1,    -1,    68,    84,    38,    85,    68,    -1,
      -1,    -1,    68,    86,    39,    87,    68,    -1,    -1,    -1,
      68,    88,    40,    89,    68,    -1,    -1,    -1,    33,    68,
      90,    35,    91,    68,    -1,    -1,    -1,    33,    68,    92,
      36,    93,    68,    -1,    -1,    -1,    33,    68,    94,    37,
      95,    68,    -1,    -1,    -1,    33,    68,    96,    38,    97,
      68,    -1,    -1,    -1,    33,    68,    98,    39,    99,    68,
      -1,    -1,    -1,    33,    68,   100,    40,   101,    68,    -1,
     104,    -1,    -1,    34,   103,    21,    74,    22,    29,    63,
      30,    -1,    -1,    -1,    -1,    41,    21,     3,   105,    11,
      42,    68,   106,    10,    68,   107,    43,    22,    -1,    44,
     109,    45,    21,   110,    22,    -1,   109,    11,     3,    -1,
       3,    -1,    -1,   111,    68,    -1,    -1,   110,    10,   112,
      68,    -1,    17,    -1,    48,     3,    -1,    49,     6,    -1,
      49,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   198,   198,   198,   200,   200,   202,   202,   204,   204,
     205,   205,   206,   206,   209,   213,   218,   218,   220,   220,
     222,   222,   222,   222,   222,   222,   222,   224,   224,   238,
     238,   255,   258,   261,   265,   268,   271,   273,   302,   316,
     324,   324,   333,   341,   341,   357,   368,   368,   387,   387,
     408,   408,   408,   411,   411,   411,   412,   412,   412,   413,
     413,   413,   414,   414,   414,   415,   415,   415,   416,   416,
     416,   417,   417,   417,   418,   418,   418,   419,   419,   419,
     420,   420,   420,   421,   421,   421,   422,   424,   424,   446,
     450,   457,   446,   466,   471,   478,   486,   486,   494,   494,
     500,   502,   507,   510
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
  "$@10", "condicion", "$@11", "$@12", "comparacion", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "$@24", "$@25", "$@26", "$@27", "$@28", "$@29", "$@30", "$@31", "$@32",
  "$@33", "$@34", "$@35", "$@36", "repeticion", "$@37", "between", "$@38",
  "$@39", "$@40", "asignacionlet", "lista_var", "lista_valores", "$@41",
  "$@42", "comentarios", "ingreso", "egreso", 0
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
      71,    70,    72,    73,    72,    74,    75,    74,    76,    74,
      78,    79,    77,    80,    81,    77,    82,    83,    77,    84,
      85,    77,    86,    87,    77,    88,    89,    77,    90,    91,
      77,    92,    93,    77,    94,    95,    77,    96,    97,    77,
      98,    99,    77,   100,   101,    77,    77,   103,   102,   105,
     106,   107,   104,   108,   109,   109,   111,   110,   112,   110,
     113,   114,   115,   115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     4,     2,     1,     0,     4,
       0,     4,     0,     4,     3,     1,     0,     4,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     3,     3,     1,     3,     3,     1,     1,     1,     1,
       0,     4,     7,     0,    12,     1,     0,     4,     0,     4,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       6,     0,     0,     6,     0,     0,     6,     0,     0,     6,
       0,     0,     6,     0,     0,     6,     1,     0,     8,     0,
       0,     0,    13,     6,     3,     1,     0,     2,     0,     4,
       1,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     4,    16,     0,     3,     0,     8,
      12,    10,     0,     7,     0,     0,     0,     0,     5,     6,
       0,   100,     0,    87,     0,     0,     0,     0,    18,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,    27,
       0,     0,    95,     0,   101,   103,   102,    17,    19,    15,
       9,    13,    11,     0,     0,    37,    38,    39,    40,     0,
       0,    50,    33,    36,     0,    45,    86,     0,     0,     0,
       0,    28,    30,     0,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    96,    14,     0,     0,     0,     0,     0,     0,     0,
      89,    31,    32,    51,    54,    57,    60,    63,    66,    34,
      35,     0,     0,     0,     0,     0,     0,    41,    69,    72,
      75,    78,    81,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    49,     0,    98,    93,    97,     0,     0,
       0,     0,     0,     0,     0,    52,    55,    58,    61,    64,
      67,    42,     0,     0,    70,    73,    76,    79,    82,    85,
       0,    43,    88,    99,    90,     0,     0,     0,     0,     0,
      91,    44,     0,     0,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    12,    13,    15,    17,    16,
      50,     7,     8,    27,    28,    29,    53,    54,    61,    62,
      63,    73,    30,   165,    64,    87,    88,    65,    78,   125,
      79,   126,    80,   127,    81,   128,    82,   129,    83,   130,
      94,   138,    95,   139,    96,   140,    97,   141,    98,   142,
      99,   143,    31,    41,    66,   124,   166,   172,    32,    43,
     115,   116,   153,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
    -110,     4,    -1,  -110,  -110,  -110,    15,  -110,     7,  -110,
    -110,  -110,   119,  -110,    36,     3,    19,    23,  -110,  -110,
      34,  -110,    12,  -110,    51,    53,     6,     0,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,    76,    76,    76,    31,
      62,    79,  -110,    -3,  -110,  -110,  -110,  -110,  -110,  -110,
      92,    92,    92,    89,   101,  -110,  -110,  -110,  -110,    89,
      88,    75,   -15,  -110,    95,    37,  -110,    62,   132,   115,
     134,    48,  -110,    89,    82,   135,    89,    89,   104,   105,
     103,   106,   108,   109,    89,    89,   114,   117,   113,   124,
    -110,  -110,  -110,   107,   116,   118,   120,   112,   121,   122,
    -110,   -15,   -15,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,    36,    62,    62,   123,    -4,    89,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,   142,    89,    89,    89,    89,    89,
      89,     2,  -110,  -110,    36,  -110,  -110,    48,    89,    89,
      89,    89,    89,    89,   125,    48,    48,    48,    48,    48,
      48,   127,    11,    89,    48,    48,    48,    48,    48,    48,
      89,  -110,  -110,    48,    48,   129,   146,    36,    89,    13,
      48,  -110,   126,   137,  -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,  -110,  -110,  -110,   149,  -110,  -110,  -110,
      44,  -110,  -110,  -109,   -27,  -110,  -110,  -110,   -52,    20,
      39,  -110,  -110,  -110,    96,  -110,  -110,    21,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      48,    71,   131,    20,     3,    20,   135,    74,    68,    45,
      84,    85,    46,     4,    20,    36,    20,    21,   136,    21,
      47,    93,     9,    10,    11,   152,    14,    22,    21,    22,
      21,    37,   151,    40,    23,    38,    23,   -29,    22,    20,
      22,   162,    69,   171,    24,    23,    24,    23,    25,    26,
      25,    26,    39,    21,    42,    24,    44,    24,   169,    25,
      26,    25,    26,    22,   137,    55,    56,    57,   -46,   -48,
      23,    76,    77,   145,   146,   147,   148,   149,   150,    49,
      24,    51,    52,    58,    25,    26,   154,   155,   156,   157,
     158,   159,    55,    56,    57,    59,   101,   102,    76,    77,
      67,   163,    70,    60,    48,    76,    77,    72,   164,    75,
      58,   -53,   -56,   -59,   -62,   -65,   170,    86,   -71,   -74,
     -77,   -80,   -83,   109,   110,    48,     9,    10,    11,   117,
      76,    77,    18,   132,   133,    90,    91,    92,   100,   103,
     105,   104,    48,   111,   106,   113,   114,   107,   112,   108,
     121,   118,   134,   144,   119,   161,   168,   120,   167,   174,
     122,    19,   123,    89,     0,     0,     0,   160,     0,   173
};

static const yytype_int16 yycheck[] =
{
      27,    53,   111,     3,     0,     3,    10,    59,    11,     3,
      25,    26,     6,    14,     3,    12,     3,    17,    22,    17,
      20,    73,     7,     8,     9,   134,    19,    27,    17,    27,
      17,    12,    30,    21,    34,    12,    34,     6,    27,     3,
      27,    30,    45,    30,    44,    34,    44,    34,    48,    49,
      48,    49,    18,    17,     3,    44,     3,    44,   167,    48,
      49,    48,    49,    27,   116,     3,     4,     5,    31,    32,
      34,    23,    24,   125,   126,   127,   128,   129,   130,     3,
      44,    37,    38,    21,    48,    49,   138,   139,   140,   141,
     142,   143,     3,     4,     5,    33,    76,    77,    23,    24,
      21,   153,    10,    41,   131,    23,    24,     6,   160,    21,
      21,    36,    37,    38,    39,    40,   168,    22,    36,    37,
      38,    39,    40,    84,    85,   152,     7,     8,     9,    22,
      23,    24,    13,   112,   113,     3,    21,     3,     3,    35,
      37,    36,   169,    29,    38,    32,    22,    39,    31,    40,
      38,    35,    29,    11,    36,    28,    10,    37,    29,    22,
      39,    12,    40,    67,    -1,    -1,    -1,    42,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,    14,    53,    54,    61,    62,     7,
       8,     9,    55,    56,    19,    57,    59,    58,    13,    56,
       3,    17,    27,    34,    44,    48,    49,    63,    64,    65,
      72,   102,   108,   113,   114,   115,    12,    12,    12,    18,
      21,   103,     3,   109,     3,     3,     6,    20,    64,     3,
      60,    60,    60,    66,    67,     3,     4,     5,    21,    33,
      41,    68,    69,    70,    74,    77,   104,    21,    11,    45,
      10,    68,     6,    71,    68,    21,    23,    24,    78,    80,
      82,    84,    86,    88,    25,    26,    22,    75,    76,    74,
       3,    21,     3,    68,    90,    92,    94,    96,    98,   100,
       3,    69,    69,    35,    36,    37,    38,    39,    40,    70,
      70,    29,    31,    32,    22,   110,   111,    22,    35,    36,
      37,    38,    39,    40,   105,    79,    81,    83,    85,    87,
      89,    63,    77,    77,    29,    10,    22,    68,    91,    93,
      95,    97,    99,   101,    11,    68,    68,    68,    68,    68,
      68,    30,    63,   112,    68,    68,    68,    68,    68,    68,
      42,    28,    30,    68,    68,    73,   106,    29,    10,    63,
      68,    30,   107,    43,    22
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
#line 198 "sintactico.y"
    {printf("Inicio compilador\n");}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 198 "sintactico.y"
    {guardarTabla(); guardarTercetosEnArchivo("tercetos.txt"); generaAsm(); printf("fin compilador\n");}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 200 "sintactico.y"
    {printf("Inicio de declaraciones:\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 200 "sintactico.y"
    {printf("fin de declaraciones\n"); agregarTiposDatosATabla();}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 204 "sintactico.y"
    {tipoDatoADeclarar = Int;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 204 "sintactico.y"
    {printf("Declaracion de variables enteras\n");}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 205 "sintactico.y"
    {tipoDatoADeclarar = Real;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 205 "sintactico.y"
    {printf("Declaracion de variables reales\n"); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 206 "sintactico.y"
    {tipoDatoADeclarar = String;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 206 "sintactico.y"
    {printf("Declaracion de variables string\n");}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 209 "sintactico.y"
    {printf("Variable a declarar recursivamente: %s\n",yylval.str_val );
                                        lineaEnTablaAuxSimbolo((yyvsp[(3) - (3)].str_val));
                                        grabarLineaEnTablaAuxSimbolo();
                                        }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 213 "sintactico.y"
    {printf("Variable a declarar: %s\n",yylval.str_val );
                                        lineaEnTablaAuxSimbolo((yyvsp[(1) - (1)].str_val));
                                        grabarLineaEnTablaAuxSimbolo();
                                        }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 218 "sintactico.y"
    {printf("Inicio del programa\n");}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 218 "sintactico.y"
    {printf("fin del programa\n");}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 224 "sintactico.y"
    {
                           cadenaAsigString = malloc(sizeof(char) * strlen((yyvsp[(1) - (2)].str_val)));
                           parsearCadena((yyvsp[(1) - (2)].str_val),cadenaAsigString);
                           ultimoTipoLeido = getTipoPorID(cadenaAsigString);
                          
                           
                        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 232 "sintactico.y"
    {printf("asignacion a operacion\n");
                        validarAsignacionDeTipos();
                        asigPointer = crearTerceto("=",cadenaAsigString,crearIndice(operacionPointer));
                        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 238 "sintactico.y"
    {
              
              cadenaAsigString = malloc(sizeof(char) * strlen((yyvsp[(1) - (2)].str_val)));
              parsearCadena((yyvsp[(1) - (2)].str_val),cadenaAsigString);
              printf("La cadena es: %s \n",cadenaAsigString);
             ultimoTipoLeido = getTipoPorID(cadenaAsigString);
             
            }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 245 "sintactico.y"
    {
            
              printf( "asignacion a STRING: %s\n", yylval.str_val);
              tipoDatoActual = String; 
                                   validarAsignacionDeTipos();
                                    agregarCteStringATabla(yylval.str_val);
                                    asigPointer=crearTerceto("=",cadenaAsigString,yylval.str_val);
                                   }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 255 "sintactico.y"
    {printf("Suma OK\n");
                                      operacionPointer = crearTerceto("+",crearIndice(operacionPointer),crearIndice(terminoPointer));
                                     }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 258 "sintactico.y"
    {printf("Resta OK\n");
                                       operacionPointer = crearTerceto("-",crearIndice(operacionPointer),crearIndice(terminoPointer));
                                      }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 261 "sintactico.y"
    {printf("Operacion es termino\n");
                    operacionPointer = terminoPointer;
           }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 265 "sintactico.y"
    {printf("Termino es multiplicacion OK\n");
                                terminoPointer = crearTerceto("*",crearIndice(terminoPointer),crearIndice(factorPointer));
         }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 268 "sintactico.y"
    {printf("Termino es division\n");
         terminoPointer= crearTerceto("/",crearIndice(terminoPointer),crearIndice(factorPointer));
         }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 271 "sintactico.y"
    {printf("termino es factor\n"); terminoPointer = factorPointer;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 273 "sintactico.y"
    {printf("factor es ID: %s\n",(yyvsp[(1) - (1)].str_val) ); 
           
            int tipoDato = getTipoPorID((yyvsp[(1) - (1)].str_val));
            if (tipoDato == String){
              yyerror("Error en asignacion");

            }
            
            if(tipoDato == Int && tipoDatoActual == Int){
              tipoDatoActual = Int;
              }

              if(tipoDatoActual == Real && tipoDato == Int){
                tipoDatoActual = Real;
               }

               if(tipoDato == Real && tipoDatoActual == Real){

                 tipoDatoActual = Real;
               }

              if(tipoDato == Real && tipoDatoActual == Int){

                  tipoDatoActual = Real;

              }

            factorPointer=crearTerceto((yyvsp[(1) - (1)].str_val),"","");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 302 "sintactico.y"
    {
                      if(tipoDatoActual=Real){
                        tipoDatoActual = Real;
                      }
                      else{
                      tipoDatoActual = Int; 
                      }

                     // validarAsignacionDeTipos();
                      printf("factor es entero: %d \n",(yyvsp[(1) - (1)].intval));agregarCteIntATabla(yylval.intval); 
                      char *cadena = (char *)malloc (sizeof (int));
                      itoa((yyvsp[(1) - (1)].intval),cadena,10);
                      factorPointer=crearTerceto(cadena,"","");
                      }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 316 "sintactico.y"
    {
                       tipoDatoActual = Real; 
                       //validarAsignacionDeTipos();
                       printf("Factor es real: %f \n",(yyvsp[(1) - (1)].val)); agregarCteFloatATabla(yylval.val);
                       char*cadena = (char *)malloc(sizeof(float));
                       ftoa((yyvsp[(1) - (1)].val),cadena,4);
                       factorPointer=crearTerceto(cadena,"","");
                      }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 324 "sintactico.y"
    {
             apilar(&pilaOperaciones,operacionPointer);
             apilar(&pilaTerminos,terminoPointer);
           }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 327 "sintactico.y"
    {printf("factor es operacion entre parentesis\n");
                            factorPointer = crearTerceto(crearIndice(operacionPointer),"","");
                            operacionPointer = desapilar(&pilaOperaciones);
                            terminoPointer = desapilar(&pilaTerminos);
           }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 333 "sintactico.y"
    {printf("IF sin rama falsa\n");
                                                 salto = desapilar(&pilaSaltos); 
												                         numeroCondicion = desapilar(&condPila); 
												                         crearTercetoNumero (devolverSalto(salto), crearIndice(contadorTercetos),"", numeroCondicion);
												                         completarTercetosAnd(contadorTercetos);
                                                 
                                                 
                                                }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 341 "sintactico.y"
    {
            					salto = desapilar(&pilaSaltos); 
											numeroCondicion = desapilar(&condPila); 
											crearTercetoNumero(devolverSalto(salto), crearIndice(contadorTercetos+1),"", numeroCondicion);
											apilar(&condPila,contadorTercetos); 
										  contadorTercetos++;
                      completarTercetosAnd(contadorTercetos);
                      
                      
                      }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 351 "sintactico.y"
    {printf("IF con rama falsa\n"); 
                          numeroSalto = desapilar(&condPila);
                          printf("Numero de salto: %d\n",numeroSalto);
                          crearTercetoNumero("JMP",crearIndice(contadorTercetos),"", numeroSalto);
                            }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 357 "sintactico.y"
    {printf("Comparacion unica\n");
                        if(esBetween==0){
			                    cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
                          apilar(&pilaCompletarAnds,-1);
						              apilar(&condPila, contadorTercetos);
						              contadorTercetos ++; 
						              condicionPointer = cmpPointer;
                          printf("SALGO DE Comparacion unica\n");
						}

          }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 368 "sintactico.y"
    {
            if(esBetween==0){
						  cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
						  apilar(&pilaCompletarAnds,contadorTercetos);
						  //pilar(&condPila, contadorTercetos);
              apilar(&pilaSaltosAnd,desapilar(&pilaSaltos));
						  contadorTercetos ++; 
						  condicionPointer = cmpPointer;
						 }
           }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 379 "sintactico.y"
    {printf("Comparacion con and");
           				             if(esBetween==0){
				                       cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
				                       apilar(&condPila, contadorTercetos);
				                       contadorTercetos ++; 
				                       condicionPointer = cmpPointer;
				 } 
           }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 387 "sintactico.y"
    {
             				if(esBetween==0){
				              cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
                      apilar(&pilaCompletarAnds,-1);
				              tipoSaltoPalOr = desapilar(&pilaSaltos);
				              posicionACompletarOrFalso = contadorTercetos;
				              contadorTercetos++;
				              posicionAcompletarOrVerdadero = contadorTercetos;
				              contadorTercetos++;
				}
           }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 398 "sintactico.y"
    {printf("comparacion por or");
            				           if(esBetween==0){
				                          cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer));
				                          apilar(&condPila, contadorTercetos); 
				                          contadorTercetos ++; 
				                          crearTercetoNumero(devolverSalto(tipoSaltoPalOr),crearIndice(cmpPointer),"",posicionACompletarOrFalso);
				                          crearTercetoNumero("JMP",crearIndice(contadorTercetos),"",posicionAcompletarOrVerdadero);
			                      	}
                            }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 408 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;apilar(&pilaBtw,0);}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 408 "sintactico.y"
    {printf("Comparacion por menor\n"); apilar(&pilaSaltos, 1);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 409 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 411 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 411 "sintactico.y"
    {printf("comparacion por menor o igual\n"); apilar(&pilaSaltos, 5);}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 411 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 412 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 412 "sintactico.y"
    {printf("comparacion por mayor\n");  apilar(&pilaSaltos,2) ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 412 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 413 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 413 "sintactico.y"
    {printf("comparacion por mayor o igual\n"); apilar(&pilaSaltos,4);}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 413 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 414 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 414 "sintactico.y"
    {printf("comparacion por distinto\n"); apilar(&pilaSaltos,6);}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 414 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 415 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 415 "sintactico.y"
    {printf("comparacion por igual\n"); apilar(&pilaSaltos,3); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 415 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 416 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 416 "sintactico.y"
    {printf("Comparacion por menor negada\n"); apilar(&pilaSaltos,4); }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 416 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 417 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 417 "sintactico.y"
    {printf("comparacion por menor o igual negada\n"); apilar(&pilaSaltos,2); }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 417 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 418 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 418 "sintactico.y"
    {printf("comparacion por mayor negada\n"); apilar(&pilaSaltos,5); }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 418 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 419 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 419 "sintactico.y"
    {printf("comparacion por mayor o igual negada \n"); apilar(&pilaSaltos,1); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 419 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 420 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 420 "sintactico.y"
    {printf("comparacion por distinto negada\n"); apilar(&pilaSaltos,3); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 420 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 421 "sintactico.y"
    {izqPointer = operacionPointer; esBetween =0;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 421 "sintactico.y"
    {printf("comparacion por igual negada\n"); apilar(&pilaSaltos,6); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 421 "sintactico.y"
    {derPointer = operacionPointer;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 424 "sintactico.y"
    { 
                     cadenaEtiq = malloc(sizeof (char)* 156);
		                  strcpy(cadenaEtiq,"ETIQ");
                      itoa(etiquetaWhile,numeroTextoWhile,10);
		                  strcat(cadenaEtiq,numeroTextoWhile);
		                  etiquetaWhile++;
		                  etiqueta = crearTerceto(cadenaEtiq,"","");
	                    apilar(&condPila,etiqueta); //Lo pongo aca arriba antes de que se aumente el contador de tercetos */
                  }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 434 "sintactico.y"
    {
              
                                                printf("bucle while\n");
                                               saltoWhile = desapilar(&pilaSaltos); //numero de salto
					                                      numeroTercetoWhile = desapilar(&condPila); //numero de terceto (aca estaría el numero donde deberia ir el terceto del salto si ya no cumple la condicion del while)
					                                      crearTercetoNumero (devolverSalto(saltoWhile), crearIndice(contadorTercetos+1),"", numeroTercetoWhile); //Hago un +2 porque tengo: 1-Terceto de JMP primero
					                                      completarTercetosAnd(contadorTercetos);
					                                      numeroTercetoWhile = desapilar(&condPila); //Desapilo la posicion del inicio del While
					                                      crearTerceto ("JMP", crearIndice(numeroTercetoWhile),"");
            
                                                }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 446 "sintactico.y"
    {esBetween = 1; 
                         
                         cadenaIDBetween = malloc(sizeof(char)*strlen((yyvsp[(3) - (3)].str_val)));
                         strcpy(cadenaIDBetween,(yyvsp[(3) - (3)].str_val));
                        }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 450 "sintactico.y"
    {
																					      crearTerceto("CMP",cadenaIDBetween,crearIndice(operacionPointer));
						                                    apilar(&pilaCompletarAnds,contadorTercetos);
                                                apilar(&pilaSaltosAnd,4);
																					      apilar(&condPila, contadorTercetos);
																					      contadorTercetos ++; 
                                                                            }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 457 "sintactico.y"
    {
                    	     apilar(&pilaSaltos, 5);
		                       cmpPointer = crearTerceto("CMP",cadenaIDBetween,crearIndice(operacionPointer));
		                       apilar(&condPila, contadorTercetos);
		                       contadorTercetos ++; 
		                       condicionPointer = cmpPointer;
         }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 464 "sintactico.y"
    {printf("comparacion con between\n");}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 466 "sintactico.y"
    { if(cantValores != cantVariables){yyerror("Error, no coinciden los argumentos del let con las variables");} 
                                                              printf("lista let\n");
                                                              crearTercetosLet();
                                                              }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 471 "sintactico.y"
    {cantVariables++;printf("Item de la lista del let %s\n",yylval.str_val);
                              vectorLetTipoDatos[cantVariables-1] = getTipoPorID((yyvsp[(3) - (3)].str_val));
                              printf("EL TIPO DE DATOS DEL LET ES: %d \n", vectorLetTipoDatos[cantVariables-1]);
							                tercetoID = crearTerceto(yylval.str_val,"","");
							                apilar(&pilaIdsLet,tercetoID);
                            }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 478 "sintactico.y"
    {cantVariables++;
              vectorLetTipoDatos[cantVariables-1] = getTipoPorID((yyvsp[(1) - (1)].str_val));
              
               printf("Item de la lista del let %s\n",yylval.str_val);
               tercetoID = crearTerceto(yylval.str_val,"",""); 
			         apilar(&pilaIdsLet,tercetoID);
              }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 486 "sintactico.y"
    {ultimoTipoLeido =  vectorLetTipoDatos[cantValores];}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 486 "sintactico.y"
    {cantValores++;
                          
                         printf("argumento del let es operacion \n");
                         tercetoOperacion = operacionPointer;
						             apilar(&pilaOperacionesLet,tercetoOperacion);
                        }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 494 "sintactico.y"
    {ultimoTipoLeido =  vectorLetTipoDatos[cantValores];}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 494 "sintactico.y"
    {cantValores++;
                                                   printf("argumento del let es operacion \n");
                                                   tercetoOperacion = operacionPointer;
						                                       apilar(&pilaOperacionesLet,tercetoOperacion);
                                                  }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 500 "sintactico.y"
    {printf("Se muestra un comentario: \n");}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 502 "sintactico.y"
    {printf("Ingreso de datos\n");
                numeroGET = crearTerceto((yyvsp[(2) - (2)].str_val),"","");
				        crearTerceto("GET",crearIndice(numeroGET),"");
               }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 507 "sintactico.y"
    {printf("Salida de string por pantalla\n");agregarCteStringATabla(yylval.str_val);
                            crearTerceto("DISPLAY",yylval.str_val,"");
                            }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 510 "sintactico.y"
    {printf("Salida de variable por pantalla\n");
                    crearTerceto("DISPLAY",(yyvsp[(2) - (2)].str_val),"");
                   }
    break;



/* Line 1455 of yacc.c  */
#line 2620 "y.tab.c"
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
#line 513 "sintactico.y"



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
    crearPila(&pilaIdsLet);
    crearPila(&pilaOperacionesLet);
    crearPila(&condPila);
    crearPila(&pilaSaltos);
    crearPila(&pilaCompletarAnds);
    crearPila(&pilaSaltosAnd);
    crearPila(&pilaBtw);
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
    default:
      return "Invalido";
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

   yyerror("Error: la variable no se encontraba");
   return -1;
}

//Función para buscar por el nombre de la variable, devuelve el valor si lo encuentra, devuelve -1 si no. 
char* getValorPorID(char* name)
{
 int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return tablaSimbolo[i].valorSimbolo;
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

void crearTercetosLet(){
	int numeroID, numeroOperacion;
	while(!pilaVacia(&pilaIdsLet)){
		numeroID = desapilar(&pilaIdsLet);
		numeroOperacion = desapilar(&pilaOperacionesLet);
		crearTerceto("=",crearIndice(numeroID),crearIndice(numeroOperacion));
	}
}

void completarTercetosAnd(int posicion){
  int tipoSalto, numeroTerceto, n;
  numeroTerceto = desapilar(&pilaCompletarAnds);
  if(numeroTerceto != -1){
    tipoSalto = desapilar(&pilaSaltosAnd);
    crearTercetoNumero(devolverSalto(tipoSalto),crearIndice(contadorTercetos),"",numeroTerceto);
  }

}

void validarAsignacionDeTipos() {
  if(tipoDatoActual != ultimoTipoLeido) {
    yyerror("Asignacion de tipos incorrecta");
  }
}

/**************************************ASSEMBLER****************************************/

void generaAsm(){
int i;
FILE* fp;
fp = fopen("Final.asm","w+t");
terceto aux;
char vectorOperandos[100][100];
int contadorOperandos =0;
int tercetosEtiquetas[1200];
int cantEtiquetas = 0;
fprintf(fp, "include macros2.asm\n");
fprintf(fp, "include number.asm\n"); //Creo que la vamos a necesitar.
fprintf(fp, ".MODEL	LARGE \n");
fprintf(fp, ".386\n");
fprintf(fp, ".STACK 200h \n"); //bytes en stack

//DATA: variables de la tabla de simbolos
fprintf(fp, ".DATA \n");
pasarTsAssembler(fp);
//funcion que pase la TS a este archivo.


//CODE: comienza la seccion de codigo
fprintf(fp, ".CODE \n");
fprintf(fp, "\n");
fprintf(fp, "\t MOV AX,@DATA 	;inicializa el segmento de datos\n");
fprintf(fp, "\t MOV DS,AX \n");
fprintf(fp, "\t MOV ES,AX \n");
fprintf(fp, "\t FNINIT \n");;
fprintf(fp, "\n");

  int opSimple,  // Formato terceto (x,  ,  ) 
	opUnaria,  // Formato terceto (x, x,  )
	opBinaria; // Formato terceto (x, x, x)

//ACA deberia ir la parte de tercetos:
//nos fijamos en que terceto tenemos que poner una etiqueta

for(i=0;i<contadorTercetos;i++){
    if (strcmp(vectorTercetos[i].elementoIzquierda, "") != 0 && strcmp(vectorTercetos[i].elementoDerecha, "") ==0){
      if (strcmp(vectorTercetos[i].primerElemento, "GET") != 0 && strcmp(vectorTercetos[i].primerElemento, "DISPLAY") != 0){
        int repetido=-1,j;
        int indiceEtiqueta = devolverIndice(vectorTercetos[i].elementoIzquierda);
        printf("%d\n",indiceEtiqueta);
        for(j=0;j<cantEtiquetas;j++){
          if(tercetosEtiquetas[j]==indiceEtiqueta){
              repetido =1;
          }
        }
        if(repetido ==-1){
					tercetosEtiquetas[cantEtiquetas] = indiceEtiqueta;
          cantEtiquetas++;
        }
      }
    }
}

//////////EMPEZAMOS A ARMAR LA SECUENCIA DE TERCETOS EN ASSEMBLER //////////////////////////////////////

for(i=0;i<contadorTercetos;i++){
  //vemos si antes que nada tenemos que poner una etiqueta
  int k;
  for(k=0;k<cantEtiquetas;k++){
    if(i == tercetosEtiquetas[k]){
    printf("Aca va una etiqueta man\n");
    fprintf(fp,"SALTO%d: \t ;Etiqueta para los saltos \n",i);
    }
  }
   if(strcmp(vectorTercetos[i].elementoIzquierda,"")==0 && strcmp(vectorTercetos[i].elementoDerecha,"")==0){
     opSimple =1;
     opUnaria=0;
     opBinaria =0;
   }
    if(strcmp(vectorTercetos[i].elementoIzquierda,"")!=0 && strcmp(vectorTercetos[i].elementoDerecha,"")==0){
     opSimple =0;
     opUnaria=1;
     opBinaria =0;
   }
    if(strcmp(vectorTercetos[i].elementoIzquierda,"")!=0 && strcmp(vectorTercetos[i].elementoDerecha,"")!=0){
     opSimple =0;
     opUnaria=0;
     opBinaria =1;
   }
   if(opSimple ==1){
     if(strncmp(vectorTercetos[i].primerElemento, "ETIQ", 4) != 0 ){
       //es una constante o un ID
       strcpy(vectorOperandos[contadorOperandos],vectorTercetos[i].primerElemento);
       contadorOperandos++;
       fprintf(fp, "\t FLD %s \t;Cargo valor \n", vectorTercetos[i].primerElemento);
       printf("Se carga un dato solo\n");
     }
     else{
       fprintf(fp,"%s:\t;ETIQUETA\n",vectorTercetos[i].primerElemento);
       printf("Se pone una etiqueta en el archivo\n");
     }
   }
   if(opUnaria==1){
     //puede ser un get, un display o un salto (creo)
     if (strcmp(vectorTercetos[i].primerElemento, "GET") != 0 && strcmp(vectorTercetos[i].primerElemento, "DISPLAY") != 0){
       //no es ni get ni display, entonces es un salto
       int numeroSalto = devolverIndice(vectorTercetos[i].elementoIzquierda);
       fprintf(fp,"%s SALTO%d \t ;salto a donde tengo que ir \n",vectorTercetos[i].primerElemento,numeroSalto);
     }
     else if (strcmp(vectorTercetos[i].primerElemento, "DISPLAY") == 0){
       printf("Entro al DISPLAY \n");
       int tipo = getTipoPorID(vectorTercetos[i].elementoIzquierda);
       
				if (tipo == Real) 
				{
					fprintf(fp, "\t DisplayFloat %s,2 \n", vectorTercetos[i].elementoIzquierda);
				}
				else if (tipo == Int) 
				{
					fprintf(fp, "\t DisplayFloat %s.0,2 \n", vectorTercetos[i].elementoIzquierda);
				} else 
				{
					fprintf(fp, "\t DisplayString %s \n", vectorTercetos[i].elementoIzquierda);
				}

      
     }
     else if (strcmp(vectorTercetos[i].primerElemento, "GET") == 0)
     {printf("Entro al GET \n");
     terceto tercetito = devolverTerceto(vectorTercetos[i].elementoIzquierda);
          int tipo = getTipoPorID(tercetito.primerElemento);
      
				if (tipo == Real) 
				{
					fprintf(fp, "\t GetFloat %s\n", tercetito.primerElemento);
				}
				else if (tipo == Int) 
				{
					fprintf(fp, "\t GetFloat %s\n", tercetito.primerElemento);
				} else 
				{
					fprintf(fp, "\t GetString %s\n", tercetito.primerElemento);
				}
				
     }
     // Siempre inserto nueva linea despues de mostrar msj
				fprintf(fp, "\t newLine \n");

   }

}
///////////////////////////////////////////////////////////////////////////////////////////////////
//Todavia falta, aca se tienen que pasar los tercetos al txt.
//Final
fprintf(fp, "\t mov AX, 4C00h \t ; Genera la interrupcion 21h\n");
fprintf(fp, "\t int 21h \t ; Genera la interrupcion 21h\n");
fclose(fp);

}

void pasarTsAssembler(FILE* fp){
int i=0;
   while(i<=finDeTabla){
      
    int tipo = tablaSimbolo[i].tipoDato;
    char* cadena = (char *) malloc(sizeof(float));

    switch (tipo){
		case Int:
			fprintf(fp, "\t%s dd ?\t\t\t\t\t\t\t\t\t\t ; Declaracion de Variable Int\n", tablaSimbolo[i].nombre );
			break;
		case Real:
			fprintf(fp, "\t%s dd ?\t\t\t\t\t\t\t\t\t\t ; Declaracion de Variable Real\n", tablaSimbolo[i].nombre );
			break;
		case String:
			fprintf(fp,  "\t%s db 30 dup (?),\"$\"\t\t\t\t\t\t\t\t\t\t;Declaracion de Variable String\n", tablaSimbolo[i].nombre );
			break;
		case CteInt:
				fprintf(fp, "\t%s dd %d.0\t\t\t\t\t\t\t\t\t\t;Declaracion de CTEINT \n", tablaSimbolo[i].nombre, tablaSimbolo[i].limite);
			break;
    case CteFloat:
      ftoa(tablaSimbolo[i].valorFloat,cadena,4);
			if(strstr(cadena,".")){
				fprintf(fp, "\t%s dd %f\t\t\t\t\t\t\t\t\t\t;Declaracion de CTEREAL\n", tablaSimbolo[i].nombre, tablaSimbolo[i].valorFloat);
			}else{
				fprintf(fp, "\t%s dd %f.0\t\t\t\t\t\t\t\t\t\t;Declaracion de CTEREAL\n", tablaSimbolo[i].nombre, tablaSimbolo[i].valorFloat);
      }
			break;
		case CteString:
			fprintf(fp, "\t%s db %s, \"$\", 30 dup (?)\t\t\t\t\t\t\t\t\t\t;Declaracion de CTESTRING\n", tablaSimbolo[i].nombre, &(tablaSimbolo[i].valorSimbolo));
			break;
      
      }
     
     i++;

  }
}

int devolverIndice(char * cadena){
  char destino[4];
  int i =0,cont =0;
  int numeroFinal;
  while(cadena[i]!=']'){
    if(cadena[i]!='['){
      destino[cont]=cadena[i];
      cont++;
    }
    i++;
  }
  destino[cont]='\0';
  numeroFinal = atoi(destino);
  return numeroFinal;
}

char* getCodOp(char* token)
{
	if(!strcmp(token, "+"))
	{
		return "FADD";
	}
	else if(!strcmp(token, "="))
	{
		return "MOV";
	}
	else if(!strcmp(token, "-"))
	{
		return "FSUB";
	}
	else if(!strcmp(token, "*"))
	{
		return "FMUL";
	}
	else if(!strcmp(token, "/"))
	{
		return "FDIV";
	}
	
}

terceto devolverTerceto (char* posicion){
int indice = -1;
indice = devolverIndice(posicion);
printf("INDICE: %d \n",indice);
return vectorTercetos[indice];
}

