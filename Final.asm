include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
.DATA 
	a1 dd ?										 ; Declaracion de Variable Int
	b1 dd ?										 ; Declaracion de Variable Int
	c1 dd ?										 ; Declaracion de Variable Int
	_2 dd 2.0										;Declaracion de CTEINT 
	_3 dd 3.0										;Declaracion de CTEINT 
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 FLD 2 	;Cargo valor 
	 FLD [0] 	;Cargo valor 
	 FSTP a1 	; Se lo asigno a la variable que va a guardar el resultado 
	 FLD 3 	;Cargo valor 
	 FLD [2] 	;Cargo valor 
	 FSTP b1 	; Se lo asigno a la variable que va a guardar el resultado 
	 FLD a1 	;Cargo valor 
	 FLD b1 	;Cargo valor 
	 FADD 		;Opero
	 FLD [6] 	;Cargo valor 
	 FSTP c1 	; Se lo asigno a la variable que va a guardar el resultado 
	 mov AX, 4C00h 	 ; Genera la interrupcion 21h
	 int 21h 	 ; Genera la interrupcion 21h
