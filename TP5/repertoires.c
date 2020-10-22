#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
/* 
 * 	nom : repertoires.c
 * 	Auteur : Philippe CHARRAT & Axel BRUYERE
 * 	But : Saisir le nom d'un dossier et le parcourir
 * 	Remarque : 
 */

// Fonction affichage des dossiers :
// Inputs : 
// 	- ptr vers le lien du dossier a afficher
// Outputs : 
// 	- none
void lire_dossier(char * buffer) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;

    // Ouverture du dosssier 
    dir = opendir(buffer);

    // Si le fichier existe
    if(dir!=NULL) {
	printf("les fichiers sont : \n");
	structure_fichier=readdir(dir);

	// Tant que le dossier est non-nul, on affiche les fichiers 
        while(structure_fichier!=NULL) {
            printf(structure_fichier->d_name);
	    printf("\n");
	    // On teste de recuperer la structure du fichier suivante 
	    structure_fichier=readdir(dir);
	}
    }

    // On ferme le fichier 
    close(dir);
}

int main() {
    // Initialisations des variables utiles 	
    char buffer[50];
    
    // Saisie du lien du repertoire
    printf("Saisir un lien  : ");
    scanf("%s",&(buffer[0]));

    // Appel de la fonction lire_dosier 
    lire_dossier(buffer);

    return(0);
}   

