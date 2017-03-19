#include "instr.h"

int indice=0;


void ajout_instr(int op, int r0, int r1, int resu){
  if(indice<MAX){
    instr[indice][0]=op;
    instr[indice][1]=r0;
    instr[indice][2]=r1;
    instr[indice][3]=resu;
  }
  indice++;
}

int indice_tab(){
 return indice;
}

void affiche_instr(){
  int i;
  FILE * f;
  f=fopen("asm.txt","a+");
  if (f!=NULL){
    for(i=0;i<indice;i++){
      switch(instr[i][0]){
      case ADD: fprintf(f,"ADD r%d r%d r%d \n",instr[i][1],instr[i][2],instr[i][3]);break;
      case SOU: fprintf(f,"SOU r%d r%d r%d \n",instr[i][1],instr[i][2],instr[i][3]);break;
      case MUL: fprintf(f,"MUL r%d r%d r%d \n",instr[i][1],instr[i][2],instr[i][3]);break;
      case DIV: fprintf(f,"DIV r%d r%d r%d \n",instr[i][1],instr[i][2],instr[i][3]);break;
      case COP: fprintf(f,"COP r%d r%d \n",instr[i][1],instr[i][2]);break;
      case AFC: fprintf(f,"AFC r%d %d \n",instr[i][1],instr[i][2]);break;
      case LOAD: fprintf(f,"LOAD r%d %d \n",instr[i][1],instr[i][2]);break;
      case STORE: fprintf(f,"STORE %d r%d \n",instr[i][1],instr[i][2]);break;
      case EQU:	fprintf(f,"EQU r%d r%d r%d\n",instr[i][1],instr[i][2],instr[i][3]);break;
      case INF: fprintf(f,"INF r%d r%d r%d\n",instr[i][1],instr[i][2],instr[i][3]);break;
      case INFE: fprintf(f,"INFE r%d r%d r%d\n",instr[i][1],instr[i][2],instr[i][3]);break;
      case SUP: fprintf(f,"SUP r%d r%d r%d\n",instr[i][1],instr[i][2],instr[i][3]);break;
      case SUPE: fprintf(f,"SUPE r%d r%d r%d\n",instr[i][1],instr[i][2],instr[i][3]);break;
      case JMP: fprintf(f,"JMP r%d \n",instr[i][1]);break;
      case JMPC: fprintf(f,"JMPC r%d r%d \n",instr[i][1],instr[i][2]);break;
      }
    }
    fclose(f);
  }
}
