#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "liste.h"
/*
    Nom : liste.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Le code main va établir deux structures couleurs qui va contenir des valeurs "test" et liste_couleurs une liste chainées générée à partire de couleurs. Pour cela, on va faire appel à deux fonctions pré-définies dans liste.h et définie dans ce code. La première a pour foncion dajouter un élément dans la liste chainés et la seconde d'afficher la liste.  
*/
// Foncion ajout d'un élément dans la liste chainée directement inspiré de la slide 46 du cours 3.
void insertion(struct liste_couleurs* ptr_liste_couleurs,struct couleur couleurs) {
	struct liste_couleurs *nouveau;
	nouveau = malloc(sizeof(*nouveau));
	nouveau -> rouge = couleurs.rouge;
        nouveau -> bleu = couleurs.bleu;
        nouveau -> vert = couleurs.vert;
        nouveau ->next = (*ptr_liste_couleurs).next;
        ptr_liste_couleurs -> next = nouveau  ;
};

// Fonction affichage des éléments inspiré de la slide 48 du cours 3  
void affichage(struct liste_couleurs* ptr_liste_couleurs) {
        for (int i = 1 ; i < 100; i++)  {
		ptr_liste_couleurs = ptr_liste_couleurs ->next;
		if (ptr_liste_couleurs == NULL) {
			break;
		 }
		else {
        		printf("couleur %d : R-%02x G-%02x B-%02x \n",i,ptr_liste_couleurs -> rouge,ptr_liste_couleurs->vert,ptr_liste_couleurs->bleu);
		}
	}
};

int main() {

   	//-- Initialisations des structures utiles et du pointeur 
	struct couleur couleurs[5] = { {0xFF,0xFF,0xAF}, {0xFF,0xFF,0xBF}, {0xFF,0xFF,0xCF}, {0xFF,0xFF,0xBF}, {0xFF,0xFF,0xCF}};
        struct liste_couleurs liste_couleurs_chaine; 
	struct liste_couleurs* ptr_liste_couleurs =&(liste_couleurs_chaine);
	
	// Boucle d'ajouts de couleurs dans la liste_couleurs
	for(int i = 0; i < 5; i++) {
		insertion(ptr_liste_couleurs, couleurs[i]);	
	 }
	
	// Affichage de la liste.
        affichage(ptr_liste_couleurs);

	 return(0);
}
