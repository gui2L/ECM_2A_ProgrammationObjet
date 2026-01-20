#ifndef ADHERENT_H
#define ADHERENT_H

#include <iostream>
#include <string>
using namespace std;
#include "Livre.h"
#include "Liste.h"

class Bibliotheque;

class Adherent {
private:
    string nom;
    string prenom;
    string adresse;
    int numeroAdherent;
    Bibliotheque* bibliotheque; // Pointeur vers sa bibliothèque 
    Liste<Livre*> emprunts;      // Liste chaînée des livres 
    int maxEmprunts;
    static int compteurId;

public:
    Adherent(string n, string p, string adr, Bibliotheque* bib);
    ~Adherent();
    string getNom() const;
    int getId() const;

    bool peutEmprunter() const;
    void ajouterEmprunt(Livre* l);
    void rendreLivre(Livre* l);
    bool aEmprunte(string codeLivre) const; //verifie si le livre ayant pour code codeLivre est un livre emprunte
    void afficher() const;
};

#endif