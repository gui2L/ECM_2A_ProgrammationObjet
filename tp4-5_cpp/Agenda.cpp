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
    NoeudRDV* courant = premier;
    while (courant != nullptr) {
        NoeudRDV* suivant = courant->getSuivant();
        delete courant;
        courant = suivant;
    }
    premier = nullptr;
}

