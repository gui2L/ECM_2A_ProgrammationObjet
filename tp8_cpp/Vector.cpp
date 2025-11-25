#include "Vector.h"

Vector::Vector() {
	taille = 0;
	coords = nullptr;
    compteur++;
}

Vector::~Vector() {
	if (coords != nullptr)
		delete[] coords;
	coords = nullptr;
    compteur--;
}

Vector::Vector(int n) {
	taille = n;
	coords = new double[taille];
    compteur++;
}

Vector::Vector(double x) {
	taille = 1;
	coords = new double[taille];
	coords[0] = x;
    compteur++;
}

Vector::Vector(double x, double y) {
	taille = 2;
	coords = new double[taille];
	coords[0] = x;
	coords[1] = y;
    compteur++;
}

Vector::Vector(double x, double y, double z) {
	taille = 3;
	coords = new double[taille];
	coords[0] = x;
	coords[1] = y;
	coords[2] = z;
    compteur++;
}

Vector::Vector(double x1, double x2, double x3, double x4) {
	taille = 4;
	coords = new double[taille];
	coords[0] = x1;
	coords[1] = x2;
	coords[2] = x3;
    coords[3] = x4;
    compteur++;
}

