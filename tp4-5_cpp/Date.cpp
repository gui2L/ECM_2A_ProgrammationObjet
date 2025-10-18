#include "Date.h"
#include <iostream>




Date::Date(int j, int m, int a){
    if (checkDate(j, m, a)){
        jour = j; mois = m; annee = a;
    }else{
        jour = 1; mois = 1; annee = 2000;
    }
}

Date::Date(Date &d):jour(d.jour), mois(d.mois), annee(d.annee){
}

Date::~Date(){

}

void Date::affiche(){
    
    std::cout<< jour << "/"; 
    if (mois <=9){
        std::cout<< "0" << mois << "/"; 
    }else{
        std::cout<< mois << "/"; 
    }
    
    std::cout<< annee << "\n"; 
}

int Date::getJour(){
    return jour;
}
int Date::getMois(){
    return mois;
}
int Date::getAnnee(){
    return annee;
}

void Date::setJour(int j){
    jour = j;
}
void Date::setMois(int m){
    mois = m;
}
void Date::setAnnee(int a){
    annee = a;
}

bool Date::estEgale(Date &d){
    return (jour == d.getJour() && mois == d.getMois() && annee == d.getAnnee());
}