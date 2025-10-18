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

    if (premier == nullptr || premier->getRDV().estSuperieurA(r)) {
        nouveau->setSuivant(premier);
        premier = nouveau;
        return;
    }

    NoeudRDV *courant = premier;
    while (courant->getSuivant() != nullptr &&
           courant->getSuivant()->getRDV().estSuperieurA(r) == false) {
        courant = courant->getSuivant();
    }

    nouveau->setSuivant(courant->getSuivant());
    courant->setSuivant(nouveau);
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

void Agenda::enleve(const RDV &r) {
    if (premier == nullptr) return;

    if (premier->getRDV().estEgale(r)) {
        NoeudRDV *temp = premier;
        premier = premier->getSuivant();
        delete temp;
        return;
    }

    NoeudRDV *courant = premier;
    while (courant->getSuivant() != nullptr &&
           !courant->getSuivant()->getRDV().estEgale(r)) {
        courant = courant->getSuivant();
    }

    if (courant->getSuivant() != nullptr) {
        NoeudRDV *temp = courant->getSuivant();
        courant->setSuivant(temp->getSuivant());
        delete temp;
    }
}

void Agenda::vider() {
    NoeudRDV *courant = premier;
    while (courant != nullptr) {
        NoeudRDV *suivant = courant->getSuivant();
        delete courant;
        courant = suivant;
    }
    premier = nullptr;
}

