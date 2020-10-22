#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
/* 
 * 	nom : repertoires.c
 * 	Auteur : Philippe CHARRAT & Axel BRUYERE
 * 	But : Saisir le nom d'un dossier et le parcourir
 * 	Remarque : 
 *      - ce code est inspiré de : https://stackoverflow.com/questions/3554120/open-directory-using-c
 */

// Fonction affichage des dossiers :
// Inputs : 
// 	- ptr vers le lien du dossier a afficher
// Outputs : 
// 	- none
void lire_dossier(char * buffer,int indent) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;
    char espace[10];

    // Ouverture du dosssier 
    dir = opendir(buffer);

    for(int i=0;i <= indent;i++) {
	    if (i == indent) { 
		    espace[i] = '\0';
	    } else {
		    espace[i] = '-';
	    }
    }

    // Si le fichier existe
    if(dir!=NULL) {
	//printf("les fichiers sont : \n");
	structure_fichier=readdir(dir);

	// Tant que le dossier est non-nul, on affiche les fichiers 
        while(structure_fichier!=NULL) {
            // Affichage du nom de dossier
	    printf("%s",&(espace[0]));
            printf(structure_fichier->d_name);
    	    printf("\n");
    	    // On teste de recuperer la structure du fichier suivante 
    	    structure_fichier=readdir(dir);
	   }
    }

    // On ferme le fichier 
    close(dir);
}

void listdir(char *buffer) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;
    int i = 0; 
    // Ouverture du dosssier 
    dir = opendir(buffer);
    
    // Si le fichier existe
    if(dir!=NULL) {

        structure_fichier=readdir(dir);
        while (structure_fichier != NULL || !(structure_fichier -> d_name == "..")) {
		
            // Test du type du fichier 
            if (structure_fichier->d_type == DT_DIR) {
		i += 1;
                lire_dossier(structure_fichier->d_name,i);
            } 
            else { 
		printf(structure_fichier->d_name);
		printf("\n");
	    }
            structure_fichier=readdir(dir);
        }
    }
    close(dir);
}


int main() {
    // Initialisations des variables utiles 	
    char buffer[50];
    int indent = 0;
    // Saisie du lien du repertoire
    printf("Saisir un lien  : ");
    scanf("%s",&(buffer[0]));

    // Appel de la fonction lire_dosier 
    listdir(buffer);

    return(0);
}   

