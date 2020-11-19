#include <stdio.h>
/*
    Nom : operateurs.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code a pour fonction d'afficher les résultats de différentes opérations arithmétiques ou logiques.  
*/
int main() {
	// Initialisation des variables et opérations 
	int a = 16;
	int b = 3;
	int somme = a+b;
	int soustraction = a-b;
	int multiplication = a*b;
	int division = a/b;
	int modulo = a%b;
	int ET = a && b;
	int OU = a || b;
	int NOTb = !b;

	// Partie Affichage 
	printf(" --- Opérations ---\n");
	printf("Somme de a et b : %d \n",somme);
	printf("Soustraction de a et b : %d \n",soustraction);
	printf("Multiplication de a et b : %d \n",multiplication);
	printf("Division de a et b : %d \n", division);
	printf("Modulo de a et b : %d \n",modulo);
	printf("ET de a et b : %d \n",ET);
	printf("OU de a et b : %d \n",OU);
	printf("NOT de b : %d \n",NOTb);
	return(0);
}
