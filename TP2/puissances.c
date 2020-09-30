#include <stdio.h>
#include <stdlib.h>
/*
    Nom : cercle.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va calculer et afficher l'aire, le périmètre d'un rayon fournis par l'utilisateur ou par défault.
    Remarque : On a utilisé une bibliothèque supplémentaire pour la fonction atoi. 
                gcc cercle.c -o cercle -lm 
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

