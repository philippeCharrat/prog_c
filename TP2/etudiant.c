#include <stdio.h>

//Auteurs : Philippe CHARRAT et Axel BRUYERE 
//Objectif : Créer des tableaux contenant des données sur 5 étudiants, puis les parcourir afin d'afficher les différentes informations pour chacun des étudiants

int main(){

    //On initialise les variables pour 5 étudiants
    char prenoms[5][30] = {"Axel","Philippe","Jean","Paul","Jacques"};
    char noms[5][30] = {"Bruyere","Charrat","Dupond","Dupont","Durant"};
    char adresses[5][50] = {"ad1","ad2","ad3","ad4","ad5"};
    char C[5][5] = {"20","0","15","3","11"};
    char sys[5][5] = {"20","0","8","14","5"};
    
    //On parcourt ensuite les tableaux et on en extrait les données à afficher
    int i;
    for (i = 0 ; i < 5 ; i++){
        printf("L'élève %s %s domicilié au %s a obtenu la note de %s en programmation en C et %s en système d'exploitation \n \n",prenoms[i],noms[i], adresses[i],C[i],sys[i]);
        
    }
    
	return(0);
}
