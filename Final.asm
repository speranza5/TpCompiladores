include macros2.asm
include number.asm
.MODEL	LARGE 
.386
.STACK 200h 
.DATA 
	a1 dd ?										 ; Declaracion de Variable Real
	b1 dd ?										 ; Declaracion de Variable Real
	_2 dd 2.0										;Declaracion de CTEINT 
	"HOLA" db HOLA, "$", 30 dup (?)										;Declaracion de CTESTRING
.CODE 

	 MOV AX,@DATA 	;inicializa el segmento de datos
	 MOV DS,AX 
	 MOV ES,AX 
	 FNINIT 

= SALTO0 	 ;salto a donde tengo que ir 
= SALTO0 	 ;salto a donde tengo que ir 
ETIQ0	;ETIQUETA
CMP SALTO5 	 ;salto a donde tengo que ir 
JNBE SALTO11 	 ;salto a donde tengo que ir 
JMP SALTO4 	 ;salto a donde tengo que ir 
	 mov AX, 4C00h 	 ; Genera la interrupcion 21h
	 int 21h 	 ; Genera la interrupcion 21h
