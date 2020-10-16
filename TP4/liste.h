#include <stdio.h>
#include <string.h>

/*
    Nom : liste.h
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Le code  va établir les deux structures nécessaires pour le code liste.c, et pré-définir les deux fonctions à dévelloppées par la suite. 
*/

//-- Initialisations des structures  --
struct couleur{
        unsigned char rouge;
        unsigned char bleu;
        unsigned char vert;
        unsigned char alpha;
};

struct liste_couleurs{
	unsigned char rouge;
	unsigned char bleu;
	unsigned char vert;
	unsigned char alpha;
	struct liste_couleurs *next;
};

// Initialisaton des foncions ---
void insertion(struct liste_couleurs*,struct couleur);

void affichage(struct liste_couleurs*);
