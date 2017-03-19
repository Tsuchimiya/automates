#ifndef FONCTIONS_H
#define FONCTIONS_H
#include <stdio.h>
#define MAX 2048

int fonctions[MAX][3];

void ajout_fct(int id, int adresse, int retour);
int adresse_fct(int id);
void set_retour(int id, int retour);

#endif
