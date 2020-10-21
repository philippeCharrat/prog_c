/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 * 
 */
/*
    Nom : serveur.c
    Auteur : John Samuel & CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va simuler un serveur qui peut recevoir et émettre des messages.
    Disclamer : Une grande partie du code a été rédiger par Mr. SAMUEL, nous n'avons qu'implémanté de petite feature, tel qu'une fonction de calcul ou de nouveau message.
    Lien utiles : 
        - nous avons rencontrée des difficultés à récuperer les nombre car on obtenais des valeurs abérentes, exemple: '0'-> 48. Cela était du au fait que l'on récupéré le code ASCI dont voici une table : http://www.asciitable.com/
        - Pour convertir des chars en floats, nous avons utilisé la fonction atof à l'aide du site : https://koor.fr/C/cstdlib/atof.wp
        - Pour convertir des chars en int, nous avons utilisé la fonction atoi à l'aide du site : https://koor.fr/C/cstdlib/atoi.wp
        - Pour convertir des ints en floats, on a utilisé la solution proposé sur : https://www.tutorialspoint.com/cprogramming/c_type_casting.htm
        - Nous avons choisis la solution d'un return void pour la fonction de calcul suite à des problèmes de variables locales : https://overiq.com/c-programming-101/local-global-and-static-variables-in-c/
        - La boucle pour récuperer les floats ou ints depuis un char[] est librement inspirés de la solution :https://stackoverflow.com/questions/11841782/how-can-i-assign-float-value-to-char-c-array


*/
// Foncion ajout d'un élément dans la liste chainée directement inspiré de la slide 46 du cours 3.

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serveur.h"

int lire_fichier(char*nom_de_fichier){
    int fichier;
    int size;
    char message;
    fichier = open(nom_de_fichier,O_RDONLY);    
    while (1){
        size = read(fichier,&message,1);
        if(size<1){
            break;
        }
        printf("%c \n", message);
    }
    close(fichier);
    return(0);
}
// Fonction qui va traiter l'opération pour des entiers 
int operation(char op,int a,int b) {
	int c;
  // Un switch qui contient les cas possibles
	switch(op) {
		case '+' :c = a+b;break;
		case '-' :c = a-b;break;
		case '*' :c = a*b;break;
		case '/' :c = a/b;break;
	}
  // Retours d'un entié C
	return c;
}

// Fonction qui va traiter l'opération pour des floats 
double operationf(char op,double a,double b) {
	double c;
  // Switch avec les 4 cas possibles
	switch(op) {
		case '+' :c = a+b;break;
		case '-' :c = a-b;break;
		case '*' :c = a*b;break;
		case '/' :c = a/b;break;
	}
  // Retours d'un float c
	return c;
}

// Fonction pour la partie : réalisation d'un calcul à partir de saisies utilisateurs. 
// Inputs : 
// - data : tableau contenant le messages de l'utilisateurs 
// - buffer : tableau vide pour récuperer le résultat de l'opération.
// Outputs : 
// - int : 0, cette fonction ne nécessite aucun retour particulié.
int recois_numero_calcule(char* data,char* buffer) {
  // Initialisations des variables utiles ---
  char op; 
  char atemp[10];
  char btemp[10];
  int a = 0;
  int b = 0;
  int j = 0;
  int fa = 0;
  int fb = 0;
  int mode = 0; 
  double af = 0;
  double bf = 0;
 
  // Initialisations d'un pointeur sur le message utilisateurs tronqué des 8 premiers caractère ('calcul : '')
  char * ptr_data = &(data[0]);
  ptr_data += 8;
  for(int g = 0; g < 100; g++) {
	  if (data[g] == ' ') {
		  mode += 1;
	  } else if (data[g] == '\0') {
		  printf("%d",mode);
		  break;
	  }
  }

  // Partie : Récupération des paramètres utilisateurs 
  for(int i = 1; i < 100; i++) {  
    // Récupération de l'opération attendue
    if( *ptr_data == '+' || *ptr_data == '-' || *ptr_data == '*' || *ptr_data == '/') {
      op = *ptr_data;
      ptr_data += 1;
    } 
    // Partie Initialisation de la valeur a 
    else if (a == 0 && af == 0) {

      // Cas 1 : la valeur est finie (présence d'un espace), convertions de la valeur en int ou double en fonction de la présence (ou non) du caractère '.'
      if (*ptr_data == ' ') {  
         if (fa == 0) {  a = atoi(atemp);}
	       else { af = atof(atemp);}
	       j = 0;
      } 
      // Cas 2 : la valeur continue donc on continue le tableau et l'on test la présence du caractère '.'.      
      else {
        atemp[j] = *ptr_data; 
	      j += 1;
      	if (*ptr_data == '.') { fa = 1;}
      }
    }
    // Partie Initialisation de la valeur b
    else if (b == 0 && bf == 0 && mode==3) {
      // Cas 1 : la valeur est finie (présence d'un espace), convertions de la valeur en int ou double en fonction de la présence (ou non) du caractère '.'
      if (*ptr_data == ' ' ||*ptr_data == '\0' || *ptr_data == 10  ) {
        if (fb == 0) { b = atoi(btemp);}
        else { bf = atof(btemp);}
      }
      // Cas 2 : la valeur continue donc on continue le tableau et l'on test la présence du caractère '.'.      
      else {
        btemp[j] = *ptr_data;
      	j += 1;	
      	if (*ptr_data == '.') { fb = 1;}
      }
    }
  
    // On incrémente de 1 le pointeur et au besoin, on sort de la boucle.
    ptr_data = ptr_data+1;
    if(*ptr_data == '\0') {
      break;
    }
  }
  if (mode == 3) {
  // Pour réaliser, l'opérations il y a 4 cas possibles : 
  // Cas 1 : Les deux valeurs sont des ints
  if( fa == 0 && fb == 0) {
  	int result = operation(op,a,b);
    sprintf(buffer,"%d",result);
	
  }
  // Cas 2 et 3 : a ou b est un float. 
  else if( fa == 0 && fb == 1) {
	af = (double) a;
  	double result = operationf(op,af,bf);
	sprintf(buffer,"%f",result);
	
  }else if( fa == 1 && fb == 0) {
  	bf = (double) b;
  	double result = operationf(op,af,  bf);
	sprintf(buffer,"%f",result);
	
  }
  // Cas 4 : les deux valeurs sont des floats.         
  else {
	double result = operationf(op,af,bf);
	sprintf(buffer,"%f",result);
  }
  }
  else {
      if (a < 6) {
        lire_fichier("etudiant/1/note1.txt");
      }
  }

  // Retourne 0 si bonne exécution de la fonction
  return 0;
}

