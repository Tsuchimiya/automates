%{
  #include "y.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "instr.h"
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
| {int i=0; for (i=0;i<indice_tab();i++){
     switch (instr[i][0]){
       case ADD: regs[instr[i][1]]=regs[instr[i][2]]+regs[instr[i][3]];break;

       case MUL:regs[instr[i][1]]=regs[instr[i][2]]*regs[instr[i][3]];break;

       case DIV:regs[instr[i][1]]=regs[instr[i][2]]/regs[instr[i][3]];break;

       case SOU:regs[instr[i][1]]=regs[instr[i][2]]-regs[instr[i][3]];break;

       case COP:regs[instr[i][1]]=regs[instr[i][2]];break;

     case LOAD: if (instr[i][2]<=255) {
	 regs[instr[i][1]]=memory[instr[i][2]];}
                else regs[instr[i][1]]=tmp[instr[i][2]-256];break;

     case STORE:if (instr[i][1]<=255) {
	 memory[instr[i][1]]= regs[instr[i][2]]; }
		  else tmp[ instr[i][1]-256]= regs[instr[i][2]];break;

       case AFC:  regs[instr[i][1]]= instr[i][2];break;
	
       case EQU:  regs[instr[i][1]]=regs[instr[i][2]]==regs[instr[i][3]];break;

       case INF:  regs[instr[i][1]]=regs[instr[i][2]]<regs[instr[i][3]];break;

       case INFE:  regs[instr[i][1]]=regs[instr[i][2]]<=regs[instr[i][3]];break;

       case SUP:  regs[instr[i][1]]=regs[instr[i][2]]>regs[instr[i][3]];break;

       case SUPE:  regs[instr[i][1]]=regs[instr[i][2]]>=regs[instr[i][3]];break;

     case JMP: i=(instr[i][1]);break;

     case JMPC: if (regs[instr[i][2]]!=0 )
		   i=instr[i][1];break;
     }

	      }


for (i=0;i<10;i++){
   
     printf("mem %d : %d\n",i,memory[i]);
     /* printf("tmp %d : %d\n",i,tmp[i]);
	printf("reg %d: %d\n",i,regs[i]);*/
   }
 };

Instruction: tadd treg tnb  treg tnb  treg  tnb   {ajout_instr(ADD,$3,$5,$7);}
            |tmul treg tnb treg  tnb  treg  tnb  { ajout_instr(MUL,$3,$5,$7);}
            |tdiv treg  tnb  treg tnb  treg tnb  { ajout_instr(DIV,$3,$5,$7);}
            |tsou treg tnb  treg tnb  treg tnb  { ajout_instr(SOU,$3,$5,$7);}
            |tcop treg tnb  treg  tnb      {ajout_instr(COP,$3,$5, VIDE);}

            |tload treg tnb  tnb      {ajout_instr(LOAD,$3,$4,VIDE);}
            |tstore tnb treg tnb  {ajout_instr(STORE,$2,$4,VIDE);}
            |tafc treg tnb tnb   {ajout_instr(AFC,$3,$4, VIDE);}
            |tequ treg tnb treg tnb treg tnb {ajout_instr(EQU,$3,$5,$7);}
            |tinf treg tnb treg tnb treg tnb {ajout_instr(INF,$3,$5,$7);}
            |tinfe treg tnb treg tnb treg tnb {ajout_instr(INFE,$3,$5,$7);}
            |tsup treg tnb treg tnb treg tnb {ajout_instr(SUP,$3,$5,$7);}
            |tsupe treg tnb treg tnb treg tnb {ajout_instr(SUPE,$3,$5,$7);}
            |tjmp tnb {ajout_instr(JMP,$2,VIDE,VIDE);}
            |tjmpc tnb treg tnb {ajout_instr(JMPC,$2,$4,VIDE);}

    
;
%%
 void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

main ()
{
  return yyparse() ;
}
