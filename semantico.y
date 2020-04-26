%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

  #define Int 1
  #define Float 2
  #define String 3
  #define CteInt 4
  #define CteFloat 5
  #define CteString 6
  #define TAMANIO_TABLA 300
  #define TAM_NOMBRE 32

int yylex();
int yystopparser=0;
FILE  *yyin;

  /* Funciones necesarias */
  int yyerror(char* mensaje);
  void agregarVarATabla(char* nombre);
  void agregarTiposDatosATabla(void);
  void agregarCteStringATabla(char* nombre);
  void agregarCteIntATabla(int valor);
  void agregarCteFloatATabla(float valor);
  void chequearVarEnTabla(char* nombre);
  int buscarEnTabla(char * name);
  void escribirNombreEnTabla(char* nombre, int pos);
  void guardarTabla(void);

/*Tabla de simbolos*/
  /* Cosas de tabla de simbolos */
  typedef struct {
    char nombre[TAM_NOMBRE];
    int tipo_dato;
    char valor_s[TAM_NOMBRE];
    float valor_f;
    int valor_i;
    int longitud;
  } simbolo;

  simbolo tabla_simbolo[TAMANIO_TABLA];
  int fin_tabla = -1;

  /* Cosas para la declaracion de variables y la tabla de simbolos */
  int varADeclarar1 = 0;
  int cantVarsADeclarar = 0;
  int tipoDatoADeclarar;
  int canVariables = 0;
  int cantValores = 0;
 /* typedef struct {
    char nombre[TAMANIO_TABLA];
    char tipo[33];
    char valor[33];
    int alias[33];
    int limite;
    int longitud;
  } t_simbolo;

  t_simbolo tablaTempSimbolo[TAMANIO_TABLA];*/


%}

%union {
    int intval;
    double val;
    char *str_val;
}

%token <str_val>ID
%token <intval>CONSTINT
%token <val> CONSTREAL
%token <str_val> CONSTSTRING

%token ENTERO STRING REAL PUNTO_COMA COMA DOS_PUNTOS ENDEF DEFVAR PALABRA TEXTO COMENTARIO
%token OP_ASIG
%token INICIO FIN 
%token P_A P_C OP_SUMA OP_RESTA OP_MUL OP_DIV
%token IF ELSE LL_A LL_C OP_COMPARACION OP_AND OP_OR OP_NOT WHILE
%token BETWEEN COR_A COR_C
%token LET OP_IGUAL
%token COM_CIERRE COM_APER
%token GET DISPLAY

%%
programa: {printf("Inicio compilador\n");} declaracion algoritmo {guardarTabla(); printf("fin compilador\n");}

declaracion: DEFVAR {printf("Inicio de declaraciones\n");} declaraciones_variables ENDEF {printf("fin de declaraciones\n"); agregarTiposDatosATabla();}

declaraciones_variables: declaraciones_variables declaracion_variable| declaracion_variable;

declaracion_variable: ENTERO DOS_PUNTOS variables {printf("declaracion de variables enteras\n");tipoDatoADeclarar = Int;}| 
                      REAL DOS_PUNTOS variables {printf("declaracion de variables reales\n"); tipoDatoADeclarar = Float;}|
						          STRING DOS_PUNTOS variables {printf("declaracion de variables string\n"); tipoDatoADeclarar = String;};
           

variables: ID|ID PUNTO_COMA variables;

algoritmo: {printf("Inicio de programa\n");} INICIO bloque FIN {printf("fin del programa\n");};

bloque: sentencia|bloque sentencia;

sentencia: asignacion| decision| repeticion|between|asignacionlet|comentarios|ingreso|egreso;

asignacion: ID OP_ASIG ID {printf("asignacion a variable\n"); chequearVarEnTabla($1);}|
            ID OP_ASIG operacion{printf("asignacion a expresion\n");}|
            ID OP_ASIG CONSTSTRING {$<str_val>$ = $<str_val>1; printf( "asignacion a STRING: %s\n", yylval.str_val); agregarCteStringATabla(yylval.str_val);};


operacion: operacion OP_SUMA termino {printf("Suma OK\n");}|
           operacion OP_RESTA termino {printf("Resta OK\n");}|termino;

termino: termino OP_MUL factor {printf("multiplicacion OK\n");}| 
         termino OP_DIV factor {printf("division OK\n");}| factor;

