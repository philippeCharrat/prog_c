#include <stdio.h>
/*
    Nom : bit.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code à pour fonction d'afficher 1 si les bits 4 et 20 (à partir de la gauche) sont à 1 sinon 0.
*/

int main(int argc, char ** argv) {

    	//-- Initialisations des variables --
        char tab[31];
        int deux = 2;
    	int j= 0;
        printf("Veuillez saisir votre nombre svp : ");
	int nbr ;
	scanf("%d",&nbr);
	int result = 1;

	// Calcul de sa version binaire
        while(j<32) {
                tab[31-j]=nbr%2;
                nbr=nbr>>1;
                j++;
        }

	// Partie affichage de sa version binaire (optionelle)
	printf("sa forme binaire vaut : ");
	for (int k = 0; k<32;k++){ 
		printf("%d",tab[k]);
	}
	
	// Partie Affichage du résultats :
	printf("\nle resultat vaut :");
       	if (tab[19] ==1 && tab[3] == 1) {
		printf("%i",result);
	}else {
		printf("%i",!result);
	}  
        printf("\n");

        return(0);
}

