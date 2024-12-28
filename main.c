#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getData.h"
#include "perceptron.h"

#define MAX_PATIENTS 5001
#define MAX_FIELDS 20


int main(){

    // Initialisation du tableau Patients Data
    char* PatientsData[MAX_PATIENTS][MAX_FIELDS];

    memset(PatientsData, 0, sizeof(PatientsData));

    // Remplir le tableau avec les donnees des fichiers patients et livestyle
    BrowseFilePatients("patients.pengu", PatientsData);
    BrowseFileLivestyle("lifestyle.pengu", PatientsData);

    // Affichage de quelques donnees de patients
    // for (int patient_id=50; patient_id<56; patient_id++){    

    //     printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s | physical_activity : %s | alcohol_consumption : %s | caffeine_consumption : %s | sleep_quality : %s\n", 
    //         PatientsData[patient_id][0], PatientsData[patient_id][1], PatientsData[patient_id][2], PatientsData[patient_id][3], PatientsData[50][4], 
    //         PatientsData[patient_id][5], PatientsData[patient_id][6], PatientsData[patient_id][7], PatientsData[patient_id][8], 
    //         PatientsData[patient_id][9], PatientsData[patient_id][10], PatientsData[patient_id][11], PatientsData[patient_id][12]);
    // }

    // Echantillonage : division des donnees en deux jeux de donnees disjoints (donnees d'entrainement et donnees de test)
    // Res res = echantillonage(10, 0.7);
    // int* data_train = res.tab1;
    // int* data_test = res.tab2;
    
    // printf("train: ");
    // for (int i=0; i<7; i++){
    //     printf("%d ", data_train[i]);
    // }
    // printf("\n");
    // printf("test: ");
    // for (int i=0; i<3; i++){
    //     printf("%d ", data_test[i]);
    // }
    // printf("\n");

    // Libération de la mémoire allouée
    for (int i = 0; i < MAX_PATIENTS; i++) {
        for (int j = 0; j < MAX_FIELDS; j++) {
            if (PatientsData[i][j]) {
                free(PatientsData[i][j]);
            }
        }
    }

    return 0;
}