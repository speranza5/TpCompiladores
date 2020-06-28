flex lexico.l
echo lex.yy.c generado
pause
bison -dyv sintactico.y
echo y.tab.c generado
pause
gcc.exe lex.yy.c y.tab.c -o Tercera.exe
echo compilador generado
pause
Tercera.exe prueba.txt
pause 
echo Se borraran los archivos innecesarios para proximas instancias
pause
del lex.yy.c
del y.tab.c
del y.tab.h
del y.output