#include <stdio.h>
#include <string.h>

/*
    Nom : chaine.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va gérer 3 cas (avec un switch), le premier est afficher la taille de la première chaine. Le second cas est de copié une chaine dans une troisième via une boucle for. Le troisième est la concaténation de deux chaine.
*/

int main(int argc, char ** argv) {

    	//-- Initialisations des variables --
	struct couleur{
		char nom[20];
		unsigned char rouge;
		unsigned char bleu;
		unsigned char vert;
		unsigned char alpha;
	};

	struct couleur couleurs[10];

	strcpy(couleurs[0].nom,"rouge");
	couleurs[0].rouge = 0xFF;
	couleurs[0].bleu = 0x00;
	couleurs[0].vert = 0x00;
	couleurs[0].alpha= 0x00;	
	strcpy(couleurs[1].nom,"bleu");
	couleurs[1].rouge = 0x00;
	couleurs[1].bleu = 0xFF;
	couleurs[1].vert = 0x00;
	couleurs[1].alpha= 0x00;	
	strcpy(couleurs[2].nom,"vert");
	couleurs[2].rouge = 0x00;
	couleurs[2].bleu = 0x00;
	couleurs[2].vert = 0xFF;
	couleurs[2].alpha= 0x00;	
	strcpy(couleurs[3].nom,"blanc");
	couleurs[3].rouge = 0xFF;
	couleurs[3].bleu = 0xFF;
	couleurs[3].vert = 0xFF;
	couleurs[3].alpha= 0x00;	
	strcpy(couleurs[4].nom,"noir");
	couleurs[4].rouge = 0x00;
	couleurs[4].bleu = 0x00;
	couleurs[4].vert = 0x00;
	couleurs[4].alpha= 0x00;	
	strcpy(couleurs[5].nom,"jaune");
	couleurs[5].rouge = 0xF7;
	couleurs[5].bleu = 0xFF;
	couleurs[5].vert = 0x3C;
	couleurs[5].alpha= 0x00;	
	strcpy(couleurs[6].nom,"violet");
	couleurs[6].rouge = 0xFF;
	couleurs[6].bleu = 0xFF;
	couleurs[6].vert = 0xFF;
	couleurs[6].alpha= 0x00;	
	strcpy(couleurs[7].nom,"orange");
	couleurs[7].rouge = 0xFF;
	couleurs[7].bleu = 0x66;
	couleurs[7].vert = 0x00;
	couleurs[7].alpha= 0x00;
	strcpy(couleurs[8].nom,"saumons");
	couleurs[8].rouge = 0xF8;
	couleurs[8].bleu = 0x8E;
	couleurs[8].vert = 0x55;
	couleurs[8].alpha= 0x00;	
	strcpy(couleurs[9].nom,"taupe");
	couleurs[9].rouge = 0xC0;
	couleurs[9].bleu = 0xB5;
	couleurs[9].vert = 0xAB;
	couleurs[9].alpha= 0x00;
	
	for (int i = 0; i < 10; i++) {
		printf("%s",couleurs[i]);
	}
	return(0);

}

