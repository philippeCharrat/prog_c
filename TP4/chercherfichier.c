#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*
	Nom : chercherfichier.c
	Auteurs : Philippe CHARRAT et Axel BRUYERE 
Objectif : Ce code va chercher 

*/

int main(void){

   //Initialisation d'une structure pour faire le lien entre une ligne et le nombre d'itration
   struct ligne_mot {
	   int ligne;
	   int cpt_mot;
   };
   struct ligne_mot lignes_mot[100];
   
   // Initialisation des variables utiles 
   int  compteur_mot_ligne = 0;
   int ligne = 0;
   int cpt = 0;

   // Initialisation de la sequence a trouver et son pointeur 
   char mot_a_trouver[100];
   printf("Quel mot voulez vous chercher : ");
   scanf("%s",&(mot_a_trouver[0]));
   char* ptr_mot = mot_a_trouver;

   // Initialisation du contenue du fichier .txt
   char content[10000];
   int fd,count,size;
   fd = open("./harrypotter.txt",O_RDONLY);
   size = read(fd,content,10000);
   
   // test un a un tous les caractres du contenue
   for (count=0;count<size;count++) {
	   
	   // 3 cas possibles : 
	   // - 1 : toutes les caracteres ont ete trouves donc on ajoute 1 au compteur.
	   if(*ptr_mot == '\0') {
		ptr_mot = mot_a_trouver;
		compteur_mot_ligne = compteur_mot_ligne + 1;
	   }
	   // - 2 : le caractere est identique a celui du fichier donc on passe au suivant 
	   else if (*ptr_mot == content[count]) {
		   ptr_mot = ptr_mot + 1;
	   }
	   // - 3 : sinon on reset 
	   else { ptr_mot = mot_a_trouver;  }
	   // Si on est en bout de ligne, si le mot a ete trouve alors on ajoute la ligne dans la strcture.
	   if (content[count] == '\n') {
		if (compteur_mot_ligne > 0) {
		   lignes_mot[cpt].ligne = ligne;
		   lignes_mot[cpt].cpt_mot = compteur_mot_ligne ;
		   cpt = cpt +1;
		}
		ligne = ligne+ 1;
		compteur_mot_ligne = 0;
	   }
   }
   close(fd);

   // Affichage de la structure avec ligne et nombre d'iterations
   for (int i = 0; i < cpt;i++) 
	  printf("A la ligne %d, il y a %d fois le mot.\n",lignes_mot[i].ligne,lignes_mot[i].cpt_mot);
   
   return(0);
}
