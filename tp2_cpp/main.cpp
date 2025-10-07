#include "Point.h"
#include "Vector.h"
#include "ArrayOfInteger.h"
#include <iostream>
#include <string>

int main(){

    //ex1
    /*Point p1;
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
    std::cout << "Nb d'instances de Point : " << Point::getCompteur() << "\n";*/

    //ex2
    /*Vector v1;
    v1.Afficher();
    Vector v2(2);
    v2.Afficher();
    Vector v3({0, 0, 1});
    v3.Afficher();
    Vector v4 = v3;
    v4.Afficher();
    std::cout<<"------------\n";

    Vector v5({0, 0, 0});
    std::cout << "vecteur v5 avant modification : "; v5.Afficher();
    
    std::cout << "vecteur v5 apres modification : \n";
    v5.setCoordinates(0, 1/std::sqrt(2));
    v5.setCoordinates(2, 1/std::sqrt(2));

    std::cout << "coord x : " << v5.getCoordinates(0) << "\n";
    std::cout << "coord y : " << v5.getCoordinates(1) << "\n";
    std::cout << "coord z : " << v5.getCoordinates(2) << "\n";
    v5.Afficher();

    std::cout << "norme du vecteur v5 : " << v5.Norme() << "\n";
    std::cout<<"------------\n";

    Vector v6({1/std::sqrt(2), 0, 1/std::sqrt(2)});
    Vector v7({3, 1/std::sqrt(2), 1/std::sqrt(2)});
    std::cout << "vecteur v6 : "; v6.Afficher();
    std::cout << "vecteur v7 : "; v7.Afficher();

    if (v5.isEqual(v6)){std::cout << "v5 est egal a v6 \n";}else{std::cout << "v5 n'est pas egal a v6 \n";}
    if (v5.isEqual(v7)){std::cout << "v5 est egal a v7 \n";}else{std::cout << "v5 n'est pas egal a v7 \n";}
    std::cout<<"------------\n";

    Vector u = Vector::Additionner(v6, v7);
    std::cout << "vecteur u, l'addition de v6 et v7 : "; u.Afficher();
    u.Multiplier(10);
    std::cout << "vecteur u, multiplier par 10 : "; u.Afficher();
    std::cout<<"------------\n";

    Vector a({0, 1/std::sqrt(2), 1/std::sqrt(2)});
    Vector b({1, 2, 3});
    std::cout << "vecteur a : "; a.Afficher();
    std::cout << "vecteur b : "; b.Afficher();
    std::cout << "Produit scalaire entre a et b : " << Vector::ProduitScalaire(a, b) << "\n";
    std::cout << "Produit scalaire entre a et a : " << Vector::ProduitScalaire(a, a) << "\n";


    std::cout << "\nNb d'instances de Vector : " << Vector::getCompteur();*/

    ArrayOfInteger t1;
    std::cout << "tableau t1 : "; t1.Afficher();
    ArrayOfInteger t2(2);
    std::cout << "tableau t2 : "; t2.Afficher();
    ArrayOfInteger t3({1, 2, 3});
    std::cout << "tableau t3 : "; t3.Afficher();
    ArrayOfInteger t4 = t3;
    std::cout << "tableau t4 : "; t4.Afficher();
    std::cout<<"------------\n";

    if (t1.Contient(0) != -1){ std::cout<<"t1 contient 0 \n";}else{ std::cout<<"t1 ne contient pas 0 \n";};
    if (t3.Contient(1) != -1 && t3.Contient(2) != -1 && t3.Contient(3) != -1){ std::cout<<"t3 contient 1, 2, 3 \n";}else{ std::cout<<"t3 ne contient pas tous les entiers 1, 2, 3 \n";};
    if (t3.Contient(4) != -1){ std::cout<<"t3 contient 4";}else{ std::cout<<"t3 ne contient pas 4 \n";};
    

    ArrayOfInteger t5({2, 0, 2, 4});
    std::cout << "tableau t5 avant modif : "; t5.Afficher();
    t5.Remove(4);
    t5.Remove(4); 
    t5.Remove(3); 
    t5.Add(5);  
    t5.Add(5);
    std::cout << "tableau t5 apres modif : "; t5.Afficher();
    
    
    
    std::cout << "\nNb d'instances de ArrayOfInteger : " << ArrayOfInteger::getCompteur();

    
    return 0;
}