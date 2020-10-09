#include <stdio.h>
#include <stdlib.h>

//Nom : grand_petit.c
//Auteurs : Philippe CHARRAT et Axel BRUYERE
//Objectif : écrire un programme qui crée un tableau de 100 entiers et qui calcule 
//la plus grande valeur ainsi que la plus petite 

int main(){
    
    //Création du tableau
    int tableau[100];
    printf("Tableau généré : \n");
    for (int i=0;i<100;i++) {
        tableau[i] = rand() % 100;
        printf(" %02d -",tableau[i]);
    }
    
    //Calcul du plus petit et du plus grand élément
    int plus_grand[2] = {tableau[0],0};
    int plus_petit[2] = {tableau[0],0};
    for (int i=1;i<100;i++){
        if (tableau[i] > plus_grand[0]){
            plus_grand[0] = tableau[i];
            plus_grand[1] = i;
        }
        if (tableau[i] < plus_petit[0]){
            plus_petit[0] = tableau[i];
            plus_petit[1] = i;
    }
    printf("\nLe plus grand élément est situé au rang %d et vaut %d \n",plus_grand[1], plus_grand[0]); 
    
    printf("Le plus petit élément est situé au rang %d et vaut %d \n",plus_petit[1], plus_petit[0]); 
    
    //
    return(0);
}
