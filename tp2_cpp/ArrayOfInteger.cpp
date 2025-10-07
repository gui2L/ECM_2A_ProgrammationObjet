#include <vector>
#include <string>
#include <iostream>
#include "ArrayOfInteger.h"

int ArrayOfInteger::compteur = 0;

ArrayOfInteger::ArrayOfInteger(int dim) : tab(dim, 0){compteur++;
}

ArrayOfInteger::ArrayOfInteger(std::vector<int> valeurs) : tab(valeurs){compteur++;

}

ArrayOfInteger::ArrayOfInteger(const ArrayOfInteger &t) : tab(t.tab){compteur++;

}

ArrayOfInteger::~ArrayOfInteger(){compteur--;}


void ArrayOfInteger::Afficher(){
    std::cout << "[";
    for (int i = 0; i < tab.size(); i++) {
        std::cout << tab[i];
        if (i+1 < tab.size()) std::cout << ", ";
    }
    std::cout << "] \n";
}


int ArrayOfInteger::Contient(int INT){
    for (int i = 0; i < tab.size(); i++) {
        if (INT == tab[i]){return i;}
    }
    return -1;
}

void ArrayOfInteger::Remove(int INT){
    int position = ArrayOfInteger::Contient(INT);
    if(position == -1){
        std::cout<< "entier:" << INT << " introuvable dans tableau \n";
    }else{
        tab.erase(tab.begin() + position);
    }
}