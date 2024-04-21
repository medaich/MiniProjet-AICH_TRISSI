#include "modifier.h"
#include "main-header.h"
#include <stdio.h>
#include "rechercher.h"

void modifierEtudiant(Etudiant etudiants[], int nbr_etudiants_actu){
    int num_apo;
    int index;
    int choix;
    printf("Entrez le numéro d'apogée de l'étudiant à modifier: ");
    scanf("%d", &num_apo);
    index = rechercherEtudiantApogee(etudiants, nbr_etudiants_actu, num_apo);
    if (index != -1) {
        do {
            printf("1. Modifier le nom\n");
            printf("2. Modifier le prénom\n");
            printf("3. Modifier la filière\n");
            printf("4. Modifier la date d'inscription\n");
            printf("5. Modifier la date de naissance\n");
            printf("6. Modifier les modules et les notes\n");
            printf("7. Quitter\n");
            printf("Votre choix: ");
            scanf("%d", &choix);
            switch(choix){
                case 1:
                    printf("Donner le nouveau nom: ");
                    scanf("%s", etudiants[index].nom);
                    break;
                case 2:
                    printf("Donner le nouveau prénom: ");
                    scanf("%s", etudiants[index].prenom);
                    break;
                case 3:
                    int num_fil;
                    printf("veuillez enter la filière\n pour SMI taper 0, pour SMA taper 1 et pour SMP taper 2:\n");
                    do {
                        scanf("%d", &num_fil);
                        switch (num_fil) {
                            case 0: etudiants[index].filiere = SMI;
                                break;
                            case 1: etudiants[index].filiere = SMA;
                                break;
                            case 2: etudiants[index].filiere = SMP;
                                break;
                            default: printf("entrer 0, 1, ou 2.\n");
                        }
                    } while (num_fil < 0 || num_fil > 2);
                    break;
                case 4:
                    printf("Donner la nouvelle date d'inscription:\n");
                    do {
                        printf("jour : ");
                        scanf("%d", &etudiants[index].date_inscription.jour);
                    } while (etudiants[index].date_inscription.jour <= 0 || etudiants[index].date_inscription.jour>31);
                    do {
                        printf("mois (un nombre):");
                        scanf("%d", &etudiants[index].date_inscription.mois);
                    } while (etudiants[index].date_inscription.mois <= 0 || etudiants[index].date_inscription.mois>12);
                    printf("année :");
                    scanf("%d", &etudiants[index].date_inscription.annee);
                    break;
                case 5:
                    printf("Donner la nouvelle date de naissance:\n");
                    do {
                        printf("jour : ");
                        scanf("%d", &etudiants[index].date_naissanse.jour);
                    } while (etudiants[index].date_naissanse.jour <= 0 || etudiants[index].date_naissanse.jour>31);
                    do {
                        printf("mois (un nombre):");
                        scanf("%d", &etudiants[index].date_naissanse.mois);
                    } while (etudiants[index].date_naissanse.mois <= 0 || etudiants[index].date_naissanse.mois>12);
                    printf("année :");
                    scanf("%d", &etudiants[index].date_naissanse.annee);
                    break;
                case 6:
                    int choix_modules;
                    do {
                        printf("1. Ajouter un module\n");
                        printf("2. Modifier un module\n");
                        printf("3. Supprimer un module\n");
                        printf("4. Quitter\n");
                        printf("Votre choix: ");
                        scanf("%d", &choix_modules);
                        switch(choix_modules){
                            case 1:
                                if (etudiants[index].nbr_modules < MAX_MODULES){
                                    printf("entrer le nom du module:");
                                    scanf("%s", etudiants[index].modules[etudiants[index].nbr_modules].nom_module);
                                    printf("entrer la note du module:");
                                    scanf("%f", &etudiants[index].modules[etudiants[index].nbr_modules].note);
                                    etudiants[index].nbr_modules++;
                                } else
                                    printf("le nombre maximum des modules est atteint\n");
                                break;
                            case 2:
                                if (etudiants[index].nbr_modules > 0){
                                    int num_module;
                                    for (int i = 0; i < etudiants[index].nbr_modules; ++i) {
                                        printf("%d. %s\n", i+1, etudiants[index].modules[i].nom_module);
                                    }
                                    printf("entrer le numéro du module à modifier: ");
                                    scanf("%d", &num_module);
                                    if (num_module > 0 && num_module <= etudiants[index].nbr_modules){
                                        printf("entrer le nom du module:");
                                        scanf("%s", etudiants[index].modules[num_module-1].nom_module);
                                        printf("entrer la note du module:");
                                        scanf("%f", &etudiants[index].modules[num_module-1].note);
                                    } else
                                        printf("numéro de module invalide\n");
                                } else
                                    printf("aucun module à modifier\n");
                                break;
                            case 3:
                                if (etudiants[index].nbr_modules > 0){
                                    int num_module;
                                    for (int i = 0; i < etudiants[index].nbr_modules; ++i) {
                                        printf("%d. %s\n", i+1, etudiants[index].modules[i].nom_module);
                                    }
                                    printf("entrer le numéro du module à supprimer: ");
                                    scanf("%d", &num_module);
                                    if (num_module > 0 && num_module <= etudiants[index].nbr_modules){
                                        for (int i = num_module-1; i < etudiants[index].nbr_modules-1; ++i) {
                                            etudiants[index].modules[i] = etudiants[index].modules[i+1];
                                        }
                                        etudiants[index].nbr_modules--;
                                    } else
                                        printf("numéro de module invalide\n");
                                } else
                                    printf("aucun module à supprimer\n");
                                break;
                            case 4:
                                break;
                            default:
                                printf("Choix invalide\n");
                        }
                    }while(choix_modules != 4);
                    break;
                case 7:
                    break;
                default:
                    printf("Choix invalide\n");
            }
        } while(choix != 7);
    } else
        printf("Aucun étudiant avec ce numéro d'apogée n'a été trouvé\n");
}