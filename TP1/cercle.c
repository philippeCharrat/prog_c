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
	int rayon = 10;
	if (argc >= 2) {
		argv++;	
		 rayon = atoi(*argv++);
	}  
	float aire = 3.14*rayon*rayon;
 	float perimetre = 3.14*2*rayon;

	// Partie affichage 
	printf("Pour un rayon de %d, on a : \n", rayon);
	printf("- l'aire est %f\n",aire);
	printf("- le périmètre est %f\n",perimetre); 
	return(0); 
}
