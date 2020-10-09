#include <stdio.h>

/*
	Nom : chercher2.c
	Auteurs : Philippe CHARRAT et Axel BRUYERE 
	Objectif : Creer un tableau contenant 10 citations, puis l'utilisateur saisie une sequence. On va parcourir toutes les chaines et voir si la sequence correspond a une des citations a l'aide de deux boucles for et des pointeurs.
Nous avons pris la liberté d'appeler ce prgramme chercher2.c et non chercher.c comme demandé dans l'énoncé car ce nom était déjà pris par le programme de l'exercice 3.4.

*/

int main(void){

   //Initialisation du tableau de 10 citations
   char citations[10][100] = {"L'homme est un loup pour l'homme","Science sans conscience n'est que ruine de l'ame","A vaincre sans peril, on triomphe sans gloire","Je est un autre","Je pense donc je suis","Un probleme sans solution est un probleme mal pose","L'enfer c'est les autres","Le souvenir est le parfum de l'ame","L'homme a besoin de passion pour exister","La religion est l'opium du peuple"};   
   //Saisie de la sequence a verifier 
   char phrase_a_verif[100];
   printf("Veuillez saisir la sequence a verifier : ");
   scanf("%s",&(phrase_a_verif[0]));

   // Initialisation des variables et pointeurs 
   char *ptr_citation =citations[0]; 
   int trouve = 0;
  
   //Partie Affichage et Recherche 
   printf("Les phrases sont : \n");

   for (int i=1; i < 11; i++) {
	// Re-definition des variables utiles par tour
       	char *ptr_verif = &phrase_a_verif[0]; 
	int size = 100;	
	printf("phrase %d : %s\n",i,ptr_citation);
	// Parcours des chaines avec 3 cas (1: char null = chaine trouvee; 2: si char sequence = char phrase, on continue; 3 : on stop car deux chars sont differents) 
	for (int j=0; j<100;j++) { 
		if (*ptr_verif == '\0') {
			trouve = i; 
			ptr_citation = ptr_citation + size;
			break;
		} else if(*ptr_citation == *ptr_verif) {	
			ptr_citation = ptr_citation + 1;
			ptr_verif = ptr_verif + 1;
			size = size - 1;
		} else {
			ptr_citation = ptr_citation+size;
			break;
		}
	}
   }
   
   // Affichage du resultat 
   if(trouve != 0) {printf("Votre entrees est la citations n %d.\n",trouve); } 
   else { printf("Votre entrees n'est pas dans les citations.\n"); }
   return(0);
}
