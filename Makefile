all : main

main: 	lex.yy.c y.tab.c
	gcc instr.c symboles.c y.tab.c lex.yy.c -ll -o yacc


lex.yy.c : 
	   flex an_lex2.lex

y.tab.c : 
	yacc -dv yacc.y


clean:
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
