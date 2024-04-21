#include "supprimer.h"
#include "main-header.h"
#include <stdio.h>
#include "rechercher.h"

void supprimerEtudiantApogee(Etudiant etudiants[], int* nbr_etudiants_actu ){
    int num_apo;
    printf("Donner le numero apogee de l'etudiant a supprimer: ");
    scanf("%d", &num_apo);
    int index = rechercherEtudiantApogee(etudiants, *nbr_etudiants_actu, num_apo);
    if(index == -1){
        printf("L'etudiant n'existe pas\n");
        return ;
    }
    for(int i = index; i < *nbr_etudiants_actu - 1; i++){
        etudiants[i] = etudiants[i+1];
    }
    *nbr_etudiants_actu = *nbr_etudiants_actu - 1;
    printf("Etudiant supprime avec succes\n");
}