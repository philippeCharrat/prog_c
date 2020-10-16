#include <stdio.h>
/*
 * Nom : factorielle.c
 * Auteur : Philippe Charrat et Axel Bruyere
 * But : On dfinie une fonction factorielle recursive et un main pour avec un tableau de differentes valeurs.
 * Remarque : Pour les iteration 20 et 100, on obtient des valeurs incoherentes car on a depasse la taille max d'un int.  
*/
// Définition de la fonction itérative 
int factorielle(int num) {
	if (num == 0) {
		return 1;
	} else {
		return(num*factorielle(num-1));
	}
}

int main () {
	// Initialisation d'un tableau pour tester différentes factorielles 
	int num[] = {0, 1, 2, 3, 4,5,6,10,20,100};

	// Boucle de test
	for (int i = 0; i<10;i++) {
		printf("Factorielle de %d est : %d\n",num[i],factorielle(num[i]));
	}
}
