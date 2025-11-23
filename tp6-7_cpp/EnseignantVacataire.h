#ifndef ENSEIGNANTVACATAIRE_H
#define ENSEIGNANTVACATAIRE_H

#include "Personnel.h"

class EnseignantVacataire : public Personnel
{
private:
    std::string casier;
    int nbreHeures;
    float taux;

public:
    EnseignantVacataire(std::string nom, std::string prenom, float salaire, std::string casier, float taux, int nbreHeures = 0, std::string adresse="", std::string telephone="");

    float calculSalaire() const; 
    void affiche() const;

    std::string getCasier() const { return casier; }
};

#endif