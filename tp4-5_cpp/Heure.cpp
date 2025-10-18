#include "Heure.h"
#include <iostream>

Heure::Heure(int h, int min):heures(h), minutes(min){
}

Heure::~Heure(){}

void Heure::affiche(){ 
    if (heures != 0){
        std::cout<< heures <<"h";
    }else{
        if (heures % 24 == 0){
            std::cout<< "00h";
        }else{
        }
        
    }

    if (minutes != 0){
        if (minutes<=9){
            std::cout<< "0" << minutes;
        }else{
            std::cout<< minutes;
        }
        
    } 
    std::cout<<"\n";
}

int Heure::getHeures(){return heures;}
int Heure::getMinutes(){return minutes;}

void Heure::setHeures(int h){heures=h;}
void Heure::setMinutes(int min){minutes=min;}

bool Heure::estEgale(Heure &h){
    return (heures == h.getHeures() && minutes == h.getMinutes());
}