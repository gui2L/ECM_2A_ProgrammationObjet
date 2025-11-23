#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "Personne.h" 

class Personnel : public Personne{
protected:
    float salaire;

public:
    Personnel(std::string nom, std::string prenom, float salaire, std::string adresse = "", std::string telephone = "");
    
    ~Personnel();

    float calculSalaire() const;

    void affiche() const;

    float getSalaire() const;
    void setSalaire(float Salaire);
};

#endif