#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include"fichier.h"
#include<string.h>


//Nom : fichier.c
//Auteurs : Philippe CHARRAT et Axel BRUYERE 
//Objectif : Ecrire un programme qui est capable d'ouvrir un fichier .txt et d'y écrire un message entré par l'utilisateur 
    
    //Fonction de lecture et d'affichage du contenu du fichier .txt
int lire_fichier(char*nom_de_fichier){
    int fichier;
    int size;
    char message;
    fichier = open(nom_de_fichier,O_RDONLY);    
    while (1){
        size = read(fichier,&message,1);
        if(size<1){
            break;
        }
        printf("%c \n", message);
    }
    close(fichier);
    return(0);
}

    //Fonction d'écriture dans le fichier .txt
int ecrire_dans_fichier(char *nom_de_fichier, char *message){  
    int fichier,size;
    fichier = open(nom_de_fichier,O_WRONLY|O_CREAT|O_APPEND,S_IRUSR|S_IWUSR);
    size = write(fichier,message,strlen(message));
    close(fichier);    
    return(0);
}

    //On demande à l'utilisateur son message, on l'écrit dans le fichier grâce à la fonction d'écriture, puis on lit le dichier avec la fonction de lecture/affichage afin de vérifier que l'écriture se passe correctement
int main(){
    char message[1000] = {};
    printf("Veuillez saisir votre message : ");
    scanf("%s",message);
    char *nom_de_fichier = "fichier.txt";
    int return_code = remove(nom_de_fichier);
    int fichier = ecrire_dans_fichier(nom_de_fichier,message);
    int k = lire_fichier(nom_de_fichier);
    return(0);
}
