#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
	int taille;
	double *coords;
    static int compteur;

public:
	Vector();
    Vector(int taille);
    Vector(double x);
    Vector(double x, double y);
    Vector(double x, double y, double z);
    Vector(double x1, double x2, double x3, double x4);
    ~Vector();
    void affiche() const;

    static int getCompteur(){
            return compteur;
        }

    friend std::ostream &operator <<(std::ostream &stream, const Vector &v);
    Vector operator +(const Vector &v) const;
    Vector(const Vector &v); // constructeur de recopie pour gérer la mémoire en utilisant l'opérateur =
    Vector &operator =(const Vector &v);
    double operator *(const Vector &v) const;
    Vector operator *(double k) const;
    friend Vector operator *(double k, const Vector &v);
};

#endif