%{  //définitions
  #include <stdio.h>
#include <stdlib.h>
  #include "y.tab.h"

%}

%%
[ \t]+ ;
\n ;
"ADD"  {return tadd; }
"MUL"  {return tmul; }
"SOU"  {return tsou; }
"DIV"  {return tdiv; }
"COP"  {return tcop; }
"AFC"  {return tafc; }
"LOAD" {return tload; }
"EQU" {return tequ; }
"STORE" {return tstore; }
"SUP" {return tsup; }
"SUPE" {return tsupe; }
"INF" {return tinf; }
"INFE" {return tinfe; }
"JMP"  {return tjmp; }
"JMPC"  {return tjmpc; }


"r"      {return treg;} 
[0-9]+ { yylval.nb=atoi(yytext); return tnb;}

. {printf("erreur\n"); return terror;}
