#include "Date.h"



int main(){

    Date d1(0, 0, 0);
    Date d2(17, 10, 2025);
    Date d3 = d2;
    d1.affiche();
    d2.affiche();
    d3.affiche();

    return 0;
}