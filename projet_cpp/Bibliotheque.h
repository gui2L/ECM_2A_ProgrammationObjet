#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H


#include <iostream>
#include <string>
using namespace std;
#include "Livre.h"
#include "Liste.h"
#include "Adherent.h"

class Bibliotheque {
private:
    string nom;
    string adresse;
    string code;
    Liste<Livre*> stock;    // Le stock de livres 
    Liste<Adherent*> inscrits;
    

public:
    Bibliotheque(string n, string a, string c);
    ~Bibliotheque();
    
    void acheterLivre(Livre* l); 
    void afficherStock() const; 
    void afficherParCategorie(string categorieDemandee) const; 
    void preterLivre(Adherent& adherent, string codeLivre); 
    void recupererLivre(Adherent& adherent, string codeLivre); 
    void supprimerLivre(string codeLivre, string motif);
    Livre* trouverLivre(string isbn);
    void demanderLivre(string isbn, Bibliotheque& autreBiblio);
    void rendreLivresPretes();
};

#endif