factor: ID |CONSTINT {printf("El entero es: %d \n",$<intval>1);agregarCteIntATabla(yylval.intval); }
           |CONSTREAL {printf("El entero es: %d \n",$<val>1); agregarCteFloatATabla(yylval.val);}
           |P_A operacion P_C;

decision: IF P_A condicion P_C LL_A bloque LL_C {printf("IF sin rama falsa\n");}| 
          IF P_A condicion P_C LL_A bloque LL_C ELSE LL_A bloque LL_C {printf("IF con rama falsa\n");};

condicion: comparacion | comparacion OP_AND comparacion| comparacion OP_OR comparacion| OP_NOT comparacion;

comparacion: factor OP_COMPARACION factor;

repeticion: WHILE P_A condicion P_C LL_A bloque LL_C {printf("bucle while\n");};

between: BETWEEN P_A ID COMA COR_A operacion PUNTO_COMA operacion COR_C P_C {printf("secuencia bituin\n");};

asignacionlet: LET lista_var OP_IGUAL tupla {printf("lista let\n");};

tupla: P_A lista_valores P_C {printf("se fue a matar la tupla\n");};

lista_var: ID|ID COMA lista_var {printf("inventaron el var\n");   
                                 agregarVarATabla(yylval.str_val);
                                 varADeclarar1 = fin_tabla; /* Guardo posicion de primer variable de esta lista de declaracion. */
                                 cantVarsADeclarar = 1;};

lista_valores: operacion|operacion PUNTO_COMA lista_valores {printf("lista de valores \n"); 
                                                             agregarVarATabla(yylval.str_val);
                                                             cantVarsADeclarar++;};

comentarios: COMENTARIO {printf("Se muestra un comentario: \n");};

ingreso:GET ID {printf("Ingreso de datos\n"); chequearVarEnTabla($2);}

egreso: DISPLAY CONSTSTRING {printf("Salida de string por pantalla\n");agregarCteStringATabla(yylval.str_val);} | DISPLAY ID {printf("Salida de variable por pantalla\n");chequearVarEnTabla($2);};
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

int yyerror(char* mensaje)
 {
  printf("Syntax Error: %s\n", mensaje);
  system ("Pause");
  exit (1);
 }



  /* Funciones de la tabla de simbolos */

/* Devuleve la posicion en la que se encuentra el elemento buscado, -1 si no encontr� el elemento */
int buscarEnTabla(char * name){
   int i=0;
   while(i<=fin_tabla){
     if(strcmp(tabla_simbolo[i].nombre,name) == 0){
       return i;
     }
     i++;
   }
   return -1;
}

/** Escribe el nombre de una variable o constante en la posición indicada */
void escribirNombreEnTabla(char* nombre, int pos){
  strcpy(tabla_simbolo[pos].nombre, nombre);
}

 /** Agrega un nuevo nombre de variable a la tabla **/
 void agregarVarATabla(char* nombre){
   //Si se llena, error
   if(fin_tabla >= TAMANIO_TABLA - 1){
     printf("Error: No hay mas espacio en la tabla de simbolos.\n");
     system("Pause");
     exit(2);
   }
   //Si no hay otra variable con el mismo nombre...
   if(buscarEnTabla(nombre) == -1){
     //Agregar a tabla
     fin_tabla++;
     escribirNombreEnTabla(nombre, fin_tabla);
   }
   else 
   {
/*
   char msg[100] ;
   sprintf(msg,"'%s' ya se encuentra declarada previamente.", nombre);
   yyerror(msg);
*/
  }
 }

/** Agrega los tipos de datos a las variables declaradas. Usa las variables globales varADeclarar1, cantVarsADeclarar y tipoDatoADeclarar */
void agregarTiposDatosATabla(){
  int i;
  for(i = 0; i < cantVarsADeclarar; i++){
    tabla_simbolo[varADeclarar1 + i].tipo_dato = tipoDatoADeclarar;
  }
}

