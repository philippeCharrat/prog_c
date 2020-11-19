#include <stdio.h>
#include <math.h>
/*
    Nom : binaire.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code à pour fonction d'afficher les nombres au formats binaires. Les nombres affichés sont imposé par l'énnoncé du TP.
    Remarque : pour compiler exécuter ce code, il faut saisir une ligne du type : 
                        gcc binaire.c -o binaire -lm
    cela est lié à la bibliothèque math.h utilisé.
*/

int main() {
    //-- Initialisations des variables --
	int nbr;
	char tab[31];
	int deux = 2;
    int j;
    
    //-- Boucles entre 0 et 65536 --
    for (int i = 0; i < 65537; i++) {
        // Tests des 4 cas du cahier des charges 
        if( i == 0 || i == 1024 || i == 4096 || i == 65535 || i==65536) {
            // Partie Initialisations du tableau 
            j = 0;
            nbr = i;
            while(j<32) {
                tab[31-j]=nbr%2;
                nbr=nbr>>1;
                j++;   
            }
            // Partie Affichage :
            printf("Le nombre i : %d ",i);
            for (int k = 0; k <31; k++) {
                printf("%d",tab[k]);
            }
            printf("\n");
        }
    }
	return(0);
}
