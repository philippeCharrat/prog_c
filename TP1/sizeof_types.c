#include <stdio.h>
/*
    Nom : sizeof_types.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code a pour fonction d'afficher la taille des différents types de variables (signées ou non).
*/

int main() {
	//-- Initialisation des variables --
	signed char string_signe;
	unsigned char string_unsign;
	short cours;
	unsigned short cours_unsign;
	int entier;
	unsigned int entier_unsign;
	long int entier_long;
	unsigned long int entier_long_unsign;
	long long int entier_long_long;
	unsigned long long int entier_long_long_unsign;
	float point;
	double doubles;
	long double doubles_long;

	//-- Partie Affichage --
	printf("Taille d'un char signé : %lu\n", sizeof(string_signe));
	printf("Taille d'un char unsigné : %lu\n", sizeof(string_unsign));
	printf("Taille d'un short : %lu\n", sizeof(cours));
	printf("Taille d'un short unsign : %lu\n", sizeof(cours_unsign));
	printf("Taille d'un int : %lu\n", sizeof(entier));
	printf("Taille d'un int unsign : %lu\n", sizeof(entier_unsign));
	printf("Taille d'un long : %lu %ld \n", sizeof(entier_long),sizeof(entier_long));
	printf("Taille d'un long unsign : %lu\n", sizeof(entier_long_unsign));
	printf("Taille d'un long long : %lu\n", sizeof(entier_long_long));
	printf("Taille d'un long long unsign : %lu\n", sizeof(entier_long_long_unsign));
	printf("Taille d'un float : %lu\n", sizeof(point));
	printf("Taille d'un double : %lu\n", sizeof(doubles));
	printf("Taille d'un long double : %lu\n", sizeof(doubles_long));

	return(0); 
}

