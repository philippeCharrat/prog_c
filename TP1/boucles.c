#include <stdio.h>
#include <stdlib.h>
/*
  Nom : boucles.c
  Auteur : CHARRAT Philippe & BRUYERE Axel
  Objectif : Ce programme a pour but d'afficher sur la console un triangle rectangle, composé de "#" à l'intérieur, et de "*" pour consituter les bords. Il existe sous deux versions différentes : une version utilisant des boucles "for" et une autre utilisant des boucles "while".
  Remarque : nous avons utilisé une bibliothèque supplémentaire pour utiliser la fonction atoi (stdlib.h).
*/


//On passe en argument la taille du triangle que l'on désir
//puis on spécifie en entrant "1" comme second argument pour utiliser la version while
//En l'absence de premier argument, la taille par défaut est 5 lignes/5 colonnes, et 
//en l'absence de second argument, c'est la version for qui est utilisée
int main(int argc, char ** argv) {
	//On initialise nos variables de taille et de choix de version du programme 
	int taille = 5;
	int select = 0;
	if (argc > 1) { // Si l'on a au moins un argument
		if (atoi(argv[1]) > 3){ //La taille du triangle ne dois pas être inférieure à 4, on teste donc la valeur entrée
			taille=atoi(argv[1]);//Si elle est supérieure à 3, elle remplace la variable de taille par défaut
		}
		else {
			printf("Taille non autorisée, valeur par défaut utilisée : 5 \n"); //Sinon, on renvoit un avertissement et on conserve 
																			   //La taille par défaut
		}	
	}
	if (argc > 2){ //Si l'on a au moins 2 arguments
		select = atoi(argv[2]); //Le second est attribué à la variable select, en charge de 
								//définir la version du programme utilisée
	}	
	
	//--------------------------
	
	int i = 1; //On initialise les variables de nos boucles de façon à en faire des variables globales
	int j = 0;
	switch (select){ //On sélectionne la version du programme souhaitée --> While si l'utilisateur
					 //a entré "1", for sinon
		case 1: //Cas où on choisis la version while
			printf("* \n"); //On affiche directement la première ligne, qui sera intrinsèquement toujours la même
			while (i<taille-1){ //Ce traitemnt est le même pour chacune des lignes, à l'exception de les première et dernière
				j = 0;
				while (j <= i){
					if (j == 0){ //j étant la variable relative aux colonnes, si elle est nulle, nous sommes sur un bord gauche
						printf("*"); //Il faut donc afficher une étoile
					}
					else if (j == i) { //Pareillement, si elle est égale à i -variable des lignes-, alors nous sommes sur un bord droit
						printf("* \n");//Il faut donc afficher une étoile et passer à la ligne suivante 
					}
					else {
						printf("#"); //Dans tous les autres cas, on affiche simplement un "#"
					}
					j++; //On incrémente notre variable des colonnes
				}
				i++; //On incrémente notre variable des lignes
			}
			j = 0; // On réinitialise notre variable des colonnes pour la dernière ligne, qui ne contient que des 
			while (j < taille - 1){ //étoiles mais donc la taille varie suivant la taille séléctionnée
				printf("*");
				j++;
			}
			printf("* \n"); //On place mannuellement la dernière étoile afin de passer à la ligne suivante 
							//pour un rendu visuel plus propre

		break; //Fin du cas de la version while



		default: //Cas par défaut : on éxecute la version for
			printf("* \n"); //On affiche directement la première ligne, qui sera intrinsèquement toujours la même
		        for (i = 1 ; i<taille - 1 ; i++){ //De la deuxième à l'avant dernière ligne, on applique les instructions suivantes
	       			for (j = 0 ; j<=i ; j++){ //Pour toute la largeur de "l'étage" du triangle
	       	                	if (j == 0){
		                      		printf("*"); //On affiche une étoile si on est sur un bord gauche
		                      	}
		               		else if (j == i){
		                       		printf("* \n"); //De même sur un bord droit, et on passe à la ligne suivante
		                	}
		               		else {
		                       		printf("#"); //Sinon, on affiche un #
		                	}
		       		}
			}
	
			for (int j = 0  ; j < taille ; j++){ //Pour la dernière ligne, on balaye toute la largeur à l'exception de la dernière colonne
		        	if (j != taille-1){
		                	printf("*"); //On affiche uniquement des étoiles
		        	}
		       		else {
		               		printf("* \n"); //Pour la dernière colonne, on l'ajoute mannuellement pour sauter un ligne et 
				}							//ainsi améliorer le rendu visuel
			}
		break; //Fin du cas de la version for
		
	}		
		
	return(0); //Fin du programme

}
