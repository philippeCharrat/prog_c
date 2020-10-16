#include <stdio.h>
#include <string.h>
#include "operateur.h"
/*
    Nom : operator.c
    Auteur : CHARRAT Philippe & BRUYERE Axel
    Objectif : Ce code à pour fonction d'afficher le résultat d'une opération arithmétique d'un caractère et nombre récupéré par la fonction scanf. 
    Remarque : Les fonctions ont été prédéfinies dans le programme operateur.h
*/

// Définition des Fonctions utiles ---
void somme(int a, int b) {printf("La somme de %d et %d est : %d\n",a,b,a+b);};
void soustraction(int a, int  b) {printf("La soustraction de %d à %d est : %d\n",b,a,a-b);};
void multiplication(int a, int b) {printf("La multiplication de %d et %d est : %d\n",a,b,a*b);};
void modulo(int a, int b) {printf("Le modulo de %d et %d est : %d\n",b,a,a%b);};
void division(int a, int b) {printf("La somme de %d par %d est : %d\n",a,b,a/b);};
void et(int a ,int b) {	printf("Le résultat  de %d ET %d est : %d\n",a,b,a&&b);};
void ou(int a ,int b){	printf("Le résultat  de %d OU %d est : %d\n",a,b,a||b);};

// Programme main ---
int main(void) {
	// Initialisation des variables utiles --
	char op;
	int a,b;

	// Récupération des valeurs de l'utilisateur
	printf("Saisir votre opérateur : "); 
	scanf("%c",&(op));
	printf("Saisir le premier numéro : "); 
	scanf("%d",&(a));
	printf("Saisir le second numéro : "); 
	scanf("%d",&(b));

	// Affichage de l'opération en fonciton de OP
	switch(op) {
	        case '+':somme(a,b);break;
	        case '-':soustraction(a,b);break;
		case '*':multiplication(a,b);break;
		case '/':division(a,b);break;
		case '%':modulo(a,b);break;
		case '&':et(a,b);break;
		case '|':ou(a,b);break;
		default: printf("opération non valide\n");
	}	

	return(0);
}
