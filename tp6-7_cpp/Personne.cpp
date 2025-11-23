#include "Personne.h"

Personne::Personne(std::string nom, std::string prenom, std::string adresse = "", std::string telephone = "") 
: nom(nom), prenom(prenom){}

Personne::~Personne()
{
}

void Personne::affiche() const{
    std::cout << "Nom : " << nom << "\n";
    std::cout << "Prenom : " << prenom << "\n";
    std::cout << "Adresse : " << adresse << "\n";
    std::cout << "Telephone : " << telephone << "\n";
}

std::string Personne::getNom() const{
    return nom;
}
void Personne::setNom(std::string Nom){
    nom = Nom;
}

std::string Personne::getPrenom() const{
    return prenom;
}
void Personne::setPrenom(std::string Prenom){
    prenom = Prenom;
}

std::string Personne::getAdresse() const{
    return adresse;
}
void Personne::setAdresse(std::string Adresse){
    adresse = Adresse;
}

std::string Personne::getTelephone() const{
    return telephone;
}
void Personne::setTelephone(std::string Telephone){
    telephone = Telephone;
}