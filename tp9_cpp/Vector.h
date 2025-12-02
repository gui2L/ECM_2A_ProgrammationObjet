#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T> 
class Vector {
    private:
        int taille;
        T *data;
        int capacite;

    public:
        Vector() : taille(0), capacite(5) {
            data = new T[capacite];
        }
   
        Vector(int taille) : taille(taille), capacite(taille*2) {
                data = new T[taille];
        }
    
        ~Vector(){
            if (data != nullptr){delete[] data;}
            data = nullptr;
        }

        void reallouer(int new_capacite) {
            if (new_capacite <= capacite) return;
            T* new_data = new T[new_capacite];
    
            for (size_t i = 0; i < taille; ++i) {
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            capacite = new_capacite;
        }

        void ajoute(T valeur){
            if (taille >= capacite) {  
                reallouer(capacite*2);
            }
            data[taille] = valeur;
            taille++;
        }

        const int getTaille(){
            return taille;
        }

        const T& getdata_i(int i){
            return data[i];
        }
        
};

#endif