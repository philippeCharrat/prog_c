#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


//Nom : etudiant_bd.c
//Auteurs : Philippe CHARRAT et Axel BRUYERE 
//Objectif : on demande via scanf ) l'utilisateur d'entrer les détails sur 5 étudiants (que l'on peut éventuellement rendre variable avec un autre scanf), puis on les écrit dans un fichier nommé etudiant.txt


int main(){ 
    
    for (int i = 0;i<1;i++){
        //On demande à l'utilisateur d'entrer les détails (on réinitialise les variables à chaque itération) 
        char prenom[30];
        char nom[30];
        char ad[50];
        char C[5];
        char sys[5];
        printf("Nom : ");
        scanf("%s",nom);
        printf("\nPrénom : ");
        scanf("%s",prenom);
        printf("Adresse : ");
        scanf("%s",ad);
        printf("\nNote en C : ");
        scanf("%s",C);
        printf("\nnote en système d'exploitation : ");
        scanf("%s",sys);
        char ligne[1000]={};//On initialise la variable char qui contiendra la phrase à écrire dans le fichier txt puis on écrit le tout dans ligne
        sprintf(ligne, "L'élève %s %s, domicilié au %s a obtenu les notes de %s en programmation en C et %s en système d'exploitation. \n",prenom,nom,ad,C,sys);    
    
        //On réutilise le code de la fonction fichier.c afin d'ouvrir le fichier etudiant.txt puis d'y écrire le informations sur l'étudiant de notre itération
        int fichier,size;
        char phrase;
        fichier = open("etudiant.txt",O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);
        size = write(fichier,ligne,strlen(ligne));        
        close(fichier);   
    }
    
    //On réutilise le code de fichier.c afin d'afficher le contenu de notre fichier txt, pour vérifier qu'on y a bien écrit ce que l'on souhaitait
    char phrase;
    int fichier,size;
    fichier = open("etudiant.txt",O_RDONLY);    
    while (1){
        size = read(fichier,&phrase,1);
        if(size<1){
            break;
        }
        printf("%c", phrase);
    }
    close(fichier);
    return 0;
    
    
    }
    
