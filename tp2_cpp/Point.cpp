#include "Point.h"
#include <iostream>
#include <string>
#include <cmath>


Point::Point(double x, double y, double z) : x(x), y(y), z(z){
    compteur++;
}

Point::Point (const Point &p)
{
	x = p.x;
	y = p.y;
    z = p.z;

    compteur++;
}

Point :: ~Point() {
    compteur--;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}

void Point::setX(double new_x){
    x = new_x;
}

void Point::setY(double new_y) {
    y = new_y;    
}

void Point::setZ(double new_z) {
    z = new_z;    
}

Point Point::saisie(){
    double x, y, z;
    std::cout << "Donnez coord x :";
    std::cin >> x;
    std::cout << "Donnez coord y :";
    std::cin >> y;
    std::cout << "Donnez coord z :";
    std::cin >> z;
    return Point(x, y, z);
}

void Point::Afficher(){
    std::cout << "(" << x << "," << y << "," << z << ") \n";
}

void Point::Translate(double dist){
    setX(x+dist);
    setY(y+dist);
    setZ(z+dist);
}

double Point::Distance(Point B){
    double dx = x - B.x;
    double dy = y - B.y;
    double dz = z - B.z;
    double dist = std::sqrt(dx*dx + dy*dy + dz*dz);
    return dist;
}
