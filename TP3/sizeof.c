#include <stdio.h>

//Auteurs : Philippe CHARRAT et Axel BRUYERE
//Objectif : écrire un programme qui affiche le résultat de la fonction sizeof appliquée à différents types


//On affiche la taille en octet de chaque types
int main() {
    printf("\n Type int : %ld\n",sizeof (int)); 
    printf("\n Type int* : %ld\n",sizeof(int*));
    printf("\n Type int** : %ld\n",sizeof(int**));
    printf("\n Type char* : %ld\n",sizeof(char*));
    printf("\n Type char** : %ld\n",sizeof(char**));
    printf("\n Type char*** : %ld\n",sizeof(char***));
    printf("\n Type float* : %ld\n",sizeof(float*));
    printf("\n Type float** : %ld\n",sizeof(float**));
    printf("\n Type float*** : %ld\n",sizeof(float***));
    
    return(0);
}

//Le type int fait 4 octets
//Tous les autres sont des pointeurs et nous sommes sur une machine 64bits avec un système d'exploitation sur 64bits également. Tous les pointeurs font donc 8 octets
