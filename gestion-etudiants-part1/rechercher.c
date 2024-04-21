#include "rechercher.h"
#include <stdio.h>
#include "main-header.h"
#include <string.h>
#include "afficher.h"
#include <ctype.h>

// une fonction pour éviter case sensitivity
void lowerCase(char chaine[]){
    for(int i = 0; i < strlen(chaine); i++){
        chaine[i] = tolower(chaine[i]);
    }
}

int rechercherEtudiantApogee(Etudiant etudiants[], int nbr_etudiants_actu , int num_apo){
    for (int i = 0; i < nbr_etudiants_actu; ++i) {
        if (etudiants[i].num_apo == num_apo){
            return i;
        }
    }
    return -1;
}




void rechercherEtudiantNom(Etudiant etudiants[], int nbr_etudiants_actu){
    char nom[MAX_STRINGS];
    char nom_temp[MAX_STRINGS];
    int existe  = 0;  //pour tester si l'étudiant existe
    int  existe_header = 1 ;      //pour tester si on doit afficher le header
    printf("Donner le nom de l'étudiant à rechercher: ");
    scanf("%s", nom);
    lowerCase(nom);
    for (int i = 0; i < nbr_etudiants_actu; ++i) {

        strcpy(nom_temp, etudiants[i].nom);
        lowerCase(nom_temp);
        if (strcmp(nom_temp, nom) == 0){
            if(existe_header){
                afficherHeader();
            }
            afficherEtudiant(etudiants[i]);
            existe_header = 0;
            existe = 1 ;
        }
    }
    if (!existe) printf("l'étudiant n'existe pas\n");

}
void rechercherEtudiantPrenom(Etudiant etudiants[], int nbr_etudiants_actu){
    char prenom[MAX_STRINGS];
    char prenom_temp[MAX_STRINGS];
    int existe  = 0;    //pour tester si l'étudiant existe
    int  existe_header = 1 ;    //pour tester si on doit afficher le header
    printf("Donner le prénom de l'étudiant à rechercher: ");
    scanf("%s", prenom);
    lowerCase(prenom);
    for (int i = 0; i < nbr_etudiants_actu; ++i) {

        strcpy(prenom_temp, etudiants[i].prenom);
        lowerCase(prenom_temp);
        if (strcmp(prenom_temp, prenom) == 0){
            if(existe_header){
                afficherHeader();
            }
            afficherEtudiant(etudiants[i]);
            existe_header = 0;
            existe = 1 ;
        }
    }
    if (!existe) printf("l'étudiant n'existe pas\n");

}
void rechercherEtudiantAnneeInscriprion(Etudiant etudiants[], int nbr_etudiants_actu){
    int annee;
    int existe  = 0;  //pour tester si l'étudiant existe
    int  existe_header = 1 ;      //pour tester si on doit afficher le header
    printf("Donner l'année d'inscription de l'étudiant à rechercher: ");
    scanf("%d", &annee);
    for (int i = 0; i < nbr_etudiants_actu; ++i) {
        if (etudiants[i].date_inscription.annee == annee){
            if(existe_header){
                afficherHeader();
            }
            existe_header = 0;
            afficherEtudiant(etudiants[i]);
            existe = 1 ;
        }
    }
    if (!existe) printf("l'étudiant n'existe pas\n");
}