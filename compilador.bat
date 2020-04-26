flex Lexico.l
pause
bison -dyv Sintactico.y
pause
gcc.exe lex.yy.c y.tab.c -o comp.exe
pause
comp.exe prueba.txt
pause