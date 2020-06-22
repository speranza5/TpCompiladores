include macros2.asm
include macros.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
MAXTEXTSIZE equ 50 
.DATA 
	@a1 dd ?										 ; Declaracion de Variable Real
	@b1 dd ?										 ; Declaracion de Variable Real
	@a3 dd ?										 ; Declaracion de Variable Real
	@variable1 db 30 dup (?),"$"										;Declaracion de Variable String
	@v2 db 30 dup (?),"$"										;Declaracion de Variable String
	@p1 dd ?										 ; Declaracion de Variable Real
	@p2 dd ?										 ; Declaracion de Variable Real
	@p3 dd ?										 ; Declaracion de Variable Real
	@a dd ?										 ; Declaracion de Variable Int
	@b dd ?										 ; Declaracion de Variable Int
	@uno dd ?										 ; Declaracion de Variable Int
	@dos dd ?										 ; Declaracion de Variable Int
	@tres dd ?										 ; Declaracion de Variable Int
	_6 dd 6.0										;Declaracion de CTEINT 
	_3 dd 3.0										;Declaracion de CTEINT 
	_12 dd 12.0										;Declaracion de CTEINT 
	_45 dd 45.0										;Declaracion de CTEINT 
	_13 dd 13.0										;Declaracion de CTEINT 
	T_VERDADERA db "VERDADERA", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_FALSA db "FALSA", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_anidado db "anidado", "$", 30 dup (?)										;Declaracion de CTESTRING
	_1 dd 1.0										;Declaracion de CTEINT 
	T_HOLA_SALGO_EN_PANTALLA db "HOLA SALGO EN PANTALLA", "$", 30 dup (?)										;Declaracion de CTESTRING
	@aux2 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux4 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux7 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux10 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux13 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux14 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux17 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux18 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux24 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux25 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux29 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux30 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux35 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux36 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux37 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux42 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux43 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux44 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux45 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux46 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux47 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux48 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux49 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux50 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux51 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux52 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux53 dd ?										 ; Declaracion de Variable Auxiliar real
.CODE 
START: 
	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 GetFloat @a1
	 DisplayFloat @a1,2 
	 newLine 
	 FLD _6 	;Cargo valor 
	 FSTP @aux2 	;Almaceno el valor en una var auxiliar
	 FLD @aux2 	;Cargo valor 
	 FSTP @a 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _3 	;Cargo valor 
	 FSTP @aux4 	;Almaceno el valor en una var auxiliar
	 FLD @aux4 	;Cargo valor 
	 FSTP @b 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO6: 	 ;Etiqueta para los saltos 
ETIQ0:	;ETIQUETA
	 FLD @b 	;Cargo valor 
	 FSTP @aux7 	;Almaceno el valor en una var auxiliar
	 FLD @a		;comparacion, operando1 
	 FLD @aux7		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNAE SALTO39 	 ;salto a donde tengo que ir 
	 FLD _12 	;Cargo valor 
	 FSTP @aux10 	;Almaceno el valor en una var auxiliar
	 FLD @a		;comparacion, operando1 
	 FLD @aux10		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNBE SALTO40 	 ;salto a donde tengo que ir 
	 FLD @a 	;Cargo valor 
	 FSTP @aux13 	;Almaceno el valor en una var auxiliar
	 FLD _45 	;Cargo valor 
	 FSTP @aux14 	;Almaceno el valor en una var auxiliar
	 FLD @aux13		;comparacion, operando1 
	 FLD @aux14		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO23 	 ;salto a donde tengo que ir 
	 FLD @b 	;Cargo valor 
	 FSTP @aux17 	;Almaceno el valor en una var auxiliar
	 FLD _13 	;Cargo valor 
	 FSTP @aux18 	;Almaceno el valor en una var auxiliar
	 FLD @aux17		;comparacion, operando1 
	 FLD @aux18		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO23 	 ;salto a donde tengo que ir 
	 mov si,OFFSET T_VERDADERA 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	JMP SALTO34 	 ;salto a donde tengo que ir 
SALTO23: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET T_FALSA 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	 FLD @b 	;Cargo valor 
	 FSTP @aux24 	;Almaceno el valor en una var auxiliar
	 FLD _12 	;Cargo valor 
	 FSTP @aux25 	;Almaceno el valor en una var auxiliar
	 FLD @aux24		;comparacion, operando1 
	 FLD @aux25		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO31 	 ;salto a donde tengo que ir 
	JMP SALTO33 	 ;salto a donde tengo que ir 
	 FLD @a 	;Cargo valor 
	 FSTP @aux29 	;Almaceno el valor en una var auxiliar
	 FLD _13 	;Cargo valor 
	 FSTP @aux30 	;Almaceno el valor en una var auxiliar
SALTO31: 	 ;Etiqueta para los saltos 
	 FLD @aux29		;comparacion, operando1 
	 FLD @aux30		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNE SALTO34 	 ;salto a donde tengo que ir 
SALTO33: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET T_anidado 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
SALTO34: 	 ;Etiqueta para los saltos 
	 DisplayString @v2 
	 newLine 
	 FLD @a 	;Cargo valor 
	 FSTP @aux35 	;Almaceno el valor en una var auxiliar
	 FLD _1 	;Cargo valor 
	 FSTP @aux36 	;Almaceno el valor en una var auxiliar
	 FLD @aux35 	;Cargo operando izquierda
	 FLD @aux36 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux37 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux37 	;Cargo valor 
	 FSTP @a 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO39: 	 ;Etiqueta para los saltos 
	JMP SALTO6 	 ;salto a donde tengo que ir 
SALTO40: 	 ;Etiqueta para los saltos 
	 GetFloat @b1
	 DisplayString T_HOLA_SALGO_EN_PANTALLA 
	 newLine 
	 FLD @uno 	;Cargo valor 
	 FSTP @aux42 	;Almaceno el valor en una var auxiliar
	 FLD @dos 	;Cargo valor 
	 FSTP @aux43 	;Almaceno el valor en una var auxiliar
	 FLD @tres 	;Cargo valor 
	 FSTP @aux44 	;Almaceno el valor en una var auxiliar
	 FLD @a 	;Cargo valor 
	 FSTP @aux45 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux46 	;Almaceno el valor en una var auxiliar
	 FLD @aux45 	;Cargo operando izquierda
	 FLD @aux46 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux47 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a 	;Cargo valor 
	 FSTP @aux48 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux49 	;Almaceno el valor en una var auxiliar
	 FLD @aux48 	;Cargo operando izquierda
	 FLD @aux49 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux50 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a 	;Cargo valor 
	 FSTP @aux51 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux52 	;Almaceno el valor en una var auxiliar
	 FLD @aux51 	;Cargo operando izquierda
	 FLD @aux52 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux53 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux53 	;Cargo valor 
	 FSTP @tres 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @aux50 	;Cargo valor 
	 FSTP @dos 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @aux47 	;Cargo valor 
	 FSTP @uno 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO57: 	;Este salto esta por si la ultima instruccion es un if o algo de eso
mov AX, 4C00h 	 ; Genera la interrupcion 21h
int 21h 	 ; Genera la interrupcion 21h
End START
