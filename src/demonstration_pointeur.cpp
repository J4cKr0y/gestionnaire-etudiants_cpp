#include "../include/demonstration_pointeur.hpp"
#include <iostream>

void demonstration_pointeur_int() {
    std::cout << "\n--- Démonstration Pointeur sur INT ---" << std::endl;

    // Créer un simple pointeur sur int
    int ma_valeur = 50;
    int* pointeur_sur_int = &ma_valeur; 

    // Accéder à la valeur pointée (Déréférencement)
    std::cout << "Valeur initiale (via la DÉRÉFÉRENCE): " << *pointeur_sur_int << std::endl;

    // Attribuer une valeur à travers le pointeur
    *pointeur_sur_int = 150; 

    std::cout << "Nouvelle valeur de 'ma_valeur' (modifiée via pointeur): " << ma_valeur << std::endl;
    std::cout << "Adresse: " << pointeur_sur_int << std::endl;
}
