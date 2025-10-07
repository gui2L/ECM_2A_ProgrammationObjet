#include <vector>
#include "ArrayOfInteger.h"

int ArrayOfInteger::compteur = 0;

ArrayOfInteger::ArrayOfInteger(int dim) : tab(dim, 0){compteur++;
}

ArrayOfInteger::ArrayOfInteger(std::vector<int> valeurs) : tab(valeurs){compteur++;

}

ArrayOfInteger::ArrayOfInteger(const ArrayOfInteger &t) : tab(t.tab){compteur++;

}

ArrayOfInteger::~ArrayOfInteger(){compteur--;}

