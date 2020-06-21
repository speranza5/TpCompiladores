include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
MAXTEXTSIZE equ 50 
.DATA 
	@a1 dd ?										 ; Declaracion de Variable Int
	@b1 dd ?										 ; Declaracion de Variable Int
	@c1 dd ?										 ; Declaracion de Variable Int
	_3 dd 3.0										;Declaracion de CTEINT 
	_5 dd 5.0										;Declaracion de CTEINT 
	_2 dd 2.0										;Declaracion de CTEINT 
	@aux0 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux2 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux3 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux4 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux6 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux7 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux8 dd ?										 ; Declaracion de Variable Auxiliar real
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 FLD _3 	;Cargo valor 
	 FSTP @aux0 	;Almaceno el valor en una var auxiliar
	 FLD @aux0 	;Cargo valor 
	 FSTP @a1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _5 	;Cargo valor 
	 FSTP @aux2 	;Almaceno el valor en una var auxiliar
	 FLD _2 	;Cargo valor 
	 FSTP @aux3 	;Almaceno el valor en una var auxiliar
	 FLD @aux2 	;Cargo operando izquierda
	 FLD @aux3 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux4 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux4 	;Cargo valor 
	 FSTP @b1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @a1 	;Cargo valor 
	 FSTP @aux6 	;Almaceno el valor en una var auxiliar
	 FLD @b1 	;Cargo valor 
	 FSTP @aux7 	;Almaceno el valor en una var auxiliar
	 FLD @aux6 	;Cargo operando izquierda
	 FLD @aux7 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux8 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux8 	;Cargo valor 
	 FSTP @c1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
mov AX, 4C00h 	 ; Genera la interrupcion 21h
int 21h 	 ; Genera la interrupcion 21h
