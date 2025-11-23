#include "EnseignantPermanent.h"
#include <iostream>

EnseignantPermanent::EnseignantPermanent(std::string nom, std::string prenom, float salaire, int grade, float prime, std::string adresse, std::string telephone, std::string bureau)
: Personnel(nom, prenom, salaire, adresse, telephone), bureau(bureau), grade(grade), primeMensuelle(prime)
{}

float EnseignantPermanent::calculSalaire() const {
    return salaire + (grade * primeMensuelle / 100); 
}

void EnseignantPermanent::affiche() const {
    Personnel::affiche();
    std::cout << "Bureau: " << bureau << "\n";
    std::cout << "Grade: " << grade << "\n";
    std::cout << "Prime Mensuelle: " << primeMensuelle << " euros \n";
}