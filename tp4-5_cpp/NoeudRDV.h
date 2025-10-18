#include "RDV.h"


#ifndef NOEUDRDV_H
#define NOEUDRDV_H

class NoeudRDV{
    private:

        RDV rdv;
        NoeudRDV *suivant;
    public:
        NoeudRDV(const RDV &r);
        NoeudRDV(const RDV &r, NoeudRDV *s);

        RDV getRDV() const;                
        NoeudRDV *getSuivant() const;

        void setRDV(const RDV &r);
        void setSuivant(NoeudRDV *s);
};

#endif