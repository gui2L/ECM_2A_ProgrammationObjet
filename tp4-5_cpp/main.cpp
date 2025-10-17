#include "Date.h"
#include "Heure.h"

#include <iostream>


int main(){

    Date d1(0, 0, 0);
    Date d2(17, 10, 2025);
    Date d3 = d2;
    std::cout<<"date d1 : ";d1.affiche();
    std::cout<<"date d2 : ";d2.affiche();
    std::cout<<"date d3 : ";d3.affiche();

    std::cout<<"\n";

    Date d4(22, 11, 1963);
    std::cout<<"date d4 avant modif: ";d4.affiche();
    std::cout<<"jour de d4 : " << d4.getJour() << "\n";
    std::cout<<"mois de d4 : " << d4.getMois() << "\n";
    std::cout<<"annee de d4 : " << d4.getAnnee() << "\n";

    d4.setJour(8);
    d4.setMois(11);
    d4.setAnnee(1960);
    std::cout<<"date d4 apres modif: ";d4.affiche();
    std::cout<<"jour de d4 : " << d4.getJour() << "\n";
    std::cout<<"mois de d4 : " << d4.getMois() << "\n";
    std::cout<<"annee de d4 : " << d4.getAnnee() << "\n";

    std::cout<<"\n";

    Heure h1;
    Heure h2(1);
    Heure h3(23, 17);
    h1.affiche();
    h2.affiche();
    h3.affiche();



    return 0;
}