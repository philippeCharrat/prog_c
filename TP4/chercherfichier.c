#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
	Nom : chercherfichier.c
	Auteurs : Philippe CHARRAT et Axel BRUYERE 
	Objectif : Creer un tableau contenant 10 citations, puis l'utilisateur saisie une sequence. On va parcourir toutes les chaines et voir si la sequence correspond a une des citations a l'aide de deux boucles for et des pointeurs.
Nous avons pris la liberté d'appeler ce prgramme chercher2.c et non chercher.c comme demandé dans l'énoncé car ce nom était déjà pris par le programme de l'exercice 3.4.

*/

int main(void){

   //Initialisation du tableau de 10 citations
   struct ligne_mot {
	   int ligne;
	   int cpt_mot;
   };
   int cpt = 0;
   struct ligne_mot lignes_mot[100];
   char mot_a_trouver[100];
   
   int  compteur_mot_ligne = 0;
   int ligne = 0;
   printf("Quel mot voulez vous chercher : ");
   scanf("%c",mot_a_trouver);

   char* ptr_mot = mot_a_trouver;
   char content[10000];
   int fd,count,size;
   fd = open("./harrypotter.txt",O_RDONLY);
   size = read(fd,content,10000);
   for (count=0;count<size;count++) {
	   
	   if(*ptr_mot == '\0') {
		*ptr_mot = mot_a_trouver[0];
		compteur_mot_ligne = compteur_mot_ligne + 1;
	   } else if (*ptr_mot == content[count]) {
		   ptr_mot = ptr_mot + 1;
		   printf("%c - %c",*ptr_mot,content[count]);
	   } else {
		   ptr_mot = &mot_a_trouver[0];
	   }

	   if (content[count] == '\0') {
		   if (compteur_mot_ligne < 0) {
			   lignes_mot[cpt].ligne = ligne;
			   lignes_mot[cpt].cpt_mot = compteur_mot_ligne ;
			   cpt = cpt +1;
		   }
		   ligne = ligne+ 1;
		   compteur_mot_ligne = 0;
	   }
   }
   close(fd);
   for (int i = 0; i < cpt;i++) 
	  printf("A la ligne %d, il y a %d fois le mot.\n",lignes_mot[i].ligne,lignes_mot[i].cpt_mot);
   return(0);
}
