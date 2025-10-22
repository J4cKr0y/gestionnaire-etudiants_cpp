#include "../include/etudiant.hpp"
#include <cstring> 


void initialiser_etudiant(etudiant* e, int mat, int a, const char* n) {
    if (e != nullptr) {
        e->matricule = mat;
        e->age = a;
        std::strncpy(e->nom, n, 49);
        e->nom[49] = '\0';
    }
}

void afficher_etudiant(const etudiant* e) {
    if (e != nullptr) {
        std::cout << "Matricule: " << e->matricule 
                  << " | Age: " << e->age 
                  << " | Nom: " << e->nom << std::endl;
    }
}


etudiant* creer_etudiant(int mat, int a, const char* n) {
    etudiant* nouveau_e = new etudiant; 
    if (nouveau_e != nullptr) {
        initialiser_etudiant(nouveau_e, mat, a, n);
    }
    return nouveau_e;
}


void detruire_etudiant(etudiant* e) {
    if (e != nullptr) {
        delete e; 
    }
}
