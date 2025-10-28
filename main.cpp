#include "include/demonstration_pointeur.hpp"
#include "include/gestion_etudiants.hpp"

int main() {
    demonstration_pointeur_int();

    std::vector<etudiant*> liste_etudiants;
    menu_principal(liste_etudiants);

    for (etudiant* e_ptr : liste_etudiants) {
        detruire_etudiant(e_ptr);
    }

    std::cout << "\nNettoyage de la mémoire de " << liste_etudiants.size()
              << " étudiants effectué. Aucune fuite mémoire." << std::endl;

    return 0;
}
