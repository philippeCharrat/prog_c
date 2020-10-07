#include <stdio.h>
/*
    Nom : ptrvariable.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code à pour fonction d'afficher les valeurs possibles en fonction des différents types de variables (signé ou non). Il va fonctionné en quatre temps, premier : initialisation des types de variables, deuxième : initialisations des pointeurs. Troisième : affectations des valeurs, quatrième :  afficher les valeurs et adresses. 
*/

int main() {
	// -- Initialisation des variables ---
	signed char string_signe;
	unsigned char string_unsign;
	short cours;
	unsigned short cours_unsign ;
	int entier;
	unsigned int entier_unsign;
	long int entier_long;
	unsigned long int entier_long_unsign;
	long long int entier_long_long;
	unsigned long long int entier_long_long_unsign;
	float point;
	double doubles;
	long double doubles_long;

	// initialisations des pointeurs
	char *ptr_string_signe = &string_signe;
	char *ptr_string_unsign = &string_unsign;
	short *ptr_cours = &cours;
	unsigned short *ptr_cours_unsign = &cours_unsign;
	int *ptr_entier = &entier;
	unsigned int *ptr_entier_unsign =  &entier_unsign;
	long int *ptr_entier_long = &entier_long;
	unsigned long int *ptr_entier_long_unsign = &entier_long_unsign;
	float *ptr_point = &point;
	double *ptr_doubles = &doubles;
	long double *ptr_doubles_long = &doubles_long;

	// Affectation des valeurs attendus
	*ptr_string_signe = 'a';
	*ptr_string_unsign = 'a';
	*ptr_cours = -310;
	*ptr_cours_unsign = 340;
	*ptr_entier = -3200;
	*ptr_entier_unsign = 35000;
	*ptr_entier_long = -2000000;
	*ptr_entier_long_unsign = 4000000;
	*ptr_point = 3.1f;
	*ptr_doubles = -4.000099;
	*ptr_doubles_long = 5.31e-5;

	//-- Partie Affichage ---
	printf("Adresse du char signé : %p \n", ptr_string_signe);
	printf("char signé : %c \n", string_signe);
	printf("Adresse du char unsigné : %p \n", ptr_string_unsign);
	printf("char unsigné : %c \n", string_unsign);
	printf("Adresse du short : %p \n", ptr_cours);
	printf("short : %hd \n", cours);
	printf("Adresse du short unsign : %p \n",ptr_cours_unsign);
	printf("short unsign : %hd \n",cours_unsign);
	printf("Adresse du int : %p\n", ptr_entier);
	printf("int : %d\n", entier);
	printf("Adresse du int unsign : %p\n", ptr_entier_unsign);
	printf("int unsign : %d\n", entier_unsign);
	printf("Adresse du long : %p \n", ptr_entier_long);
	printf("long : %ld \n", entier_long);
	printf("Adresse du long unsign : %p \n",ptr_entier_long_unsign);
	printf("long unsign : %ld \n",entier_long_unsign);
	printf("Adresse du float : %p\n", ptr_point);
	printf("float : %f\n", point);
	printf("Adresse du double : %p\n",ptr_doubles);
	printf("double : %f\n",doubles);
	printf("Adresse du long double : %p\n", ptr_doubles_long);
	printf("long double : %Lg\n", doubles_long);

	return(0); 
}

