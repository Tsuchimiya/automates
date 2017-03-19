#ifndef SYMBOLES_H
#define SYMBOLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 256

#define INITIALIZED 1
#define NON_INIT 0




struct cellule {
  char* nom;
  int profondeur;
  int adresse;
  int init;
};

struct cellule tab[TAILLE];

struct cellule tmp[TAILLE]; // pour le free c'est plus facile, et pour + de var


int ajout (char* var,int init, int prof);
int adresse(char*var);
int var_initialized(char*var);
void enlever(int prof);
void free_last_tmp();
int ajout_tmp();
int i_tab();
int i_tmp();

#endif
