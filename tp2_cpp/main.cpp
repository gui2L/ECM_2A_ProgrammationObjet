#include "Point.h"
#include "Vector.h"
#include <iostream>
#include <string>

int Point::compteur = 0;

int main(){

    //ex1
    Point p1;
    p1.Afficher();
    Point p2(1, 2, 1);
    p2.Afficher();
    Point p3 = p2; 
    p3.Afficher();

    Point p4_user = p4_user.saisie();
    p4_user.Afficher();

    p4_user.Translate(2);
    p4_user.Afficher();

    std::cout << "Points A et B : \n";
    Point A;
    Point B(1, 0, 0); 
    A.Afficher();
    B.Afficher();
    std::cout << "Distance entre les points A et B : " << A.Distance(B) << "\n";
    std::cout << "Nb d'instances de Point : " << Point::getCompteur() << "\n";

    //ex2
    



    return 0;
}