#ifndef ELEVE_H
#define ELEVE_H

#include "Personne.h"

class Eleve : public Personne{
    private:
        std::string promotion;
        std::string groupeTD;
        float GPA;
    public:
        Eleve(std::string nom, std::string prenom, std::string promotion = "", std::string groupeTD = "", float GPA = -1);
        ~Eleve();
        void affiche() const;

        std::string getPromotion() const;
        void setPromotion(std::string Promotion);

        std::string getGroupeTD() const;
        void setGroupeTD(std::string GroupeTD);

        float getGPA() const;
        void setGPA(float GPA);


};



#endif