#ifndef ENSEIGNANTPERMANENT_H
#define ENSEIGNANTPERMANENT_H

#include "Personnel.h"

class EnseignantPermanent : public Personnel{
private:
    std::string bureau;
    int grade;
    float primeMensuelle;

public:
    EnseignantPermanent(std::string nom, std::string prenom, float salaire, int grade, float prime, std::string adresse="", std::string telephone="", std::string bureau = "");

    float calculSalaire() const override; 
    void affiche() const;

    
    std::string getBureau() const { return bureau; }
};

#endif