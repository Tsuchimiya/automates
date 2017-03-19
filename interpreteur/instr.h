#ifndef INSTR_H
#define INSTR_H
#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX 2048

  int instr[MAX][4];


void ajout_instr(int op, int r0, int r1, int resu);
void affiche_instr();
int indice_tab();


#endif
