
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

/* Line 1676 of yacc.c  */
#line 172 ".\\sintactico.y"

    int intval;
    double val;
    char *str_val;



/* Line 1676 of yacc.c  */
#line 158 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


