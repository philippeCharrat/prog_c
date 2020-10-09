#include <stdio.h>
#include <string.h>

/*
    Nom : couleur_compteur.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va établir une structure couleur qui attend 5 paramètres à savoir 4 caractères qui définissent la couche RGBa en hexadécimale et un tableau de caractère pour le nom de la couleur. Une boucle for est utilisé pour afficher toutes les couleurs initialisées.
    Remarque : le tableau contenant toutes les couleurs a été initialisé à la mains mais on aurais pu l'automatiser en générant aléatoirement les couches RGBa mais pour cela, il faut modifier la structure en enlevant le nom.
    Remarque2 : Nous avons utilisé l'ANSI Escape code pour ajouter des couleurs mais il peut ne pas être compatible avec tous les distributions.
*/

int main(int argc, char ** argv) {

    	//-- Initialisations de 2 structures (couleur: tableau pour toutes les couleurs, couleur_p: tableau pour chaque couleur differente et leur compteur)   --
	struct couleur{
		unsigned char rouge;
		unsigned char bleu;
		unsigned char vert;
		unsigned char alpha;
	};
	
	struct couleur_p{
		unsigned char rouge;
		unsigned char bleu;
		unsigned char vert;
		unsigned char alpha;
		int count; 
	};
	
	//-- Initialisations du tableau de structures contenant 100 couleurs différentes --
	struct couleur couleurs[100] = {{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0xAC,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0xDE,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x0A,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23},{0xFF,0x00,0x00,0x00},{0x00,0xFF,0x00,0x00},{0x00,0x00,0xFF,0x00},{0xFF,0xFF,0x00,0x00},{0xFF,0x00,0xFF,0x00},{0x00,0xFF,0xFF,0x00},{0x00,0x00,0x00,0x00},{0xFF,0xFF,0xFF,0x00},{0xFF,0x23,0x23,0x00},{0xFF,0x23,0x23,0x23}};

	// -- Initialisation du tableau de couleur differente et variables -- 
	struct couleur_p couleur_presente[100];
	couleur_presente[0].rouge = couleurs[0].rouge;
	couleur_presente[0].bleu = couleurs[0].bleu;
	couleur_presente[0].vert = couleurs[0].vert;
	couleur_presente[0].count = 1;
	int taille = 1;
	int compt = 0; 

	// -- Boucle pour parcourir les 99 couleurs 
	for (int j = 1; j < 100; j++) {
		// -- Boucle pour tester les diffenrentes couleurs presentent 
		for(int i = 0; i<taille; i++) {
			// 2 cas : (1- deux couleurs identiques -> increment du compteur; 2- si la couleur n'est pas dans le tableau -> add couleurs) 
			if(couleur_presente[i].rouge == couleurs[j].rouge && couleur_presente[i].bleu == couleurs[j].bleu && couleur_presente[i].vert == couleurs[j].vert && couleur_presente[i].alpha == couleurs[j].alpha) {
				couleur_presente[i].count = couleur_presente[i].count + 1;
				break;
			} else if (i == taille-1) {
				couleur_presente[taille].rouge = couleurs[j].rouge;
				couleur_presente[taille].bleu = couleurs[j].bleu;
				couleur_presente[taille].vert = couleurs[j].vert;
				couleur_presente[taille].alpha = couleurs[j].alpha;
				couleur_presente[taille].count = 1;
				taille = taille + 1;
				break;
			}
		}
	}

	// -- Partie Affichage des couleurs differentes et leurs nombres --- 
	printf("numero ----- r -- g -- b -- a -- count \n");
	for(int i=0; i<taille;i++) {
		printf("Couleur %02i : %02x - %02x - %02x- %02x - %02d\n",i,couleur_presente[i].rouge,couleur_presente[i].bleu,couleur_presente[i].vert,couleur_presente[i].alpha,couleur_presente[i].count);
		compt = compt + couleur_presente[i].count;

	}
	printf("Conclusion : %d couleurs totales repartie en %d couleurs differentes.\n",compt,taille);
	return(0);

}

