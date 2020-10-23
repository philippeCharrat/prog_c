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
void lire_dossier(char * buffer) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier; 

    // Ouverture du dosssier 
    dir = opendir(buffer);

    // Si le fichier existe
    if(dir!=NULL) {
	//printf("les fichiers sont : \n");
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
    closedir(dir);
}

void listdir(char *buffer,int indent) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;
    char espace[15];
    char lien_parent[100];

    // Ouverture du dosssier 
    dir = opendir(buffer);
    
    // Si le fichier existe
    for(int i=0;i <= indent;i++) {
	    if (i == indent) { 
		    espace[i] = '\0';
	    } else {
		    espace[i] = '-';
	    }
    }

    if(dir!=NULL) {

        structure_fichier=readdir(dir);
	while (structure_fichier != NULL )  {
            // Test du type du fichier 
	    memset(lien_parent,0,sizeof(lien_parent));
	    strcpy(lien_parent,buffer);   
	    strcat(lien_parent,"/");
            if (structure_fichier->d_type == 4 && strcmp(structure_fichier->d_name,"..")  != 0 && strcmp(structure_fichier->d_name,".")!=0) {
    		strcat(lien_parent,structure_fichier->d_name);
		printf("\033[0;32m");
		printf("%s %s\n",&espace,&lien_parent);
		printf("\033[0m");

                listdir(lien_parent,indent+3);
		printf("\n");
            } 
            else { 
		printf("%s",&espace);
		printf(structure_fichier->d_name);
		printf("\n");
	    }
            structure_fichier=readdir(dir);
        }
    } else {printf("fin du buzz");}
    closedir(dir);
}


int main() {
    // Initialisations des variables utiles 	
    char buffer[50];
    int indent = 1;

    // Saisie du lien du repertoire
    printf("Saisir un lien  : ");
    scanf("%s",&(buffer[0]));
    printf("Les dossiers et sous dossiers de %s sont : \n",&buffer);

    // Appel de la fonction lire_dosier 
    listdir(buffer,indent);

    return(0);
}   

