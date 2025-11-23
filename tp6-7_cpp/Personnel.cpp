#include "Personnel.h"


Personnel::Personnel(std::string nom, std::string prenom, std::string adresse, std::string telephone, float salaire)
: Personne(nom, prenom, adresse, telephone), salaire(salaire){}

Personnel::~Personnel() {}

float Personnel::calculSalaire() const {
    return salaire;
}

void Personnel::affiche() const {
    Personne::affiche();
    std::cout << "salaire : " << salaire << " euros" << "\n";
}

float Personnel::getSalaire() const {
    return salaire;
}
void Personnel::setSalaire(float Salaire) {
    salaire = Salaire;
}