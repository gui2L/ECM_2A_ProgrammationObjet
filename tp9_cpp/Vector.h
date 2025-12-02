#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T> 
class Vector {
    private:
        int taille;
        T *data;

    public:
        Vector() : taille(0), data(nullptr) {
        }
   
        Vector(int taille) : taille(taille) {
                data = new T[taille];
        }
    
        ~Vector(){
                delete[] data;
        }

        void ajoute(T &valeur);
};

#endif