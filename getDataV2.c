#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 5001
#define MAX_FIELDS 20

void BrowseFilePatients(char file_name[], char* PatientsData[MAX_PATIENTS][MAX_FIELDS]) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    int i_line = 0;
    char line[256];

    fgets(line, sizeof(line), file); // Lecture de la première ligne du fichier (nom des colonnes), qu'on ignore

    // Lire chaque ligne
    while (fgets(line, sizeof(line), file) && i_line < MAX_PATIENTS) {
        char* tokens[MAX_FIELDS];
        int field_index = 0;

        // Découper la ligne en tokens
        char *token = strtok(line, "$");
        while (token != NULL && field_index < MAX_FIELDS) {
            tokens[field_index++] = token;
            token = strtok(NULL, "$");
        }

        // Ajouter les données du patient
        for (int i = 0; i < 9; i++) {
            PatientsData[i_line][i] = strdup(tokens[i + 1]);
        }

        i_line++;
    }

    fclose(file);
}

void BrowseFileLivestyle(char file_name[], char* PatientsData[MAX_PATIENTS][MAX_FIELDS]) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

    int i_line = 0;
    char line[256];

    fgets(line, sizeof(line), file); // Lecture de la première ligne du fichier (nom des colonnes), qu'on ignore

    // Lire chaque ligne
    while (fgets(line, sizeof(line), file) && i_line < MAX_PATIENTS) {
        char* tokens[MAX_FIELDS];
        int field_index = 0;

        // Découper la ligne en tokens
        char *token = strtok(line, "$");
        while (token != NULL && field_index < MAX_FIELDS) {
            tokens[field_index++] = token;
            token = strtok(NULL, "$");
        }

        // Récupérer l'ID du patient (colonne 2 dans le fichier lifestyle)
        int i_patient = atoi(tokens[1]) - 1;  // L'ID commence à 1 dans le fichier, ajustement à 0 pour le tableau

        PatientsData[i_patient][9] = strdup(tokens[2]);  // physical_activity
        PatientsData[i_patient][10] = strdup(tokens[3]); // alcohol_consumption
        PatientsData[i_patient][11] = strdup(tokens[4]); // caffeine_consumption
        PatientsData[i_patient][12] = strdup(tokens[5]); // sleep_quality

        i_line++;
    }

    fclose(file);
}

// char* InitializeDataStruct(){
//     /* Retourne un pointeur vers la structure de donnees creee */

//     // Création du tableau PatientsData
//     char* PatientsData[MAX_PATIENTS][MAX_FIELDS];

//     memset(PatientsData, 0, sizeof(PatientsData));

//     BrowseFilePatients("patients.pengu", PatientsData);
//     BrowseFileLivestyle("lifestyle.pengu", PatientsData);

//     return PatientsData;
// }

int main() {    // il faudra enlever le main apres

    // Création du tableau PatientsData
    char* PatientsData[MAX_PATIENTS][MAX_FIELDS];

    memset(PatientsData, 0, sizeof(PatientsData));

    BrowseFilePatients("patients.pengu", PatientsData);
    BrowseFileLivestyle("lifestyle.pengu", PatientsData);

    for (int patient_id=50; patient_id<56; patient_id++){    

        printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s | physical_activity : %s | alcohol_consumption : %s | caffeine_consumption : %s | sleep_quality : %s\n", 
            PatientsData[patient_id][0], PatientsData[patient_id][1], PatientsData[patient_id][2], PatientsData[patient_id][3], PatientsData[50][4], 
            PatientsData[patient_id][5], PatientsData[patient_id][6], PatientsData[patient_id][7], PatientsData[patient_id][8], 
            PatientsData[patient_id][9], PatientsData[patient_id][10], PatientsData[patient_id][11], PatientsData[patient_id][12]);
    }

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
