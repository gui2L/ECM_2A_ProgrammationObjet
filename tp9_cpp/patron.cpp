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

template <typename T> 
int minimum(int nb_ele, T tab[]){
    T min = tab[0];
    int indice = 0;
    for (int i = 1; i < nb_ele; i++){
        if (min > tab[i]) {
            min = tab[i];
            indice = i;
        };
    }
    return indice;
}

template <typename T, typename U>
int minimum_2tab(int nb_ele1, int nb_ele2, T tab1[], U tab2[]){
    int indice_min1 = minimum(nb_ele1, tab1);
    int indice_min2 = minimum(nb_ele2, tab2);
    if (tab1[indice_min1] < tab2[indice_min2]){
        return indice_min1;
    }else{
        return indice_min2;
    }
}

int main(){
    int entiers[] = {3, 2, 1, 5, 4}; int t_entiers = sizeof(entiers)/sizeof(entiers[0]);
    double doubles[] = {3.0, 1.5, 2.5, 0.2}; int t_doubles = sizeof(doubles)/sizeof(doubles[0]);
    char cars[] = {'a', 'b', 'c'}; int t_cars = sizeof(cars)/sizeof(cars[0]);
    string caracteres[] = {"a", "b", "c"}; int t_caracteres = sizeof(caracteres)/sizeof(caracteres[0]);
    
    cout << "somme entiers : " << somme(t_entiers, entiers) <<"\n";
    cout << "somme doubles : " << somme(t_doubles, doubles) <<"\n";
    cout << "somme cars (caractere): " << somme(t_cars, cars) <<"\n";
    cout << "somme caracteres (concatenation en string): " << somme(t_caracteres, caracteres) <<"\n";

    cout << "indice min entiers :" << minimum(t_entiers, entiers)<< "\n";
    cout << "indice min doubles :" << minimum(t_doubles, doubles)<< "\n";

    string s[] = {"abbbb", "abbab", "aab"};
    int t_s = sizeof(s)/sizeof(s[0]);
    cout << "indice min string : " << minimum(t_s, s)<< "\n";

    cout << "indice min entre doubles et entiers :" << minimum_2tab(t_entiers, t_doubles, entiers, doubles)<< "\n";
    //cout << int(cars[0]);
    cout << "indice min entre entiers et cars :" << minimum_2tab(t_entiers, t_cars, entiers, cars)<< "\n";

    //ex4 template que sur la classe
    return 0;
}
