#include <stdio.h>
/*
    Nom : chaine.c
    Auteur : CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va gérer 3 cas (avec un switch), le premier est afficher la taille de la première chaine. Le second cas est de copié une chaine dans une troisième via une boucle for. Le troisième est la concaténation de deux chaine.
*/

int main(int argc, char ** argv) {

    	//-- Initialisations des variables --
        char message[50] ;
	char messageDeux[50] ;
	char messageTrois[50];
	char cas ;
	
	
	printf("Veuillez saisir votre cas (1- taille de la chaine; 2-copie d'une chaine; 3- Concaténation de deux chaines) : ");
	scanf("%c",&(cas));
	printf("le cas séléctionné est : %c \n",cas);
	
	printf("Veuillez saisir votre chaine : ");	
	scanf("%s",&(message[0]));
	printf("la première chaine est : %s\n",message);
	
	// Input disponible qu'en cas deux
	if ( cas == '2') {
		printf("Veuillez saisir votre seconde chaine : ");
		scanf("%s",&(messageDeux[0]));
		printf("la seconde chaine : %s\n",messageDeux);
	}
	
	int isave;
	
	// Déterminer la taille d'une chaine 
	for (int i =0; i <= 50; i++) {	
		if(message[i] == '\0')  {
			isave = i; 
			break;
		} 
	}

	switch(cas) {
	// Cas : taille 
	case '0':
		printf("il y a %d valeurs dans la chaine 1 \n",isave);
		break;
	// Cas : Copie 
	case '1' :
		for(int j=0; j <= isave;j++) {
			 messageTrois[j] = message[j];	
		}
		printf("le message est copié dans une troisième chaine : %s \n", messageTrois);
	        break;
	// Cas : Concaténation 
	case '2':
		for (int k=isave+1; k<= 50; k++) {
                	if(messageDeux[k-isave-1] == '\0')  { 
				message[k-1] = '\0';				
				break; }
			else { 	message[k-1] = messageDeux[k-isave-1];	}
        	}
		printf("La concaténation donne : %s",message);
		printf("\n");
		break;	

	}

	return(0);

}

