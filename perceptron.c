#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// separer les donnees en 70% - 30%

// pour chaque couple de caracteristiques
    // pour chaque patient des 70%
    // recuperer les deux caracteristiques w1 et w2
    // calculer b
    // appliquer la fonction d'activation pourclasser dans la classe 0 ou 1

void melangerTableau(int* tableau, int taille){
    /* Melange le tableau donne en entree (algorithme de Fisher-Yates, melange de Knuth) */

    for (int i = taille - 1; i > 0; i--){   // pour chaque i

        int j = rand() % (i + 1);   // choisir un j aleatoirement

        // Echanger tableau[i] et tableau[j]
        int temp = tableau[i];
        tableau[i] = tableau[j];
        tableau[j] = temp;
    }
}

int* echantillonage(int* tableau, int taille, int taille_tableau_reduit){
    /* Retourne une partie du tableau donne en entree */

    // Melange les elements de tableau
    melangerTableau(&tableau, taille);

    // Calcul de la taille du tableau reduit et initialisation de ce tableau
    int* tableau_reduit[taille_tableau_reduit];

    // Remplissage de tableau_reduit avec les premiers elements de tableau
    for (int i=0; i<taille_tableau_reduit; i++){
        //*tableau_reduit[i] = *tableau[i];
    }

    return &tableau_reduit;
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

    int b; // = ?

    int best_c1 = 1;
    int best_c2 = 2;
    float best_error_rate = perceptron(1, 2, b);
    float res;
    
    // Recuperer tous les couples (c1, c2) des champs de patients.pengu
    for (int c1 = 2; c1 < 7; c1++){
        for (int c2 = 3; c2 < 8; c2++){

            res = perceptron(c1, c2, b);

            if (res < best_error_rate){ // Memoriser les meilleurs champs
                best_c1 = c1;
                best_c2 = c2;
            }
        }
    }
    return 0;
}