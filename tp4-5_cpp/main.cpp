#include "Date.h"
#include "Heure.h"
#include "RDV.h"
#include "NoeudRDV.h"
#include "test_fonctions.h"
#include "Agenda.h"

#include <iostream>
#include <cassert> 




int main(){

    //test_Date();

    //test_Heure();

    //test_RDV_saisie();

    //test_RDV_estCompatibleAvec();

    /*RDV r1, r2;
    NoeudRDV n1(r1);      
    NoeudRDV n2(r2, &n1);    
    n1.setSuivant(&n2);

    assert(n2.getSuivant() == &n1);
    assert(n1.getSuivant() == &n2);*/
    
    RDV r1, r2, r3;
    r1.setLieu("Bureau"); r1.setDate(Date(10, 10, 2025));
    r1.setHeure(Heure(9, 30));

    r2.setLieu("Maison");r2.setDate(Date(9, 10, 2025));
    r2.setHeure(Heure(11, 0));

    r3.setLieu("Coiffeur");r3.setDate(Date(10, 10, 2025));
    r3.setHeure(Heure(8, 0));

    Agenda a;
    a.ajoute(r1);
    a.ajoute(r2);
    a.ajoute(r3);

    std::cout << "Agenda ordonne\n";
    a.affiche();

    std::cout << "Suppression d'un RDV\n";
    a.enleve(r2);
    a.affiche();

    

    return 0;
}