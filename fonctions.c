#include "fonctions.h"

int i_fct=0;

void ajout_fct(char* id, int adresse, int BP){
  if(i_fct<MAX){
    fonctions[i_fct].nom=malloc(sizeof(id));
    strcpy(fonctions[i_fct].nom,id);
    fonctions[i_fct].adresse=adresse;
    fonctions[i_fct].BP=BP;
  }
  i_fct++;
}

int index_fct(char*var){
  int i=0;
  int trouve=0;

  while(i<i_fct && !trouve){
    if (strcmp(fonctions[i].nom,var)==0){
      trouve=1;
      return i;
      
    }
    i++;
  }

  return -1;
}
int adresse_fct(char* id){
  int i=0;
  if ((i=index_fct(id))>=0){
    return fonctions[i].adresse;
      }
  else
    return -1;
  
}
void set_retour(char* id, int BP){
  int i=0;
  if ((i=index_fct(id))>0){
    fonctions[i].BP=BP;
  }
}

void affiche_fct(){
  int i=0;
  for (i;i<i_fct;i++){
    printf("Fct : %s -- adresse : %d\n",fonctions[i].nom,fonctions[i].adresse); 
  }
}

/*
int main(){
  ajout_fct("prout",2,0);
  affiche_fct();
  printf(" adresse : %d ", adresse_fct("prout"));
}*/
