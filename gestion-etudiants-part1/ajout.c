#include<stdio.h>
#include<string.h>
#include "main-header.h"
#include "ajout.h"

Etudiant ajout_etudiant(){
    Etudiant e;
    int num_fil;
    float som_notes =0 ;
    printf("Entrer le nom:");
    fgets(e.nom , MAX_STRINGS, stdin);
    e.nom[strcspn(e.nom, "\n")] = '\0'; // supprimer le caractère de retour à la ligne
    printf("Entrer le prénom:");
    fgets(e.prenom , MAX_STRINGS, stdin);
    e.prenom[strcspn(e.prenom, "\n")] = '\0'; // supprimer le caractère de retour à la ligne
    printf("entrer la date de naissance:\n");
    do {
        printf("jour : ");
        scanf("%d", &e.date_naissanse.jour);
    } while (e.date_naissanse.jour <= 0 || e.date_naissanse.jour>31);
    do {
        printf("mois (un nombre):");
        scanf("%d", &e.date_naissanse.mois);
   } while (e.date_naissanse.mois <= 0 || e.date_naissanse.mois>12);

    printf("année :");
    scanf("%d", &e.date_naissanse.annee);

    printf("entrer la date d'inscription:\n");
    do {
        printf("jour : ");
        scanf("%d", &e.date_inscription.jour);
    } while (e.date_inscription.jour <= 0 || e.date_inscription.jour>31);
    do {
        printf("mois (un nombre):");
        scanf("%d", &e.date_inscription.mois);
    } while (e.date_inscription.mois <= 0 || e.date_inscription.mois>12);

    printf("année :");
    scanf("%d", &e.date_inscription.annee);

    // saisir fil

    do {
        printf("veuillez enter la filière\n pour SMI taper 0, pour SMA taper 1 et pour SMP taper 2:\n");
        scanf("%d", &num_fil);
        switch (num_fil) {
            case 0: e.filiere = SMI;
                break;
            case 1: e.filiere = SMA;
                break;
            case 2: e.filiere = SMP;
                break;
            default: printf("entrer 0, 1, ou 2.\n");
        }
    } while (num_fil < 0 || num_fil > 2);
    // les notes et modules
    printf("veuillez entrer les notes:\n");
    do {
        printf("saisir le nombre de modules:");
        scanf("%d", &e.nbr_modules);
        getchar();
    } while (e.nbr_modules <= 0 ||e.nbr_modules >MAX_MODULES );

    for (int i = 0; i < e.nbr_modules; ++i) {
        float note;
        printf("entrer le nom du module numéro %d:", i + 1);
        fgets(e.modules[i].nom_module, MAX_MODULES, stdin);
        e.modules[i].nom_module[strcspn(e.modules[i].nom_module, "\n")] = '\0'; // supprimer le caractère de retour à la ligne
        do {
            printf("entrer la note du module numéro %d:", i + 1);
            scanf("%f", &note);
            getchar();
        }while (note < 0 || note > 20);
        e.modules[i].note = note;
        som_notes+= e.modules[i].note;
    }
    e.moyenne = som_notes/(e.nbr_modules);

    return e;
}
void ajout_n_etudiants(Etudiant etudiants[] ,int *nbr_etudiants_actu){
    int nbr_etudiants_ajout;
    do {
        printf("entrer le nombre des étudiants à ajouter:");
        scanf("%d", &nbr_etudiants_ajout);
        getchar();
    } while (nbr_etudiants_ajout<= 0 || nbr_etudiants_ajout + *nbr_etudiants_actu > MAX_ETUDIANTS);
    for (int i = *nbr_etudiants_actu; i < nbr_etudiants_ajout + *nbr_etudiants_actu ; ++i) {
        printf("\nsaisir les informations d'étudiant numéro %d:\n", i+1);
        etudiants[i] = ajout_etudiant();
        etudiants[i].num_apo = (etudiants[i].date_inscription.annee)*100 + i;
    }
    *nbr_etudiants_actu += nbr_etudiants_ajout;
}


