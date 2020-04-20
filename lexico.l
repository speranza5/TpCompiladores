%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"
FILE  *yyin;


void InformarError(char* mensaje);

%}
%option noyywrap  
%option yylineno 

DIGITO			[0-9]
LETRA			[a-zA-Z]
PALABRA			{LETRA}({LETRA}|{DIGITO}|_)*
COMILLA         \"

CONSTINT			{DIGITO}+
CONSTREAL			{DIGITO}*"."{DIGITO}+
CONSTSTRING         {COMILLA}{PALABRA}{COMILLA} 

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
"BETWEEN"		{return BETWEEN;}
"let"			{return LET;}
"{"			{return LL_A;}
"}"			{return LL_C;}
"["			{return COR_A;}
"]"			{return COR_C;}
"<"			{return OP_COMPARACION;}
"+"			{ return OP_SUMA;}
"-"			{ return OP_RESTA;}
"*"			{ return OP_MUL;}
"/"			{ return OP_DIV;}
"("			{ return P_A;}
")"			{ return P_C;}
"NOT"		{return	OP_NOT;}

{ID}		{if(strlen(yytext) <= 30){
						yylval.str_val = yytext;
			            return ID;
			         	}
			           	InformarError("Error en la longitud del ID");
			          }

{CONSTINT}	{if(atoll(yytext)>=-32768 && atoll(yytext)<=32767){
								yylval.intval = atoi(yytext);
		                      	return CONSTINT;
		                      }
		                      InformarError("Error en la longitud del CONSTINT");
		                     }

{CONSTREAL}	{if(atof(yytext)>=-3.40282347e+38F && atof(yytext)<=3.40282347e+38F){
								yylval.val = atof(yytext);
		                    	return CONSTREAL;
		                    }
		                    InformarError("Error en la longitud del CONSTREAL");
		                }

{CONSTSTRING}		{if(strlen(yytext) <= 30){
						yylval.str_val = yytext;
			            return CONSTSTRING;
			         	}
			           InformarError("Error en la longitud del CONSTSTRING");	
			          }
"\n"      		
"\t"		

%%


void InformarError(char* mensaje){

		printf("%s",mensaje);
		system ("Pause");
		exit(1);  
}
