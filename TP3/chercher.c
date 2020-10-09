#include <stdio.h>
#include <stdlib.h>

//Auteurs : Philippe CHARRAT et Axel BRUYERE
//Objectif : écrire un programme qui crée un tableau de 100 entiers puis qui cherche si un entier passé en argument se trouve dans le tableau
int main(int argc,char ** argv){
    
    //Création du tableau
    int tableau[100];
    printf("Tableau généré : \n");
    for (int i=0;i<100;i++) {
        tableau[i] = rand() % 100;
        printf(" %02d -",tableau[i]);
    }
    
    //On parcourt la liste et on vérifie si l'entier y est présent
    int entier = atoi(argv[1]);
    for (int i = 0;i < 100;i++){
        if (tableau[i] == entier){
            printf("\nL'entier est présent à l'indice %d \n",i);
            return(0);
        }
        printf("\n i : %d",i);

    }
    printf("\nL'entier n'est pas présent\n");
    return(0);
}
