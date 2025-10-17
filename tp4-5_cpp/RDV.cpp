#include "RDV.h"
#include <iostream>


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