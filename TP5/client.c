/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/*
    Nom : client.c
    Auteur : John Samuel & CHARRAT Philippe & BRUYERE Axel 
    Objectif : Ce code va simuler un client qui peut recevoir et émettre des messages.
    Disclamer : Une grande partie du code a été rédigée par M. SAMUEL, nous n'avons qu'implémanté de petites features, l'ajout d'un en-tête par exemple. 
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include "client.h"

/* 
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd) {
 
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // Demande à l'utilisateur d'entrer un message
  char message[1024];
  puts("Exemples de syntaxe : \n-> Voici mon message \n-> + a b pour sommer a + b (opérateurs disponibles : +|-|*|/)\n-> M x (avec x la matière dont on veut connaître la moyenne)\n Votre message [max 1000 caracteres] :");
  fgets(message, 1024, stdin);
  int calcul = 0; 
  
  // Parcours du message pour chercher un opérateur et si oui ajout de l'en-tête "calcul:""
  for (int i = 0; i < 100; i ++ ) {
	  if(message[i] == '+' || message[i] == '-' || message[i] == '*' || message[i] == '/'|| message[i] == 'M') {
  		strcpy(data, "calcul: ");
		  calcul = 1;
		  break;
	  }
  }
  // Sinon ajout de l'en-tête "message :"
  if(calcul == 0) {
  	strcpy(data, "message: ");
  }
  strcat(data, message);
  
  // Envoi du message au serveur 
  int write_status = write(socketfd, data, strlen(data));
  
  // Si cas d'échec, alors arrêt système
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));

  // lire les données de la socket
  int read_status = read(socketfd, data, sizeof(data));
  if ( read_status < 0 ) {
    perror("erreur lecture");
    return -1;
  }

  printf("Message recu: %s\n", data);
 
  return 0;
}

int main() {
  int socketfd;
  int bind_status;

  struct sockaddr_in server_addr, client_addr;

  /*
   * Creation d'une socket
   */
  socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if ( socketfd < 0 ) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  //détails du serveur (adresse et port)
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  //demande de connexion au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connexion serveur");
    exit(EXIT_FAILURE);
  }

  // appeler la fonction pour envoyer un message au serveur
  envoie_recois_message(socketfd);

  close(socketfd);
}
