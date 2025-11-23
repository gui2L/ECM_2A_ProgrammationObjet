#include "Eleve.h"

Eleve::Eleve(std::string nom, std::string prenom, std::string promotion, std::string groupeTD, float GPA) 
: Personne(nom, prenom), promotion(promotion), groupeTD(groupeTD), GPA(GPA){}


Eleve::~Eleve(){}

void Eleve::affiche() const{
    Personne::affiche();
    std::cout << "Promotion : " << promotion << "\n";
    std::cout << "Groupe de TD : " << groupeTD << "\n";
    std::cout << "GPA : " << GPA << "\n";
    std::cout << "\n";
}

std::string Eleve::getPromotion() const{
    return promotion;
}
void Eleve::setPromotion(std::string Promotion){
    promotion = Promotion;
}

std::string Eleve::getGroupeTD() const{
    return groupeTD;
}
void Eleve::setGroupeTD(std::string GroupeTD){
    groupeTD = GroupeTD;
}

float Eleve::getGPA() const{
    return GPA;
}
void Eleve::setGPA(float GPA){
    Eleve::GPA = GPA;
}