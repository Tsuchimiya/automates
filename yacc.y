%{
  #include "y.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "symboles.h"
  #include "operations.h"
  #include "instr.h"
  #include "fonctions.h"

  // R23 Save du return
  // R22 Décalage VD initialement = 0
  // R21 adresse retour
  int prof=0;
  int save;
  void yyerror (char const *s);
  %}
// %error-verbose compile pas avec ça
%union { int nb; char *var;};

%token tmin tplus tmul tdiv tif telse twhile tao taf tpo tpf tv tpv teq teqeq tret tint tstring tet tou tinclude tdefine tconst tmain tinf tinfeq tsup tsupeq terror tprintf

%left tmul // pour résoudre conflits, à expliquer
%left tdiv
%left tplus
%left tmin
%left teqeq
%left tet
%left tou
%left tinf
%left tinfeq
%left tsup
%left tsupeq

%start Prog

%token <nb> tnb;
%token <var> tid;
%type <nb> E;
%type <nb> Invoc;
%type <nb> tpo;
%type <nb> twhile;
%type <nb> Else;
%type <nb> Args;
%type <nb> ArgsN;
%type <nb> Params;
%type <nb> ParamsN;
%type <nb> BodyFct;
%type <nb> Fonction;

%%
   Prog: {
     ajout_instr(AFC,R21,0,VIDE);
   ajout_instr(AFC,R22,0,VIDE);
   ajout_instr(AFC,R23,0,VIDE);
ajout_instr(JMP,0,VIDE,VIDE);
}Fonctions{printf("prog\n");}; 



 Fonctions: Fonction Fonctions 
 | Main {printf("affiche instr\n");affiche_instr();printf("INDEX TAB: %d INDEX TMP: %d \n",i_tab(),i_tmp());}
	      ;

 Fonction: tint tid  tpo {
   ajout_fct($2,indice_tab(),0);
   
 } Args/* {$$=ajout_tmp();}*/ tpf BodyFct {printf("fct\n");
   //printf("Adresse body fct : %d, adresse tmp : %d\n",$7,$$);
   ajout_instr(LOAD,R23,$7,VIDE);
   //   ajout_instr(STORE,$$,R5,VIDE);
   ajout_instr(JMPR,R21,VIDE,VIDE);
   reset_symb();
  
 };

 Main: tint tmain  tpo {instr[3][1]=indice_tab()-1;} Args tpf BodyFct {printf("main\n");}
      |;

Args: tint tid {ajout($2,0,prof);} ArgsN 
      |
      {printf("args\n");};
    
ArgsN: tv tint tid {ajout($3,0,prof);} ArgsN 
       |
       {printf("aargsn\n");};

Body: tao {prof++;} Instrs taf
   {printf("Body %d\n",prof);enlever(prof);prof--;};

BodyFct: tao {printf("Body fct\n");prof++;} Instrs tret E tpv taf {$$=$5;printf("Body fct%d\n",prof);enlever(prof);prof--;};
//BodyFct: tao {printf("Body fct\n");prof++;} Instrs tret E tpv{$$=$5;printf("Adresse return %d\n",$$);} taf
// {printf("Body fct%d\n",prof);enlever(prof);prof--;};

Instrs: Aff tpv Instrs
       |Decl tpv Instrs 
       |Invoc tpv Instrs
       |While Instrs
       |If Instrs
       |
       {printf("instrs\n");};

If: tif tpo E tpf { 
  ajout_instr(LOAD,R0,$3,VIDE);
  ajout_instr(AFC,R1,0,VIDE);
  ajout_instr(EQU,R0,R0,R1);
  $2=indice_tab();
  ajout_instr(JMPC,0,R0,VIDE);
       }
Body { printf("if\n");  instr[$2][1]=indice_tab()+1;
  ajout_instr(LOAD,R0,$3,VIDE);
  $2=indice_tab(); 
  ajout_instr(JMPC,0,R0,VIDE);

} Else {instr[$2][1]=$8;};

Else : telse Body {$$=indice_tab();} ;



E: tid {printf("tid arithm\n"); 
   if (adresse($1)!=-1) 
     {printf("%d \n",adresse($1));$$=ajout_tmp();
       ajout_instr(LOAD,R0,adresse($1),VIDE);
       ajout_instr(STORE,$$,R0,VIDE);} 
   else printf("erreur var non declaree %s\n", $1);}

   |tnb {printf("nombre : %d\n", $1); 
        ajout_instr(AFC,R0,$1,VIDE); 
	$$=ajout_tmp(); 
	ajout_instr(STORE,$$,R0,VIDE);
        }

|E tinf E { ajout_instr(LOAD,R0,$1,VIDE);
            ajout_instr(LOAD,R1,$3,VIDE);
	    ajout_instr(INF,R0,R0,R1);
	    free_last_tmp(); // grossissement pile ? 
	    free_last_tmp();
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
}

|E tinfeq E { ajout_instr(LOAD,R0,$1,VIDE);
            ajout_instr(LOAD,R1,$3,VIDE);
	    ajout_instr(INFE,R0,R0,R1);
	    free_last_tmp();
	    free_last_tmp(); // grossissement pile ? 
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
}

|E tsup E { ajout_instr(LOAD,R0,$1,VIDE);
            ajout_instr(LOAD,R1,$3,VIDE);
	    ajout_instr(SUP,R0,R0,R1);
	    free_last_tmp(); // grossissement pile ? 
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
}

|E tsupeq E { ajout_instr(LOAD,R0,$1,VIDE);
            ajout_instr(LOAD,R1,$3,VIDE);
	    ajout_instr(SUPE,R0,R0,R1);
	    free_last_tmp();
	    free_last_tmp(); // grossissement pile ? 
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
}

