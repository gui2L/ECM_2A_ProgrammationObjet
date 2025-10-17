#include "Heure.h"
#include <iostream>

Heure::Heure(int h, int min):heures(h), minutes(min){
}

Heure::~Heure(){}

void Heure::affiche(){
    std::cout<< heures <<"h "<< minutes << "min" <<"\n";
}