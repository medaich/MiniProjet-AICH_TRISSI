
#include "trier.h"
#include "main-header.h"
#include <stdio.h>

void trierEtudiantsInscription(Etudiant etudiants[], int nbr_etudiants_actu){
    int i, j;
    Etudiant temp;
    for(i = 0; i < nbr_etudiants_actu; i++){
        for(j = i+1; j < nbr_etudiants_actu; j++){
            if(etudiants[i].date_inscription.annee > etudiants[j].date_inscription.annee){
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Les étudiants sont triés par année d'inscription\n");
}
void trierEtudiantMoyenne(Etudiant etudiants[], int nbr_etudiants_actu){
    int i, j;
    Etudiant temp;
    for(i = 0; i < nbr_etudiants_actu; i++){
        for(j = i+1; j < nbr_etudiants_actu; j++){
            if(etudiants[i].moyenne > etudiants[j].moyenne){
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Les étudiants sont triés par moyenne\n");
}
void trierEtudiantApogee(Etudiant etudiants[], int nbr_etudiants_actu){
    int i, j;
    Etudiant temp;
    for(i = 0; i < nbr_etudiants_actu; i++){
        for(j = i+1; j < nbr_etudiants_actu; j++){
            if(etudiants[i].num_apo > etudiants[j].num_apo){
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("Les étudiants sont triés par numéro d'apogée\n");
}