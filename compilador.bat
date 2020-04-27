flex Lexico.l
echo lex.yy.c generado
pause
bison -dyv Sintactico.y
echo y.tab.c generado
pause
gcc.exe lex.yy.c y.tab.c -o comp.exe
echo compilador generado
pause
Primera.exe prueba.txt
pause 