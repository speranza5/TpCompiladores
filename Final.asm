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

	 FLD a1 	;Cargo valor 
	 GetFloat a1
	 newLine 
	 DisplayFloat a1,2 
	 newLine 
	 FLD 3 	;Cargo valor 
	 FLD 12.5000 	;Cargo valor 
	 FLD 4 	;Cargo valor 
	 FLD a1 	;Cargo valor 
	 FLD b1 	;Cargo valor 
	 FLD [11] 	;Cargo valor 
	 FLD a1 	;Cargo valor 
	 FLD b1 	;Cargo valor 
	 FLD [15] 	;Cargo valor 
	 FLD b1 	;Cargo valor 
	 FLD [18] 	;Cargo valor 
	 FLD 43.2000 	;Cargo valor 
	 FLD 12.5699 	;Cargo valor 
ETIQ0:	;ETIQUETA
	 FLD b 	;Cargo valor 
SALTO29: 	 ;Etiqueta para los saltos 
JNB SALTO54 	 ;salto a donde tengo que ir 
	 newLine 
	 FLD 12 	;Cargo valor 
JNA SALTO55 	 ;salto a donde tengo que ir 
	 newLine 
	 FLD a 	;Cargo valor 
	 FLD 45 	;Cargo valor 
JNAE SALTO43 	 ;salto a donde tengo que ir 
	 newLine 
	 FLD b 	;Cargo valor 
	 FLD 13 	;Cargo valor 
JNAE SALTO43 	 ;salto a donde tengo que ir 
	 newLine 
JMP SALTO54 	 ;salto a donde tengo que ir 
	 newLine 
SALTO43: 	 ;Etiqueta para los saltos 
	 FLD b 	;Cargo valor 
	 FLD 12 	;Cargo valor 
JNAE SALTO51 	 ;salto a donde tengo que ir 
	 newLine 
JMP SALTO53 	 ;salto a donde tengo que ir 
	 newLine 
	 FLD a 	;Cargo valor 
	 FLD 13 	;Cargo valor 
SALTO51: 	 ;Etiqueta para los saltos 
JNE SALTO54 	 ;salto a donde tengo que ir 
	 newLine 
SALTO53: 	 ;Etiqueta para los saltos 
SALTO54: 	 ;Etiqueta para los saltos 
JMP SALTO29 	 ;salto a donde tengo que ir 
	 newLine 
SALTO55: 	 ;Etiqueta para los saltos 
	 FLD b1 	;Cargo valor 
	 GetFloat b1
	 newLine 
	 DisplayString "HOLA SALGO EN PANTALLA" 
	 newLine 
	 FLD uno 	;Cargo valor 
	 FLD dos 	;Cargo valor 
	 FLD tres 	;Cargo valor 
	 FLD a 	;Cargo valor 
	 FLD b 	;Cargo valor 
	 FLD a 	;Cargo valor 
	 FLD b 	;Cargo valor 
	 FLD a 	;Cargo valor 
	 FLD b 	;Cargo valor 
	 mov AX, 4C00h 	 ; Genera la interrupcion 21h
	 int 21h 	 ; Genera la interrupcion 21h
