
#include "menu.h"
#include "trier.h"
#include "ajout.h"
#include "afficher.h"
#include "rechercher.h"
#include "supprimer.h"
#include <stdio.h>
#include "main-header.h"
#include "modifier.h"
int menu(Etudiant etudiants[], int *nbr_etudiants_actu){
    int choix;
    int sauvegarder;
    do{
        printf("Menu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Consulter les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Modifier un etudiant\n");
        printf("5. Trier les etudiants\n");
        printf("6. Supprimer un etudiant\n");
        printf("7. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        switch(choix){
            case 1:
                ajout_n_etudiants(etudiants, nbr_etudiants_actu);
                break;
            case 2:
                int choix_consultation;
                printf("1. Consulter tous les etudiants\n");
                printf("2. Consulter les etudiants admis seulement\n");
                printf("3. Consulter les etudiants par filière\n");
                printf("Votre choix: ");
                scanf("%d", &choix_consultation);
                switch(choix_consultation){
                    case 1:
                        afficherNEtudiants(etudiants, *nbr_etudiants_actu);
                        break;
                    case 2:
                        afficherEtudiantsAdmisSeulement(etudiants, *nbr_etudiants_actu);
                        break;
                    case 3:
                        AfficherEtudiantsFiliere(etudiants, *nbr_etudiants_actu);
                        break;
                    default:
                        printf("Choix invalide\n");
                }
                break;
            case 3:
                int choix_recherche;
                printf("1. Rechercher par nom\n");
                printf("2. Rechercher par prénom\n");
                printf("3. Rechercher par numero d'apogee\n");
                printf("4. Rechercher par année d'inscription\n");
                printf("Votre choix: ");
                scanf("%d", &choix_recherche);
                switch(choix_recherche){
                    case 1:
                        rechercherEtudiantNom(etudiants, *nbr_etudiants_actu);
                        break;
                    case 2:
                        rechercherEtudiantPrenom(etudiants, *nbr_etudiants_actu);
                        break;
                    case 3:
                        AfficherEtudiantApogee(etudiants, *nbr_etudiants_actu);
                        break;
                    case 4:
                        rechercherEtudiantAnneeInscriprion(etudiants, *nbr_etudiants_actu);
                        break;
                    default:
                        printf("Choix invalide\n");
                }
                break;
            case 4:
                modifierEtudiant(etudiants, *nbr_etudiants_actu);
                break;
            case 5:
                int choix_tri;
                printf("1. Trier par année d'inscription\n");
                printf("2. Trier par moyenne\n");
                printf("3. Trier par numero d'apogee\n");
                printf("Votre choix: ");
                scanf("%d", &choix_tri);
                switch(choix_tri){
                    case 1:
                        trierEtudiantsInscription(etudiants, *nbr_etudiants_actu);
                        break;
                    case 2:
                        trierEtudiantMoyenne(etudiants, *nbr_etudiants_actu);
                        break;
                    case 3:
                        trierEtudiantApogee(etudiants, *nbr_etudiants_actu);
                        break;
                    default:
                        printf("Choix invalide\n");
                }
                break;
            case 6:
                supprimerEtudiantApogee(etudiants, nbr_etudiants_actu);
                break;
            case 7:
                int choix_quitter;
                    printf("1. Sauvegarder les modifications\n");
                    printf("2. Quitter sans sauvegarder\n");
                    printf("3. Annuler\n");
                    printf("Votre choix: ");
                    scanf("%d", &choix_quitter);
                    switch(choix_quitter){
                        case 1:
                            sauvegarder = 1;
                            break;
                        case 2:
                            sauvegarder = 0;
                            break;
                        case 3:
                            choix=0; break;
                        default:
                            printf("Choix invalide\n");
                    }
                break;
            default:
                printf("Choix invalide\n");
        }
    }while(choix != 7);
    return sauvegarder;
}