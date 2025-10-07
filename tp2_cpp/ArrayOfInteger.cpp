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
