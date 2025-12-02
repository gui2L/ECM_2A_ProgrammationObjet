using namespace std;
#include <iostream>

template <typename T>
T somme(int nb_ele, T tab[]){
    T somme = T(); 
    cout<<T()<<"\n";
    for (int i = 0; i < nb_ele; i++){
        somme += tab[i];
    }
    return somme;
};

int main(){
    int entiers[] = {1, 2, 3, 4, 5};
    double doubles[] = {1.5, 2.5, 3.0};
    string caracteres[] = {"a", "b", "c"};
    cout << "somme entiers : " << somme(sizeof(entiers)/sizeof(entiers[0]), entiers) <<"\n";
    cout << "somme doubles : " << somme(sizeof(doubles)/sizeof(doubles[0]), doubles) <<"\n";
    cout << "somme caracteres : " << (somme(sizeof(caracteres)/sizeof(caracteres[0]), caracteres)) <<"\n";

    return 0;
}
