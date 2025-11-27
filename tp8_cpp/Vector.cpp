#include "Vector.h"
#include <iostream>

int Vector::compteur = 0;

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

void Vector::affiche() const {
    if (coords != nullptr){
        std::cout<<"(";
        for (int i =0; i < taille; i++){
            std::cout<<coords[i];
            if (i != taille -1){
                std::cout<<",";
            }
        }
        std::cout<<")\n";
    }else{
        std::cout<<"()\n";
    }
    
}

std::ostream &operator <<(std::ostream &stream, const Vector &v) {
	if (v.coords != nullptr){
        stream<<"(";
        for (int i = 0; i < v.taille; i++){
            stream<< v.coords[i];
            if (i != v.taille -1){
                    stream<<",";
            }
        }
        stream<<")";
    }else{
        stream<<"()\n";
    }
	return stream;
}

Vector Vector::operator +(const Vector &v) const{
    Vector somme(taille) ;
    for (int i = 0; i < taille; i++)
		somme.coords[i] = coords[i] + v.coords[i];

	return somme;
}

Vector::Vector(const Vector &v) {
    taille = v.taille;
    coords = new double[taille]; 
    for (int i = 0; i < taille; i++) {
        coords[i] = v.coords[i];
    }
    compteur++; 
}

Vector &Vector::operator =(const Vector &v) {
    if (this != &v) {      
        if (coords != nullptr) {
            delete[] coords;
        }
        taille = v.taille;
        coords = new double[taille];
        for (int i = 0; i < taille; i++) {
            coords[i] = v.coords[i];
        }
    }
    return *this; 
}


