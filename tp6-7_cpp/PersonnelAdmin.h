#ifndef PERSONNELADMIN_H
#define PERSONNELADMIN_H

#include "Personnel.h" 

class PersonnelAdmin : public Personnel{
private:
    int heuresSup;
    float taux;

public:
    PersonnelAdmin(std::string nom, std::string prenom, float taux, float salaire, int heuresSup = 0, std::string adresse = "", std::string telephone = "");

    float calculSalaire() const override; 

    void affiche() const;

    int getHeuresSup() const;
    void setHeuresSup(int HeuresSup);

    float getTaux() const;
    void setTaux(float Taux);
};

#endif