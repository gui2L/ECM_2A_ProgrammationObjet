#include <stdio.h>
#include "fonctions.h"

int main(){

    //ex1
    /*int a = 666;
    int b = 999;
    printf("avant appel de exchange : a= %d  ; b=%d \n",a,b);
	exchange( &a , &b );
	printf("apres appel de exchange : a= %d  ; b=%d \n",a,b);

    //ex2
    int M[2][2];
    saisir(M);
    afficher(M);

    int A[2][2] = { {1, 1}, 
                    {1, 1}};
    int B[2][2] = { {1, 2}, 
                    {3, 4}};
    int C[2][2];
    additionner(A, B, C);
    afficher(C);

    int I[2][2] = { {1, 0}, 
                    {0, 1}};
    int D[2][2] = { {1, 2}, 
                    {3, 4}};
    int E[2][2];
    multiplier(I, D, E);
    afficher(E);

    char operation[20];
    menu(operation);*/

    //ex3
    int lignes, colonnes;
    int **Mat = SaisirMatrice(&lignes, &colonnes);
    AfficheMatrice(&lignes, &colonnes, Mat);
    

}