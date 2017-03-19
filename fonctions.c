#include "fonctions.h"

int i_fct=0;

void ajout_fct(int id, int adresse, int retour){
  if(i_fct<MAX){
    fonctions[i_fct][0]=op;
    fonctions[i_fct][1]=adresse;
    fonctions[i_fct][2]=retour;
  }
  i_fct++;
}
int adresse_fct(int id);
void set_retour(int id, int retour);
