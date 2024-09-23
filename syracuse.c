// Code pour Syracuse groupe Taurus
// Desmons Teïlo et Alexandre Garrier


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void syracuse(int u_0);


// fonction main qui appelle la fonction syracuse
int main(){
 // Declaration des variables
 int u_0;

  // on demande la valeur d'entrée de U_0

  printf("Entrer la valeur U_0(>1)\n");
  scanf("%d",&u_0);
  syracuse(u_0);
}



// Fonction syracuse
void syracuse(int u_0){

//Declaration des variables
// Les variables de la suite : u_n,u_n+1=u_np1
//p le compteur de rang et A l'altitude

int u_np1,u_n;
int p=0,A;
FILE *fich;


//On ouvre le fichier pour y mettre les données
fich=fopen("donnees_syracuse.txt","w");


// On écrit le nom de notre colonne
fprintf(fich,"#U_n\n");

//On initialise U_n à U_0, l'altitude à U_0 et on marque la valeur U_0 dans le fichier
u_n=u_0;
A=u_0;
fprintf(fich,"%d\n",u_0);

//On fait une boucle while telle que tant que la suite ne converge pas à 1, on continue
while(u_n!=1){
  p=p+1;

  //Condition paire
  if(u_n%2==0){
    u_np1=u_n/2;
    u_n=u_np1;
    fprintf(fich,"%d\n",u_n);
    if (u_n>A){
      A=u_n;
    }
  }

  //Condition impaire
  else{
    u_np1=3*u_n+1;
    u_n=u_np1;
    fprintf(fich,"%d\n",u_n);
    if (u_n>A){
      A=u_n;
    }
  }
}


// On renvoie le nombre d'itérations p = temps de vol

printf("\nLe temps de vol est : %d\n",p);
printf("L'altitude est : %d\n",A);


//On ferme le fichier
fclose(fich);

}
