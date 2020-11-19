#include <stdio.h>
/*
    Nom : operateur2.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code à pour fonction d'afficher le résultat d'une opération arithmétique ou logique en fonction d'un caractère à l'aide d'un switch case. Pour tester les différents cas, j'ai ajouté une boucle for.  
*/

int main() {
	//-- Initialisation des variables --
	int a = 2;
	int b = 1;
	char op; 
	int somme = a+b;
	int soustraction = a-b;
	int multiplication = a*b;
	int division = a/b;
	int modulo = a%b;
	int et = a && b;
	int ou = a || b;
	char tableau[8];
	tableau[0] = '+';
	tableau[1] = '-';
	tableau[2] = '*';
	tableau[3] = '/';
	tableau[4] = '%';
	tableau[5] = '|';
	tableau[6] = '&';
 	tableau[7] = 'a';
 	
	//-- Initialisation des cas du switch --
	for(int i = 0; i<7; i++) {
		printf("----- Tour %d ----\n",i);
		op = tableau[i];
		switch(op) {
			case '+':printf("Opérateur %c donc on fait la somme de a et b : %d \n",op,somme);break;
	
			case '-':printf("Opérateur %c donc on fait la Soustraction de a et b : %d \n",op,soustraction);break;

			case '*':printf("Opérateur %c donc on fait la Multiplication de a et b : %d \n",op,multiplication);break;

			case '/':printf("Opérateur %c donc on fait la Division de a et b : %d \n",op,division);break;

			case '%':printf("Opérateur %c donc on fait le Modulo de a et b : %d \n",op,modulo);break;

			case '&':printf("Opérateur %c donc on fait l'opération a ET b : %d \n",op,et);break;	

			case '|':printf("Opérateur %c donc on fait l'opération a OU b : %d \n",op,ou);break;

	default: printf("opération non valide\n");	
		}	
	}
	return(0);
}
