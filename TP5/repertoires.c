#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void main() {
    DIR *dir;
    struct dirent *dent;
    char buffer[50];
    printf("Saisir un lien")
    scanf("%s",&(buffer[0]));
    dir = opendir(buffer);   //this part
    if(dir!=NULL) {
        while((dent=readdir(dir))!=NULL)
            printf(dent->d_name);
    }
    close(dir);
}
