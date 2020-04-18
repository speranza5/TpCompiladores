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
%token ID ENTERO STRING REAL PUNTO_COMA DOS_PUNTOS ENDEF DEFVAR CONSTINT CONSTREAL
%token OP_ASIG
%token INICIO FIN 
%token P_A P_C OP_SUMA OP_RESTA OP_MUL OP_DIV
%token IF ELSE LL_A LL_C OP_COMPARACION OP_AND OP_OR OP_NOT

%%
programa: {printf("Inicio compilador\n");} declaracion algoritmo {printf("fin compilador\n");}

declaracion: DEFVAR {printf("Inicio de declaraciones\n");} declaraciones_variables ENDEF {printf("fin de declaraciones\n");}

declaraciones_variables: declaraciones_variables declaracion_variable| declaracion_variable;

declaracion_variable: ENTERO DOS_PUNTOS variables {printf("declaracion de variables enteras\n");}| REAL DOS_PUNTOS variables {printf("declaracion de variables reales\n");}|
						STRING DOS_PUNTOS variables {printf("declaracion de variables string\n");};

variables: ID|ID PUNTO_COMA variables;

algoritmo: {printf("Inicio de programa\n");} INICIO bloque FIN {printf("fin del programa\n");} 

bloque: sentencia|bloque sentencia;
sentencia: asignacion| decision;
asignacion: ID OP_ASIG ID {printf("asignacion a variable\n");}|ID OP_ASIG operacion{printf("asignacion a expresion\n");};
operacion: operacion OP_SUMA termino {printf("Suma OK\n");}|operacion OP_RESTA termino {printf("Resta OK\n");}|termino;

termino: termino OP_MUL factor {printf("multiplicacion OK\n");}| termino OP_DIV factor {printf("division OK\n");}| factor;

factor: ID| CONSTINT|CONSTREAL |P_A operacion P_C;

decision: IF P_A condicion P_C LL_A bloque LL_C {printf("IF sin rama falsa\n");}| IF P_A condicion P_C LL_A bloque LL_C ELSE LL_A bloque LL_C {printf("IF con rama falsa\n");};

condicion: comparacion | comparacion OP_AND comparacion| comparacion OP_OR comparacion| OP_NOT comparacion;

comparacion: factor OP_COMPARACION factor;

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
