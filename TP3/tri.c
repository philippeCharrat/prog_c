#include <stdio.h>
#include <stdlib.h>

//Nom : tric.c
//Auteurs : Philippe CHARRAT et Axel BRUYERE
//Objectif : écrire un programme qui crée un tableau de 100 entiers puis qui le trie dans l'ordre croissant
int main(){
    
    //Création du tableau
    int tableau[100];
    printf("Tableau généré : \n");
    for (int i=0;i<100;i++) {
        tableau[i] = rand() % 100;
        printf(" %02d -",tableau[i]);
    }
    
    //tri (par la méthode du tri à bulle)
    for (int i=1;i<100;i++){
        for (int j=0;j<100-i;j++){
            if (tableau[j]>tableau[j+1]){
                int stock_variable = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = stock_variable;                
            }
        }
    }
    
    //Affichage du tableau trié
    printf("\n Tableau trié : \n");
    for (int k=0;k<100;k++){
        printf(" %02d -", tableau[k]);
    }
    
    return(0);
}
