%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
#define CANT_TERCETOS 2000
#define TAM_PILA 120

int yylex();
int yystopparser=0;
FILE  *yyin;

  /*Para verificar el LET*/
  int cantVariables = 0;
  int cantValores = 0;
  int vectorLetTipoDatos[999];

  /* Funciones */
  int yyerror(char* mensaje);
  void validarAsignacionDeTipos();
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
  int getTipoPorID(char* name);
  char* getValorPorID(char* name);

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
  t_simbolo tablaParaStrings[TAM_TABLA];
  int finDeTabla = -1;

  /* Para la declaracion de variables y la tabla de simbolos*/
  int varADeclarar = 0;
  int cantVarsADeclarar = 0;
  int tipoDatoADeclarar = 0;
  int cantVariablesADeclarar = 0;
  int cantDeVariablesDeclaradas = 0;
  /* Struct para tercetos y un par de funciones para que funcionen bien*/
  	typedef struct 
  	{	
  		int numeroTerceto;
  		char * primerElemento; //primer elemento del terceto, duh
  		char * elementoIzquierda; //segundo elemento del terceto
  		char * elementoDerecha; //tercer elemento del terceto
  	}terceto;
 terceto vectorTercetos[CANT_TERCETOS];
void reverse(char* str, int len);
 int contadorTercetos = 0; //cada vez que metemos un tercetos aumentamos en uno este contadorcito
 char* crearIndice(int);//recibe un numero entero y lo convierte en un indice, por ejemplo le mando 12 y guarda en el char * "[12]"
 int crearTerceto (char *, char *,char *); //le mandamos los tres strings para crear el terceto. No reciben numeros ni nada, solo strings. 
 										   //la funcion tambien tiene que guardar el terceto creado en el vectorTercetos.
 										   //La posicion en el vector se lo da contadorTercetos. Variable que debe aumentar en 1.
 int crearTercetoNumero(char*, char *, char *, int);//Parecida a la anterior pero crea un terceto con un numero en especifico.
 											       //No aumenta en 1 contadorTercetos.
 												   //La funcion guarda el terceto en el vector en la posicion que recibe por argumento.
int itoaBienPiola(int x, char str[], int d); //recibe un numero y lo convierte a string cosa de que podamos hacer crearTerceto("=","id",itoa(cte));
void ftoa(float n, char* res, int afterpoint); //lo mismo que arriba perri
 void guardarTercetosEnArchivo(char *); //guarda los tercetos en un archivo con el nombre que nosotros le pasemos (creo que en un binaro queda mejor)
 void parsearCadena (char * origen, char * destino);//porque no me voy a poner a ver como anda bison
 /*Struct para usar la dichosa pila y las primitivas de pila*/
  typedef struct 
  {
  	int pila [TAM_PILA];
  	int tope;
  }t_pila;

  void crearPila(t_pila *);
  int pilaLLena(t_pila *);
  int pilaVacia(t_pila *);
  int apilar (t_pila *, int dato);
  int desapilar(t_pila*);

/*Indices y variables auxiliares de aca a abajo. Indiquen de que estructura es cada index o cada auxiliar o les pego un tiro en la rodilla. Atte carlos :D*/
/*punteros y esas cosas para operaciones*/
int factorPointer;
int terminoPointer;
int operacionPointer;
int asigPointer;
char * cadenaAsigString;
t_pila pilaOperaciones;
t_pila pilaTerminos;
t_pila pilaSaltosAnd;

/*punteros y esas cosas para el LET*/
int tercetoID;
int tercetoOperacion;
t_pila pilaIdsLet;
t_pila pilaOperacionesLet;
void crearTercetosLet();

/*punteros y esas cosas para GET*/
int numeroGET;

/*punteros y esas cosas para comparaciones y ANDS y todas esas cosas*/
int esBetween=0;
int vectorComparaciones [999];
int contadorComparaciones = 0;
int tipoSaltoPalOr;
int posicionACompletarOr;
char * cadenaIDBetween;
int cmpPointer;
t_pila condPila; //pila para los numeros de tercetos donde tendriamos que completar con las condiciones
t_pila pilaSaltos;
t_pila pilaBtw;
int condicionPointer;
int tipoSaltoPalOr;
int posicionACompletarOrFalso;
int posicionAcompletarOrVerdadero;
int izqPointer;
int derPointer;
void completarTercetosAnd(int);
char * devolverSalto(int );
void completarTercetosBtw();
/*punteros y esas cosas para el IF */
int salto;
int numeroCondicion;
int numeroSalto;
t_pila pilaCompletarAnds;
/*punteros y esas cosas para el while*/
int etiqueta;
int etiquetaWhile;
int numeroTercetoWhile;
int saltoWhile;
char * cadenaEtiq;
char numeroTextoWhile[5];

/*Validación de tipos*/
int ultimoTipoLeido;

/*Cosas para Assembler */
void generaAsm();
void pasarTsAssembler(FILE* fp);
int devolverIndice(char * cadena);
terceto devolverTerceto (char* posicion);


