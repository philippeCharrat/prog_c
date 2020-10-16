#include <stdio.h>
#include <string.h>

/*
    Nom : couleur.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va établir une structure couleur qui attend 5 paramètres à savoir 4 caractères qui définissent la couche RGBa en hexadécimale et un tableau de caractère pour le nom de la couleur. Une boucle for est utilisé pour afficher toutes les couleurs initialisées.
    Remarque : le tableau contenant toutes les couleurs a été initialisé à la mains mais on aurais pu l'automatiser en générant aléatoirement les couches RGBa mais pour cela, il faut modifier la structure en enlevant le nom.
    Remarque2 : Nous avons utilisé l'ANSI Escape code pour ajouter des couleurs mais il peut ne pas être compatible avec tous les distributions.
*/

   	//-- Initialisations de la structure  --
struct liste_couleur{
	unsigned char rouge;
	unsigned char bleu;
	unsigned char vert;
	unsigned char alpha;
	struct couleur *next;
};
	
void insertion(struct liste_couleur*,struct couleur) {
	*liste_couleur.rouge = couleur.rouge;
	*liste_couleur.vert = couleur.vert;
	*liste_couleur.bleu = couleur.bleu;
	*liste_couleur.next = &(liste_couleur+sizeof(*liste_couleur));
};

