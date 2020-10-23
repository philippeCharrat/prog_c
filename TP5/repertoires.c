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
 *      - La partie sous dossier a été inspirée de : https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux
 *      - Focntion
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

// Fonction affichage des dossiers et sous dossiers  :
// Inputs : 
//  - ptr vers le lien du dossier a afficher
//  - int pour l'affichage 
// Outputs : 
//  - none
void lire_dossier_rec(char *buffer,int indent) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;
    char espace[15];
    char lien_parent[100];

    // Ouverture du dosssier 
    dir = opendir(buffer);
    
    // Création d'un niveau d'intenation esthétique
    for(int i=0;i <= indent;i++) {
	    if (i == indent) { 
		    espace[i] = '\0';
	    } else {
		    espace[i] = '-';
	    }
    }

    // Si l'on peut ouvrir le dossiers, on le parcours
    if(dir!=NULL) {

        structure_fichier=readdir(dir);
    	while (structure_fichier != NULL )  {
            // Génération du nouveau lien parents 
    	    memset(lien_parent,0,sizeof(lien_parent));
    	    strcpy(lien_parent,buffer);   
    	    strcat(lien_parent,"/");

            // Si le fichier est un directory et différent de . et .. alors on fait une récursion
            if (structure_fichier->d_type == 4 && strcmp(structure_fichier->d_name,"..")  != 0 && strcmp(structure_fichier->d_name,".")!=0) {
                // Génération du lien complet
                strcat(lien_parent,structure_fichier->d_name);

                // Affichage du lien complet (en vert)
        		printf("\033[0;32m");
        		printf("%s %s\n",&espace,&lien_parent);
        		printf("\033[0m");

                // Appel de la récursion
                lire_dossier_rec(lien_parent,indent+3);
                printf("\n");
            }
            // Sinon on affiche le fichier avec une indentation  
            else { 
        		printf("%s",&espace);
        		printf(structure_fichier->d_name);
        		printf("\n");
            }

            // Prochain fichier
            structure_fichier=readdir(dir);
        }   
    } 

    // Fermeture du fichier 
    closedir(dir);
}

// Fonction affichage des dossiers et sous dossiers  :
// Inputs : 
//  - ptr vers le lien du dossier a afficher
//  - int pour l'affichage 
// Outputs : 
//  - none
void lire_dossier_it(char *buffer,int indent) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;
    char espace[15];
    char lien_parent[100];

    // Ouverture du dosssier 
    dir = opendir(buffer);
    
    // Création d'un niveau d'intenation esthétique
    for(int i=0;i <= indent;i++) {
        if (i == indent) { 
            espace[i] = '\0';
        } else {
            espace[i] = '-';
        }
    }

    // Si l'on peut ouvrir le dossiers, on le parcours
    if(dir!=NULL) {

        structure_fichier=readdir(dir);
        while (structure_fichier != NULL )  {
            // Génération du nouveau lien parents 
            memset(lien_parent,0,sizeof(lien_parent));
            strcpy(lien_parent,buffer);   
            strcat(lien_parent,"/");

            // Si le fichier est un directory et différent de . et .. alors on fait appel à la fonction lire_dossier
            if (structure_fichier->d_type == 4 && strcmp(structure_fichier->d_name,"..")  != 0 && strcmp(structure_fichier->d_name,".")!=0) {
                // Génération du lien complet
                strcat(lien_parent,structure_fichier->d_name);

                // Affichage du lien complet (en vert)
                printf("\033[0;32m");
                printf("%s %s --- \n",&espace,&lien_parent);
                printf("\033[0m");

                // Appel de la focntion
                lire_dossier(lien_parent,indent+3);
                printf("---\n");
            }
            // Sinon on affiche le fichier avec une indentation  
            else { 
                printf("%s",&espace);
                printf(structure_fichier->d_name);
                printf("\n");
            }

            // Prochain fichier
            structure_fichier=readdir(dir);
        }   
    } 

    // Fermeture du fichier 
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
    lire_dossier_rec(buffer,indent);

    return(0);
}   

