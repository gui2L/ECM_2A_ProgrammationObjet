#include "Vector.h"

int main(){
    Vector v1(1, 2, 3);
    Vector v2;
    Vector v3(5);
    Vector v4(1, 0);
    Vector v5(1, 0, 0, 0);
    v1.affiche();
    v2.affiche();

    Vector v(0, 0, 0);
    std::cout<< "v = " << v << "\n";
    
    std::cout<< "v1 = "<< v1 << "\n";

    Vector v6(2, 4, 8);
    std::cout<< "v6 = " << v6 << "\n";

    std::cout<< "v + v1 = " << v + v1 << "\n";
    std::cout<< "v1 + v6 = "<< v1 + v6 << "\n";

    Vector v7 = v1;
    std::cout<< "v7 = " << v7 << "\n";
    Vector v8; Vector v9;
    v8 = v9 = v7;
    std::cout<< "v8 = " << v8 << "\n";
    std::cout<< "v9 = " << v9 << "\n";

    std::cout<< "Produit scalaire entre v1 et v1 = " << v1*v1 << "\n";
    std::cout<< "Produit scalaire entre v1 et v = " << v1*v << "\n";

    double k = 2;
    std::cout<< "v1 * k = " << v1*k << "\n";
    std::cout<< "k * v1 = " << k * v1 << "\n";

    v += v1;
    std::cout<< "v += v1 donne v =" << v << "\n";
    v += v6;
    std::cout<< "v += v6 donne v =" << v << "\n";

    std::cout<< (v8 == v9) << "\n";
    std::cout<< ((k * v1) == (v1 * k)) << "\n";
    std::cout<< (v1 != v5) << "\n";
    std::cout<< (v1 != v6) << "\n";







    return 0;
}