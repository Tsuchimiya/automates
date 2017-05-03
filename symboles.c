#include "symboles.h"



int index_tab=0; // index de la prochaine case dispo
int index_tmp=TAILLE-1;



int i_tab(){
  return index_tab;
}
int i_tmp(){
  return index_tab;
}

void restauration_symb(int tab,int tmp){
  index_tmp=tmp;
  index_tab=tab;
  
}


int ajout_int (struct cellule * tab1,char* var,int init, int prof, int *index){
  int i=*index;
  int trouve=0;
  /* if(initialized1==0){
    init_tab();
    initialized1=1;
    }*/
  if (i<TAILLE){

    tab1[i].nom=malloc(sizeof(var));
    strcpy(tab1[i].nom,var);
    tab1[i].init=init;
    tab1[i].profondeur=prof;
    tab1[i].adresse=i;
    
    (*index)++;
    return 0;
  }
  
  
  return -1;

} 
// on choisi adresse=indice tableau
int ajout (char* var,int init, int prof){
  ajout_int(tab,var,init,prof,&index_tab);
  return index_tab-1;
}

int ajout_tmp(){
 return  ajout("",INITIALIZED,-1);
  /* char buffer=(char)index_tmp;
  if (index_tmp>index_tab){
    tab[index_tmp].nom=malloc(sizeof(buffer));
    strcpy(tab[index_tmp].nom,&buffer);
    tab[index_tmp].init=INITIALIZED;
    tab[index_tmp].profondeur=-1;
    tab[index_tmp].adresse=index_tmp;
    
    index_tmp--;
  return index_tmp+1;
  }
  else 
  return -1;*/
}


int adresse(char*var){
  int i=index_tab-1;
  int trouve=0;

  while(i>=0 && !trouve){
    if (strcmp(tab[i].nom,var)==0){
      trouve=1;
      return tab[i].adresse;
      
    }
    i--;
  }

  return -1;
}

int var_initialized(char*var){
  int a=adresse(var);
  if (a!=-1){
    tab[a].init=INITIALIZED;
    return 0;
  }
  return -1;
}

void free_last_tmp(){
  int i; 
if (index_tmp>index_tab){
      free(tab[index_tab].nom);
      tab[index_tab].nom=NULL;
      index_tab--;
 }
  /*
  if (index_tmp>index_tab){
      free(tab[index_tmp].nom);
      tab[index_tmp].nom=NULL;
     
  index_tmp--;
  }*/
}

void enlever(int prof){
  int i=index_tab-1;
  int stop=0;

  while(i>0 && !stop){
    if(tab[i].profondeur>=prof){
      free(tab[i].nom);
      tab[i].nom=NULL;
      index_tab--;
    }
    else stop=1;
    i--;
  }

}

void afficher(struct cellule * t, int index){
  int i;
  for(i=0;i<index;i++){
   
    printf("%s : prof %d adresse %d init %d \n",
	   t[i].nom,t[i].profondeur,t[i].adresse,t[i].init);
    
  }
}
void reset_symb(){
  index_tab=0;
  index_tmp=TAILLE-1;
}
/*
int main(int argc,char argv[]){

  ajout("test1",INITIALIZED,0);
  printf("%d\n",index_tab);

  ajout("test2",INITIALIZED,1);
  printf("%d\n",index_tab);

  ajout_tmp(); 
  printf("%d\n",index_tab);

  afficher(tab,TAILLE);
  free_last_tmp();

  enlever(1);
  printf("%d\n",index_tab);
  afficher(tab,TAILLE);
  printf(" ------------------- %d \n",adresse("test1"));
  

  }*/

