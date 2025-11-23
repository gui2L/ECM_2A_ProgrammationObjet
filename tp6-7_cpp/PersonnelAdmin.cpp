#include "PersonnelAdmin.h" 

PersonnelAdmin::PersonnelAdmin(std::string nom, std::string prenom, float taux, std::string adresse, std::string telephone, float salaire, int heuresSup)
: Personnel(nom, prenom, adresse, telephone, salaire), taux(taux), heuresSup(heuresSup)
{}

float PersonnelAdmin::calculSalaire() const {
    return salaire + (taux * heuresSup); 
}

void PersonnelAdmin::affiche() const {
    Personnel::affiche();
    std::cout << "Heures Sup.: " << heuresSup << "h \n";
    std::cout << "Taux Horaire Sup.: " << taux << " euros/h \n";
}

int PersonnelAdmin::getHeuresSup() const {
    return heuresSup;
}
void PersonnelAdmin::setHeuresSup(int HeuresSup) {
    heuresSup = HeuresSup;
}

float PersonnelAdmin::getTaux() const {
    return taux;
}
void PersonnelAdmin::setTaux(float Taux) {
    taux = Taux;
}