int tipoDatoActual;

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
programa: {printf("Inicio compilador\n");} declaracion algoritmo {guardarTabla(); guardarTercetosEnArchivo("tercetos.txt"); generaAsm(); printf("fin compilador\n");}

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

sentencia: asignacion| decision| repeticion |asignacionlet|comentarios|ingreso|egreso;

asignacion: ID  OP_ASIG {
                           cadenaAsigString = malloc(sizeof(char) * strlen($<str_val>1));
                           parsearCadena($<str_val>1,cadenaAsigString);
                           ultimoTipoLeido = getTipoPorID(cadenaAsigString);
                          
                           
                        }

            operacion   {printf("asignacion a operacion\n");
             
                        validarAsignacionDeTipos();
                        asigPointer = crearTerceto("=",cadenaAsigString,crearIndice(operacionPointer));
                        }
            |

            ID  OP_ASIG{
              
              cadenaAsigString = malloc(sizeof(char) * strlen($<str_val>1));
              parsearCadena($<str_val>1,cadenaAsigString);
              printf("La cadena es: %s \n",cadenaAsigString);
             ultimoTipoLeido = getTipoPorID(cadenaAsigString);
             
            } CONSTSTRING {
            
              printf( "asignacion a STRING: %s\n", yylval.str_val);
              tipoDatoActual = String; 
                                   validarAsignacionDeTipos();
                                    agregarCteStringATabla(yylval.str_val);
                                    asigPointer=crearTerceto("=",cadenaAsigString,yylval.str_val);
                                   };


operacion: operacion OP_SUMA termino {printf("Suma OK\n");
                                      operacionPointer = crearTerceto("+",crearIndice(operacionPointer),crearIndice(terminoPointer));
                                     }|
           operacion OP_RESTA termino {printf("Resta OK\n");
                                       operacionPointer = crearTerceto("-",crearIndice(operacionPointer),crearIndice(terminoPointer));
                                      }|
           termino {printf("Operacion es termino\n");
                    operacionPointer = terminoPointer;
           };

termino: termino OP_MUL factor {printf("Termino es multiplicacion OK\n");
                                terminoPointer = crearTerceto("*",crearIndice(terminoPointer),crearIndice(factorPointer));
         }| 
         termino OP_DIV factor {printf("Termino es division\n");
         terminoPointer= crearTerceto("/",crearIndice(terminoPointer),crearIndice(factorPointer));
         }| 
         factor {printf("termino es factor\n"); terminoPointer = factorPointer;};

factor: ID {printf("factor es ID: %s\n",$1 ); 
           
            int tipoDato = getTipoPorID($1);
        
            if (tipoDato == String){
              yyerror("Error en asignacion");

            }
            
            if(tipoDato == Int && tipoDatoActual == Int){
              tipoDatoActual = Int;
              }

              if(tipoDatoActual == Real && tipoDato == Int){
                tipoDatoActual = Real;
               }

               if(tipoDato == Real && tipoDatoActual == Real){

                 tipoDatoActual = Real;
               }

              if(tipoDato == Real && tipoDatoActual == Int){

                  tipoDatoActual = Real;

              }

           
            factorPointer=crearTerceto($1,"","");}
           
           |CONSTINT {
                      if(tipoDatoActual==Real){
                        tipoDatoActual = Real;
                      }
                      else{
                      tipoDatoActual = Int; 
                      }

                     // validarAsignacionDeTipos();
                      printf("factor es entero: %d \n",$<intval>1);agregarCteIntATabla(yylval.intval); 
                      char *cadena = (char *)malloc (sizeof (int));
                      itoa($<intval>1,cadena,10);
                      factorPointer=crearTerceto(cadena,"","");
                      }
           |CONSTREAL {
                       tipoDatoActual = Real; 
                       //validarAsignacionDeTipos();
                       printf("Factor es real: %f \n",$<val>1); agregarCteFloatATabla(yylval.val);
                       char*cadena = (char *)malloc(sizeof(float));
                       ftoa($<val>1,cadena,4);
                       factorPointer=crearTerceto(cadena,"","");
                      }
           |P_A{
             apilar(&pilaOperaciones,operacionPointer);
             apilar(&pilaTerminos,terminoPointer);
           } operacion P_C {printf("factor es operacion entre parentesis\n");
                            //factorPointer = crearTerceto(crearIndice(operacionPointer),"","");
                            factorPointer = operacionPointer;
                            operacionPointer = desapilar(&pilaOperaciones);
                            terminoPointer = desapilar(&pilaTerminos);
           };

