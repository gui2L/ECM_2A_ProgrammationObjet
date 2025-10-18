#ifndef AGENDA_H
#define AGENDA_H

#include "NoeudRDV.h"
#include <iostream>

class Agenda {
private:
    NoeudRDV *premier; 

public:
    
    Agenda();                       
    Agenda(const Agenda &a);   
    ~Agenda();                  

    void ajoute(const RDV &r);    
    void enleve(const RDV &r);                  
    void affiche() const;      
};

#endif