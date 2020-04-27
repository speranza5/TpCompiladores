%{
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "y.tab.h"

#define Int 1
#define Real 2
#define String 3
#define CteInt 4
#define CteFloat 5
#define CteString 6
#define TAM_TABLA 300
#define TAM_NOMBRE 33

int yylex();
int yystopparser=0;
FILE  *yyin;

  /* Funciones */
  int yyerror(char* mensaje);
  void validarAsignacion(char *id,char *cadena);
  void validarAsignacionInt(char *cadena);
  void agregarVarATabla(char* nombre);
  void agregarTiposDatosATabla(void);
  void agregarCteStringATabla(char* nombre);
  void agregarCteIntATabla(int valor);
  void agregarCteFloatATabla(float valor);
  void chequearVarEnTabla(char* nombre);
  int buscarEnTabla(char * name);
  void escribirNombreEnTabla(char* nombre, int pos);
  void guardarTabla(void);
  void lineaEnTablaAuxSimbolo(char *cadena);
  void grabarLineaEnTablaAuxSimbolo();
  void agregarTipoVariableATabla(char *cadena);
  void formatearCadena(char *s);
  int esPalabra(char aux);
  void eliminarSubCadena(char *cad,char *subcad);
  void trim(char *v);

/*Tabla de simbolos*/
  typedef struct {
    char nombre[TAM_NOMBRE];
    int tipoDato;
    char valorSimbolo[TAM_NOMBRE];
    float valorFloat;
    int limite;
    int longitud;
  } t_simbolo;

  t_simbolo tablaSimbolo[TAM_TABLA];
  t_simbolo tablaAux[TAM_TABLA];
  int finDeTabla = -1;

  /* Para la declaracion de variables y la tabla de simbolos*/
  int varADeclarar = 0;
  int cantVarsADeclarar = 0;
  int tipoDatoADeclarar = 0;
  int cantVariablesADeclarar = 0;
  int cantDeVariablesDeclaradas = 0;

  /*Para verificar el LET*/
  int cantVariables = 0;
  int cantValores = 0;
 
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
%token IF ELSE LL_A LL_C OP_AND OP_OR OP_NOT WHILE OP_MENOR OP_MENORIGUAL OP_MAYOR OP_MAYORIGUAL OP_DISTINTO OP_IGUALDAD
%token BETWEEN COR_A COR_C
%token LET OP_IGUAL
%token COM_CIERRE COM_APER
%token GET DISPLAY

%%
programa: {printf("Inicio compilador\n");} declaracion algoritmo {guardarTabla(); printf("fin compilador\n");}

declaracion: DEFVAR {printf("Inicio de declaraciones:\n");} declaraciones_variables ENDEF {printf("fin de declaraciones\n"); agregarTiposDatosATabla();}

declaraciones_variables: declaraciones_variables declaracion_variable| declaracion_variable;

declaracion_variable: ENTERO {tipoDatoADeclarar = Int;} DOS_PUNTOS variables     {printf("Declaracion de variables enteras\n");}| 
                      REAL {tipoDatoADeclarar = Real;} DOS_PUNTOS variables      {printf("Declaracion de variables reales\n"); }|
						          STRING {tipoDatoADeclarar = String;}DOS_PUNTOS variables   {printf("Declaracion de variables string\n");};
           

variables: variables PUNTO_COMA ID      {printf("Variable a declarar recursivamente: %s\n",yylval.str_val );
                                        lineaEnTablaAuxSimbolo($3);
                                        grabarLineaEnTablaAuxSimbolo();
                                        }|
          ID                            {printf("Variable a declarar: %s\n",yylval.str_val );
                                        lineaEnTablaAuxSimbolo($1);
                                        grabarLineaEnTablaAuxSimbolo();
                                        };

algoritmo: {printf("Inicio del programa\n");} INICIO bloque FIN {printf("fin del programa\n");};

bloque: sentencia|bloque sentencia;

sentencia: asignacion| decision| repeticion|between|asignacionlet|comentarios|ingreso|egreso;

asignacion: ID OP_ASIG operacion{printf("asignacion a operacion\n");}|
            ID OP_ASIG CONSTSTRING {printf( "asignacion a STRING: %s\n", yylval.str_val); agregarCteStringATabla(yylval.str_val);};


operacion: operacion OP_SUMA termino {printf("Suma OK\n");}|
           operacion OP_RESTA termino {printf("Resta OK\n");}|termino {printf("Operacion es termino\n");};

termino: termino OP_MUL factor {printf("multiplicacion OK\n");}| 
         termino OP_DIV factor {printf("division OK\n");}| factor {printf("termino es factor\n");};

factor: ID {printf("factor es ID: %s\n",$1 );}|CONSTINT {printf("factor es entero: %d \n",$<intval>1);agregarCteIntATabla(yylval.intval); }
           |CONSTREAL {printf("Factor es real: %f \n",$<val>1); agregarCteFloatATabla(yylval.val);}
           |P_A operacion P_C;

decision: IF P_A condicion P_C LL_A bloque LL_C {printf("IF sin rama falsa\n");}| 
          IF P_A condicion P_C LL_A bloque LL_C ELSE LL_A bloque LL_C {printf("IF con rama falsa\n");};

condicion: comparacion | comparacion OP_AND comparacion| comparacion OP_OR comparacion| OP_NOT comparacion;

comparacion: factor op_comparacion factor;

op_comparacion: OP_MENOR| OP_MENORIGUAL | OP_MAYOR | OP_MAYORIGUAL | OP_DISTINTO | OP_IGUALDAD;

repeticion: WHILE P_A condicion P_C LL_A bloque LL_C {printf("bucle while\n");};

between: BETWEEN P_A ID COMA COR_A operacion PUNTO_COMA operacion COR_C P_C {printf("secuencia between\n");};

asignacionlet: LET lista_var OP_IGUAL P_A lista_valores P_C { if(cantValores != cantVariables){yyerror("Error, no coinciden los argumentos del let con las variables");} printf("lista let\n");};

lista_var: lista_var COMA ID {cantVariables++;printf("Item de la lista del let %s\n",yylval.str_val);};

lista_var: ID {cantVariables++;printf("Item de la lista del let %s\n",yylval.str_val);};

lista_valores: operacion{cantValores++;printf("argumento del let es operacion \n");};

lista_valores: lista_valores PUNTO_COMA operacion {cantValores++;printf("argumento del let es operacion \n");};

comentarios: COMENTARIO {printf("Se muestra un comentario: \n");};

ingreso:GET ID {printf("Ingreso de datos\n");}

egreso: DISPLAY CONSTSTRING {printf("Salida de string por pantalla\n");agregarCteStringATabla(yylval.str_val);} | DISPLAY ID {printf("Salida de variable por pantalla\n");};
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

  /* Tabla de simbolos */
int buscarEnTabla(char * name){
   int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return i;
     }
     i++;
   }
   return -1;
}