decision: IF P_A condicion P_C LL_A bloque LL_C {printf("IF sin rama falsa\n");
                                                 salto = desapilar(&pilaSaltos); 
												                         numeroCondicion = desapilar(&condPila); 
												                         crearTercetoNumero (devolverSalto(salto), crearIndice(contadorTercetos),"", numeroCondicion);
												                         completarTercetosAnd(contadorTercetos);
                                                 
                                                 
                                                }| 
          IF P_A condicion P_C LL_A bloque LL_C ELSE {
            					salto = desapilar(&pilaSaltos); 
											numeroCondicion = desapilar(&condPila); 
											crearTercetoNumero(devolverSalto(salto), crearIndice(contadorTercetos+1),"", numeroCondicion);
											apilar(&condPila,contadorTercetos); 
										  contadorTercetos++;
                      completarTercetosAnd(contadorTercetos);
                      
                      
                      } 
           LL_A bloque LL_C {printf("IF con rama falsa\n"); 
                          numeroSalto = desapilar(&condPila);
                          printf("Numero de salto: %d\n",numeroSalto);
                          crearTercetoNumero("JMP",crearIndice(contadorTercetos),"", numeroSalto);
                            };

condicion: comparacion {printf("Comparacion unica\n");
                        if(esBetween==0){
			                    cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
                          apilar(&pilaCompletarAnds,-1);
						              apilar(&condPila, contadorTercetos);
						              contadorTercetos ++; 
						              condicionPointer = cmpPointer;
                          printf("SALGO DE Comparacion unica\n");
						}

          } | 
           comparacion {
            if(esBetween==0){
						  cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
						  apilar(&pilaCompletarAnds,contadorTercetos);
						  //pilar(&condPila, contadorTercetos);
              apilar(&pilaSaltosAnd,desapilar(&pilaSaltos));
						  contadorTercetos ++; 
						  condicionPointer = cmpPointer;
						 }
           } 
           
           OP_AND comparacion {printf("Comparacion con and");
           				             if(esBetween==0){
				                       cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
				                       apilar(&condPila, contadorTercetos);
				                       contadorTercetos ++; 
				                       condicionPointer = cmpPointer;
				 } 
           }| 
           comparacion {
             				if(esBetween==0){
				              cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer)); 
                      apilar(&pilaCompletarAnds,-1);
				              tipoSaltoPalOr = desapilar(&pilaSaltos);
				              posicionACompletarOrFalso = contadorTercetos;
				              contadorTercetos++;
				              posicionAcompletarOrVerdadero = contadorTercetos;
				              contadorTercetos++;
				}
           }
            OP_OR comparacion {printf("comparacion por or");
            				           if(esBetween==0){
				                          cmpPointer = crearTerceto("CMP",crearIndice(izqPointer),crearIndice(derPointer));
				                          apilar(&condPila, contadorTercetos); 
				                          contadorTercetos ++; 
				                          crearTercetoNumero(devolverSalto(tipoSaltoPalOr),crearIndice(cmpPointer),"",posicionACompletarOrFalso);
				                          crearTercetoNumero("JMP",crearIndice(contadorTercetos),"",posicionAcompletarOrVerdadero);
			                      	}
                            };

comparacion: operacion {izqPointer = operacionPointer; esBetween =0;apilar(&pilaBtw,0);} OP_MENOR {printf("Comparacion por menor\n"); apilar(&pilaSaltos, 1);}
             operacion{derPointer = operacionPointer;} 
             | 
             operacion {izqPointer = operacionPointer; esBetween =0;} OP_MENORIGUAL{printf("comparacion por menor o igual\n"); apilar(&pilaSaltos, 5);} operacion {derPointer = operacionPointer;} | 
             operacion {izqPointer = operacionPointer; esBetween =0;} OP_MAYOR {printf("comparacion por mayor\n");  apilar(&pilaSaltos,2) ;} operacion {derPointer = operacionPointer;} | 
             operacion {izqPointer = operacionPointer; esBetween =0;} OP_MAYORIGUAL{printf("comparacion por mayor o igual\n"); apilar(&pilaSaltos,4);} operacion  {derPointer = operacionPointer;}| 
             operacion {izqPointer = operacionPointer; esBetween =0;} OP_DISTINTO{printf("comparacion por distinto\n"); apilar(&pilaSaltos,6);} operacion  {derPointer = operacionPointer;}| 
             operacion {izqPointer = operacionPointer; esBetween =0;} OP_IGUALDAD{printf("comparacion por igual\n"); apilar(&pilaSaltos,3); } operacion  {derPointer = operacionPointer;} |
             OP_NOT operacion {izqPointer = operacionPointer; esBetween =0;}  OP_MENOR {printf("Comparacion por menor negada\n"); apilar(&pilaSaltos,4); } operacion  {derPointer = operacionPointer;} |
             OP_NOT operacion {izqPointer = operacionPointer; esBetween =0;} OP_MENORIGUAL{printf("comparacion por menor o igual negada\n"); apilar(&pilaSaltos,2); } operacion  {derPointer = operacionPointer;} |
             OP_NOT operacion {izqPointer = operacionPointer; esBetween =0;} OP_MAYOR {printf("comparacion por mayor negada\n"); apilar(&pilaSaltos,5); } operacion  {derPointer = operacionPointer;} |
             OP_NOT operacion {izqPointer = operacionPointer; esBetween =0;} OP_MAYORIGUAL{printf("comparacion por mayor o igual negada \n"); apilar(&pilaSaltos,1); } operacion  {derPointer = operacionPointer;} |
             OP_NOT operacion {izqPointer = operacionPointer; esBetween =0;} OP_DISTINTO{printf("comparacion por distinto negada\n"); apilar(&pilaSaltos,3); } operacion  {derPointer = operacionPointer;} |
             OP_NOT operacion {izqPointer = operacionPointer; esBetween =0;} OP_IGUALDAD{printf("comparacion por igual negada\n"); apilar(&pilaSaltos,6); } operacion  {derPointer = operacionPointer;} |
             between ;

