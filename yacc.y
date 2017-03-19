%{
  #include "y.tab.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "symboles.h"
  #include "operations.h"
  #include "instr.h"


  int prof=0;
  void yyerror (char const *s);
  %}

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

%%
Prog:Fonctions{printf("prog\n");}; 



Fonctions: Fonction Fonctions {printf("affiche instr\n");affiche_instr();}
           | Main
           {printf("fcts\n");};

Fonction: tint tid tpo Args tpf Body   {printf("fct\n");};

Main: tint tmain tpo Args tpf Body {printf("main\n");}
      |;

Args: tint tid ArgsN {ajout($2,0,prof);}
      |
      {printf("args\n");};
    
ArgsN: tv tint tid ArgsN {ajout($3,0,prof);}
       |
       {printf("aargsn\n");};

                   Body: tao {prof++;} Instrs taf
   {printf("Body %d\n",prof);};

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

} Else {instr[$2][1]=$8;}

Else : telse Body {$$=indice_tab();} ;



E: tid {printf("tid arithm\n"); 
   if (adresse($1)!=-1) 
     {printf("%d \n",adresse($1));$$=adresse($1);} 
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
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
}

|E tinfeq E { ajout_instr(LOAD,R0,$1,VIDE);
            ajout_instr(LOAD,R1,$3,VIDE);
	    ajout_instr(INFE,R0,R0,R1);
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
	    free_last_tmp(); // grossissement pile ? 
	    $$=ajout_tmp();
	    ajout_instr(STORE,$$,R0,VIDE);
}

| E teqeq E {  ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(EQU,R0,R1,R0);
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
	   $$=ajout_tmp();
	   ajout_instr(STORE,$$,R0,VIDE);
    }

| E tou E {ajout_instr(AFC,R0,0,VIDE);
           ajout_instr(LOAD,R1,$3,VIDE);
	   ajout_instr(LOAD,R2,$1,VIDE);
	   ajout_instr(ADD,R1,R1,R2);
	   ajout_instr(SUP,R0,R1,R0);
    
	   free_last_tmp();
	   $$=ajout_tmp();
	   ajout_instr(STORE,$$,R0,VIDE);

	   }
   | Invoc {$$=$1;}
   |tpo E tpf {$$=$2;}
   |E tplus E {printf("ajout\n");
               ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(ADD,R0,R1,R0);
	       free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);
               }

   |E tmin E {printf("soustraction\n");
               ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(SOU,R0,R1,R0);
	       free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);}

   |E tmul E {printf("mult\n");
               ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(MUL,R0,R1,R0);
	       free_last_tmp();
	       $$=ajout_tmp(); 
               ajout_instr(STORE,$$,R0,VIDE);}

   |E tdiv E {printf("div\n");
                ajout_instr(LOAD,R0,$1,VIDE);
               ajout_instr(LOAD,R1,$3,VIDE);
	       ajout_instr(DIV,R0,R1,R0);
	       free_last_tmp();
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
		      enlever(prof);prof--;
		}

;

Invoc:tid tpo Params tpf {printf("invoc\n");};



Params: E ParamsN 
        | {printf("param\n");} ;

ParamsN: tv E ParamsN
         |
         {printf("paramN\n");};

Aff: tid teq E {if (adresse($1)==-1) printf("erreur_declaration\n"); 
   else{ ajout_instr(LOAD,R0,$3,VIDE);
     ajout_instr(STORE,adresse($1),R0,VIDE);
   }
          }
     |
     {printf("aff\n");};

Decl1: tid {ajout($1,0,prof);}
|tid teq E {
            printf("Id : %s\n",$1); 
	    ajout_instr(LOAD,R0,$3,VIDE);
	    ajout_instr(STORE,ajout($1,1,prof),R0,VIDE);
	    
	    printf("affichage");
	    afficher(tab,i_tab());};
     

Decl: tint Decl1 Decln   {printf("decl\n");};

Decln: tv Decl1 Decln
       |
       {printf("Decln\n");};
%%

 void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }

main ()
{
  return yyparse() ;
}

