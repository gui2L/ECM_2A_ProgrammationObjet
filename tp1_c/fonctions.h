#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>


void exchange(int *x, int *y);

void saisir(int M[2][2]);
void afficher(int M[2][2]);
void additionner(int A[2][2], int B[2][2], int C[2][2]);
void multiplier(int A[2][2], int B[2][2], int C[2][2]);
void menu(char operation[20]);

int** SaisirMatrice(int *lignes, int *colonnes);
void AfficheMatrice(int *lignes, int *colonnes, int **Mat);
#endif