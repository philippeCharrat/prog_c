#include <stdio.h>
#include <string.h>

int main(){
 
    struct etudiant {
        char prenom[30];
        char nom[30];
        char adresse[50];
        int C;
        int sys;
    };
    
    struct etudiant students[5];
    strcpy(students[0].prenom, "Axel");
    strcpy(students[0].nom, "Bruyere");
    strcpy(students[0].adresse, "Ad1");
    students[0].C = 20;
    students[0].sys = 20;
    
    strcpy(students[1].prenom, "Philippe");
    strcpy(students[1].nom, "Charrat");
    strcpy(students[1].adresse, "Ad2");
    students[1].C = 0;
    students[1].sys = 0;
    
    strcpy(students[2].prenom, "Jean");
    strcpy(students[2].nom, "Dupond");
    strcpy(students[2].adresse, "Ad3");
    students[2].C = 15;
    students[2].sys = 8;
    
    strcpy(students[3].prenom, "Pierre");
    strcpy(students[3].nom, "Dupont");
    strcpy(students[3].adresse, "Ad4");
    students[3].C = 3;
    students[3].sys = 14;
    
    strcpy(students[4].prenom, "Paul");
    strcpy(students[4].nom, "Durant");
    strcpy(students[4].adresse, "Ad5");
    students[4].C = 11;
    students[4].sys = 5;
    
    int i;
    
    for (i = 0 ; i<5 ; i++){
        printf("L'élève %s %s domicilié au %s a obtenu la note de %d en programmation en C et %d en système d'exploitation \n \n",students[i].prenom,students[i].nom,students[i].adresse,students[i].C,students[i].sys);
    }

    
    
    
    
    return(0);
}
