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
    
    RDV r1, r2;
    r1.setLieu("Bureau");
    r2.setLieu("Maison");
    Agenda agenda;
    agenda.ajoute(r1);
    agenda.ajoute(r2);

    return 0;
}