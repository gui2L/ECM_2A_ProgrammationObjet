#include "ListePersonnel.h"
#include <iostream>

ListePersonnel::ListePersonnel() : nb(0) {
    for (int i = 0; i < 100; ++i) {
        tab[i] = nullptr;
    }
}

void ListePersonnel::ajoutPersonnel(Personnel *ptPersonnel) {
    if (nb < 100) { 
        tab[nb] = ptPersonnel;
        nb++;
    } else {
        std::cerr << "Erreur: Liste déjà pleine" << "\n";
    }
}

void ListePersonnel::afficherSalaires() const {
    std::cout << "\n__Affichage des salaires de la liste__" << "\n";
    for (int i = 0; i < nb; ++i) {
        float salaire = tab[i]->calculSalaire(); 
        
        std::cout << tab[i]->getNom() << " " << tab[i]->getPrenom() 
                  << " : " << salaire << " euros" << std::endl;
    }
}