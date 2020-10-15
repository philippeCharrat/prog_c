#include <stdio.h>
/*
    Nom : operateur2.c
    Auteur : CHARRAT Philippe & BRUYERE Axel
    Objectif : Ce code à pour fonction d'afficher le résultat d'une opération arithmétique ou logique en fonction d'un caractère à l'aide d'un switch case. Pour tester les différents cas, j'ai ajouté une boucle for.  
*/

int main(int argc, char ** argv ) {
    //-- Initialisation des variables --
    if (argc == 4) {
	int a = argv[3];
    	int b = argv[4];
    	char op = argv[2];
    	int somme = a+b;
    	int soustraction = a-b;
    	int multiplication = a*b;
    	int division = a/b;
    	int modulo = a%b;
    	int et = a && b;
    	int ou = a || b;
    	char tableau[8];
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
    
    } else {
    	printf("Erreur : Manque d'arguments");
    }
    return(0);
}
