#include "EnseignantVacataire.h"
#include <iostream>

EnseignantVacataire::EnseignantVacataire(std::string nom, std::string prenom, float salaire, std::string casier, float taux, int nbreHeures, std::string adresse, std::string telephone)
    : Personnel(nom, prenom, salaire, adresse, telephone), casier(casier), taux(taux), nbreHeures(nbreHeures)
{}

float EnseignantVacataire::calculSalaire() const{
    return taux * nbreHeures;
}

void EnseignantVacataire::affiche() const {
    Personnel::affiche();
    std::cout << "Casier: " << casier << "\n";
    std::cout << "Nombre Heures: " << nbreHeures << "h" << "\n";
    std::cout << "Taux Horaire: " << taux << " euros/h" << "\n";
}