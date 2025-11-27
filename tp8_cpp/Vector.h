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
};

#endif