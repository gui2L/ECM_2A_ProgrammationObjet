#include "Date.h"
#include "Heure.h"
#include "RDV.h"

#include <iostream>
#include <cassert> //for better testing




int main(){

    //tests class Date
    Date d1(0, 0, 0);
    Date d2(17, 10, 2025);
    Date d3 = d2;
    std::cout<<"date d1 : ";d1.affiche();
    std::cout<<"date d2 : ";d2.affiche();
    std::cout<<"date d3 : ";d3.affiche();

    std::cout<<"\n";

    Date d4(22, 11, 1963);
    //std::cout<<"date d4 avant modif: ";d4.affiche();
    /*std::cout<<"jour de d4 : " << d4.getJour() << "\n";*/ assert(d4.getJour() == 1);
    /*std::cout<<"mois de d4 : " << d4.getMois() << "\n";*/ assert(d4.getMois() == 1);
    /*std::cout<<"annee de d4 : " << d4.getAnnee() << "\n";*/ assert(d4.getAnnee() == 2000);
    

    d4.setJour(8);
    d4.setMois(11);
    d4.setAnnee(2002);
    //std::cout<<"date d4 apres modif: ";d4.affiche();
    /*std::cout<<"jour de d4 : " << d4.getJour() << "\n";*/ assert(d4.getJour() == 8);
    /*std::cout<<"mois de d4 : " << d4.getMois() << "\n";*/ assert(d4.getMois() == 11);
    /*std::cout<<"annee de d4 : " << d4.getAnnee() << "\n";*/ assert(d4.getAnnee() == 2002);

    std::cout<<"\n";

    //tests class Heure
    Heure h1;
    Heure h2(1);
    Heure h3(23, 17);
    std::cout<<"heure h1 : "; h1.affiche();
    std::cout<<"heure h2 : "; h2.affiche();
    std::cout<<"heure h3 : "; h3.affiche();

    //std::cout<<"\n";

    Heure h4(12, 15);
    //std::cout<<"heure h4 avant modif: "; h4.affiche();
    /*std::cout<<"heures de h4 : " << h4.getHeures() << "\n";*/ assert(h4.getHeures() == 12);
    /*std::cout<<"minutes de h4 : " << h4.getMinutes() << "\n";*/ assert(h4.getMinutes() == 15);

    h4.setHeures(14);
    h4.setMinutes(0);
    //std::cout<<"heure h4 apres modif: "; h4.affiche();
    /*std::cout<<"heures de h4 : " << h4.getHeures() << "\n";*/ assert(h4.getHeures() == 14);
    /*std::cout<<"minutes de h4 : " << h4.getMinutes() << "\n";*/ assert(h4.getMinutes() == 0);
    
    std::cout<<"\n";

    //tests class RDV
    RDV r1;
    r1.affiche();
    //r1.saisieLieu();
    //r1.saisie();
    //r1.affiche();


    Date d_rdv1(10, 10, 2010); Date d_rdv2(7, 12, 2010);
    Heure h_rdv1(9, 30); Heure h_rdv2(11, 0);
    RDV r2; 
    RDV r3; 

    // test1 : r2 compatible avec r3 ? 
    std::cout<< "--------- cas rdvs meme date, meme heure --------- \n";
    r2.setDate(d_rdv1); r2.setHeure(h_rdv1);
    r3.setDate(d_rdv1); r3.setHeure(h_rdv1);

    r2.affiche();
    r3.affiche();

    if (r2.estCompatibleAvec(r3)){
        std::cout << "rdvs compatibles \n";
    }else{
        std::cout << "rdvs non compatibles \n";
    }

    std::cout<<"\n";

    // test2 : r2 compatible avec r3 ? 
    std::cout << "--------- cas rdvs meme date, heure differente --------- \n";
    r3.setHeure(h_rdv2);

    r2.affiche();
    r3.affiche();

    if (r2.estCompatibleAvec(r3)){
        std::cout << "rdvs compatibles \n";
    }else{
        std::cout << "rdvs non compatibles \n";
    }

    // test3 : r2 compatible avec r3 ? 
    std::cout<< "--------- cas rdvs date et heure differentes --------- \n";
    r3.setDate(d_rdv2); r3.setHeure(h_rdv2);

    r2.affiche();
    r3.affiche();

    if (r2.estCompatibleAvec(r3)){
        std::cout << "rdvs compatibles \n";
    }else{
        std::cout << "rdvs non compatibles \n";
    }
    return 0;
}