include macros2.asm
include number.asm
.MODEL  LARGE 
.386
.STACK 200h 
MAXTEXTSIZE equ 50 
.DATA 
    @a1 dd ?                                         ; Declaracion de Variable Int
    @b1 dd ?                                         ; Declaracion de Variable Int
    @c1 dd ?                                         ; Declaracion de Variable Int
    _10 dd 10.0                                     ;Declaracion de CTEINT 
    _5 dd 5.0                                       ;Declaracion de CTEINT 
    T_HOLA_SALGO_EN_PANTALLA db "HOLA SALGO EN PANTALLA", "$", 30 dup (?)                                       ;Declaracion de CTESTRING
    T_VERDADERO db "VERDADERO", "$", 30 dup (?)                                     ;Declaracion de CTESTRING
    T_FALSO db "FALSO", "$", 30 dup (?)                                     ;Declaracion de CTESTRING
    _6 dd 6.0                                       ;Declaracion de CTEINT 
    @aux0 dd ?                                       ; Declaracion de Variable Auxiliar real
    @aux2 dd ?                                       ; Declaracion de Variable Auxiliar real
    @aux5 dd ?                                       ; Declaracion de Variable Auxiliar real
    @aux6 dd ?                                       ; Declaracion de Variable Auxiliar real
    @aux12 dd ?                                      ; Declaracion de Variable Auxiliar real
.CODE 
START: 
     MOV AX,@DATA   ;inicializa el segmento de datos
     MOV DS,AX 
     MOV ES,AX 
     FNINIT 

     FLD _10    ;Cargo valor 
     FSTP @aux0     ;Almaceno el valor en una var auxiliar
     FLD @aux0  ;Cargo valor 
     FSTP @a1   ;Se lo asigno a la variable que va a guardar el resultado 
     FFREE      ; Vacio pila
     FLD _5     ;Cargo valor 
     FSTP @aux2     ;Almaceno el valor en una var auxiliar
     FLD @aux2  ;Cargo valor 
     FSTP @b1   ;Se lo asigno a la variable que va a guardar el resultado 
     FFREE      ; Vacio pila
     DisplayString T_HOLA_SALGO_EN_PANTALLA 
     newLine 
     FLD @a1    ;Cargo valor 
     FSTP @aux5     ;Almaceno el valor en una var auxiliar
     FLD @b1    ;Cargo valor 
     FSTP @aux6     ;Almaceno el valor en una var auxiliar
     FLD @aux5      ;comparacion, operando1 
     FLD @aux6      ;comparacion, operando2 
     FXCH       ;intercambio para el fcom
     FCOM       ;Comparo 
     FSTSW AX       ; mueve los bits C a FLAGS
     SAHF           ;Almacena el registro AH en el registro FLAGS 
    JNB SALTO11      ;salto a donde tengo que ir 
     DisplayString T_VERDADERO 
     newLine 
    JMP SALTO12      ;salto a donde tengo que ir 
SALTO11:     ;Etiqueta para los saltos 
     DisplayString T_FALSO 
     newLine 
SALTO12:     ;Etiqueta para los saltos 
     FLD _6     ;Cargo valor 
     FSTP @aux12    ;Almaceno el valor en una var auxiliar
     FLD @aux12     ;Cargo valor 
     FSTP @a1   ;Se lo asigno a la variable que va a guardar el resultado 
     FFREE      ; Vacio pila
mov AX, 4C00h    ; Genera la interrupcion 21h
int 21h      ; Genera la interrupcion 21h
End START
