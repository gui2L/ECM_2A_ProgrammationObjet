#ifndef LISTE_H
#define LISTE_H

#include <iostream>
using namespace std;

template <typename T>
struct Element {
    T donnee;
    Element* suivant;

    Element(T d) : donnee(d), suivant(nullptr) {}
};

// Classe Template Liste pour représenter le stock d'une bibliotheque et la liste des adherents 
template <typename T>
class Liste {
private:
    Element<T>* tete;

public:
    Liste() : tete(nullptr) {}

    // pour nettoyer la mémoire 
    ~Liste() {
        while (tete != nullptr) {
            Element<T>* aSupprimer = tete;
            tete = tete->suivant;
            delete aSupprimer;
        }
    }

    void ajouter(T val) {
        Element<T>* nouv = new Element<T>(val);
        nouv->suivant = tete;
        tete = nouv;
    }

    // Pour supprimer un élément spécifique
    void supprimer(T val) {
        if (!tete) return;

        // cas particulier : tête supprimée
        if (tete->donnee == val) {
            Element<T>* aSupprimer = tete;
            tete = tete->suivant;
            delete aSupprimer;
            return;
        }

        Element<T>* actuel = tete;
        while (actuel->suivant != nullptr && actuel->suivant->donnee != val) {
            actuel = actuel->suivant;
        }

        // si trouvé on supprime
        if (actuel->suivant != nullptr) {
            Element<T>* aSupprimer = actuel->suivant;
            actuel->suivant = aSupprimer->suivant;
            delete aSupprimer;
        }
    }

    Element<T>* getTete() const {
        return tete;
    }
    
    bool estVide() const { return tete == nullptr; }
    
    // utile pour le quota de livres à respecter
    int taille() const {
        int c = 0;
        Element<T>* temp = tete;
        while(temp) { c++; temp = temp->suivant; }
        return c;
    }
};

#endif