#include <iostream>

 template<class T, class U> void fct(T a, U b) {
 std::cout << "je suis la fonction1";
 }
 template<class T, class U> void fct(T * a, U b) {
 std::cout << "je suis la fonction 2";
 }
 template<class T> void fct(T, T, T) {
 std::cout << "je suis la fonction 3";
 }
 void fct(int a, float b) {
 std::cout << "Je suis la fonction 4";
 }

 /*int main() {
    int n=0, p=0, q=0;
    float x=0.0, y=0.0;
    double z=0.0;
    std::cout << "fct (n, p) ;";
    fct(n, p);
    std::cout << "fct (x, y) ;";
    fct(x, y);
    std::cout << "fct (n, x) ;";
    fct(n, x);
    std::cout << "fct (n, z) ;";
    fct(n, z);
    std::cout << "fct (&n, p) ;";
    fct(&n, p);
    std::cout << "fct (&n, x) ;";
    fct(&n, x);
    std::cout << "fct (&n, &p, &q);";
    fct(&n, &p, &q);
    return 0;
 }*/