/*
void validarAsignacionString(char *id,char *cadena){
  
printf("-----LA ID ES:%s y la cadena es %s\n",id,cadena);

  if(*cadena != '"')
    {
      printf("Error en la asignacion. No es un string valido.");
      yyerror("Error en la asignacion. No es un string valido.");
    }
 }
*/
/*
void validarAsignacionInt(char *cadena){


}

void validarAsignacionFloat(char *){

}
*/

void escribirNombreEnTabla(char* nombre, int pos){
  strcpy(tablaSimbolo[pos].nombre, nombre);
}

 void agregarVarATabla(char* nombre){

   if(finDeTabla >= TAM_TABLA - 1){
     printf("Error: No hay mas espacio en la tabla de simbolos.\n");
     system("Pause");
     exit(2);
   }
   if(buscarEnTabla(nombre) == -1){
     finDeTabla++;
     escribirNombreEnTabla(nombre, finDeTabla);
   }
 }

void agregarTiposDatosATabla(){
  int i;
  for(i = 0; i < cantVarsADeclarar; i++){
    tablaSimbolo[varADeclarar + i].tipoDato = tipoDatoADeclarar;
  }
}

void guardarTabla(){
  if(finDeTabla == -1)
    yyerror("No se encontro la tabla de simbolos");

  FILE* arch = fopen("ts.txt", "w+");
  if(!arch){
    printf("No se pudo crear el archivo ts.txt\n");
    return;
  }
  
  int i;
  //printf("ANTES DEL archivo\n");
  fprintf(arch, "%-30s|%-30s|%-30s|%-30s\n","NOMBRE","TIPO","VALOR","LONGITUD");
  fprintf(arch, ".........................................................................................................\n");
  for(i = 0; i <= finDeTabla; i++){
    fprintf(arch, "%-30s", &(tablaSimbolo[i].nombre) );

    if(tablaSimbolo[i].tipoDato == Real)
      fprintf(arch, "|%-30s|%-30s|%-30s","REAL"," -"," -");
        else if(tablaSimbolo[i].tipoDato == Int)
         fprintf(arch, "|%-30s|%-30s|%-30s","INT"," -"," -");
          else if(tablaSimbolo[i].tipoDato == String)
           fprintf(arch, "|%-30s|%-30s|%-30s","STRING"," -"," -");
            else if(tablaSimbolo[i].tipoDato == CteFloat)
             fprintf(arch, "|%-30s|%-30f|%-30s", "CTE_FLOAT",tablaSimbolo[i].valorFloat," -");
               else if(tablaSimbolo[i].tipoDato == CteInt)
                fprintf(arch, "|%-30s|%-30d|%-30s", "CTE_INT",tablaSimbolo[i].limite," -");
                 else if(tablaSimbolo[i].tipoDato == CteString)
                  fprintf(arch, "|%-30s|%-30s|%-30d", "CTE_STRING",&(tablaSimbolo[i].valorSimbolo), tablaSimbolo[i].longitud);

    fprintf(arch, "\n");
  }
  fclose(arch);
}

