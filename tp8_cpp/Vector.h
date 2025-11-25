#ifndef VECTOR_H
#define VECTOR_H

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
};

#endif