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
	_3 dd 3.0										;Declaracion de CTEINT 
	_12_50 dd 12.500000										;Declaracion de CTEREAL
	_4 dd 4.0										;Declaracion de CTEINT 
	_43_20 dd 43.200001										;Declaracion de CTEREAL
	_6 dd 6.0										;Declaracion de CTEINT 
	_12 dd 12.0										;Declaracion de CTEINT 
	_45 dd 45.0										;Declaracion de CTEINT 
	_13 dd 13.0										;Declaracion de CTEINT 
	T_VERDADERA db "VERDADERA", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_FALSA db "FALSA", "$", 30 dup (?)										;Declaracion de CTESTRING
	T_anidado db "anidado", "$", 30 dup (?)										;Declaracion de CTESTRING
	_1 dd 1.0										;Declaracion de CTEINT 
	T_HOLA_SALGO_EN_PANTALLA db "HOLA SALGO EN PANTALLA", "$", 30 dup (?)										;Declaracion de CTESTRING
	@aux0 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux1 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux2 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux3 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux4 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux6 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux7 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux8 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux9 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux10 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux11 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux12 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux13 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux14 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux16 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux18 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux20 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux22 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux25 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux28 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux31 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux32 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux35 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux36 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux42 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux43 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux47 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux48 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux53 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux54 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux55 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux60 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux61 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux62 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux63 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux64 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux65 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux66 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux67 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux68 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux69 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux70 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux71 dd ?										 ; Declaracion de Variable Auxiliar real
.CODE 
START: 
	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 FLD _3 	;Cargo valor 
	 FSTP @aux0 	;Almaceno el valor en una var auxiliar
	 FLD _12_50 	;Cargo valor 
	 FSTP @aux1 	;Almaceno el valor en una var auxiliar
	 FLD _4 	;Cargo valor 
	 FSTP @aux2 	;Almaceno el valor en una var auxiliar
	 FLD @aux1 	;Cargo operando izquierda
	 FLD @aux2 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux3 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux0 	;Cargo operando izquierda
	 FLD @aux3 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux4 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux4 	;Cargo valor 
	 FSTP @a3 	;Se lo asigno a la variable que va a guardar el resultado 
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
	 FLD @a1 	;Cargo valor 
	 FSTP @aux9 	;Almaceno el valor en una var auxiliar
	 FLD @b1 	;Cargo valor 
	 FSTP @aux10 	;Almaceno el valor en una var auxiliar
	 FLD @aux9 	;Cargo operando izquierda
	 FLD @aux10 	;Cargo operando derecha
	 FSUB 		;Opero
	 FSTP @aux11 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @b1 	;Cargo valor 
	 FSTP @aux12 	;Almaceno el valor en una var auxiliar
	 FLD @aux11 	;Cargo operando izquierda
	 FLD @aux12 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux13 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux8 	;Cargo operando izquierda
	 FLD @aux13 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux14 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux14 	;Cargo valor 
	 FSTP @a1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _43_20 	;Cargo valor 
	 FSTP @aux16 	;Almaceno el valor en una var auxiliar
	 FLD @aux16 	;Cargo valor 
	 FSTP @p1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _12_50 	;Cargo valor 
	 FSTP @aux18 	;Almaceno el valor en una var auxiliar
	 FLD @aux18 	;Cargo valor 
	 FSTP @p2 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _6 	;Cargo valor 
	 FSTP @aux20 	;Almaceno el valor en una var auxiliar
	 FLD @aux20 	;Cargo valor 
	 FSTP @a 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD _3 	;Cargo valor 
	 FSTP @aux22 	;Almaceno el valor en una var auxiliar
	 FLD @aux22 	;Cargo valor 
	 FSTP @b 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO24: 	 ;Etiqueta para los saltos 
