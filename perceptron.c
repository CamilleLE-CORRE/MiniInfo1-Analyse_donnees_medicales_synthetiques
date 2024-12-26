#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "getData.h"

// separer les donnees en 70% - 30%

// pour chaque couple de caracteristiques
    // pour chaque patient des 70%
    // recuperer les deux caracteristiques w1 et w2
    // calculer b
    // appliquer la fonction d'activation pourclasser dans la classe 0 ou 1


int* creerTableauEntiers(int N){

    /* Retourne un tableau des entiers de 1 à N */

    int* tableau = (int*)malloc(N * sizeof(int));
    // if (array == NULL) {
    //     perror("Failed to allocate memory");
    //     return NULL; // Retourne NULL en cas d'échec d'allocation
    // }

    // Remplir le tableau avec les entiers de 1 à N
    for (int i = 0; i < N; i++) {
        tableau[i] = i + 1;
    }

    return tableau; // Retourne le pointeur vers le tableau
}

void melangerTableau(int* tableau, int taille){

    /* Melange le tableau donne en entree (algorithme de Fisher-Yates, melange de Knuth) */


    srand((unsigned int)time(NULL));

    for (int i = taille - 1; i > 0; i--){   // pour chaque i

        int j = rand() % (i + 1);   // choisir un j aleatoirement

        // Echanger tableau[i] et tableau[j]
        int temp = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = temp;
    }
}



int* echantillonage(int N1, float p){

    /* Cette fonction permet de separer l'ensemble des donnees en deux : donnees d'entrainement et donnees de test.

        Elle prend en entree le plus grand element N1 (taille du tableau initial) et le pourcentage p que l'on veut piocher
        pour former le premier tableau.
        Retourne deux tableaux de taille reduite, avec respectivement N2 et N3 elements pioches aleatoirement entre 1 et N1,
        avec (N2 union N3 = N1) et (N2 inter N3 = ensemble vide) */


    // Cree un tableau d'entiers de 1 à N1
    int* tableau = creerTableauEntiers(N1);
    for (int i=0; i<10; i++){
        printf("%d ", tableau[i]); 
    }
    printf("\n");

    // Melange les elements de ce tableau
    melangerTableau(tableau, N1);

    // Calcul de la taille du tableau reduit (N2) et initialisation de ce tableau
    int N2 = N1*p; // taille du tableau reduit
    //int* tableau_reduit[N2];
    int* tableau_reduit = (int*)malloc(N2 * sizeof(int));

    // Calcul de la taille d


    // Remplissage de tableau_reduit avec les premiers elements du tableau initial (melange)
    for (int i=0; i<N2; i++){
        tableau_reduit[i] = tableau[i];
    }

    free(tableau);

    return tableau_reduit;
}

int activation(float z){
    if (z>=0){
        return 1;
    }
    else {
        return 0;
    }
}

float perceptron(int c1, int c2, float b){

    /* Effectue l'entrainement du perceptron pour les champs c1 et c2
    et retourne son taux d'erreur*/


    //int taille_tableau_reduit = taille*0.7;

    //int learning_data[taille_tableau_reduit] =  

    // récupérer x1 et x2, les données de c1 et c2 pour p

    
}


int main(){

    ////////////////////////////////////////////////////////
    char* PatientsData[MAX_PATIENTS][MAX_FIELDS];
    memset(PatientsData, 0, sizeof(PatientsData));
    BrowseFilePatients("patients.pengu", PatientsData);
    BrowseFileLivestyle("lifestyle.pengu", PatientsData);
    for (int i = 0; i < MAX_PATIENTS; i++) {
        for (int j = 0; j < MAX_FIELDS; j++) {
            if (PatientsData[i][j]) {
                free(PatientsData[i][j]);
            }
        }
    }
    ///////////////////////////////////////////////////////

    int* data_train;
    int* data_test;

    int* tab_red = echantillonage(10,0.75);
    for (int i=0; i<7; i++){
        printf("%d ", tab_red[i]);
    }
    printf("\n");



    int b; // = ?

    int best_c1 = 1;
    int best_c2 = 2;
    //float best_error_rate = perceptron(1, 2, b);
    float res;
    
    // Recuperer tous les couples (c1, c2) des champs de patients.pengu
    // for (int c1 = 2; c1 < 7; c1++){
    //     for (int c2 = 3; c2 < 8; c2++){

    //         res = perceptron(c1, c2, b);

    //         if (res < best_error_rate){ // Memoriser les meilleurs champs
    //             best_c1 = c1;
    //             best_c2 = c2;
    //         }
    //     }
    // }
    return 0;
}