#include "../include/demonstration_pointeur.hpp" 
#include "../include/etudiant.hpp"
#include <vector>
#include <limits>

using namespace std;


void nettoyer_buffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void ajouter_etudiant(vector<etudiant*>& liste) {
    int mat, age;
    string nom_temp;

    cout << "\n--- AJOUTER UN ÉTUDIANT ---" << endl;
    
    cout << "Entrez le Matricule (entier): ";
    if (!(cin >> mat)) { nettoyer_buffer(); cout << "Erreur de saisie. Annulation." << endl; return; }

    cout << "Entrez l'Age (entier): ";
    if (!(cin >> age)) { nettoyer_buffer(); cout << "Erreur de saisie. Annulation." << endl; return; }
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Entrez le Nom (max 49 caracteres): ";
    getline(cin, nom_temp);
    
    etudiant* nouvel_etudiant = creer_etudiant(mat, age, nom_temp.c_str());

    if (nouvel_etudiant) {
        liste.push_back(nouvel_etudiant);
        cout << "Étudiant ajouté avec succès!" << endl;
    } else {
        cout << "❌ Erreur: Allocation mémoire échouée." << endl;
    }
}


void lister_etudiants(const vector<etudiant*>& liste) {
    cout << "\n--- LISTE DES ÉTUDIANTS (" << liste.size() << ") ---" << endl;
    if (liste.empty()) {
        cout << "La liste est vide." << endl;
        return;
    }

    for (const etudiant* e_ptr : liste) {
        // Utilisation de la fonction d'affichage de la librairie
        afficher_etudiant(e_ptr);
    }
}


void supprimer_etudiant(vector<etudiant*>& liste) {
    if (liste.empty()) {
        cout << "\nLa liste est vide. Rien à supprimer." << endl;
        return;
    }

    int mat_a_supprimer;
    cout << "\n--- SUPPRIMER UN ÉTUDIANT ---" << endl;
    cout << "Entrez le Matricule de l'étudiant à supprimer : ";
    if (!(cin >> mat_a_supprimer)) {
        nettoyer_buffer();
        cout << "Erreur de saisie. Annulation." << endl;
        return;
    }

    for (auto it = liste.begin(); it != liste.end(); ++it) {
        if ((*it)->matricule == mat_a_supprimer) {
            
            // 1. Libérer la mémoire sur le tas (le 'detruire_etudiant' de la librairie)
            detruire_etudiant(*it); 

            // 2. Retirer le pointeur du conteneur vectoriel
            liste.erase(it);

            cout << "Étudiant avec matricule " << mat_a_supprimer << " supprimé et mémoire libérée." << endl;
            return;
        }
    }

    cout << "❌ Erreur: Étudiant avec matricule " << mat_a_supprimer << " non trouvé." << endl;
}


void supprimer_tous_les_etudiants(vector<etudiant*>& liste) {
    if (liste.empty()) {
        cout << "\nLa liste est déjà vide. Rien à supprimer." << endl;
        return;
    }

    size_t count = liste.size();
    
    for (etudiant* e_ptr : liste) {
        detruire_etudiant(e_ptr); // Utilise 'delete' sur l'objet pointé
    }

    liste.clear();

    cout << "OK. " << count << " étudiants supprimés et toute la mémoire a été libérée." << endl;
}

void menu_principal(vector<etudiant*>& liste) {
    int choix;
    do {
        cout << "\n===== GESTIONNAIRE D'ÉTUDIANTS =====" << endl;
        cout << "1. Ajouter un étudiant" << endl;
        cout << "2. Lister tous les étudiants" << endl;
        cout << "3. Supprimer un étudiant (avec son matricule)" << endl;
        cout << "4. Supprimer TOUS les étudiants : EXTERMINATE !" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix: ";
        
        if (!(cin >> choix)) {
            nettoyer_buffer();
            choix = -1; // Force une boucle ou un message d'erreur
            cout << "Saisie invalide. Veuillez réessayer." << endl;
            continue;
        }

        switch (choix) {
            case 1:
                ajouter_etudiant(liste);
                break;
            case 2:
                lister_etudiants(liste);
                break;
            case 3:
                supprimer_etudiant(liste);
                break;
            case 4:
                supprimer_tous_les_etudiants(liste);
                break;
            case 0:
                cout << "Au revoir!" << endl;
                break;
            default:
                cout << "Choix non reconnu. Veuillez choisir 1, 2 ou 0." << endl;
                break;
        }
    } while (choix != 0);
}


int main() {
    demonstration_pointeur_int(); 

    vector<etudiant*> liste_etudiants;

    menu_principal(liste_etudiants);

    for (etudiant* e_ptr : liste_etudiants) {
        detruire_etudiant(e_ptr); 
    }

    cout << "\nNettoyage de la mémoire de " << liste_etudiants.size() 
         << " étudiants effectué. Aucune fuite mémoire." << endl;

    return 0;
}





