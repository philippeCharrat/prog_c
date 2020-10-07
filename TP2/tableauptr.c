#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
	printf("----- Cas : Tableau Int ------\n");
	printf("Tableau inital : \n");
	for (int i=0;i<30;i++) {
		tab_int[i] = rand() % 10;
		printf("%02d -",tab_int[i]);
	}
	printf("\n Nouveau Tableau :\n");
	for(int i=0;i<30;i++) {
		if(i%2 == 0) {
			*ptr_tab_int = *ptr_tab_int*3;
		}
		ptr_tab_int = ptr_tab_int +1;
		printf("%02d -",tab_int[i]);
	}
	printf("\n");
	
	printf("----- Cas : Tableau Float ------\n");
	printf("Tableau inital : \n");
	for (int i=0;i<30;i++) {
		tab_float[i] = (double) (rand() % 999 )/100 ;
		printf("%d -",tab_float[i]);
	}
	printf("\n Nouveau Tableau :\n");
	for(int i=0;i<30;i++) {
		if(i%2 == 0) {
			*ptr_tab_int = *ptr_tab_int*3;
		}
		ptr_tab_int = ptr_tab_int +1;
		printf("%02d -",tab_int[i]);
	}
	printf("\n");
	
	
	return(0);
}
