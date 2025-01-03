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


//// Fonctions pour la construction des deux jeux de donnees ////

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

typedef struct Res {
        int* tab1;
        int* tab2;
    } Res;

Res echantillonage(int N1, float p){

    /* Cette fonction permet de separer l'ensemble des donnees en deux : donnees d'entrainement et donnees de test.

        Elle prend en entree le plus grand element N1 (taille du tableau initial) et le pourcentage p que l'on veut piocher
        pour former le premier tableau.
        Retourne deux tableaux de taille reduite, avec respectivement N2 et N3 elements pioches aleatoirement entre 1 et N1,
        avec (N2 union N3 = N1) et (N2 inter N3 = ensemble vide) */


    // Cree un tableau d'entiers de 1 à N1
    int* tableau = creerTableauEntiers(N1);

    // Melange les elements de ce tableau
    melangerTableau(tableau, N1);

    // Calcul de la taille du premier tableau reduit (de taille N2) et initialisation de ce tableau
    int N2 = N1*p; // taille du tableau reduit
    int* tableau_reduit1 = (int*)malloc(N2 * sizeof(int));

    // Remplissage de tableau_reduit1 avec les premiers elements du tableau initial (melange)
    for (int i=0; i<N2; i++){
        tableau_reduit1[i] = tableau[i];
    }

    // Calcul de la taille du deuxieme tableau réduit (de taille N3) et initialisation de ce tableau
    int N3 = N1 - N2;
    int* tableau_reduit2 = (int*)malloc(N3 * sizeof(int));

    // Remplissage de tableau_reduit2 avec les derniers elements du tableau initial (melange)
    for (int i=N2; i<N1; i++){
        tableau_reduit2[i-N2] = tableau[i];
    }

    Res res;
    res.tab1 = tableau_reduit1;
    res.tab2 = tableau_reduit2;

    free(tableau);

    return res;
}


float charToFloat(char* str){
    return atof(str);
}

// int charToInt(char* str){
//     return atoi(str);
// }

float CharToFloat(char array[], size_t length, int c){

    /// Bout de code ChatGPT ===>>> a modifier ensuite

    // Gestion du sexe M/F transforme en 0/1
    if (c==2){
        if (array[0] == 'M'){
            array[0] = '1';
        }
        else{
            array[0] = '0';
        }
    }

    // Ajouter un caractère nul à la fin pour transformer en chaîne
    char str[length + 1]; // +1 pour le '\0'
    memcpy(str, array, length); // Copier les caractères
    str[length] = '\0'; // Ajouter '\0' à la fin
    // Convertir la chaîne en flottant
    float value = strtof(str, NULL);
    return value;
}

int qualitativeToInt(char* str, char* val){

    /* Prend en argument une chaine de caracteres str et renvoie 1 si str = val, 0 sinon */
    // est utilisé pour transformer le sexe (H ou F) en 0 ou 1

    if (str == val){
        return 1;   
    }
    else {
        return 0;
    }
}


int activation(float z){
    if (z>=0){
        return 1;
    }
    else {
        return 0;
    }
}

float calculTauxErreur(float w1, float w2, float b, int* data, char* PatientsData[MAX_PATIENTS][MAX_FIELDS]){

}

typedef struct ResPerceptron{
    float w1;
    float w2;
    float b;
    float nu;
    float error_rate;
} ResPerceptron;

