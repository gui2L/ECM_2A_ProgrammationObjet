#include <vector>

#ifndef ARRAYOFINTEGER_H
#define ARRAYOFINTEGER_H


class ArrayOfInteger{
    private:
        std::vector<int> valeurs;
        static int compteur;
    public:
        ArrayOfInteger(int dim = 10);
        ArrayOfInteger(std::vector<int> valeurs);
        ArrayOfInteger(const ArrayOfInteger &t);
        ~ArrayOfInteger();

        static int getCompteur(){
            return compteur;
        }

        //int getDimension() const;
        void Afficher();
        int Contient(int INT);
        void Remove(int INT);
        void Add(int INT);
        bool Equal(const ArrayOfInteger &tt);

        

};

#endif