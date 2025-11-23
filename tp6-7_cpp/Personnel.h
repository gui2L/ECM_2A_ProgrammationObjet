#ifndef PERSONNEL_H
#define PERSONNEL_H

#include "Personne.h" 

class Personnel : public Personne{
private:
    float salaire;

public:
    Personnel(std::string nom, std::string prenom, float salaire = 0);
    
    ~Personnel();

    float calculSalaire() const;

    void affiche() const;

    float getSalaire() const;
    void setSalaire(float Salaire);
};

#endif