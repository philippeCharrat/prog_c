#include <stdio.h>
#include <string.h>

/*
    Nom : couleur.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va établir une structure couleur qui attend 5 paramètres à savoir 4 caractères qui définissent la couche RGBa en hexadécimale et un tableau de caractère pour le nom de la couleur. Une boucle for est utilisé pour afficher toutes les couleurs initialisées.
    Remarque : le tableau contenant toutes les couleurs a été initialisé à la mains mais on aurais pu l'automatiser en générant aléatoirement les couches RGBa mais pour cela, il faut modifier la structure en enlevant le nom.
    Remarque2 : Nous avons utilisé l'ANSI Escape code pour ajouter des couleurs mais il peut ne pas être compatible avec tous les distributions.
*/

int main(int argc, char ** argv) {

    	//-- Initialisations de la structure  --
	struct couleur{
		char nom[20];
		unsigned char rouge;
		unsigned char bleu;
		unsigned char vert;
		unsigned char alpha;
	};
	
	//-- Initialisations du tableau de structures contenant 10 couleurs différentes --
	struct couleur couleurs[10];
	
	// Couleur 1 : Rouge ---
	strcpy(couleurs[0].nom,"rouge");
	couleurs[0].rouge = 0xFF;
	couleurs[0].bleu = 0x00;
	couleurs[0].vert = 0x00;
	couleurs[0].alpha= 0x00;

	// Couleur 2 : Bleu ---	
	strcpy(couleurs[1].nom,"bleu");
	couleurs[1].rouge = 0x00;
	couleurs[1].bleu = 0xFF;
	couleurs[1].vert = 0x00;
	couleurs[1].alpha= 0x00;

	// Couleur 3 : Vert ---	
	strcpy(couleurs[2].nom,"vert");
	couleurs[2].rouge = 0x00;
	couleurs[2].bleu = 0x00;
	couleurs[2].vert = 0xFF;
	couleurs[2].alpha= 0x00;

	// Couleur 4 : Blanc ---	
	strcpy(couleurs[3].nom,"blanc");
	couleurs[3].rouge = 0xFF;
	couleurs[3].bleu = 0xFF;
	couleurs[3].vert = 0xFF;
	couleurs[3].alpha= 0x00;

	// Couleur 5 : Noir ---	
	strcpy(couleurs[4].nom,"noir");
	couleurs[4].rouge = 0x00;
	couleurs[4].bleu = 0x00;
	couleurs[4].vert = 0x00;
	couleurs[4].alpha= 0x00;

	// Couleur 6 : Jaune ---	
	strcpy(couleurs[5].nom,"jaune");
	couleurs[5].rouge = 0xF7;
	couleurs[5].bleu = 0xFF;
	couleurs[5].vert = 0x3C;
	couleurs[5].alpha= 0x00;

	// Couleur 7 : Violet ---	
	strcpy(couleurs[6].nom,"violet");
	couleurs[6].rouge = 0xFF;
	couleurs[6].bleu = 0xFF;
	couleurs[6].vert = 0xFF;
	couleurs[6].alpha= 0x00;

	// Couleur 8 : Orange ---	
	strcpy(couleurs[7].nom,"orange");
	couleurs[7].rouge = 0xFF;
	couleurs[7].bleu = 0x66;
	couleurs[7].vert = 0x00;
	couleurs[7].alpha= 0x00;

	// Couleur 9 : Saumons ---
	strcpy(couleurs[8].nom,"saumons");
	couleurs[8].rouge = 0xF8;
	couleurs[8].bleu = 0x8E;
	couleurs[8].vert = 0x55;
	couleurs[8].alpha= 0x00;

	// Couleur 10 : Taupe ---	
	strcpy(couleurs[9].nom,"taupe");
	couleurs[9].rouge = 0xC0;
	couleurs[9].bleu = 0xB5;
	couleurs[9].vert = 0xAB;
	couleurs[9].alpha= 0x00;
	
	for (int i = 0; i < 10; i++) {
		printf("-Couleur %d : nom=%7s ",i,couleurs[i].nom);
		printf("\33[31m");
		printf("rouge:%02x",couleurs[i].rouge);
		printf("\33[0m");
		printf("\33[34m");
		printf(" bleu:%02x",couleurs[i].bleu);
		printf("\33[0m");
		printf("\33[32m");
		printf(" vert:%02x",couleurs[i].vert);
		printf("\33[0m");
		printf(" alpha:%02x \n",couleurs[i].alpha);
	}
	return(0);

}

