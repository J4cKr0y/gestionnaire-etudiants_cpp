#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <iostream>

struct etudiant {
    int matricule;
    int age;
    char nom[50];
};


void initialiser_etudiant(etudiant* e, int mat, int a, const char* n);
void afficher_etudiant(const etudiant* e);
etudiant* creer_etudiant(int mat, int a, const char* n); 
void detruire_etudiant(etudiant* e); 

#endif // ETUDIANT_H
