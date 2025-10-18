#include "Agenda.h"

Agenda::Agenda() : premier(nullptr) {}


Agenda::Agenda(const Agenda &a) : premier(nullptr) {
    if (a.premier == nullptr) return;

    premier = new NoeudRDV(a.premier->getRDV());
    NoeudRDV *courant = premier;
    NoeudRDV *autre = a.premier->getSuivant();

    while (autre != nullptr) {
        courant->setSuivant(new NoeudRDV(autre->getRDV()));
        courant = courant->getSuivant();
        autre = autre->getSuivant();
    }
}

Agenda::~Agenda() {
    NoeudRDV*courant = premier;
    while (courant != nullptr) {
        NoeudRDV* suivant = courant->getSuivant();
        delete courant;
        courant = suivant;
    }
    premier = nullptr;
}

void Agenda::ajoute(const RDV &r) {
    NoeudRDV *nouveau = new NoeudRDV(r);

    if (premier == nullptr) {
        premier = nouveau; // premier élément
    } else {
        NoeudRDV *courant = premier;
        while (courant->getSuivant() != nullptr) {
            courant = courant->getSuivant();
        }
        courant->setSuivant(nouveau);
    }
}

void Agenda::affiche() const {
    if (premier == nullptr) {
        std::cout << "Agenda vide.\n";
    }

    NoeudRDV *courant = premier;
    int i = 1;
    while (courant != nullptr) {
        std::cout << "RDV #" << i << " :\n";
        courant->getRDV().affiche();
        courant = courant->getSuivant();
        i++;
    }
}

void Agenda::enleve() {
    if (premier == nullptr) {
        std::cout << "Agenda vide, rien a enlever.\n";
        return;
    }

    NoeudRDV *temp = premier;
    premier = premier->getSuivant();
    delete temp;
}

