

#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

// variables globales
#define MAX_MODULES 10
#define MAX_STRINGS 15
#define MAX_ETUDIANTS 100
// variable pour compter numero d'etudiant

//déclaration des types
typedef struct Etudiant Etudiant;
typedef enum Filiere Filiere ;
typedef struct Module Module;
typedef struct Date Date;

//définition des types

enum Filiere {
    SMI,
    SMA,
    SMP
};
struct Module {
    char nom_module[15];
    float note;
};

struct Date {
    int jour;
    int mois;
    int annee;
};
struct Etudiant {
    int num_apo;
    char nom[MAX_STRINGS];
    char prenom[MAX_STRINGS];
    Date date_naissanse;
    Filiere filiere;
    Module modules[MAX_MODULES];
    int nbr_modules;
    float moyenne;
    Date date_inscription;
};



#endif //MAIN_HEADER_H