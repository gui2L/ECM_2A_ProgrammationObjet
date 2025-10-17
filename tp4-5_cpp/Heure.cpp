#include "Heure.h"
#include <iostream>

Heure::Heure(int h, int min):heures(h), minutes(min){
}

Heure::~Heure(){}

void Heure::affiche(){ //modifier si 0h ou 0min
    std::cout<< heures <<"h "<< minutes << "min" <<"\n";
}

int Heure::getHeures(){return heures;}
int Heure::getMinutes(){return minutes;}

void Heure::setHeures(int h){heures=h;}
void Heure::setMinutes(int min){minutes=min;}