repeticion: WHILE { 
                     cadenaEtiq = malloc(sizeof (char)* 156);
		                  strcpy(cadenaEtiq,"ETIQ");
                      itoa(etiquetaWhile,numeroTextoWhile,10);
		                  strcat(cadenaEtiq,numeroTextoWhile);
		                  etiquetaWhile++;
		                  etiqueta = crearTerceto(cadenaEtiq,"","");
	                    apilar(&condPila,etiqueta); //Lo pongo aca arriba antes de que se aumente el contador de tercetos */
                  }

            P_A condicion P_C LL_A bloque LL_C {
              
                                                printf("bucle while\n");
                                               saltoWhile = desapilar(&pilaSaltos); //numero de salto
					                                      numeroTercetoWhile = desapilar(&condPila); //numero de terceto (aca estaría el numero donde deberia ir el terceto del salto si ya no cumple la condicion del while)
					                                      crearTercetoNumero (devolverSalto(saltoWhile), crearIndice(contadorTercetos+1),"", numeroTercetoWhile); //Hago un +2 porque tengo: 1-Terceto de JMP primero
					                                      completarTercetosAnd(contadorTercetos);
					                                      numeroTercetoWhile = desapilar(&condPila); //Desapilo la posicion del inicio del While
					                                      crearTerceto ("JMP", crearIndice(numeroTercetoWhile),"");
            
                                                };

between: BETWEEN P_A ID {esBetween = 1; 
                         
                         cadenaIDBetween = malloc(sizeof(char)*strlen($3));
                         strcpy(cadenaIDBetween,$3);
                        } COMA COR_A operacion{
																					      crearTerceto("CMP",cadenaIDBetween,crearIndice(operacionPointer));
						                                    apilar(&pilaCompletarAnds,contadorTercetos);
                                                apilar(&pilaSaltosAnd,4);
																					      apilar(&condPila, contadorTercetos);
																					      contadorTercetos ++; 
                                                                            } 
         PUNTO_COMA operacion{
                    	     apilar(&pilaSaltos, 5);
		                       cmpPointer = crearTerceto("CMP",cadenaIDBetween,crearIndice(operacionPointer));
		                       apilar(&condPila, contadorTercetos);
		                       contadorTercetos ++; 
		                       condicionPointer = cmpPointer;
         } 
         COR_C P_C {printf("comparacion con between\n");};

asignacionlet: LET lista_var OP_IGUAL P_A lista_valores P_C { if(cantValores != cantVariables){yyerror("Error, no coinciden los argumentos del let con las variables");} 
                                                              printf("lista let\n");
                                                              crearTercetosLet();
                                                              };

lista_var: lista_var COMA ID {cantVariables++;printf("Item de la lista del let %s\n",yylval.str_val);
                              vectorLetTipoDatos[cantVariables-1] = getTipoPorID($<str_val>3);
                              printf("EL TIPO DE DATOS DEL LET ES: %d \n", vectorLetTipoDatos[cantVariables-1]);
							                tercetoID = crearTerceto(yylval.str_val,"","");
							                apilar(&pilaIdsLet,tercetoID);
                            };

lista_var: ID {cantVariables++;
              vectorLetTipoDatos[cantVariables-1] = getTipoPorID($<str_val>1);
              
               printf("Item de la lista del let %s\n",yylval.str_val);
               tercetoID = crearTerceto(yylval.str_val,"",""); 
			         apilar(&pilaIdsLet,tercetoID);
              };

lista_valores: {ultimoTipoLeido =  vectorLetTipoDatos[cantValores];} operacion {cantValores++;
                          
                         printf("argumento del let es operacion \n");
                         tercetoOperacion = operacionPointer;
						             apilar(&pilaOperacionesLet,tercetoOperacion);
                        };
                        

lista_valores: lista_valores PUNTO_COMA {ultimoTipoLeido =  vectorLetTipoDatos[cantValores];} operacion {cantValores++;
                                                   printf("argumento del let es operacion \n");
                                                   tercetoOperacion = operacionPointer;
						                                       apilar(&pilaOperacionesLet,tercetoOperacion);
                                                  };

comentarios: COMENTARIO {printf("Se muestra un comentario: \n");};

