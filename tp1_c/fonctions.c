#include "fonctions.h"
#include <string.h>
#include <stdlib.h>

void exchange(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void saisir(int M[2][2]){
    printf("Saisir les elements d'une matrice carree : \n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("M(%d,%d) :", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void afficher(int M[2][2]){
    printf("matrice carree :");
    for(int i = 0; i < 2; i++){
        printf("\n");
        for(int j = 0; j < 2; j++){
            printf("%d", M[i][j]);
        }
    }
    printf("\n");
}

void additionner(int A[2][2], int B[2][2], int C[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
		    C[i][j] = A[i][j]+B[i][j];
        }
	}
}

void multiplier(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0; 
            for (int k = 0; k < 2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void menu(char operation[20]) {
    while (strcmp(operation, "additionner") != 0 && strcmp(operation, "multiplier") != 0) {
        printf("Veuillez saisir une operation entre additionner et multiplier : ");
        scanf("%14s", operation);  // %14s pour éviter un dépassement de buffer
        printf("%s\n", operation);
    }
}
    

int** SaisirMatrice(int *lignes, int *colonnes) {
    printf("Veuillez saisir le nombre de lignes de votre matrice : ");
    scanf("%d", lignes);

    printf("Veuillez saisir le nombre de colonnes de votre matrice : ");
    scanf("%d", colonnes);

    int **M = malloc(*lignes * sizeof(int*));
    for (int i = 0; i < *lignes; i++) {
        M[i] = malloc(*colonnes * sizeof(int)); 
    }

    printf("Veuillez saisir les valeurs de votre matrice : \n");
    for (int i = 0; i < *lignes; i++) {
        for (int j = 0; j < *colonnes; j++) {
            printf("M(%d,%d) : ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
    printf("\n");
    return M;
}

void AfficheMatrice(int *lignes, int *colonnes, int **Mat){
    for (int i = 0; i < *lignes; i++) {
        printf("\n");
        for (int j = 0; j < *colonnes; j++) {
            printf("%d ", Mat[i][j]);
        }
        
    }
    printf("\n");
}

int** MaxLigne( int *lignes, int *colonnes, int **Mat) {

    int **MaxLig = malloc(*lignes * sizeof(int*));
    for (int i = 0; i < *lignes; i++) {
        MaxLig[i] = malloc(*colonnes * sizeof(int));
    }

    for (int i = 0; i < *lignes; i++) {
        int maxVal = Mat[i][0];

        for (int j = 1; j < *colonnes; j++) {
            if (Mat[i][j] > maxVal) {
                maxVal = Mat[i][j];
            }
        }

        for (int j = 0; j < *colonnes; j++) {
            if (Mat[i][j] == maxVal) {
                MaxLig[i][j] = 1;
            } else {
                MaxLig[i][j] = 0;
            }
        }
    }

    return MaxLig;
}

int** MinColonne(int *lignes, int *colonnes, int **Mat) {

    int **MinCol = malloc(*lignes * sizeof(int*));
    for (int i = 0; i < *lignes; i++) {
        MinCol[i] = malloc(*colonnes * sizeof(int));
    }

    for (int j = 0; j < *colonnes; j++) {
        int minVal = Mat[0][j];

        for (int i = 1; i < *lignes; i++) {
            if (Mat[i][j] < minVal) {
                minVal = Mat[i][j];
            }
        }

        for (int i = 0; i < *lignes; i++) {
            if (Mat[i][j] == minVal) {
                MinCol[i][j] = 1;
            } else {
                MinCol[i][j] = 0;
            }
        }
    }

    return MinCol;
}

void TrouvePointsClos(int lignes, int colonnes, int **Mat) {
    int **MaxL = MaxLigne(&lignes, &colonnes, Mat);
    int **MinC = MinColonne(&lignes, &colonnes, Mat);

    printf("Points-Clos :\n");

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            if (MaxL[i][j] == 1 && MinC[i][j] == 1) {
                printf("Valeur=%d, ligne %d, colonne %d)\n", Mat[i][j], i+1, j+1);
            }
        }
    }

    for (int i = 0; i < lignes; i++) {
        free(MaxL[i]);
        free(MinC[i]);
    }
    free(MaxL);
    free(MinC);
}