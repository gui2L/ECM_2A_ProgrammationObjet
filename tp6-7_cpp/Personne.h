#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>

class Personne
{
private:
    std::string nom;
    std::string prenom;
    std::string adresse;
    std::string telephone;

public:
    Personne(std::string nom, std::string prenom, std::string adresse = "", std::string telephone = "");
    ~Personne();
    void affiche() const;

    std::string getNom() const;
    void setNom(std::string Nom);

    std::string getPrenom() const;
    void setPrenom(std::string Prenom);

    std::string getAdresse() const;
    void setAdresse(std::string Adresse);

    std::string getTelephone() const;
    void setTelephone(std::string Telephone);

    
};

#endif