void agregarCteStringATabla(char* nombre){
  if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  if(buscarEnTabla(nombre) == -1){
    finDeTabla++;
    escribirNombreEnTabla(nombre, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = CteString;
    int length = strlen(nombre);
    char auxiliar[length];
    strcpy(auxiliar,nombre);
    auxiliar[strlen(auxiliar)-1] = '\0';
    strcpy(tablaSimbolo[finDeTabla].valorSimbolo, auxiliar+1); 
    tablaSimbolo[finDeTabla].longitud = strlen(nombre) - 2;
  }
}

void agregarCteFloatATabla(float valor){
  if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  char nombre[12];
  sprintf(nombre, "_%f", valor);
  if(buscarEnTabla(nombre) == -1){
    finDeTabla++;
    escribirNombreEnTabla(nombre, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = CteFloat;
    tablaSimbolo[finDeTabla].valorFloat = valor;
  }
}

void agregarCteIntATabla(int valor){
  if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  char nombre[30];
  sprintf(nombre, "_%d", valor);
  if(buscarEnTabla(nombre) == -1){
    finDeTabla++;
    escribirNombreEnTabla(nombre, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = CteInt;
    tablaSimbolo[finDeTabla].limite = valor;
  }
}

void lineaEnTablaAuxSimbolo(char *cadena)
{
  strcpy(tablaAux[cantVariablesADeclarar].nombre,cadena); 
  //printf("SE VA A GUARDAR LA CADENA:%s. y su tipo de dato es %d",tablaAux[cantVariablesADeclarar].nombre,tipoDatoADeclarar);
  cantVariablesADeclarar++;
}

void grabarLineaEnTablaAuxSimbolo()
{
  //printf("\n\n\nTIPO DE DATO A DECLARAR ES:%d.\n\n\n",tipoDatoADeclarar);
  //printf("A GUARDAR:%s:\n",tablaAux[cantVariablesADeclarar-1].nombre);

  char *token = strtok(tablaAux[cantVariablesADeclarar-1].nombre,";");

  int j;
  for(j = 0; token != NULL; j++){

    strcpy(tablaAux[cantDeVariablesDeclaradas].nombre,token);
   //printf("Token: %s---%d\n", token,j);
    token = strtok(NULL, ";");
    //printf("-------------------------ENCONTRADAS:%s.\n",tablaAux[cantDeVariablesDeclaradas].nombre);
    eliminarSubCadena(tablaAux[cantDeVariablesDeclaradas].nombre,"ENDEF");
    eliminarSubCadena(tablaAux[cantDeVariablesDeclaradas].nombre,"STRING");
    eliminarSubCadena(tablaAux[cantDeVariablesDeclaradas].nombre,"FLOAT");
    eliminarSubCadena(tablaAux[cantDeVariablesDeclaradas].nombre,"INT");
    agregarTipoVariableATabla(tablaAux[cantDeVariablesDeclaradas].nombre);
/*
    if(!strstr(tablaAux[cantDeVariablesDeclaradas].nombre,"ENDEF") && !strstr(tablaAux[cantDeVariablesDeclaradas].nombre,"STRING") && !strstr(tablaAux[cantDeVariablesDeclaradas].nombre,"INT"))   
      {
      agregarTipoVariableATabla(tablaAux[cantDeVariablesDeclaradas].nombre);
      }
    else formatearCadenaUltima  
*/
    cantDeVariablesDeclaradas++;
    }
  cantVariablesADeclarar=0;
}


void agregarTipoVariableATabla(char *cadena){
 if(finDeTabla >= TAM_TABLA - 1){
    printf("Error: No hay mas espacio en la tabla de simbolos.\n");
    system("Pause");
    exit(2);
  }
  trim(cadena);
  formatearCadena(cadena);
  if(buscarEnTabla(cadena) == -1){
    finDeTabla++;
    escribirNombreEnTabla(cadena, finDeTabla);
    tablaSimbolo[finDeTabla].tipoDato = tipoDatoADeclarar;
    int length = strlen(cadena);
    char auxiliar[length];
    strcpy(auxiliar,cadena);
    auxiliar[strlen(auxiliar)-1] = '\0';
    strcpy(tablaSimbolo[finDeTabla].valorSimbolo, auxiliar+1); 
    tablaSimbolo[finDeTabla].longitud = strlen(cadena) - 2;
  }
}

void formatearCadena(char *s) {
  
char *aux;
char *aux2;
aux = aux2 = s;

    while(*aux=*aux2++)
        if(esPalabra(*aux) || *aux == ' ')
            aux++;
}   

int esPalabra(char aux)
{
    return ((aux >= 'A' && aux <= 'Z')||(aux >= 'a' && aux <= 'z')||(aux >= '0' && aux <= '9'))? 1 : 0 ;
}

void trim(char *v)
{
    char *aux;
    aux = v;
    int i=0;

    while (*aux)
    {
    if((*aux ==' '))
    {
    *aux='.';

    }
    aux++;
    }
}

void eliminarSubCadena(char *cad,char *subcad)
{
    char *pl1=cad;
    char *pl2=subcad;
    char *dest=cad;
    char*ant;

    while(*pl1)
    {
        ant=subcad;
        while(*pl1==*pl2&&*pl2)
        {
            pl1++;
            pl2++;
        }
        if(*pl2=='\0')
            subcad=ant;
        *dest=*pl1;
        dest++;
        pl1++;
    }
}