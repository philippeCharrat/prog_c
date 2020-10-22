#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
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
            // Affichage du nom de dossier
            printf(structure_fichier->d_name);
    	    printf("\n");
    	    // On teste de recuperer la structure du fichier suivante 
    	    structure_fichier=readdir(dir);
	   }
    }

    // On ferme le fichier 
    close(dir);
}

void listdir(char *buffer, int indent) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;

    // Ouverture du dosssier 
    dir = opendir(buffer);
 
    // Si le fichier existe
    if(dir!=NULL) {
        structure_fichier=readdir(dir);
        while ((structure_fichier == NULL) {
            // Test du type du fichier 
            if (structure_fichier->d_type == DT_DIR) {
                char path[1024];
                if (strcmp(structure_fichier->d_name, ".") == 0 || strcmp(structure_fichier->d_name, "..") == 0)
                    continue;
                snprintf(path, sizeof(path), "%s/%s", name, structure_fichier->d_name);
                printf("%*s[%s]\n", indent, "", structure_fichier->d_name);
                listdir(path, indent + 2);
            } 
            else { printf("%*s- %s\n", indent, "", structure_fichier->d_name); }
            structure_fichier=readdir(dir);
        }
    }
    closedir(dir);
}

int main(void) {
    listdir(".", 0);
    return 0;
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

