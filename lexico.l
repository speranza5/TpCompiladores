%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
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
CONSTSTRING         \"{LETRA}({LETRA}|{DIGITO}|_)*\"

ID			{LETRA}({LETRA}|{DIGITO}|_)*

%%
"DEFVAR"		{ return DEFVAR;}
"ENDEF"			{return ENDEF;}
":="			{return OP_ASIG;}
":"			{return DOS_PUNTOS;}
";"			{return PUNTO_COMA;}
","			{return COMA;}
"FLOAT"			{return REAL;}
"STRING"		{return STRING;}
"INT"			{return ENTERO;}
"BEGIN"			{return INICIO;}
"END"			{return FIN;}
"if"			{return IF;}
"else"			{return ELSE;}
"while"			{return WHILE;}
"{"			{return LL_A;}
"}"			{return LL_C;}
"<"			{return OP_COMPARACION;}
"+"			{ return OP_SUMA;}
"-"			{ return OP_RESTA;}
"*"			{ return OP_MUL;}
"/"			{ return OP_DIV;}
"("			{ return P_A;}
")"			{ return P_C;}
"NOT"		{return	OP_NOT;}
{ID}			{	if(strlen(yytext) <= 30){
			            return ID;
			         	}
			           	printf("Error en la longitud del ID\n");
						system ("Pause");
						exit(1);  
			          }
{CONSTINT}			{return CONSTINT;}
{CONSTREAL}			{return CONSTREAL;}
{CONSTSTRING}		{if(strlen(yytext) <= 30){
			            return CONSTSTRING;
			         	}
			           	printf("Error en la longitud del string\n");
						system ("Pause");
						exit(1);  
			          }
"\n"      		
"\t"		

%%