| E teqeq E {  ajout_instr(LOAD,R0,$1,VIDE); // MARCHE PAS
            ajout_instr(LOAD,R1,$3,VIDE);
	    ajout_instr(EQU,R0,R0,R1);
	    free_last_tmp();
	    free_last_tmp(); 
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
    }
| E tet E {ajout_instr(AFC,R0,0,VIDE);
           ajout_instr(LOAD,R1,$3,VIDE);
	   ajout_instr(LOAD,R2,$1,VIDE);
	   ajout_instr(MUL,R1,R1,R2);
	   ajout_instr(SUP,R0,R1,R0);
    free_last_tmp();
	   free_last_tmp();
	   $$=ajout_tmp();
	   ajout_instr(STORE,$$,R0,VIDE);
    }

| E tou E {ajout_instr(AFC,R0,0,VIDE);
           ajout_instr(LOAD,R1,$3,VIDE);
	   ajout_instr(LOAD,R2,$1,VIDE);
	   ajout_instr(ADD,R1,R1,R2);
	   ajout_instr(SUP,R0,R1,R0);
    free_last_tmp();
	   free_last_tmp();
	   $$=ajout_tmp();
	   ajout_instr(STORE,$$,R0,VIDE);

	   }
| Invoc {$$=$1; }
   |tpo E tpf {$$=$2;}
   |E tplus E {printf("ajout\n");
               ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(ADD,R0,R1,R0);
	       free_last_tmp();free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);
               }

   |E tmin E {printf("soustraction\n");
               ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(SOU,R0,R0,R1);
	       free_last_tmp();free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);}

   |E tmul E {printf("mult\n");
               ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(MUL,R0,R1,R0);
	       free_last_tmp();free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);}

   |E tdiv E {printf("div\n");
                ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(DIV,R0,R0,R1);
	       free_last_tmp();free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);};

While: twhile {$1=indice_tab();}
       tpo E tpf 
       {
			 ajout_instr(LOAD,R0,$4,VIDE);
                         ajout_instr(AFC,R1,0,VIDE);
			 ajout_instr(EQU,R0,R0,R1);
			 $3=indice_tab();
			 ajout_instr(JMPC,0,R0,VIDE);
              }
       Body{              
		      ajout_instr(JMP,$1,VIDE,VIDE);
		      instr[$3][1]=indice_tab();
		      printf("while\n"); 
		     
		}


;
// Besoin éventuellement de faire une save du contexte pour plus tard
// appel fct 0 param OK, 1 param OK, 2 params OK, fct dans fct: OK mais fct dans une fct dans une fct NON
// par contre ne met pas d'erreurs quand on met 1 param alors que 2 sont attendus ... 
Invoc:tid  tpo {
  ajout_instr(STORE,ajout_tmp(),R22,VIDE);
  ajout_instr(STORE,ajout_tmp(),R21,VIDE);
  
  $2=i_tab();
  
       } Params { // save=ajout_tmp();
	           printf("ajout tmp retour %d\n",save);
	           printf("nb de parametres de la fct %d\n",$4); 
	           ajout_instr(AFC,R0,i_tab(),VIDE);
	           ajout_instr(ADD,R22,R22,R0);
	           ajout_instr(AFC,R0,$4,VIDE); // +1 avec la save
		   ajout_instr(SOU,R22,R22,R0);
reset_symb();  ajout_instr(AFC,R21,indice_tab()+1,VIDE);
ajout_instr(JMP,adresse_fct($1)-1,VIDE,VIDE);
   } tpf { 
	 
// restauration ctxt   
    
     //  ajout_instr(LOAD,R6,0,VIDE); // BIZARRE
     ajout_instr(LOAD,R21,-1,VIDE);
     ajout_instr(LOAD,R22,-2,VIDE);
     restauration_symb($2-2,255);
     $$=ajout_tmp();
     ajout_instr(STORE,$$,R23,VIDE);
  printf("STORING retour à %d\n",$$);
     
     printf("ici c'est valeur de table des symboles  de invoc : %d\n",$2-2);
     
	 
printf("invoc\n");};


//faire copie des paramètres 
Params: E ParamsN {$$=$2+1;printf(" PARAM = %d\n" , $1);
	 //	 ajout_instr(LOAD,R0,$1,VIDE);
         
	 //	 ajout_instr(STORE,ajout("",1,prof),R0,VIDE);
 }
        | {printf("param\n");} ;

ParamsN: tv E ParamsN {$$=$3+1; //ajout_instr(LOAD,R0,$2,VIDE);
	 //ajout_instr(STORE,ajout("",1,prof),R0,VIDE);
       }
         |
         {printf("paramN\n");};

Aff: tid teq E {if (adresse($1)==-1) printf("erreur_declaration\n"); 
   else{ ajout_instr(LOAD,R0,$3,VIDE);
     ajout_instr(STORE,adresse($1),R0,VIDE);
     free_last_tmp();
   }
          }
     |
     {printf("aff\n");};

Decl1: tid {ajout($1,0,prof);}
|tid teq E {
            printf("Id : %s\n",$1); 
	    ajout_instr(LOAD,R0,$3,VIDE);
	    free_last_tmp();
	    ajout_instr(STORE,ajout($1,1,prof),R0,VIDE);
	    printf("affichage \n");
	    afficher(tab,i_tab());};
     

Decl: tint Decl1 Decln   {printf("decl\n");};

Decln: tv Decl1 Decln
       |
       {printf("Decln\n");};
%%

  void yyerror (char const *s) {
   extern int yylineno;
  fprintf(stderr, "At line %d: %s\n", yylineno, s);
 }

main ()
{
  return yyparse() ;
}

