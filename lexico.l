%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
FILE  *yyin;
int yylval;

%}
%option noyywrap  
%option yylineno 

DIGITO			[0-9]
LETRA			[a-zA-Z]

CONSTINT			{DIGITO}+
CONSTREAL			{DIGITO}*"."{DIGITO}+

ID			{LETRA}({LETRA}|{DIGITO}|_)*

%%
"DEFVAR"		{ return DEFVAR;}
"ENDEF"			{return ENDEF;}
":="			{return OP_ASIG;}
":"			{return DOS_PUNTOS;}
";"			{return PUNTO_COMA;}
"FLOAT"			{return REAL;}
"STRING"			{return STRING;}
"INT"			{return ENTERO;}
"BEGIN"			{return INICIO;}
"END"			{return FIN;}
{ID}			{return ID;}

"\n"      		
"\t"		


