#include "Vector.h"

Vector::Vector(int dim) : coords(dim, 0.0) {compteur++;}
Vector::Vector(std::vector<double> valeurs) : coords(valeurs){compteur++;}
Vector::Vector(const Vector &v) : coords(v.coords) {compteur++;}
Vector::~Vector(){compteur--;}

double Vector::getCoordinates(int i) const{
    return coords[i];
}

int Vector::getDimension() const {
    return coords.size();
}

void Vector::setCoordinates(int i, double coord){
    coords[i] = coord;
}

void Vector::Afficher(){
    std::cout << "(";
    for (int i = 0; i < coords.size(); i++) {
        std::cout << coords[i];
        if (i+1 < coords.size()) std::cout << ", ";
    }
    std::cout << ") \n";
}

double Vector::Norme(){
    double sum = 0;
    for (double x : coords){
        sum += x*x;
    } 
    return std::sqrt(sum);
}

bool Vector::isEqual(Vector w){
    for(int i = 0; i < coords.size(); i++){
        if (coords[i] != w.getCoordinates(i)){
            return false;
        }
    }
    return true;
}

void Vector::Multiplier(double k){
    for(int i = 0; i < coords.size(); i++){
        coords[i] *= k;
    }
}