ETIQ0:	;ETIQUETA
	 FLD @b 	;Cargo valor 
	 FSTP @aux25 	;Almaceno el valor en una var auxiliar
	 FLD @a		;comparacion, operando1 
	 FLD @aux25		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNAE SALTO57 	 ;salto a donde tengo que ir 
	 FLD _12 	;Cargo valor 
	 FSTP @aux28 	;Almaceno el valor en una var auxiliar
	 FLD @a		;comparacion, operando1 
	 FLD @aux28		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNBE SALTO58 	 ;salto a donde tengo que ir 
	 FLD @a 	;Cargo valor 
	 FSTP @aux31 	;Almaceno el valor en una var auxiliar
	 FLD _45 	;Cargo valor 
	 FSTP @aux32 	;Almaceno el valor en una var auxiliar
	 FLD @aux31		;comparacion, operando1 
	 FLD @aux32		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO41 	 ;salto a donde tengo que ir 
	 FLD @b 	;Cargo valor 
	 FSTP @aux35 	;Almaceno el valor en una var auxiliar
	 FLD _13 	;Cargo valor 
	 FSTP @aux36 	;Almaceno el valor en una var auxiliar
	 FLD @aux35		;comparacion, operando1 
	 FLD @aux36		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO41 	 ;salto a donde tengo que ir 
	 mov si,OFFSET T_VERDADERA 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	JMP SALTO52 	 ;salto a donde tengo que ir 
SALTO41: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET T_FALSA 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	 FLD @b 	;Cargo valor 
	 FSTP @aux42 	;Almaceno el valor en una var auxiliar
	 FLD _12 	;Cargo valor 
	 FSTP @aux43 	;Almaceno el valor en una var auxiliar
	 FLD @aux42		;comparacion, operando1 
	 FLD @aux43		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNB SALTO49 	 ;salto a donde tengo que ir 
	JMP SALTO51 	 ;salto a donde tengo que ir 
	 FLD @a 	;Cargo valor 
	 FSTP @aux47 	;Almaceno el valor en una var auxiliar
	 FLD _13 	;Cargo valor 
	 FSTP @aux48 	;Almaceno el valor en una var auxiliar
SALTO49: 	 ;Etiqueta para los saltos 
	 FLD @aux47		;comparacion, operando1 
	 FLD @aux48		;comparacion, operando2 
	 FXCH		;intercambio para el fcom
	 FCOM		;Comparo 
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNE SALTO52 	 ;salto a donde tengo que ir 
SALTO51: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET T_anidado 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
SALTO52: 	 ;Etiqueta para los saltos 
	 DisplayString @v2 
	 newLine 
	 FLD @a 	;Cargo valor 
	 FSTP @aux53 	;Almaceno el valor en una var auxiliar
	 FLD _1 	;Cargo valor 
	 FSTP @aux54 	;Almaceno el valor en una var auxiliar
	 FLD @aux53 	;Cargo operando izquierda
	 FLD @aux54 	;Cargo operando derecha
	 FADD 		;Opero
	 FSTP @aux55 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux55 	;Cargo valor 
	 FSTP @a 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO57: 	 ;Etiqueta para los saltos 
	JMP SALTO24 	 ;salto a donde tengo que ir 
SALTO58: 	 ;Etiqueta para los saltos 
	 GetFloat @b1
	 DisplayString T_HOLA_SALGO_EN_PANTALLA 
	 newLine 
	 FLD @uno 	;Cargo valor 
	 FSTP @aux60 	;Almaceno el valor en una var auxiliar
	 FLD @dos 	;Cargo valor 
	 FSTP @aux61 	;Almaceno el valor en una var auxiliar
	 FLD @tres 	;Cargo valor 
	 FSTP @aux62 	;Almaceno el valor en una var auxiliar
	 FLD @a 	;Cargo valor 
	 FSTP @aux63 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux64 	;Almaceno el valor en una var auxiliar
	 FLD @aux63 	;Cargo operando izquierda
	 FLD @aux64 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux65 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a 	;Cargo valor 
	 FSTP @aux66 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux67 	;Almaceno el valor en una var auxiliar
	 FLD @aux66 	;Cargo operando izquierda
	 FLD @aux67 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux68 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @a 	;Cargo valor 
	 FSTP @aux69 	;Almaceno el valor en una var auxiliar
	 FLD @b 	;Cargo valor 
	 FSTP @aux70 	;Almaceno el valor en una var auxiliar
	 FLD @aux69 	;Cargo operando izquierda
	 FLD @aux70 	;Cargo operando derecha
	 FMUL 		;Opero
	 FSTP @aux71 	;Almaceno el resultado en una var auxiliar
	 FFREE  	; Vacio pila
	 FLD @aux71 	;Cargo valor 
	 FSTP @tres 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @aux68 	;Cargo valor 
	 FSTP @dos 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
	 FLD @aux65 	;Cargo valor 
	 FSTP @uno 	;Se lo asigno a la variable que va a guardar el resultado 
	 FFREE  	; Vacio pila
SALTO75: 	;Este salto esta por si la ultima instruccion es un if o algo de eso
mov AX, 4C00h 	 ; Genera la interrupcion 21h
int 21h 	 ; Genera la interrupcion 21h
End START
