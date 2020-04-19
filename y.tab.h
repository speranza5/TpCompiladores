
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
     ENTERO = 259,
     STRING = 260,
     REAL = 261,
     PUNTO_COMA = 262,
     COMA = 263,
     DOS_PUNTOS = 264,
     ENDEF = 265,
     DEFVAR = 266,
     CONSTINT = 267,
     CONSTREAL = 268,
     CONSTSTRING = 269,
     OP_ASIG = 270,
     ERROR = 271,
     TEXTO = 272,
     INICIO = 273,
     FIN = 274,
     P_A = 275,
     P_C = 276,
     OP_SUMA = 277,
     OP_RESTA = 278,
     OP_MUL = 279,
     OP_DIV = 280,
     IF = 281,
     ELSE = 282,
     LL_A = 283,
     LL_C = 284,
     OP_COMPARACION = 285,
     OP_AND = 286,
     OP_OR = 287,
     OP_NOT = 288,
     WHILE = 289
   };
#endif
/* Tokens.  */
#define ID 258
#define ENTERO 259
#define STRING 260
#define REAL 261
#define PUNTO_COMA 262
#define COMA 263
#define DOS_PUNTOS 264
#define ENDEF 265
#define DEFVAR 266
#define CONSTINT 267
#define CONSTREAL 268
#define CONSTSTRING 269
#define OP_ASIG 270
#define ERROR 271
#define TEXTO 272
#define INICIO 273
#define FIN 274
#define P_A 275
#define P_C 276
#define OP_SUMA 277
#define OP_RESTA 278
#define OP_MUL 279
#define OP_DIV 280
#define IF 281
#define ELSE 282
#define LL_A 283
#define LL_C 284
#define OP_COMPARACION 285
#define OP_AND 286
#define OP_OR 287
#define OP_NOT 288
#define WHILE 289




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