ingreso:GET ID {printf("Ingreso de datos\n");
                //numeroGET = crearTerceto($2,"","");
				        crearTerceto("GET",$2,"");
               }

egreso: DISPLAY CONSTSTRING {printf("Salida de string por pantalla\n");agregarCteStringATabla(yylval.str_val);
                            crearTerceto("DISPLAY",yylval.str_val,"");
                            } | 
        DISPLAY ID {printf("Salida de variable por pantalla\n");
                    crearTerceto("DISPLAY",$2,"");
                   };
%%


int main(int argc,char *argv[])
{
  if ((yyin = fopen(argv[1], "rt")) == NULL)
  {
	printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  }
  else
  {
    crearPila(&pilaOperaciones);
    crearPila(&pilaTerminos);
    crearPila(&pilaIdsLet);
    crearPila(&pilaOperacionesLet);
    crearPila(&condPila);
    crearPila(&pilaSaltos);
    crearPila(&pilaCompletarAnds);
    crearPila(&pilaSaltosAnd);
    crearPila(&pilaBtw);
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
             fprintf(arch, "|%-30s|%-30f|%-30s", "CTE_REAL",tablaSimbolo[i].valorFloat," -");
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
  strcpy(tablaParaStrings[cantVariablesADeclarar].nombre,cadena); 
  //printf("SE VA A GUARDAR LA CADENA:%s. y su tipo de dato es %d",tablaParaStrings[cantVariablesADeclarar].nombre,tipoDatoADeclarar);
  cantVariablesADeclarar++;
}

void grabarLineaEnTablaAuxSimbolo()
{
  //printf("\n\n\nTIPO DE DATO A DECLARAR ES:%d.\n\n\n",tipoDatoADeclarar);
  //printf("A GUARDAR:%s:\n",tablaParaStrings[cantVariablesADeclarar-1].nombre);

  char *token = strtok(tablaParaStrings[cantVariablesADeclarar-1].nombre,";");

  int j;
  for(j = 0; token != NULL; j++){

    strcpy(tablaParaStrings[cantDeVariablesDeclaradas].nombre,token);
   //printf("Token: %s---%d\n", token,j);
    token = strtok(NULL, ";");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"ENDEF");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"STRING");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"FLOAT");
    eliminarSubCadena(tablaParaStrings[cantDeVariablesDeclaradas].nombre,"INT");
    agregarTipoVariableATabla(tablaParaStrings[cantDeVariablesDeclaradas].nombre);

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

//Las funciones de pila:

void crearPila( t_pila *p){
    p->tope = 0;
}

int pilaLLena( t_pila *p ){
    return p->tope == TAM_PILA;
}

int pilaVacia( t_pila *p){
    return p->tope == 0; //Verificar
}

int apilar(t_pila *p, int dato){
    if( p->tope == TAM_PILA){
        return 0;
    }
    p->pila[p->tope] = dato;
    p->tope++;
    return 1;
}

int desapilar(t_pila *p){
    if( p->tope == 0){
        return 0;
    }
    p->tope--;
    return p->pila[p->tope];
}

//TERCETOS

char* crearIndice(int num){

char * resultado = (char*)malloc(sizeof(char)*7);
char numeroTexto [4];

	strcpy(resultado,"[");
	itoa(num,numeroTexto,10);
    strcat(resultado,numeroTexto);
	strcat(resultado,"]");
    return resultado;
}

int crearTerceto (char * primero, char *izquierda,char *derecha){//le mandamos los tres strings para crear el terceto. No reciben numeros ni nada, solo strings. 
                                            //la funcion tambien tiene que guardar el terceto creado en el vectorTercetos.
                                           //La posicion en el vector se lo da contadorTercetos. Variable que debe aumentar en 1.
  terceto nuevo;
  nuevo.primerElemento = malloc(sizeof(char)*strlen(primero)+1);
  strcpy(nuevo.primerElemento,primero);
  nuevo.elementoIzquierda = malloc(sizeof(char)*strlen(izquierda)+1);
  strcpy(nuevo.elementoIzquierda,izquierda);
  nuevo.elementoDerecha = malloc(sizeof(char)*strlen(derecha)+1);
  strcpy(nuevo.elementoDerecha,derecha);
  nuevo.numeroTerceto = contadorTercetos;
  //printf("%d %s %s %s\n",nuevo.numeroTerceto,nuevo.primerElemento,nuevo.elementoIzquierda,nuevo.elementoDerecha);
  vectorTercetos[contadorTercetos] = nuevo;
  contadorTercetos++;
  return nuevo.numeroTerceto;
} 
int crearTercetoNumero(char* primero, char * izquierda, char *derecha, int numero){
  terceto nuevo;
  nuevo.primerElemento = malloc(sizeof(char)*strlen(primero)+1);
  strcpy(nuevo.primerElemento,primero);
  nuevo.elementoIzquierda = malloc(sizeof(char)*strlen(izquierda)+1);
  strcpy(nuevo.elementoIzquierda,izquierda);
  nuevo.elementoDerecha = malloc(sizeof(char)*strlen(derecha)+1);
  strcpy(nuevo.elementoDerecha,derecha);
  nuevo.numeroTerceto = numero;
  vectorTercetos[numero] = nuevo;
  return nuevo.numeroTerceto;
}//Parecida a la anterior pero crea un terceto con un numero en especifico.
                             //No aumenta en 1 contadorTercetos.
                           //La funcion guarda el terceto en el vector en la posicion que recibe por argumento.

