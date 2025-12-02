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
   
        Vector(int taille) : taille(0), capacite(taille) {
                data = new T[capacite];
        }
    
        ~Vector(){
            if (data != nullptr){delete[] data;}
            data = nullptr;
        }

        void reallouer(int new_capacite) {
            if (new_capacite <= capacite) return;
            T* new_data = new T[new_capacite];
    
            for (int i = 0; i < taille; ++i) {
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

        int getTaille() const{
            return taille;
        }

        T& getdata_i(int i) const{
            return data[i];
        }

        T& operator[](int index) {
            if (index < 0 || index >= taille) {
                cerr<<"Erreur: Indice hors de la plage autorisee \n";
            }
            return data[index]; 
        }
    
};

#endif