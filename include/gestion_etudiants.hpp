#pragma once
#include <vector>
#include "etudiant.hpp"

void ajouter_etudiant(std::vector<etudiant*>& liste);
void lister_etudiants(const std::vector<etudiant*>& liste);
void supprimer_etudiant(std::vector<etudiant*>& liste);
void supprimer_tous_les_etudiants(std::vector<etudiant*>& liste);
void menu_principal(std::vector<etudiant*>& liste);
