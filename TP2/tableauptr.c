#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Auteurs : Philippe CHARRAT et Axel BRUYERE 
//Objectif : Créer deux tableaux, l'un constitué d'entiers, l'autres de réels. Ces tableaux sont 
//remplis de façon aléatoire. En utilisant les pointeurs, nous appliquons le protocole suivant : 
//Si l'indice de la valeur et paire, on la multiplie par 3.

/*
 *
 */

int main() {
	srand(time(NULL));	
	// -- Initialisation des variables ---
	char tab_int[30];
	char tab_float[30];
	char *ptr_tab_int = &tab_int[0];
	char *ptr_tab_float = &tab_float[0];
        
        //Premier cas : les entiers
        //On initialise le tableau
	printf("----- Cas : Tableau Int ------\n");
	printf("Tableau inital : \n");
	for (int i=0;i<30;i++) {
		tab_int[i] = rand() % 10;
		printf("%02d -",tab_int[i]);
	}
	//Puis on le parcourt en y appliquant le protocole expliqué au-dessus 
	printf("\n Nouveau Tableau :\n");
	for(int i=0;i<30;i++) {
		if(i%2 == 0) {
			*ptr_tab_int = *ptr_tab_int*3;
		}
		ptr_tab_int = ptr_tab_int +1;
		printf("%02d -",tab_int[i]);
	}
	printf("\n");
	
        //Second cas : les réels
        //On initialise le tableau de la même manière
	printf("\n ----- Cas : Tableau Float ------\n");
	printf("Tableau inital : \n");
	for (int i=0;i<30;i++) {
		tab_float[i] = (double) (rand() % 999 )/100 ;
		printf(" %d -",tab_float[i]);
	}
	//Puis on le parcourt en appliquant le protocole
	printf("\n Nouveau Tableau :\n");
	for(int i=0;i<30;i++) {
		if(i%2 == 0) {
			*ptr_tab_float = *ptr_tab_float*3;
		}
		ptr_tab_float = ptr_tab_float +1;
		printf("%02d -",tab_float[i]);
	}
	printf("\n");
	
	
	return(0);
}
