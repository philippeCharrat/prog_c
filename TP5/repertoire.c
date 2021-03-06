#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "repertoire.h"
/* 
 * 	nom : repertoire.c
 * 	Auteur : Philippe CHARRAT & Axel BRUYERE
 * 	But : Saisir le nom d'un dossier et le parcourir
 * 	Remarque : 
 *      - ce code est inspiré de : https://stackoverflow.com/questions/3554120/open-directory-using-c
 *      - La partie sous dossier a été inspirée de : https://stackoverflow.com/questions/8436841/how-to-recursively-list-directories-in-c-on-linux
 */

// Fonction affichage des dossiers :
// Inputs : 
// 	- ptr vers le lien du dossier à afficher
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
    	    // On tente de recuperer la structure du fichier suivante 
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
// Remarque : Nous avons ajouté un int en input par rapport à la consigne pour des questions d'esthetique de l'afichage 
void lire_dossier_rec(char *buffer,int indent) {
    // Initialisation des variables utiles 
    DIR *dir;
    struct dirent *structure_fichier;
    char espace[15];
    char lien_parent[100];

    // Ouverture du dosssier 
    dir = opendir(buffer);
    
    // Création d'un niveau d'indentation esthétique
    for(int i=0;i <= indent;i++) {
	    if (i == indent) { 
		    espace[i] = '\0';
	    } else {
		    espace[i] = '-';
	    }
    }

    // Si l'on peut ouvrir le dossier, on le parcourt
    if(dir!=NULL) {

        structure_fichier=readdir(dir);
    	while (structure_fichier != NULL )  {
            // Génération du nouveau lien parent
    	    memset(lien_parent,0,sizeof(lien_parent));
    	    strcpy(lien_parent,buffer);   
    	    strcat(lien_parent,"/");

            // Si le fichier est un directory et différent de . et .. alors on fait une récursion
            if (structure_fichier->d_type == 4 && strcmp(structure_fichier->d_name,"..")  != 0 && strcmp(structure_fichier->d_name,".")!=0) {
                // Génération du lien complet
                strcat(lien_parent,structure_fichier->d_name);

                // Affichage du lien complet (en vert)
        		printf("\033[0;32m");
        		printf("%s %s\n",&(espace[0]),&(lien_parent[0]));
        		printf("\033[0m");

                // Appel de la récursion
                lire_dossier_rec(lien_parent,indent+3);
                printf("\n");
            }
            // Sinon on affiche le fichier avec une indentation  
            else { 
        		printf("%s",&(espace[0]));
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
    char liste_doss[30][100];
    char nomfichier[100];
    strcpy(liste_doss[0],buffer);
    int taille;
    int indice = 0; 
    int derniereindice = 1;
    // Si l'on peut ouvrir le dossier, on le parcourt
    while (1) {    
        //Ouverture du nième dossier de la liste 
    	dir = opendir(liste_doss[indice]);
        //Si il existe, on le parcourt
	if (dir != NULL) {
		printf("---- %s\n",&liste_doss[indice]);		
		structure_fichier=readdir(dir);
            // Tant que le dossier est non-nul, on affiche les fichiers 
        	while(structure_fichier!=NULL) {
                //Si le fichier est un dossier, on l'ajoute à la liste 
	    		if (structure_fichier->d_type == 4 && strcmp(structure_fichier->d_name,"..")  != 0 && strcmp(structure_fichier->d_name,".")!=0) {
		    		memset(nomfichier,0,sizeof(nomfichier));
	    	    	strcpy(nomfichier,&liste_doss[indice]);   
	    	    	strcat(nomfichier,"/");
	    	    	strcat(nomfichier,structure_fichier->d_name);   
                    strcpy(&liste_doss[derniereindice], nomfichier);
                    derniereindice += 1;
                }  
                //Affichage et fichier suivant
                printf(structure_fichier->d_name);
            	printf("\n");
            	structure_fichier=readdir(dir);
        	} 
            	indice += 1;
	} else {
        //Si le dossier n'existe pas, on sort de la fonction
		break;
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
    printf("Les dossiers et sous dossiers de %s sont : \n",&(buffer[0]));

    // Appel de la fonction lire_dosier 
    lire_dossier_rec(buffer,indent);

    return(0);
}   

