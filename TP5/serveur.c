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
        - Fonction lire_fichier librement inspirée de : https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c/16421-lire-et-ecrire-dans-des-fichiers
*/

#include <sys/types.h> 
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "serveur.h"

// Fonction pour ouvrir et récuperer les chiffres d'un fichier 
int lire_fichier(char *nom_de_fichier){
    // Initialisations des variables utiles ---
    int fichier;
    char carac;
    char tempchar[3];
    int cmpt = 0;
    int size;

    // Partie ouverture, parcours et cloture du fichier ---
    fichier = open(nom_de_fichier,O_RDONLY);
    if (fichier != 0) {
	    while (1) {
		    size = read(fichier,&carac,1);
        // Si le fichier est finie alors on sort de la boucle
		    if(size<1) { break;}
		    if(carac != 10) {
			    tempchar[cmpt] = carac;
			    cmpt += 1;
		    }
	    }
	    cmpt = atoi(tempchar);
    }
    close(fichier);

    // Retous du int contenu dans le fichier
    return(cmpt);
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

// Fonction pour la partie : réalisation d'un calcul à partir de saisies utilisateurs ou de la moyenne. 
// Inputs : 
// - data : tableau contenant le messages de l'utilisateurs 
// - buffer : tableau vide pour récuperer le résultat de l'opération.
// Outputs : 
// - int : 0, cette fonction ne nécessite aucun retour particulié.
int recois_numero_calcule(char* data,char* buffer, char *opreturn) {
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

  // Parcours une première fois de la liste pour déterminer le mode. 
  // 2 cas possibles : 
  //    - mode == 3 -> présence de 3 ' ' donc de B
  //    - mode != 3 -> présence de moins de 3 ' ' donc pas de B
  for(int g = 0; g < 100; g++) {
	  if (data[g] == ' ') {
		  mode += 1;
	  } else if (data[g] == '\0') {
		  break;
	  }
  }
  
  // Partie : Récupération des paramètres utilisateurs 
  for(int i = 1; i < 100; i++) {  
    // Récupération de l'opération attendue ou de la moyenne
    if( *ptr_data == '+' || *ptr_data == '-' || *ptr_data == '*' || *ptr_data == '/' || *ptr_data == 'M') {
      op = *ptr_data;
      ptr_data += 1;
    } 

    // Partie Initialisation de la valeur a 
    else if (a == 0 && af == 0) {

      // Cas 1 : la valeur est finie (présence d'un espace), convertions de la valeur en int ou double en fonction de la présence (ou non) du caractère '.'
      if (*ptr_data == ' ' || *ptr_data == 10) {  
         if (fa == 0) {  a = atoi(atemp);}
	       else { af = atof(atemp);}
	       j = 0;
	       if( mode != 3) { break; }
      } 
      // Cas 2 : la valeur continue donc on continue le tableau et l'on test la présence du caractère '.'.      
      else {
        atemp[j] = *ptr_data; 
	      j += 1;
      	if (*ptr_data == '.') { fa = 1;}
      }
    }

    // Partie Initialisation de la valeur b si le mode est 3
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
    if(*ptr_data == '\0') { break; }
  }

  // 2 cas possibles :
  //  * 1 : calcul de c (int ou float) 
  if (mode == 3) {
    // Pour réaliser, l'opérations il y a 4 cas possibles : 
    // Cas 1 : Les deux valeurs sont des ints
    if( fa == 0 && fb == 0) {
    	int result = operation(op,a,b);
      sprintf(buffer,"%d",result);
    }
    // Cas 2 et 3 : a ou b est un float et on convertie l'autre en float pour faire le calcul. 
    else if( fa == 0 && fb == 1) {
    	af = (double) a;
      double result = operationf(op,af,bf);
    	sprintf(buffer,"%f",result);
    }
    else if( fa == 1 && fb == 0) {
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

  //  * 2 : calcul de la moyenne  
  else {

      // Si a est une des 5 matières possibles 
      if (a < 6) {
        // Initialisation de variables utiles
        char lien[100];
        double moyenne = 0;
        char lien_a = a + '0';

        // Boucle pour traiter les 5 fichiers '.txt'
        for (int i = 1; i<6;i++) {
          // Génération automatique des liens 
          strcpy(lien, "etudiant/");
          lien[strlen(lien)] = lien_a;
          strcat(lien,"/note");
          lien[strlen(lien)] = i + '0';
          strcat(lien,".txt");

          // Appel de la fonction pour parcourir un fichier 
          int noten = lire_fichier(lien);


          moyenne = moyenne + noten;
          memset(lien,0,strlen(lien));
        }
        moyenne =moyenne/5;
        sprintf(buffer,"%f",moyenne);
      }
      // Sinon, return 0  
      else {
        double moyenne = 0;
        sprintf(buffer,"%f",moyenne);
      }
  }
  
  // Affectation de l'opérateur 
  *opreturn = op;
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
    char opreturn[1];
    // Calcul du résultat ---
  	int temp = recois_numero_calcule(data,buffer,opreturn);
    // Création de la chaine à retourner ---
    printf("\n%s",&opreturn);
    if(opreturn[0] == 'M') {
  	strcpy(message, "La moyenne du devoir est :");
  	strcat(message,buffer);
    } else {
  	strcpy(message, "Le resultat est :");
  	strcat(message,buffer);
    }
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
