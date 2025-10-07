#include <vector>

#ifndef ARRAYOFINTEGER_H
#define ARRAYOFINTEGER_H


class ArrayOfInteger{
    private:
        std::vector<int> tab;
        static int compteur;
    public:
        ArrayOfInteger(int dim = 10);
        ArrayOfInteger(std::vector<int> valeurs);
        ArrayOfInteger(const ArrayOfInteger &t);
        ~ArrayOfInteger();

        static int getCompteur(){
            return compteur;
        }

        void Afficher();
        int Contient(int INT);
        void Remove(int INT);

        

};

#endif