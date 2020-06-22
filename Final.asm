include macros2.asm
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
	_3 dd 3.0										;Declaracion de CTEINT 
	_12.500000 dd 12.500000										;Declaracion de CTEREAL
	_4 dd 4.0										;Declaracion de CTEINT 
	_43.200001 dd 43.200001										;Declaracion de CTEREAL
	_12.570000 dd 12.570000										;Declaracion de CTEREAL
	_12 dd 12.0										;Declaracion de CTEINT 
	_45 dd 45.0										;Declaracion de CTEINT 
	_13 dd 13.0										;Declaracion de CTEINT 
	T_VERDADERA db "VERDADERA", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_FALSA db "FALSA", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_anidado db "anidado", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_HOLA_SALGO_EN_PANTALLA db "HOLA SALGO EN PANTALLA", "$", 30 dup (?)										;Declaracion de CTESTRING
	@aux2 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux3 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux4 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux5 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux6 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux8 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux9 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux10 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux11 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux12 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux13 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux14 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux15 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux16 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux18 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux20 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux23 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux26 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux29 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux30 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux33 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux34 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux40 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux41 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux45 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux46 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux53 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux54 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux55 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux56 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux57 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux58 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux59 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux60 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux61 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux62 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux63 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux64 dd ?										 ; Declaracion de Variable Auxiliar real
.CODE 
START: 
	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 GetFloat a1
	 DisplayFloat @a1,2 
	 newLine 
	 FLD _3 	;Cargo valor 
	 FSTP @aux2 	;Almaceno el valor en una var auxiliar
	 FLD _12.5000 	;Cargo valor 
	 FSTP @aux3 	;Almaceno el valor en una var auxiliar
	 FLD _4 	;Cargo valor 
	 FSTP @aux4 	;Almaceno el valor en una var auxiliar
	 FLD @aux3 	;Cargo operando izquierda
	 FLD @aux4 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux5 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux2 	;Cargo operando izquierda
	 FLD @aux5 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux6 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux6 	;Cargo valor 
	 FSTP @a3 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @a1 	;Cargo valor 
	 FSTP @aux8 	;Almaceno el valor en una var auxiliar
	 FLD @b1 	;Cargo valor 
	 FSTP @aux9 	;Almaceno el valor en una var auxiliar
	 FLD @aux8 	;Cargo operando izquierda
	 FLD @aux9 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux10 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a1 	;Cargo valor 
	 FSTP @aux11 	;Almaceno el valor en una var auxiliar
	 FLD @b1 	;Cargo valor 
	 FSTP @aux12 	;Almaceno el valor en una var auxiliar
	 FLD @aux11 	;Cargo operando izquierda
	 FLD @aux12 	;Cargo operando derecha
	 FSUB 		;Opero
	 FSTP @aux13 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @b1 	;Cargo valor 
	 FSTP @aux14 	;Almaceno el valor en una var auxiliar
	 FLD @aux13 	;Cargo operando izquierda
	 FLD @aux14 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux15 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux10 	;Cargo operando izquierda
	 FLD @aux15 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux16 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux16 	;Cargo valor 
	 FSTP @a1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _43.2000 	;Cargo valor 
	 FSTP @aux18 	;Almaceno el valor en una var auxiliar
	 FLD @aux18 	;Cargo valor 
	 FSTP @p1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _12.5699 	;Cargo valor 
	 FSTP @aux20 	;Almaceno el valor en una var auxiliar
	 FLD @aux20 	;Cargo valor 
	 FSTP @p2 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO22: 	 ;Etiqueta para los saltos 
ETIQ0:	;ETIQUETA
	 FLD @b 	;Cargo valor 
	 FSTP @aux23 	;Almaceno el valor en una var auxiliar
	 FLD @a		;comparacion, operando1 
	 FLD @aux23		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNAE SALTO50 	 ;salto a donde tengo que ir 
	 FLD _12 	;Cargo valor 
	 FSTP @aux26 	;Almaceno el valor en una var auxiliar
	 FLD @a		;comparacion, operando1 
	 FLD @aux26		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNBE SALTO51 	 ;salto a donde tengo que ir 
	 FLD @a 	;Cargo valor 
	 FSTP @aux29 	;Almaceno el valor en una var auxiliar
	 FLD _45 	;Cargo valor 
	 FSTP @aux30 	;Almaceno el valor en una var auxiliar
	 FLD @aux29		;comparacion, operando1 
	 FLD @aux30		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO39 	 ;salto a donde tengo que ir 
	 FLD @b 	;Cargo valor 
	 FSTP @aux33 	;Almaceno el valor en una var auxiliar
	 FLD _13 	;Cargo valor 
	 FSTP @aux34 	;Almaceno el valor en una var auxiliar
	 FLD @aux33		;comparacion, operando1 
	 FLD @aux34		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO39 	 ;salto a donde tengo que ir 
	 mov si,OFFSET T_VERDADERA 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	JMP SALTO50 	 ;salto a donde tengo que ir 
SALTO39: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET T_FALSA 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	 FLD @b 	;Cargo valor 
	 FSTP @aux40 	;Almaceno el valor en una var auxiliar
	 FLD _12 	;Cargo valor 
	 FSTP @aux41 	;Almaceno el valor en una var auxiliar
	 FLD @aux40		;comparacion, operando1 
	 FLD @aux41		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO47 	 ;salto a donde tengo que ir 
	JMP SALTO49 	 ;salto a donde tengo que ir 
	 FLD @a 	;Cargo valor 
	 FSTP @aux45 	;Almaceno el valor en una var auxiliar
	 FLD _13 	;Cargo valor 
	 FSTP @aux46 	;Almaceno el valor en una var auxiliar
SALTO47: 	 ;Etiqueta para los saltos 
	 FLD @aux45		;comparacion, operando1 
	 FLD @aux46		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNE SALTO50 	 ;salto a donde tengo que ir 
SALTO49: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET T_anidado 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
SALTO50: 	 ;Etiqueta para los saltos 
	JMP SALTO22 	 ;salto a donde tengo que ir 
SALTO51: 	 ;Etiqueta para los saltos 
	 GetFloat b1
	 DisplayString T_HOLA_SALGO_EN_PANTALLA 
	 newLine 
	 FLD @uno 	;Cargo valor 
	 FSTP @aux53 	;Almaceno el valor en una var auxiliar
	 FLD @dos 	;Cargo valor 
	 FSTP @aux54 	;Almaceno el valor en una var auxiliar
	 FLD @tres 	;Cargo valor 
	 FSTP @aux55 	;Almaceno el valor en una var auxiliar
	 FLD @a 	;Cargo valor 
	 FSTP @aux56 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux57 	;Almaceno el valor en una var auxiliar
	 FLD @aux56 	;Cargo operando izquierda
	 FLD @aux57 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux58 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a 	;Cargo valor 
	 FSTP @aux59 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux60 	;Almaceno el valor en una var auxiliar
	 FLD @aux59 	;Cargo operando izquierda
	 FLD @aux60 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux61 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a 	;Cargo valor 
	 FSTP @aux62 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux63 	;Almaceno el valor en una var auxiliar
	 FLD @aux62 	;Cargo operando izquierda
	 FLD @aux63 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux64 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux64 	;Cargo valor 
	 FSTP @tres 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @aux61 	;Cargo valor 
	 FSTP @dos 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @aux58 	;Cargo valor 
	 FSTP @uno 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO68: 	;Este salto esta por si la ultima instruccion es un if o algo de eso
mov AX, 4C00h 	 ; Genera la interrupcion 21h
int 21h 	 ; Genera la interrupcion 21h
End START
