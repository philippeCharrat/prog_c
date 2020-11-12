/*
 * SPDX-FileCopyrightText: 2020 John Samuel
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>  
#include <sys/socket.h>
#include <netinet/in.h>
#include <json/json.h>
#include "client.h"
#include "bmp.h"

/* 
 * Fonction d'envoi et de réception de messages
 * Il faut un argument : l'identifiant de la socket
 */

int envoie_recois_message(int socketfd) {
 
  char data[1024];
  // la réinitialisation de l'ensemble des données
  memset(data, 0, sizeof(data));


  // Demandez à l'utilisateur d'entrer un message
  char message[100];
  printf("Votre message (max 1000 caracteres): ");
  fgets(message, 1024, stdin);
  strcpy(data, "message: ");
  strcat(data, message);
  
  int write_status = write(socketfd, data, strlen(data));
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

void analyse(char *pathname, char *data) {
  //Variables utiles ---
  couleur_compteur *cc = analyse_bmp_image(pathname);
  int test;
  int count;
  strcpy(data, "couleurs: ");
  // Saisie du nombre de couleurs 
  char temp_string[10];
  printf("Saisir le nombre de couleur à analyser (max < 30) : ");
  fgets(temp_string,10,stdin);

  // Boucle infinie
  while(1) {
    // Convertion de la variable char to int 
  	test = atoi(temp_string);
    // si la saisie correspond à l'intervalle, on break
  	if (test < 31 && test > 0 ) {
  		break;
  	} 
    // Sinon on re-saisie une nouvelle valeur
    else {
  		memset(temp_string,0,strlen(temp_string));
    	printf("Saisir le nombre de couleur à analyser (max < 30) : ");
    	fgets(temp_string,10,stdin);		
  	}
  }
  
  // Ajout de la valeur de dans la chaine de caractère
  strcat(data,",");
  temp_string[strlen(temp_string)-1] = '\0';
  strcat(data, temp_string);
  strcat(data,",");
  
  //choisir X couleurs (saisie par l'utilisateur)
  for (count = 1; count < test+1 && cc->size - count >0; count++) {
    if(cc->compte_bit ==  BITS32) {
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc24[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    if(cc->compte_bit ==  BITS24) {
      sprintf(temp_string, "#%02x%02x%02x,", cc->cc.cc32[cc->size-count].c.rouge,cc->cc.cc32[cc->size-count].c.vert,cc->cc.cc32[cc->size-count].c.bleu);
    }
    strcat(data, temp_string);
  }

  //enlever le dernier virgule
  data[strlen(data)-1] = '\0';
}

int envoie_couleurs(int socketfd, char *pathname) {
  char data[1024];
  memset(data, 0, sizeof(data));
  analyse(pathname, data);
  json_object *jobj = json_object_new_object();

    /*Creating a json string*/
    json_object *jstring = json_object_new_string("Joys of Programming");

    /*Creating a json integer*/
    json_object *jint = json_object_new_int(10);

    /*Creating a json boolean*/
    json_object *jboolean = json_object_new_boolean(1);

    /*Creating a json double*/
    json_object *jdouble = json_object_new_double(2.14);

    /*Creating a json array*/
    json_object *jarray = json_object_new_array();

    /*Creating json strings*/
    json_object *jstring1 = json_object_new_string("c");
    json_object *jstring2 = json_object_new_string("c++");
    json_object *jstring3 = json_object_new_string("php");

    /*Adding the above created json strings to the array*/
    json_object_array_add(jarray,jstring1);
    json_object_array_add(jarray,jstring2);
    json_object_array_add(jarray,jstring3);

    /*Form the json object*/
    /*Each of these is like a key value pair*/
    json_object_object_add(jobj,"Site Name", jstring);
    json_object_object_add(jobj,"Technical blog", jboolean);
    json_object_object_add(jobj,"Average posts per day", jdouble);
    json_object_object_add(jobj,"Number of posts", jint);
    json_object_object_add(jobj,"Categories", jarray);

    printf("Size of JSON object- %lu\n", sizeof(jobj));
    printf("Size of JSON_TO_STRING- %lu,\n %s\n", sizeof(json_object_to_json_string(jobj)), json_object_to_json_string(jobj));

    //printf("Size of string- %lu\n", sizeof(json_object_to_json_string(jobj)));
    printf("%s\n", json_object_to_json_string(jobj)
  int write_status = write(socketfd, data, strlen(data));
  if ( write_status < 0 ) {
    perror("erreur ecriture");
    exit(EXIT_FAILURE);
  }

  return 0;
}


int main(int argc, char **argv) {
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

  //demande de connection au serveur
  int connect_status = connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
  if ( connect_status < 0 ) {
    perror("connection serveur");
    exit(EXIT_FAILURE);
  }
  //envoie_recois_message(socketfd);
  envoie_couleurs(socketfd, argv[1]);

  close(socketfd);
}
