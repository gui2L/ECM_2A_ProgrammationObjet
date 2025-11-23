#include "Personne.h"
#include "Eleve.h"

#include <iostream>

int main(){
    Personne p1("", "");
    p1.affiche();
    p1.setNom("Baker");
    p1.setPrenom("Colson");
    p1.setAdresse("Earth");
    p1.setTelephone("0024");
    p1.affiche();

    Personne p2("Santa", "Claus", "Antartica", "0025122025");
    std::cout << p2.getNom() << "\n" << p2.getPrenom() << "\n" << p2.getAdresse() << "\n" << p2.getTelephone() << "\n";

    Eleve e1("Daft", "Punk");
    e1.affiche();


    return 0;
}