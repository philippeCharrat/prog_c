/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "serveur.h"

int recois_numero_calcule(char data) {
    char op; 
  int a = 0;
  int atemp = 0;
  int b =0;
  int btemp = 0;
  char * ptr_data = &(data[0]);
  ptr_data += 8;
  for(int i = 1; i < 100; i++) {  
    if( *ptr_data == '+' || *ptr_data == '-' || *ptr_data == '*' || *ptr_data == '/') {
      op = *ptr_data;
      ptr_data += 1;
    } else if (a == 0 ) {
      if (*ptr_data == ' ') {
        a = atemp + 0;
      } else {
        atemp = atemp*10 + (int)(*ptr_data - '0');
      }
    } else if (b == 0) {
      if (*ptr_data == ' ' ||*ptr_data == '\0' || *ptr_data == 10  ) {
        b = btemp + 0;
      } else {
        btemp = btemp*10 + (int)(*ptr_data - '0');
      }
    }
  
    ptr_data = ptr_data+1;
    if(*ptr_data == '\0') {
      break;
    }
  }
  int result = operation(op,a,b);
  return result
}
int operation(char op,int a,int b) {
	int c;
	int i = 0;
	int somme = 0;
	
	switch(op) {
		case '+' :c = a+b;break;
		case '-' :c = a-b;break;
		case '*' :c = a*b;break;
		case '/' :c = a/b;break;
	}

	return c;
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

  //Si le message commence par le mot: 'message:' 
  if (strcmp(code, "message:") == 0) {
    	//renvoie_message(client_socket_fd, data);
  	char message[1024];
  	printf("Renvoyez un nouveau message : ");
  	fgets(message,1024,stdin);
  	renvoie_message(client_socket_fd,message);
  } else if (strcmp(code, "calcul:") == 0) {
    	//renvoie_message(client_socket_fd, data);
	
  result = recois_numero_calcule(data);
	char buffer[30];
	sprintf(buffer,"%d",result);
	printf("%d - %s\n",result, buffer);	
	char message[100];
	strcat(message,buffer);	
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
