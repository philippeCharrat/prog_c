#include <stdio.h>
/*
    Nom : fibonacci.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va simuler la suite de Fibonacci (https://fr.wikipedia.org/wiki/Suite_de_Fibonacci) à n itérations, avec n saisie par l'utilisateur. Le code fonctionne sous la forme d'une boucle for qui va calculer et afficher le ième termes (exclu, les termes 1,2,3).
    Remarque : Si l'utilisateur entre une valeur inférieur à 3, cela est une valeur interdite donc on affiche les 3 premières itérations puis on finit le programme.
*/

int main(int argc, char ** argv) {

    	//-- Initialisations des variables --
        printf("Veuillez saisir votre nombre svp : ");
	int n ;
	scanf("%d",&n);
	int un_2 = 1;
	int un_1 = 1;
	int un = un_1 + un_2;
	
	//--- Affichage des 3 premières itérations ---
	printf("Pour %d itérations, on obtient la suite :\n",n);
	printf("%d, %d, %d,",un_2,un_1,un);
	
	// vérification de la valeurs utilisateurs 
	if (n > 3) {
		// Application de la suite de Fibonnaci 
		for(int i=0;i<=n-3;i++) {
			un_2 = un_1;
			un_1 = un;
			un = un_2 + un_1;
			printf(" %d",un);
			if( i < n-3) { printf(",");}
		}
	} 
	printf("\n");
       return(0);
}

