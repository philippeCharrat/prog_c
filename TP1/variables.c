#include <stdio.h>
/*
    Nom : variable.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code a pour fonction d'afficher les valeurs possibles en fonction des différents types de variables (signées ou non).
*/

int main() {
	// -- Initialisation des variables ---
	signed char string_signe = 'a';
	unsigned char string_unsign = 'a';
	short cours = -310;
	unsigned short cours_unsign = 340;
	int entier = -3200;
	unsigned int entier_unsign = 35000;
	long int entier_long = -2000000;
	unsigned long int entier_long_unsign = 4000000;
	long long int entier_long_long = -90000000;
	unsigned long long int entier_long_long_unsign = 180000000;
	float point = 3.1f;
	double doubles = -4.000099;
	long double doubles_long = 5.31e-5;

	//-- Partie Affichage ---
	printf("char signé : %c \n", string_signe);
	printf("char unsigné : %c \n", string_unsign);
	printf("short : %hd \n", cours);
	printf("short unsign : %hd \n",cours_unsign);
	printf("int : %d\n", entier);
	printf("int unsign : %d\n", entier_unsign);
	printf("long : %ld \n", entier_long);
	printf("long unsign : %ld \n",entier_long_unsign);
	printf("long long : %lld \n", entier_long_long);
	printf("long long unsign : %lld\n",entier_long_long_unsign);
	printf("float : %f\n", point);
	printf("double : %f\n",doubles);
	printf("long double : %Lg\n", doubles_long);

	return(0); 
}

