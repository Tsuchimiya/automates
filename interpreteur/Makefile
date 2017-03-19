all : main

main: 	lex.yy.c y.tab.c
	gcc instr.c y.tab.c lex.yy.c -ll -o yacc


lex.yy.c : 
	   flex interp.lex

y.tab.c : 
	yacc -dv interp.y


clean:
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
