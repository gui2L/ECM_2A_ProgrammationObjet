#include <vector>
#include <string>
#include <iostream>
#include "ArrayOfInteger.h"

int ArrayOfInteger::compteur = 0;

ArrayOfInteger::ArrayOfInteger(int dim) : valeurs(dim, 0){compteur++;
}

ArrayOfInteger::ArrayOfInteger(std::vector<int> valeurs) : valeurs(valeurs){compteur++;

}

ArrayOfInteger::ArrayOfInteger(const ArrayOfInteger &t) : valeurs(t.valeurs){compteur++;

}

ArrayOfInteger::~ArrayOfInteger(){compteur--;}


void ArrayOfInteger::Afficher(){
    std::cout << "[";
    for (int i = 0; i < valeurs.size(); i++) {
        std::cout << valeurs[i];
        if (i+1 < valeurs.size()) std::cout << ", ";
    }
    std::cout << "] \n";
}


int ArrayOfInteger::Contient(int INT){
    for (int i = 0; i < valeurs.size(); i++) {
        if (INT == valeurs[i]){return i;}
    }
    return -1;
}

void ArrayOfInteger::Remove(int INT){
    int position = Contient(INT);
    if(position == -1){
        std::cout<< "entier:" << INT << " introuvable dans tableau :"; Afficher();
    }else{
        valeurs.erase(valeurs.begin() + position);
        std::cout<< "entier:" << INT << " supprimer du tableau -->"; Afficher();
    }
}

void ArrayOfInteger::Add(int INT){
    if(Contient(INT) != -1){
        std::cout<< "entier:" << INT << " deja dans tableau :"; Afficher();
    }else{
        valeurs.push_back(INT);
        std::cout<< "entier:" << INT << " ajoute au tableau -->"; Afficher();
    }
    
}

bool Equal(std::vector<int> &tt){}