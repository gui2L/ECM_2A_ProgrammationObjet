#ifndef PERSONNELADMIN_H
#define PERSONNELADMIN_H

#include "Personnel.h" 

class PersonnelAdmin : public Personnel{
private:
    int heuresSup;
    float taux;

public:
    PersonnelAdmin(std::string nom, std::string prenom, float taux, std::string adresse = "", std::string telephone = "", float salaire = 0, int heuresSup = 0);

    float calculSalaire() const; 

    void affiche() const;

    int getHeuresSup() const;
    void setHeuresSup(int HeuresSup);

    float getTaux() const;
    void setTaux(float Taux);
};

#endif