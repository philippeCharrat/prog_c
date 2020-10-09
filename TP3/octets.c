#include <stdio.h>
/*
 	Nom : octets.c
	Auteur : CHARRAT Philippe & BRUYERE Axel 
	Objectif : Ce code à pour fonction d'afficher les octets de différents variables à l'aide d'un pointeur char (qui s'incrémente de 1).
        Remarque : https://stackoverflow.com/questions/24885685/is-it-possible-to-assign-char-pointer-to-float-value, ce site a été une référence pour affecter un pointeur char pour un float ou double.	
 */

int main(void) {

	//--- Initialisation des differentes variables avec des valeurs arbitraires---
	short court = 6;
	int entier =12567; 
	int long entier_long = 12567;
	float point= 12.58f;
	double point_double=123.55;
	double long point_double_long = 1523.1000154;

	// --- Partie Int :  ---
	char* ptr_char =(char*) &entier;
	printf("Les octets d'un int : ");
	for (int i = 0 ; i<sizeof(entier);i++) {
		printf("%02x -",*ptr_char);
		ptr_char++;
	}
	
	// --- Partie Long : ---
        printf("\nLes octets d'un long : ");	
	ptr_char  =(char*) &entier_long;
	for (int i = 0 ; i<sizeof(entier_long);i++) {
                printf("%02x -",*ptr_char);
                ptr_char++;
        }
	
	// --- Partie Float : ---
	char const * ptr_char_float =(char const *) &point;
	printf("\nLe octets d'un flotant : ");
	for (int i = 0 ; i<sizeof(point);i++) {
                printf("%d -",ptr_char_float[i]);
        }
	
	// --- Partie Double : ---
	char const  *ptr_point_double = (char const *) &point_double;
	printf("\nLe octets d'un double : ");
        for (int i = 0 ; i<sizeof(point_double);i++) {
                printf("%d -",ptr_point_double[i]);
        }

	// --- Partie Double long ---
        char const *ptr_point_double_long = (char const *) &point_double_long;
	printf("\nLe octets d'un double long : ");
        for (int i = 0 ; i<sizeof(point_double_long);i++) {
                printf("%d -",ptr_point_double_long[i]);
        }

	// --- Partie Short :  ---
        char * ptr_char_short =(char *) &court;
        printf("\nLes octets d'un short : ");
        for (int i = 0 ; i<sizeof(court);i++) {
                printf("%02x -",*ptr_char_short);
                ptr_char_short++;
        }
	printf("\n");

	return(0);		
}
