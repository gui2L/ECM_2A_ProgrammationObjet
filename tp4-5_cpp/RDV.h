#include "Date.h"
#include "Heure.h"
#include <iostream>
#include <vector>


#ifndef RDV_H
#define RDV_H

class RDV {
    private:
        Date d;
        Heure h;
        std::string lieu;
        int nb_participants;
        std::string *participants;

    public:
        RDV(int nb_particpants = 0, std::string *ps = new std::string[10]);
        void affiche();
        void saisieParticipants();
        void saisieLieu(); 
        void saisie(); 
        void setDate(const Date& dateRdv);  
        void setHeure(const Heure& heureRdv);  
        void setLieu(const std::string& lieuRdv);  
        void setNb_participants(int nb_participants); 
        void setParticipants(std::string* ps);  
        void setParticipant(int i, std::string s);
};

#endif
