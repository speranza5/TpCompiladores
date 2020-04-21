
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
     COMILLA = 271,
     ESPACIO = 272,
     TABULACION = 273,
     CARACTERES_ESPECIALES = 274,
     COMENTARIO = 275,
     OP_ASIG = 276,
     INICIO = 277,
     FIN = 278,
     P_A = 279,
     P_C = 280,
     OP_SUMA = 281,
     OP_RESTA = 282,
     OP_MUL = 283,
     OP_DIV = 284,
     IF = 285,
     ELSE = 286,
     LL_A = 287,
     LL_C = 288,
     OP_COMPARACION = 289,
     OP_AND = 290,
     OP_OR = 291,
     OP_NOT = 292,
     WHILE = 293,
     BETWEEN = 294,
     COR_A = 295,
     COR_C = 296,
     LET = 297,
     OP_IGUAL = 298
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
#define COMILLA 271
#define ESPACIO 272
#define TABULACION 273
#define CARACTERES_ESPECIALES 274
#define COMENTARIO 275
#define OP_ASIG 276
#define INICIO 277
#define FIN 278
#define P_A 279
#define P_C 280
#define OP_SUMA 281
#define OP_RESTA 282
#define OP_MUL 283
#define OP_DIV 284
#define IF 285
#define ELSE 286
#define LL_A 287
#define LL_C 288
#define OP_COMPARACION 289
#define OP_AND 290
#define OP_OR 291
#define OP_NOT 292
#define WHILE 293
#define BETWEEN 294
#define COR_A 295
#define COR_C 296
#define LET 297
#define OP_IGUAL 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 12 "semantico.y"

int intval;
double val;
char *str_val;



/* Line 1676 of yacc.c  */
#line 146 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


