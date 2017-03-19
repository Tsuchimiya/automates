#include "symboles.h"



int index_tab=0; // index de la prochaine case dispo
int index_tmp=0;



int i_tab(){
  return index_tab;
}
int i_tmp(){
  return index_tmp;
}


/*void init_tab(){
  int i;
  for(i=0;i<TAILLE;i++){
    tab[i].case_pleine=0;
  }
  }*/



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
  char buffer=(char)index_tmp;
  ajout_int(tmp,&buffer,INITIALIZED,0,&index_tmp);
  return index_tmp-1+256;
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
	for (i=0;i<index_tmp;i++){
      free(tmp[index_tmp].nom);
      tmp[index_tmp].nom=NULL;
}
  index_tmp=0;
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

/*int main(int argc,char argv[]){

  ajout("test1",INITIALIZED,0);
  printf("%d\n",index_tab);

  ajout("test2",INITIALIZED,1);
  printf("%d\n",index_tab);

  ajout("test3",INITIALIZED,1); 
  printf("%d\n",index_tab);

  afficher(tab,index_tab);

  enlever(1);
  printf("%d\n",index_tab);
  afficher(tab,index_tab);
  printf(" ------------------- %d \n",adresse("test1"));
  

  }
*/
