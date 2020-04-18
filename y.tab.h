
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
     DOS_PUNTOS = 263,
     ENDEF = 264,
     DEFVAR = 265,
     CONSTINT = 266,
     CONSTREAL = 267,
     OP_ASIG = 268,
     INICIO = 269,
     FIN = 270,
     P_A = 271,
     P_C = 272,
     OP_SUMA = 273,
     OP_RESTA = 274,
     OP_MUL = 275,
     OP_DIV = 276,
     IF = 277,
     ELSE = 278,
     LL_A = 279,
     LL_C = 280,
     OP_COMPARACION = 281,
     OP_AND = 282,
     OP_OR = 283,
     OP_NOT = 284
   };
#endif
/* Tokens.  */
#define ID 258
#define ENTERO 259
#define STRING 260
#define REAL 261
#define PUNTO_COMA 262
#define DOS_PUNTOS 263
#define ENDEF 264
#define DEFVAR 265
#define CONSTINT 266
#define CONSTREAL 267
#define OP_ASIG 268
#define INICIO 269
#define FIN 270
#define P_A 271
#define P_C 272
#define OP_SUMA 273
#define OP_RESTA 274
#define OP_MUL 275
#define OP_DIV 276
#define IF 277
#define ELSE 278
#define LL_A 279
#define LL_C 280
#define OP_COMPARACION 281
#define OP_AND 282
#define OP_OR 283
#define OP_NOT 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


