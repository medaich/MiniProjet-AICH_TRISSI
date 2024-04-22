
#include <stdio.h>
#include "main-header.h"
#include <string.h>
#include "fichiers.h"

void enregistrerEtudiantsDansFichier(Etudiant etudiants[], int nbr_etudiants_actu){
    FILE* fichier = fopen("etudiants.txt", "w");
    rewind(fichier);
    if (fichier == NULL){
        return;
    }
    for (int i = 0; i < nbr_etudiants_actu; ++i) {
        fprintf(fichier, "%d %s %s %d %d %d %d %d %d %f ", etudiants[i].num_apo, etudiants[i].nom, etudiants[i].prenom,
                etudiants[i].date_naissanse.jour, etudiants[i].date_naissanse.mois , etudiants[i].date_naissanse.annee ,
                etudiants[i].date_inscription.jour, etudiants[i].date_inscription.mois, etudiants[i].date_inscription.annee,
                etudiants[i].moyenne);
        switch (etudiants[i].filiere) {
            case SMI:
                fprintf(fichier, "0");
                break;
            case SMA:
                fprintf(fichier, "1");
                break;
            case SMP:
                fprintf(fichier, "2");
                break;
        }
        fprintf(fichier, " %d", etudiants[i].nbr_modules);
        for (int j = 0; j < etudiants[i].nbr_modules; ++j) {
            fprintf(fichier, " %s %f", etudiants[i].modules[j].nom_module, etudiants[i].modules[j].note);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
    printf("Les modifications ont été enregistrés avec succès\n");
}
void lireEtudiantsDeFichier(Etudiant etudiants[], int* nbr_etudiants_actu){
    FILE* fichier = fopen("etudiants.txt", "r");
    if (fichier == NULL){
        return;
    }
    int filiere;
    while (fscanf(fichier, "%d %s %s %d %d %d %d %d %d %f %d", &etudiants[*nbr_etudiants_actu].num_apo, etudiants[*nbr_etudiants_actu].nom, etudiants[*nbr_etudiants_actu].prenom,
                  &etudiants[*nbr_etudiants_actu].date_naissanse.jour, &etudiants[*nbr_etudiants_actu].date_naissanse.mois , &etudiants[*nbr_etudiants_actu].date_naissanse.annee ,
                  &etudiants[*nbr_etudiants_actu].date_inscription.jour, &etudiants[*nbr_etudiants_actu].date_inscription.mois, &etudiants[*nbr_etudiants_actu].date_inscription.annee,
                  &etudiants[*nbr_etudiants_actu].moyenne, &filiere) != EOF){
        switch(filiere){
            case 0:
                etudiants[*nbr_etudiants_actu].filiere = SMI;
                break;
            case 1:
                etudiants[*nbr_etudiants_actu].filiere = SMA;
                break;
            case 2:
                etudiants[*nbr_etudiants_actu].filiere = SMP;
                break;
        }
        fscanf(fichier, " %d", &etudiants[*nbr_etudiants_actu].nbr_modules);
        for (int i = 0; i < etudiants[*nbr_etudiants_actu].nbr_modules; ++i) {
            fscanf(fichier, " %s %f", etudiants[*nbr_etudiants_actu].modules[i].nom_module, &etudiants[*nbr_etudiants_actu].modules[i].note);
        }
        *nbr_etudiants_actu = *nbr_etudiants_actu + 1;
    }
    fclose(fichier);
}