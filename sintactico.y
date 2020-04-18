%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "y.tab.h"
int yylval;
int yystopparser=0;
FILE  *yyin;
char *yyltext;
char *yytext;

%}
%token ID ENTERO STRING REAL PUNTO_COMA DOS_PUNTOS ENDEF DEFVAR
%token OP_ASIG
%token INICIO FIN 

%%
programa: {printf("Inicio compilador\n");} declaracion algoritmo {printf("fin compilador\n");}

declaracion: DEFVAR {printf("Inicio de declaraciones\n");} declaraciones_variables ENDEF {printf("fin de declaraciones\n");}

declaraciones_variables: declaraciones_variables declaracion_variable| declaracion_variable;

declaracion_variable: ENTERO DOS_PUNTOS variables {printf("declaracion de variables enteras\n");}| REAL DOS_PUNTOS variables {printf("declaracion de variables reales\n");}|
						STRING DOS_PUNTOS variables {printf("declaracion de variables string\n");};

variables: ID|ID PUNTO_COMA variables;

algoritmo: {printf("Inicio de programa\n");} INICIO ID FIN {printf("fin del programa\n");} 

%%
int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
	yyparse();
  }
  fclose(yyin);
  return 0;
}
int yyerror(void)
     {
       printf("Syntax Error\n");
	 system ("Pause");
	 exit (1);
     }
