%{
  #include "y.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
#include "../instr.h"
  #define TAILLE 256
  int regs[39];
  int memory[TAILLE];
  int tmp[TAILLE];
  void yyerror (char const *s);
  %}
%union { int nb; char *var;};
%token tadd tmul tsou tdiv tcop tafc tload tstore tjmp tinf tinfe tsup tsupe tjmpc tequ terror treg

%token <nb> tnb;


%start Asm

%%

Asm: Instructions;

Instructions: Instruction Instructions
| {int i=0; for (i=0;i<10;i++){
     printf("mem %d : %d\n",i,memory[i]);
     /* printf("tmp %d : %d\n",i,tmp[i]);
	printf("reg %d: %d\n",i,regs[i]);*/
   }
 };

 Instruction: tadd treg tnb  treg tnb  treg  tnb   {regs[$3]=regs[$5]+regs[$7] ;}
             |tmul treg tnb treg  tnb  treg  tnb  { regs[$3]=regs[$5]*regs[$7] ;}
             |tdiv treg  tnb  treg tnb  treg tnb  { regs[$3]=regs[$5]/regs[$7] ;}
             |tsou treg tnb  treg tnb  treg tnb  { regs[$3]=regs[$5]+regs[$7] ;}
             |tcop treg tnb  treg  tnb      {regs[$3]=regs[$5];}

             |tload treg tnb  tnb      {if ($4<=255) regs[$3]=memory[$4];
                                  else regs[$3]=tmp[$4-256];}
             |tstore tnb treg tnb  {if ($2<=255) memory[$2]=regs[$4]; 
                               else tmp[$2-256]=regs[$4];}
             |tafc treg tnb tnb   {regs[$3]=$4; }
|tequ treg tnb treg tnb treg tnb {regs[$3]=regs[$5]==regs[$7];}
|tinf treg tnb treg tnb treg tnb {regs[$3]=regs[$5]<regs[$7];}
|tinfe treg tnb treg tnb treg tnb {regs[$3]=regs[$5]<=regs[$7];}
|tsup treg tnb treg tnb treg tnb {regs[$3]=regs[$5]>regs[$7];}
|tsupe treg tnb treg tnb treg tnb {regs[$3]=regs[$5]>=regs[$7];}

    
;
%%
 void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

main ()
{
  return yyparse() ;
}
