#include <stdio.h>
#include <stdlib.h>

//Nom : recherche_dichotomique.c
//Auteurs : Philippe CHARRAT et Axel BRUYERE
//Objectif : écrire un programme qui crée un tableau de 100 entiers, qui le trie dans l'ordre croissant, puis qui recherche par la méthode de la recherche dichotomique si un entier passé en input si il est présent ou non dans la liste

//Création et tri du tableau grâce à la fonction tri de l'exercice 3.3

int main(int argc,char ** argv){
    //Création du tableau
    int tableau[100];
    for (int i=0;i<100;i++) {
        tableau[i] = rand() % 100;

    }
    //tri
    printf("Tableau inital : \n");
    for (int i=1;i<100;i++){
        for (int j=0;j<100-i;j++){
            if (tableau[j]>tableau[j+1]){
                int stock_variable = tableau[j];
                tableau[j] = tableau[j+1];
                tableau[j+1] = stock_variable;                
            }
        }
    }
    for (int i = 0;i<100;i++){
        printf("%02d -",tableau[i]);
    }
    
    int entier_recherche = atoi(argv[1]);
    int trouve = 0;
    int min = 0;
    int max = 50;
    int size = 100;
    while (trouve == 0){
        if (tableau[max] == entier_recherche){
            printf("\nL'entier recherché est présent à l'indice %d. \n",max);
            return(0);
        }
        if (max - min == 1){
            break;
        }
        if (max == 0){
            break;
        }
        if (entier_recherche > tableau[max]){
            int stock_var = min;
            min = max;
            max = max + (max-stock_var-1);
        }
        else{
            max = max - ((max-min) / 2);
        }

    }
        
            
        

    
    printf("\n L'entier recherché n'est pas présent. \n");
                   
    return(0);
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
