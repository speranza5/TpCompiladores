include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
.DATA 
	a1 dd ?										 ; Declaracion de Variable Real
	b1 dd ?										 ; Declaracion de Variable Real
	var db 30 dup (?),"$"										;Declaracion de Variable String
	a dd ?										 ; Declaracion de Variable Int
	b dd ?										 ; Declaracion de Variable Int
	uno dd ?										 ; Declaracion de Variable Int
	dos dd ?										 ; Declaracion de Variable Int
	tres dd ?										 ; Declaracion de Variable Int
	"VERDADERO" db VERDADERO, "$", 30 dup (?)										;Declaracion de CTESTRING
	"FALSO" db FALSO, "$", 30 dup (?)										;Declaracion de CTESTRING
	"TERMINE" db TERMINE, "$", 30 dup (?)										;Declaracion de CTESTRING
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

JNBE SALTO6 	 ;salto a donde tengo que ir 
JMP SALTO7 	 ;salto a donde tengo que ir 
SALTO6 	 ;Etiqueta para los saltos 
SALTO7 	 ;Etiqueta para los saltos 
	 mov AX, 4C00h 	 ; Genera la interrupcion 21h
	 int 21h 	 ; Genera la interrupcion 21h
