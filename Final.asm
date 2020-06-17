include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
.DATA 
	a1 dd ?										 ; Declaracion de Variable Real
	b1 dd ?										 ; Declaracion de Variable Real
	_2 dd 2.0										;Declaracion de CTEINT 
	_3 dd 3.0										;Declaracion de CTEINT 
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

	 FLD 2 	;Cargo valor 
	 FLD 3 	;Cargo valor 
	 FLD b1 	;Cargo valor 
	 FLD 2 	;Cargo valor 
	 FLD 2 	;Cargo valor 
	 FLD 2 	;Cargo valor 
	 mov AX, 4C00h 	 ; Genera la interrupcion 21h
	 int 21h 	 ; Genera la interrupcion 21h
