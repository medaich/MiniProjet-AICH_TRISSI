

#ifndef GESTION_ETUDIANTS_AFFICHER_H
#define GESTION_ETUDIANTS_AFFICHER_H

#include "main-header.h"
extern void afficherHeader();
extern void afficherEtudiant(Etudiant etudiant );
extern void afficherNEtudiants(Etudiant etudiants[], int nbr_etudiants_actu);
extern void afficherEtudiantsAdmisSeulement(Etudiant etudiants[], int nbr_etudiants_actu);
extern void AfficherEtudiantsFiliere(Etudiant etudiants[], int nbr_etudiants_actu);
extern void AfficherEtudiantApogee(Etudiant etudiants[], int nbr_etudiants_actu);
#endif //GESTION_ETUDIANTS_AFFICHER_H
