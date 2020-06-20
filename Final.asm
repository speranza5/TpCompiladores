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
	T_HOLA SALGO EN PANTALLA db "HOLA SALGO EN PANTALLA", "$", 30 dup (?)										;Declaracion de CTESTRING
	@aux5 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux6 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux10 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux13 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux15 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux16 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux58 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux61 dd ?										 ; Declaracion de Variable Auxiliar real
	@aux64 dd ?										 ; Declaracion de Variable Auxiliar real
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 GetFloat a1
	 DisplayFloat a1,2 
	 newLine 
	 FLD @aux6 	;Cargo valor 
	 FSTP @a3 	;Se lo asigno a la variable que va a guardar el resultado 
	 FLD @aux16 	;Cargo valor 
	 FSTP @a1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FLD @aux18 	;Cargo valor 
	 FSTP @p1 	;Se lo asigno a la variable que va a guardar el resultado 
	 FLD @aux20 	;Cargo valor 
	 FSTP @p2 	;Se lo asigno a la variable que va a guardar el resultado 
ETIQ0:	;ETIQUETA
	 FLD @a		;comparacion, operando1 
	 FLD @aux23		;comparacion, operando2 
	 FCOMP		;Comparo 
	 FFREE ST(0) 	; Vacio ST0
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
SALTO25: 	 ;Etiqueta para los saltos 
	JNB SALTO50 	 ;salto a donde tengo que ir 
	 FLD @a		;comparacion, operando1 
	 FLD @aux26		;comparacion, operando2 
	 FCOMP		;Comparo 
	 FFREE ST(0) 	; Vacio ST0
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNA SALTO51 	 ;salto a donde tengo que ir 
	 FLD @aux29		;comparacion, operando1 
	 FLD @aux30		;comparacion, operando2 
	 FCOMP		;Comparo 
	 FFREE ST(0) 	; Vacio ST0
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNAE SALTO39 	 ;salto a donde tengo que ir 
	 FLD @aux33		;comparacion, operando1 
	 FLD @aux34		;comparacion, operando2 
	 FCOMP		;Comparo 
	 FFREE ST(0) 	; Vacio ST0
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNAE SALTO39 	 ;salto a donde tengo que ir 
	 mov si,OFFSET "VERDADERA" 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	JMP SALTO50 	 ;salto a donde tengo que ir 
SALTO39: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET "FALSA" 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
	 FLD @aux40		;comparacion, operando1 
	 FLD @aux41		;comparacion, operando2 
	 FCOMP		;Comparo 
	 FFREE ST(0) 	; Vacio ST0
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNAE SALTO47 	 ;salto a donde tengo que ir 
	JMP SALTO49 	 ;salto a donde tengo que ir 
SALTO47: 	 ;Etiqueta para los saltos 
	 FLD @aux45		;comparacion, operando1 
	 FLD @aux46		;comparacion, operando2 
	 FCOMP		;Comparo 
	 FFREE ST(0) 	; Vacio ST0
	 FSTSW AX 		; mueve los bits C a FLAGS
	 SAHF 			;Almacena el registro AH en el registro FLAGS 
	JNE SALTO50 	 ;salto a donde tengo que ir 
SALTO49: 	 ;Etiqueta para los saltos 
	 mov si,OFFSET "anidado" 	;Cargo en si el origen
	 mov di,OFFSET @v2 	; cargo en di el destino 
	 STRCPY	; llamo a la macro para copiar 
SALTO50: 	 ;Etiqueta para los saltos 
	JMP SALTO25 	 ;salto a donde tengo que ir 
SALTO51: 	 ;Etiqueta para los saltos 
	 GetFloat b1
	 DisplayString "HOLA SALGO EN PANTALLA" 
	 newLine 
	 FLD @aux64 	;Cargo valor 
	 FSTP @tres 	;Se lo asigno a la variable que va a guardar el resultado 
	 FLD @aux61 	;Cargo valor 
	 FSTP @dos 	;Se lo asigno a la variable que va a guardar el resultado 
	 FLD @aux58 	;Cargo valor 
	 FSTP @uno 	;Se lo asigno a la variable que va a guardar el resultado 
mov AX, 4C00h 	 ; Genera la interrupcion 21h
int 21h 	 ; Genera la interrupcion 21h
