#include <stdio.h>
/*
    Nom : conditions.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code à pour fonction d'afficher des nombres entre 0 et 1000 qui respecte certaine conditions définit par le cahier des charges et type de boucle implementé en C.
    Remarque : 
	- for : implémente automatiquement la variable.
	- while : besoin d'implémenté la variable.
	- do while : différence avec while, on exécute une première fois la boucle même si la condition n'est pas respectée.
*/
int main() {
	printf("--- Boucle for ---\n ");
	for(int i = 1; i <=1000; i++) {
		if(i%2 == 0 && i%15 == 0) {
			printf("cas a : %d\n",i);
		}
	}
	printf("--- Boucle while ---\n ");
	int j = 1;
	while (j <= 1000) {
		if(j%103 == 0 || j%107 == 0) {
			printf("cas b : %d\n",j);
		}
		j++;
	}
	printf("--- Boucle do while ---\n ");
	int k = 1; 
	do {	
		if((k%7 == 0 || k%5 == 0)&&(k%3 != 0)) {	
			printf("cas c : %d\n",k);
		}
		k++;	
	} while (k <= 1000);
	return(0);
}