void reverse(char* str, int len) 
{ 
    int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
} 
  
// Convierte el entero dado a un string str[].  
// d es el numero de digitos requridos en la salida.  
// Si d es mas que el numero de digitos en x entonces ceros son agregados al principio. 
int itoaBienPiola(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
  
    // Si un numero de digitos es mayor entonces agrega ceros al principio 
    while (i < d) 
        str[i++] = '0'; 
  
    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 
  
// Convierte un float/double a un string 
void ftoa(float n, char* res, int afterpoint) 
{ 
    // Saca la parte entera 
    int ipart = (int)n; 
  
    // Extrae la parte flotante
    float fpart = n - (float)ipart; 
  
    // Convierte la parte entera en string
    int i = itoaBienPiola(ipart, res, 0); 
  
    if (afterpoint != 0) { 
        res[i] = '.'; // add dot 
        fpart = fpart * pow(10, afterpoint); 
  
        itoaBienPiola((int)fpart, res + i + 1, afterpoint); 
    } 
} 
void guardarTercetosEnArchivo(char *nombreArchivo){//guarda los tercetos en un archivo con el nombre que nosotros le pasemos (creo que en un binaro queda mejor)
  int i;
  FILE * fp;
  fp = fopen(nombreArchivo,"w+t");
  terceto aux;
  for (i=0;i<contadorTercetos;i++){
    aux = vectorTercetos[i];
    fprintf(fp,"%d (%s,%s,%s) \n",aux.numeroTerceto,aux.primerElemento,aux.elementoIzquierda,aux.elementoDerecha);
  }
  fclose(fp);
} 

char * devolverSalto(int numero){
	switch (numero){
		case 1:
			return "JNAE";
			break;
		case 2:
			return "JNBE";
			break;
		case 3:
			return "JNE";
			break;
		case 4:
			return "JNB";
			break;
		case 5:
			return "JNA";
			break;
		case 6:
			return "JE";
			break;
    default:
      return "Invalido";
      break;
	}
}

 

//Función para buscar por el nombre de la variable, devuelve un int correspondiente al tipo de dato si lo encuentra
/*
#define Int 1
#define Real 2
#define String 3
#define CteInt 4
#define CteFloat 5
#define CteString 6
*/
//devuelve -1 si no
int getTipoPorID(char* name)
{
   int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return tablaSimbolo[i].tipoDato;
     }
     i++;
   }

   yyerror("Error: la variable no se encontraba");
   return -1;
}

//Función para buscar por el nombre de la variable, devuelve el valor si lo encuentra, devuelve -1 si no. 
char* getValorPorID(char* name)
{
 int i=0;
   while(i<=finDeTabla){
     if(strcmp(tablaSimbolo[i].nombre,name) == 0){
       return tablaSimbolo[i].valorSimbolo;
     }
     i++;
   }
   return NULL;
}

void parsearCadena (char * origen, char * destino){
  int i=0,contDestino=0;
  while(origen[i]!=' ' && origen[i]!=':'){
    destino[i]=origen[i];
    i++;
  }
  destino[i]='\0';
}

void crearTercetosLet(){
	int numeroID, numeroOperacion;
	while(!pilaVacia(&pilaIdsLet)){
		numeroID = desapilar(&pilaIdsLet);
		numeroOperacion = desapilar(&pilaOperacionesLet);
		crearTerceto("=",crearIndice(numeroID),crearIndice(numeroOperacion));
	}
}

void completarTercetosAnd(int posicion){
  int tipoSalto, numeroTerceto, n;
  numeroTerceto = desapilar(&pilaCompletarAnds);
  if(numeroTerceto != -1){
    tipoSalto = desapilar(&pilaSaltosAnd);
    crearTercetoNumero(devolverSalto(tipoSalto),crearIndice(contadorTercetos),"",numeroTerceto);
  }

}

void validarAsignacionDeTipos() {
  if(tipoDatoActual != ultimoTipoLeido) {
    yyerror("Asignacion de tipos incorrecta");
  }
}

/**************************************ASSEMBLER****************************************/

