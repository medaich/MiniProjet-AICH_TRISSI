#include "afficher.h"
#include <stdio.h>
#include "main-header.h"
#include "rechercher.h"

void afficherHeader(){
    printf("\n---------------------------------------------------------------------------------\n");
    printf("| Apogée  | Nom            | Prénom         | Naissance  | Inscription | Filière |\n");
}

void afficherEtudiant(Etudiant etudiant){
    printf("---------------------------------------------------------------------------------\n");
    printf("| %-8d| %-15s| %-15s| %02d/%02d/%04d | %02d/%02d/%04d  |", etudiant.num_apo,
           etudiant.nom, etudiant.prenom, etudiant.date_naissanse.jour, etudiant.date_naissanse.mois,
           etudiant.date_naissanse.annee, etudiant.date_inscription.jour, etudiant.date_inscription.mois,
           etudiant.date_inscription.annee);
    switch (etudiant.filiere) {
        case SMI: printf(" %-8s|", "SMI");
            break;
        case SMA: printf(" %-8s|", "SMA");
            break;
        case SMP: printf(" %-8s|", "SMP");
            break;
    }
    printf("\n---------------------------------------------------------------------------------\n");
    printf("                                       | Modules    |\n");
    printf("                 **********************************************************");
    for (int j = 0; j < etudiant.nbr_modules; ++j) {

        printf("\n                 **   %02d: %-15s| %05.2f/20                      **",
               j+1, etudiant.modules[j].nom_module, etudiant.modules[j].note);

    }
    printf("\n                 **********************************************************\n");
    printf("                                       | Moyenne:%-2.2f/20 |\n", etudiant.moyenne);
}

void afficherNEtudiants(Etudiant etudiants[], int nbr_etudiants_actu){
    if (nbr_etudiants_actu == 0) printf("aucun étudiant n'est inscrit\n");
    else
        afficherHeader();
    for (int i = 0; i < nbr_etudiants_actu; ++i) {
        afficherEtudiant(etudiants[i]);
    }
}
void afficherEtudiantsAdmisSeulement(Etudiant etudiants[], int nbr_etudiants_actu){
    int existe  = 0;    //pour tester si l'étudiant existe
    int  existe_header = 1 ;    //pour tester si on doit afficher le header

    for (int i = 0; i < nbr_etudiants_actu; ++i) {
        if (etudiants[i].moyenne >= 10){
            if(existe_header){
                afficherHeader();
            }
            afficherEtudiant(etudiants[i]);
            existe_header = 0;
            existe = 1;
        }
    } if(!existe) printf("étudiant n'est  admis\n");

}
void AfficherEtudiantsFiliere(Etudiant etudiants[], int nbr_etudiants_actu){
    Filiere filiere;
    int num_fil;
    int existe  = 0;    //pour tester si l'étudiant existe
    int  existe_header = 1 ;    //pour tester si on doit afficher le header
    printf("veuillez enter la filière\n pour SMI taper 0, pour SMA taper 1 et pour SMP taper 2:\n");
    do {
        scanf("%d", &num_fil);
        switch (num_fil) {
            case 0: filiere = SMI;
                break;
            case 1: filiere = SMA;
                break;
            case 2: filiere = SMP;
                break;
            default: printf("entrer 0, 1, ou 2.\n");
        }
    } while (num_fil < 0 || num_fil > 2);
    for (int i = 0; i < nbr_etudiants_actu; ++i) {
        if (etudiants[i].filiere == filiere){
            if(existe_header){
                afficherHeader();
            }
            afficherEtudiant(etudiants[i]);
            existe_header = 0;
            existe = 1;
        }
    }
    if(!existe) printf("cette filiére est vide\n");
}
void AfficherEtudiantApogee(Etudiant etudiants[], int nbr_etudiants_actu){
    int num_apo;
    printf("Donner le numéro apogée de l'étudiant à rechercher: ");
    scanf("%d", &num_apo);
    int i=rechercherEtudiantApogee(etudiants, nbr_etudiants_actu, num_apo);
    if(i != -1) {
        afficherHeader();
        afficherEtudiant(etudiants[i]);
    }else printf("l'étudiant n'existe pas\n");
}