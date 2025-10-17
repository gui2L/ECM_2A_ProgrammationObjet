#include "Date.h"
#include <iostream>


int main(){

    Date d1(0, 0, 0);
    Date d2(17, 10, 2025);
    Date d3 = d2;
    std::cout<<"date d1 : ";d1.affiche();
    std::cout<<"date d2 : ";d2.affiche();
    std::cout<<"date d3 : ";d3.affiche();



    return 0;
}