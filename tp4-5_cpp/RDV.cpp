#include "RDV.h"
#include <iostream>
#include <sstream>


RDV::RDV() : d(), h(){
    participants = new std::string[10];
}

void RDV::affiche(){
    std::cout<< "rdv " << lieu << "\n"; 
    std::cout<< "le "; d.affiche();
    std::cout<< "a "; h.affiche();
    std::cout<< "avec " << nb_participants << " participants : ";
    for (int i = 0; i < nb_participants; i++) {
        std::cout << participants[i];
        if (i < nb_participants - 1) std::cout << ", ";
    }
    
}

RDV::~RDV(){
    delete[] participants;
}

void RDV::saisieParticipants(){
    for (int i = 0; i < nb_participants; i++){
        std::string p;
        std::cout<< "rentrez un participant :";
        std::cin>> p;
        participants[i] = p;
    }
         
}

void RDV::saisieLieu(){
    std::string l;
    std::cout<< "rentrez le lieu du rdv :";
    std::cin>> l;
    lieu = l;
}

void RDV::saisie(){

    saisieLieu();

    std::string date;
    int jour, mois, annee;
    char sep; 
    while (true){
        std::cout<< "rentrez la date du rdv sous format jj/mm/aa :";
        std::cin>> date;
        std::stringstream ss(date);
        ss >> jour >> sep >> mois >> sep >> annee;
        if (ss.fail()) {
            std::cout << "Format de date invalide, veuillez reessayer " << "\n";
        } else {
            Date d(jour, mois, annee);
            setDate(d);
            break;
        }
    }
    
    std::string heure;
    int heures, minutes;
    while (true){   
        std::cout<< "rentrez l'heure du rdv sous format XX:XX :";
        std::cin>> heure;
        std::stringstream ss(heure);
        ss >> heures >> sep >> minutes;
        if (ss.fail()) {
            std::cout << "Format de l'heure invalide, veuillez reessayer " << "\n";
        } else {
            Heure h(heures, minutes);
            setHeure(h);
            break;
        }
    }

    int nb_p;
    std::cout<< "rentrez le nombre de participants :";
    std::cin>> nb_p;
    setNb_participants(nb_p);

    saisieParticipants();
    

}