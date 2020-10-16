#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int lire_fichier(char*);
int ecrire_dans_fichier(char *nom_de_fichier, char *message);