ResPerceptron perceptron(int c1, int c2, char* PatientsData[MAX_PATIENTS][MAX_FIELDS], int* data_train){

    /* Effectue l'entrainement du perceptron pour les champs c1 et c2
    et retourne son taux d'erreur*/

    // Declaration des variables
    float vect_x1[3500];
    float vect_x2[3500];
    float vect_risque[3500];    // vecteur contenant des 0 ou des 1
    float w1;
    float w2;
    float b=1;
    float nu=0.001;   //prendre ensuite une valeur aléatoire ?? 
    int iteration=0;
    float error_rate;
    int cpt_erreurs;

    // Stocker les valeurs des champs c1 et c2 pour tous les patients, ainsi que leur risque respectif
    for (int i=0; i<3500; i++){
        vect_x1[i] = CharToFloat(PatientsData[i][c1], strlen(PatientsData[i][c1]), c1);
        vect_x2[i] = CharToFloat(PatientsData[i][c2], strlen(PatientsData[i][c2]), c2);
        vect_risque[i] = CharToFloat(PatientsData[i][8], strlen(PatientsData[i][8]), 8);
    }

    // for (int i=0; i<5; i++){
    //     printf("patient=%d ; x1=%f ; x2=%f ; risk=%f\n", i, vect_x1[i], vect_x2[i], vect_risque[i]);
    // }

    // Initialisation de w1 et w2 par un flottant aleatoire dans [-1;1]
    srand(time(NULL));
    w1 = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    w2 = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;


    while (iteration < 100){    // au maximum 100 itérations

        cpt_erreurs = 0;

        for (int i=0; i<3500; i++){   // pour chaque patient
            int patient = data_train[i];
            
            // Utilisation de la fonction d'activation pour determiner le risque du patient
            int risque = activation(vect_x1[patient]*w1 + vect_x2[patient]*w2 + b);

            // Comparaison du risque predit avec le risque attendu
            if (risque != vect_risque[patient]){    // s'il s'agit d'une erreur
                cpt_erreurs++;

                // Modification des poids w1 et w2, ainsi que du biais b
                w1 += nu * (vect_risque[patient] - risque) * vect_x1[patient];
                w2 += nu * (vect_risque[patient] - risque) * vect_x2[patient];
                b += nu * (vect_risque[patient] - risque);
                if (patient <100){
                    printf("w1=%f ; w2=%f\n", w1, w2);
                }
            }
        }
        iteration++;
    }

    // Calcul du taux d'erreur
    error_rate = cpt_erreurs/3500;      // 3500 à modifier -> mettre taille de vect_x1

    // Resultat en sortie
    ResPerceptron res;
    res.w1=w1;
    res.w2=w2;
    res.b=b;
    res.nu=nu;
    res.error_rate=error_rate;

    return res;
}


int main(){
    
    ////////////////////////////////////////////////////////
    // Initialisation de la structure de donnees
    char* PatientsData[MAX_PATIENTS][MAX_FIELDS];

    memset(PatientsData, 0, sizeof(PatientsData));

    // Remplir le tableau avec les donnees des fichiers patients et livestyle
    BrowseFilePatients("patients.pengu", PatientsData);
    BrowseFileLivestyle("lifestyle.pengu", PatientsData);
    
    ///////////////////////////////////////////////////////
    // Formation des deux jeux de donnees : entrainement et test    
    Res res = echantillonage(10, 0.7);
    int* data_train = res.tab1;
    int* data_test = res.tab2;
    ///////////////////////////////////////////////////////

    // printf("!!!! %s !!!!\n", PatientsData[2][2]);
    // printf("!!!! %f !!!!\n", CharToFloat(PatientsData[2][2], strlen(PatientsData[2][2]), 2));
    // char* t = PatientsData[1][3];
    // printf("char=%s ; float=%f\n", t, CharToFloat(t, strlen(t)));

    // Initialisation des variables permettant de stocker le meilleur score et les caracteristiques associees
    int best_c1 = 1;
    int best_c2 = 2;
    float best_error_rate = perceptron(1, 2, PatientsData, data_train).error_rate;

    // Pour chaque couple (c1, c2) des champs de patients.pengu
    for (int c1 = 1; c1 < 8; c1++){
        for (int c2 = c1+1; c2 < 8; c2++){
            if (c1 != c2){

                //printf("champs testes : %d et %d\n", c1, c2);
                ResPerceptron res = perceptron(c1, c2, PatientsData, data_train);
                // printf("resultats : w1=%f, w2=%f, b=%f, nu=%f\n", res.w1, res.w2, res.b, res.nu);
                // printf("taux d'erreur = %f\n", res.error_rate);

                if (res.error_rate < best_error_rate){ // Memoriser les meilleurs champs
                    best_c1 = c1;
                    best_c2 = c2;
                    best_error_rate = res.error_rate;
                }
            }
            
        }
    }

    return 0;
}