/* renvoyer un message (*data) au client (client_socket_fd)
 */
int renvoie_message(int client_socket_fd, char *data) {
  int data_size = write (client_socket_fd, (void *) data, strlen(data));
      
  if (data_size < 0) {
    perror("erreur ecriture");
    return(EXIT_FAILURE);
  }
}

/* accepter la nouvelle connection d'un client et lire les données
 * envoyées par le client. En suite, le serveur envoie un message
 * en retour
 */
int recois_envoie_message(int socketfd) {
  struct sockaddr_in client_addr;
  char data[1024];

  int client_addr_len = sizeof(client_addr);
 
  // nouvelle connection de client
  int client_socket_fd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_socket_fd < 0 ) {
    perror("accept");
    return(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  //lecture de données envoyées par un client
  int data_size = read (client_socket_fd, (void *) data, sizeof(data));
      
  if (data_size < 0) {
    perror("erreur lecture");
    return(EXIT_FAILURE);
  }
  
  /*
   * extraire le code des données envoyées par le client. 
   * Les données envoyées par le client peuvent commencer par le mot "message :" ou un autre mot.
   */
  printf ("Message recu: %s\n", data);
  char code[10];
  sscanf(data, "%s:", code);
  // Deux cas possibles : 

  //Cas 1 : Si le message commence par le mot: 'message:', alors le serveur doit saisir et renvoyer un message vers le client.  
  if (strcmp(code, "message:") == 0) {
    // Initialisations des variables utiles ---
  	char message[1024];
    // Récupération du nouveau message ---
  	printf("saisir un nouveau message : ");
  	fgets(message,1024,stdin);
    // Envoie du nouveau message --- 
  	renvoie_message(client_socket_fd,message);
  } 
  //Cas 2 : Si le message commence par le mot: 'calcul:', alors le serveur renvoye le résultat vers le client.  
  else if (strcmp(code, "calcul:") == 0) {
    // Initialisations des variables utiles ---
    char buffer[30];
    char message[100];
    // Calcul du résultat ---
  	int temp = recois_numero_calcule(data,buffer);
    // Création de la chaine à retourner ---
  	strcpy(message, "Le résultat est :");
  	strcat(message,buffer);	
    // Envoie du résultat
  	renvoie_message(client_socket_fd,message);
  }

  //fermer le socket 
  close(socketfd);
}

int main() {

  int socketfd;
  int bind_status;
  int client_addr_len;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("Unable to open a socket");
    return -1;
  }

  int option = 1;
  setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Relier l'adresse à la socket
  bind_status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if (bind_status < 0 ) {
    perror("bind");
    return(EXIT_FAILURE);
  }
 
  // Écouter les messages envoyés par le client
  listen(socketfd, 10);

  //Lire et répondre au client
  recois_envoie_message(socketfd);

  return 0;
}
