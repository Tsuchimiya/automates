#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2048


struct fcellule {
  char* nom;
  int adresse;
  int BP;
};

struct fcellule fonctions[MAX];

void ajout_fct(char* id, int adresse, int BP);
int adresse_fct(char* id);
void set_BP(char* id, int BP);

#endif
