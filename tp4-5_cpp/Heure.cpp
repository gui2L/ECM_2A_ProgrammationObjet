#include "Heure.h"
#include <iostream>

Heure::Heure(int h, int min):heures(h), minutes(min){
}

Heure::~Heure(){}

void Heure::affiche(){ 
    if (heures != 0){
        std::cout<< heures <<"h ";
    }else{
        if (heures % 24 == 0){
            std::cout<< "00h ";
        }else{

        }
        
    }

    if (minutes != 0){
        std::cout<< minutes << "min";
    } 
    std::cout<<"\n";
}

int Heure::getHeures(){return heures;}
int Heure::getMinutes(){return minutes;}

void Heure::setHeures(int h){heures=h;}
void Heure::setMinutes(int min){minutes=min;}