#include <vector>
#include <iostream>
#include <cmath>

#ifndef VECTOR_H
#define VECTOR_H

class Vector{
    private:
        std::vector<double> coords;
        static int compteur;

    public:
        Vector(int dim = 0);
        Vector(std::vector<double> valeurs);
        Vector (const Vector &v);
        ~Vector();

        static int getCompteur(){
            return compteur;
        }

        double getCoordinates(int i) const;
        int getDimension() const;
        void setCoordinates(int i, double coord);
        void Afficher();
        double Norme();
        bool isEqual(Vector w);
        void Multiplier(double k);

        static Vector Additionner(Vector &v, Vector &w){ //v et w supposés de même dimension
            Vector u(v.getDimension());
            for(int i = 0; i < v.getDimension(); i++){
                u.setCoordinates(i, v.getCoordinates(i) + w.getCoordinates(i));
            }
            return u;
        }

        static double ProduitScalaire(Vector &v, Vector &w){ //v et w supposés de même dimension
            double produitscalaire = 0;
            for(int i = 0; i < v.getDimension(); i++){
                produitscalaire += v.getCoordinates(i) * w.getCoordinates(i);
            }
            return produitscalaire;
        }

};


#endif