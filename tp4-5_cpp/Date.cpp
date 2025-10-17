#include "Date.h"
#include <iostream>



bool Date::checkDate(int j, int m, int a){
    return ((j >= 1 && j <= 31) && (m >= 1 && m <= 12) && (a >= 2000 && a <= 2050));
}

Date::Date(int j, int m, int a){
    if (checkDate(j, m, a)){
        jour = j; mois = m; annee = a;
    }else{
        jour = 1; mois = 1; annee = 2000;
    }
}

void Date::affiche(){
    std::cout<< jour << " / " << mois << " / " << annee << "\n"; 
}