void generaAsm(){
int i;
FILE* fp;
fp = fopen("Final.asm","w+t");
terceto aux;
char vectorOperandos[100][100];
int contadorOperandos =0;
int tercetosEtiquetas[1200];
int cantEtiquetas = 0;
fprintf(fp, "include macros2.asm\n");
fprintf(fp, "include number.asm\n"); //Creo que la vamos a necesitar.
fprintf(fp, ".MODEL	LARGE \n");
fprintf(fp, ".386\n");
fprintf(fp, ".STACK 200h \n"); //bytes en stack

//DATA: variables de la tabla de simbolos
fprintf(fp, ".DATA \n");
pasarTsAssembler(fp);
//funcion que pase la TS a este archivo.


//CODE: comienza la seccion de codigo
fprintf(fp, ".CODE \n");
fprintf(fp, "\n");
fprintf(fp, "\t MOV AX,@DATA 	;inicializa el segmento de datos\n");
fprintf(fp, "\t MOV DS,AX \n");
fprintf(fp, "\t MOV ES,AX \n");
fprintf(fp, "\t FNINIT \n");;
fprintf(fp, "\n");

  int opSimple,  // Formato terceto (x,  ,  ) 
	opUnaria,  // Formato terceto (x, x,  )
	opBinaria; // Formato terceto (x, x, x)

//ACA deberia ir la parte de tercetos:
//nos fijamos en que terceto tenemos que poner una etiqueta

for(i=0;i<contadorTercetos;i++){
    if (strcmp(vectorTercetos[i].elementoIzquierda, "") != 0 && strcmp(vectorTercetos[i].elementoDerecha, "") ==0){
      if (strcmp(vectorTercetos[i].primerElemento, "GET") != 0 && strcmp(vectorTercetos[i].primerElemento, "DISPLAY") != 0){
        int repetido=-1,j;
        int indiceEtiqueta = devolverIndice(vectorTercetos[i].elementoIzquierda);
        printf("%d\n",indiceEtiqueta);
        for(j=0;j<cantEtiquetas;j++){
          if(tercetosEtiquetas[j]==indiceEtiqueta){
              repetido =1;
          }
        }
        if(repetido ==-1){
					tercetosEtiquetas[cantEtiquetas] = indiceEtiqueta;
          cantEtiquetas++;
        }
      }
    }
}

//////////EMPEZAMOS A ARMAR LA SECUENCIA DE TERCETOS EN ASSEMBLER //////////////////////////////////////

for(i=0;i<contadorTercetos;i++){
  //vemos si antes que nada tenemos que poner una etiqueta
  int k;
  for(k=0;k<cantEtiquetas;k++){
    if(i == tercetosEtiquetas[k]){
    printf("Aca va una etiqueta man\n");
    fprintf(fp,"SALTO%d: \t ;Etiqueta para los saltos \n",i);
    }
  }
   if(strcmp(vectorTercetos[i].elementoIzquierda,"")==0 && strcmp(vectorTercetos[i].elementoDerecha,"")==0){
     opSimple =1;
     opUnaria=0;
     opBinaria =0;
   }
    if(strcmp(vectorTercetos[i].elementoIzquierda,"")!=0 && strcmp(vectorTercetos[i].elementoDerecha,"")==0){
     opSimple =0;
     opUnaria=1;
     opBinaria =0;
   }
    if(strcmp(vectorTercetos[i].elementoIzquierda,"")!=0 && strcmp(vectorTercetos[i].elementoDerecha,"")!=0){
     opSimple =0;
     opUnaria=0;
     opBinaria =1;
   }

  //VERIFICAMOS QUE CONTIENE EL TERCETO, EN BASE A QUE CLASE DE OPERADOR ES:

   if(opSimple ==1){
     if(strncmp(vectorTercetos[i].primerElemento, "ETIQ", 4) != 0 ){
       //es una constante o un ID
       strcpy(vectorOperandos[contadorOperandos],vectorTercetos[i].primerElemento);
       contadorOperandos++;
       fprintf(fp, "\t FLD %s \t;Cargo valor \n", vectorTercetos[i].primerElemento);
       printf("Se carga un dato solo\n");
     }
     else{
       fprintf(fp,"%s:\t;ETIQUETA\n",vectorTercetos[i].primerElemento);
       printf("Se pone una etiqueta en el archivo\n");
     }
   }

   if(opUnaria==1){
     //puede ser un get, un display o un salto (creo)
     if (strcmp(vectorTercetos[i].primerElemento, "GET") != 0 && strcmp(vectorTercetos[i].primerElemento, "DISPLAY") != 0){
       //no es ni get ni display, entonces es un salto
       int numeroSalto = devolverIndice(vectorTercetos[i].elementoIzquierda);
       fprintf(fp,"%s SALTO%d \t ;salto a donde tengo que ir \n",vectorTercetos[i].primerElemento,numeroSalto);
     }
     else if (strcmp(vectorTercetos[i].primerElemento, "DISPLAY") == 0){
       printf("Entro al DISPLAY \n");
       int tipo = getTipoPorID(vectorTercetos[i].elementoIzquierda);
       
				if (tipo == Real) 
				{
					fprintf(fp, "\t DisplayFloat %s,2 \n", vectorTercetos[i].elementoIzquierda);
          fprintf(fp, "\t newLine \n");
				}
				else if (tipo == Int) 
				{
					fprintf(fp, "\t DisplayFloat %s.0,2 \n", vectorTercetos[i].elementoIzquierda);
          fprintf(fp, "\t newLine \n");
				} else 
				{
					fprintf(fp, "\t DisplayString %s \n", vectorTercetos[i].elementoIzquierda);
          fprintf(fp, "\t newLine \n");
				}

      
     }
     else if (strcmp(vectorTercetos[i].primerElemento, "GET") == 0)
     {printf("Entro al GET \n");
          int tipo = getTipoPorID(vectorTercetos[i].elementoIzquierda);
      
				if (tipo == Real) 
				{
					fprintf(fp, "\t GetFloat %s\n", vectorTercetos[i].elementoIzquierda);
				}
				else if (tipo == Int) 
				{
					fprintf(fp, "\t GetFloat %s\n", vectorTercetos[i].elementoIzquierda);
				} else 
				{
					fprintf(fp, "\t GetString %s\n",vectorTercetos[i].elementoIzquierda);
				}
				
     }
     // Siempre inserto nueva linea despues de mostrar msj
				

   }
   if(opBinaria==1){
    // Expresiones ; Comparaciones ; Asignacion
    



   }

}
///////////////////////////////////////////////////////////////////////////////////////////////////
//Todavia falta, aca se tienen que pasar los tercetos al txt.
//Final
fprintf(fp, "\t mov AX, 4C00h \t ; Genera la interrupcion 21h\n");
fprintf(fp, "\t int 21h \t ; Genera la interrupcion 21h\n");
fclose(fp);

}

