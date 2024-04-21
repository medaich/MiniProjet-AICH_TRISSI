#include "main-header.h"
#include "ajout.h"
#include "menu.h"

int main() {
    Etudiant etudiants[MAX_ETUDIANTS];
    int nbr_etudiants_actu = 0;
    menu(etudiants, &nbr_etudiants_actu);
    return 0;
}
