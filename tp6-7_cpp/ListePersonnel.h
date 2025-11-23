#ifndef LISTEPERSONNEL_H
#define LISTEPERSONNEL_H

#include "Personnel.h"

class ListePersonnel{
private:
    Personnel* tab[100]; 
    int nb;  // nombre d'employés ajoutés à la liste (entre 0 et 100) 

public:
    ListePersonnel();
    void ajoutPersonnel(Personnel *ptPersonnel); 
    void afficherSalaires() const; 
};

#endif