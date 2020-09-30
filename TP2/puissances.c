#include <stdio.h>
#include <stdlib.h>
/*
    Nom : puissances.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va calculer et afficher l'argument a à la puissance b.
    Remarque : On a utilisé une bibliothèque supplémentaire pour la fonction atoi. 
                gcc puissances.c -o puissances -lm 
*/
int main(int argc, char * argv[]) {
        // Initialisation et récupération de la variable et calculs.
        if (argc > 2) {
		
                argv++;
                int a = atoi(*argv++);
                int b = atoi(*argv++);
      		int result = 1;
		
        	for (int i=0;i<b;i++) {
			result = result*a;
		}

       		// Partie affichage 
       		printf("Pour a= %i à la puissance %i, on obtient : %i\n",a,b,result);
        }
	else {
		printf("Attention, le nombre d'arguments est insuffisent\n");
	}
        return(0);
}

