#include "main-header.h"
#include "ajout.h"
#include "menu.h"
#include "fichiers.h"

int main() {
    int sauvegarde = 0;
    Etudiant etudiants[MAX_ETUDIANTS];
    int nbr_etudiants_actu = 0;
    lireEtudiantsDeFichier(etudiants, &nbr_etudiants_actu);
    sauvegarde= menu(etudiants, &nbr_etudiants_actu);

    if (sauvegarde == 1)enregistrerEtudiantsDansFichier(etudiants, nbr_etudiants_actu);

    return 0;


}