void pasarTsAssembler(FILE* fp){
int i=0;
   while(i<=finDeTabla){
      
    int tipo = tablaSimbolo[i].tipoDato;
    char* cadena = (char *) malloc(sizeof(float));

    switch (tipo){
		case Int:
			fprintf(fp, "\t%s dd ?\t\t\t\t\t\t\t\t\t\t ; Declaracion de Variable Int\n", tablaSimbolo[i].nombre );
			break;
		case Real:
			fprintf(fp, "\t%s dd ?\t\t\t\t\t\t\t\t\t\t ; Declaracion de Variable Real\n", tablaSimbolo[i].nombre );
			break;
		case String:
			fprintf(fp,  "\t%s db 30 dup (?),\"$\"\t\t\t\t\t\t\t\t\t\t;Declaracion de Variable String\n", tablaSimbolo[i].nombre );
			break;
		case CteInt:
				fprintf(fp, "\t%s dd %d.0\t\t\t\t\t\t\t\t\t\t;Declaracion de CTEINT \n", tablaSimbolo[i].nombre, tablaSimbolo[i].limite);
			break;
    case CteFloat:
      ftoa(tablaSimbolo[i].valorFloat,cadena,4);
			if(strstr(cadena,".")){
				fprintf(fp, "\t%s dd %f\t\t\t\t\t\t\t\t\t\t;Declaracion de CTEREAL\n", tablaSimbolo[i].nombre, tablaSimbolo[i].valorFloat);
			}else{
				fprintf(fp, "\t%s dd %f.0\t\t\t\t\t\t\t\t\t\t;Declaracion de CTEREAL\n", tablaSimbolo[i].nombre, tablaSimbolo[i].valorFloat);
      }
			break;
		case CteString:
			fprintf(fp, "\t%s db %s, \"$\", 30 dup (?)\t\t\t\t\t\t\t\t\t\t;Declaracion de CTESTRING\n", tablaSimbolo[i].nombre, &(tablaSimbolo[i].valorSimbolo));
			break;
      
      }
     
     i++;

  }
}

int devolverIndice(char * cadena){
  char destino[4];
  int i =0,cont =0;
  int numeroFinal;
  while(cadena[i]!=']'){
    if(cadena[i]!='['){
      destino[cont]=cadena[i];
      cont++;
    }
    i++;
  }
  destino[cont]='\0';
  numeroFinal = atoi(destino);
  return numeroFinal;
}

char* getCodOp(char* token)
{
	if(!strcmp(token, "+"))
	{
		return "FADD";
	}
	else if(!strcmp(token, "="))
	{
		return "MOV";
	}
	else if(!strcmp(token, "-"))
	{
		return "FSUB";
	}
	else if(!strcmp(token, "*"))
	{
		return "FMUL";
	}
	else if(!strcmp(token, "/"))
	{
		return "FDIV";
	}
	
}

terceto devolverTerceto (char* posicion){
int indice = -1;
indice = devolverIndice(posicion);
printf("INDICE: %d \n",indice);
return vectorTercetos[indice];
}

int esTercetoSimple(int indice){
  if(strcmp(vectorTercetos[indice].elementoIzquierda,"")==0 && strcmp(vectorTercetos[indice].elementoDerecha,"")==0){
      return 1;
  }
  return -1;
}
