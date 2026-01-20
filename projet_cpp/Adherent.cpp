#include <iostream>
#include <string>
using namespace std;
#include "Adherent.h"


int Adherent::compteurId = 0;

Adherent::Adherent(string n, string p, string adr, Bibliotheque* bib)
    : nom(n), prenom(p), adresse(adr), bibliotheque(bib), maxEmprunts(3) {
    numeroAdherent = ++compteurId; // ID auto-incrémenté
}

Adherent::~Adherent() {}

string Adherent::getNom() const { return nom; }
int Adherent::getId() const { return numeroAdherent; }


bool Adherent::peutEmprunter() const {
    return emprunts.taille() < maxEmprunts;
}

void Adherent::ajouterEmprunt(Livre* l) {
    if (!peutEmprunter()) throw Erreur("Quota de livres atteint");
    emprunts.ajouter(l); 
}

void Adherent::rendreLivre(Livre* l) {
    emprunts.supprimer(l); 
}

bool Adherent::aEmprunte(string codeLivre){
    Element<Livre*>* courant = emprunts.getTete();
    while (courant != nullptr) {
        if (courant->donnee->getCode() == codeLivre) {
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}

void Adherent::afficher() const {
    cout << "Adherent " << nom << " (" << emprunts.taille() << " emprunts)" << endl;
}