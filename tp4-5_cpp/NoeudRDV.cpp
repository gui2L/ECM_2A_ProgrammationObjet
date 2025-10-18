#include "NoeudRDV.h"
#include "RDV.h"

NoeudRDV::NoeudRDV(const RDV &r) : rdv(r), suivant(nullptr) {
}

NoeudRDV::NoeudRDV(const RDV &r, NoeudRDV *s) : rdv(r), suivant(s) {
}

RDV NoeudRDV::getRDV() const { return rdv; }               
NoeudRDV *NoeudRDV::getSuivant() const { return suivant; }   


void NoeudRDV::setRDV(const RDV &r) { rdv = r; }
void NoeudRDV::setSuivant(NoeudRDV *s) { suivant = s; }