using namespace std;
#include <iostream>

template <typename T>
T somme(int nb_ele, T tab[]){
    T somme = T(); 
    for (int i = 0; i < nb_ele; i++){
        somme += tab[i];
    }
    return somme;
};

template <typename T> T minimum(int nb_ele, T tab[]){
    T ele = T();
    for (int i = 0; i < nb_ele; i++){
        if (ele > tab[i]) {
            ele = tab[i];
        };
    }
    return ele;
}

int main(){
    int entiers[] = {1, 2, 3, 4, 5}; int t_entiers = sizeof(entiers)/sizeof(entiers[0]);
    double doubles[] = {1.5, 2.5, 3.0}; int t_doubles = sizeof(doubles)/sizeof(doubles[0]);
    char cars[] = {'a', 'b', 'c'}; int t_cars = sizeof(cars)/sizeof(cars[0]);
    string caracteres[] = {"a", "b", "c"};
    cout << "somme entiers : " << somme(t_entiers, entiers) <<"\n";
    cout << "somme doubles : " << somme(t_doubles, doubles) <<"\n";
    cout << "somme cars (caractere): " << somme(t_cars, cars) <<"\n";
    cout << "somme caracteres (concatenation en string): " << somme(sizeof(caracteres)/sizeof(caracteres[0]), caracteres) <<"\n";

    //cout << minimum()
    return 0;
}
