#include <stdio.h>
#include <stdlib.h>
#include "operateur.h"

/*
    Nom : calcule.c
    Auteur : CHARRAT Philippe & BRUYERE Axel
    Objectif : Ce code à pour fonction d'afficher le résultat d'une opération arithmétique ou logique en fonction d'un caractère passé en ligne à l'aide du code définie dans operateur.c. 
    Remarque : Si l'on souhaite faire un exécutable qui se nomme calcul, il faut faire la ligne de commande suivante : gcc calcule.c -o calcul  
    Remarque 2 : Ne pas oublier les '' pour le caractère op, exemple : ./calcul '&' 1 1 sinon certain caractères sont considérés comme spéiaux.
*/

// Définitions des différentes fonctions utiles et pré-définie dans operateur.h
void somme(int a, int b) {
	printf("La somme de %d et %d est : %d\n",a,b,a+b);
};
void soustraction(int a, int  b) {
	printf("La soustraction de %d à %d est : %d\n",b,a,a-b);
};
void multiplication(int a, int b) {
	printf("La multiplication de %d et %d est : %d\n",a,b,a*b);
};
void modulo(int a, int b) {
	printf("Le modulo de %d et %d est : %d\n",b,a,a%b);
};
void division(int a, int b) {
	printf("La somme de %d par %d est : %d\n",a,b,a/b);
};

void et(int a ,int b) {	printf("Le résultat  de %d ET %d est : %d\n",a,b,a&&b);};
void ou(int a ,int b){	printf("Le résultat  de %d OU %d est : %d\n",a,b,a||b);};

// Code Main :
int main(int argc, char *argv[] ) {
    //-- Test du nombre d'arguments passés en ligne de commande --
    if (argc == 4) {
	// Initialisation des différentes variables --- 
	int a =atoi( argv[2]);
    	int b =atoi( argv[3]);
    	char op = argv[1][0];
	
	// Affichage d'une opération en foncion du caractère op
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
     }else { printf("Paramètres Non-valides\n"); } 
	return(0);
}
