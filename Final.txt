include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
.DATA 
	a1 dd ?										 ; Declaracion de Variable Real
	b1 dd ?										 ; Declaracion de Variable Real
	a3 dd ?										 ; Declaracion de Variable Real
	variable1 db 30 dup (?),"$"										;Declaracion de Variable String
	v2 db 30 dup (?),"$"										;Declaracion de Variable String
	p1 dd ?										 ; Declaracion de Variable Real
	p2 dd ?										 ; Declaracion de Variable Real
	p3 dd ?										 ; Declaracion de Variable Real
	a dd ?										 ; Declaracion de Variable Int
	b dd ?										 ; Declaracion de Variable Int
	uno dd ?										 ; Declaracion de Variable Int
	dos dd ?										 ; Declaracion de Variable Int
	tres dd ?										 ; Declaracion de Variable Int
	_3 dd 3.0										;Declaracion de CTEINT 
	_12.500000 dd 12.500000										;Declaracion de CTEREAL
	_4 dd 4.0										;Declaracion de CTEINT 
	_43.200001 dd 43.200001										;Declaracion de CTEREAL
	_12.570000 dd 12.570000										;Declaracion de CTEREAL
	_12 dd 12.0										;Declaracion de CTEINT 
	_45 dd 45.0										;Declaracion de CTEINT 
	_13 dd 13.0										;Declaracion de CTEINT 
	"VERDADERA" db VERDADERA, "$", 30 dup (?)										;Declaracion de CTESTRING
	"FALSA" db FALSA, "$", 30 dup (?)										;Declaracion de CTESTRING
	"anidado" db anidado, "$", 30 dup (?)										;Declaracion de CTESTRING
	"HOLA SALGO EN PANTALLA" db HOLA SALGO EN PANTALLA, "$", 30 dup (?)										;Declaracion de CTESTRING
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

EN DESARROLLO 
	 mov AX, 4C00h 	 ; Genera la interrupcion 21h
	 int 21h 	 ; Genera la interrupcion 21h
