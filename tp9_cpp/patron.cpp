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
    char caractere[] = {'a', 'b', 'c'};
    cout <<sizeof(entiers);
    //cout << somme(sizeof(entiers), entiers);

    return 0;
}