/** Guarda la tabla de simbolos en un archivo de texto */
void guardarTabla(){
  if(fin_tabla == -1)
    yyerror("No se encontro la tabla de simbolos");

  FILE* arch = fopen("ts.txt", "w+");
  if(!arch){
    printf("No se pudo crear el archivo ts.txt\n");
    return;
  }
  
  int i;
  printf("ANTES DEL archivo\n");
  fprintf(arch, "%-30s|%-30s|%-30s|%-30s\n","NOMBRE","TIPO","VALOR","LONGITUD");
  fprintf(arch, ".........................................................................................................\n");
  for(i = 0; i <= fin_tabla; i++){
    fprintf(arch, "%-30s", &(tabla_simbolo[i].nombre) );

    switch (tabla_simbolo[i].tipo_dato){
    case Float:
      fprintf(arch, "|%-30s|%-30s|%-30s","FLOAT","--","--");
      break;
    case Int:
      fprintf(arch, "|%-30s|%-30s|%-30s","INT","--","--");
      break;
    case String:
      fprintf(arch, "|%-30s|%-30s|%-30s","STRING","--","--");
      break;
    case CteFloat:
      fprintf(arch, "|%-30s|%-30f|%-30s", "CTE_FLOAT",tabla_simbolo[i].valor_f,"--");
      break;
    case CteInt:
      fprintf(arch, "|%-30s|%-30d|%-30s", "CTE_INT",tabla_simbolo[i].valor_i,"--");
      break;
    case CteString:
      fprintf(arch, "|%-30s|%-30s|%-30d", "CTE_STRING",&(tabla_simbolo[i].valor_s), tabla_simbolo[i].longitud);
      break;
    }
    printf("DESPUES DEL archivo\n");
    fprintf(arch, "\n");
  }
   printf("TERMINO DEL archivo\n");
  fclose(arch);
}

/* Calculo que estas 3 funciones se podrían juntar en una sola */

/** Agrega una constante string a la tabla de simbolos */
void agregarCteStringATabla(char* nombre){
  if(fin_tabla >= TAMANIO_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }

  //Si no hay otra variable con el mismo nombre...
  if(buscarEnTabla(nombre) == -1){
    //Agregar nombre a tabla
    fin_tabla++;
    escribirNombreEnTabla(nombre, fin_tabla);

    //Agregar tipo de dato
    tabla_simbolo[fin_tabla].tipo_dato = CteString;

    //Agregar valor a la tabla
    int length = strlen(nombre);
    char auxiliar[length];
    strcpy(auxiliar,nombre);
    auxiliar[strlen(auxiliar)-1] = '\0';
    strcpy(tabla_simbolo[fin_tabla].valor_s, auxiliar+1); 

    //Agregar longitud
    tabla_simbolo[fin_tabla].longitud = strlen(nombre) - 2;
  }
}

/** Agrega una constante real a la tabla de simbolos */
void agregarCteFloatATabla(float valor){
  if(fin_tabla >= TAMANIO_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }

  //Genero el nombre
  char nombre[12];
  sprintf(nombre, "_%f", valor);

  //Si no hay otra variable con el mismo nombre...
  if(buscarEnTabla(nombre) == -1){
    //Agregar nombre a tabla
    fin_tabla++;
    escribirNombreEnTabla(nombre, fin_tabla);

    //Agregar tipo de dato
    tabla_simbolo[fin_tabla].tipo_dato = CteFloat;

    //Agregar valor a la tabla
    tabla_simbolo[fin_tabla].valor_f = valor;
  }
}

/** Agrega una constante entera a la tabla de simbolos */
void agregarCteIntATabla(int valor){
  if(fin_tabla >= TAMANIO_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }

  //Genero el nombre
  char nombre[30];
  sprintf(nombre, "_%d", valor);

  //Si no hay otra variable con el mismo nombre...
  if(buscarEnTabla(nombre) == -1){
    //Agregar nombre a tabla
    fin_tabla++;
    escribirNombreEnTabla(nombre, fin_tabla);

    //Agregar tipo de dato
    tabla_simbolo[fin_tabla].tipo_dato = CteInt;

    //Agregar valor a la tabla
    tabla_simbolo[fin_tabla].valor_i = valor;
  }
}

/** Se fija si ya existe una entrada con ese nombre en la tabla de simbolos. Si no existe, muestra un error de variable sin declarar y aborta la compilacion. */
void chequearVarEnTabla(char* nombre){
  //Si no existe en la tabla, error
  /*
  if( buscarEnTabla(nombre) == -1){
    char msg[100];
    sprintf(msg,"La variable '%s' debe ser declarada previamente en la seccion de declaracion de variables", nombre);
    yyerror(msg);
  }*/
  //Si existe en la tabla, dejo que la compilacion siga
}
