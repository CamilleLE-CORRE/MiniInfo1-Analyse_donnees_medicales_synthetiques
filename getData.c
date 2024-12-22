#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TYPE_DE_VARIABLE(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    char: "char", \
    char*: "char*", \
    default: "inconnu")

int MAX_PATIENTS = 5001;
int MAX_FIELDS = 20;

/// Construction de la structure de donnees Patient ///
/// contenant toutes les informations sur un patient donne ///

        //id, age, sex, weight, blood_pressure, average_heart_rate, blood_sugar, cholesterol, risk
        //physical_activity, alcohol_consumption, caffeine_consumption, sleep_quality

// typedef struct Patient {
//     int id;
//     int age;
//     char sex;
//     float weight;
//     int blood_pressure;
//     int average_heart_rate;
//     float blood_sugar;
//     float cholesterol;
//     int physical_activity;     // Placeholder
//     float alcohol_consumption; // Placeholder
//     float caffeine_consumption; // Placeholder
//     float sleep_quality;       // Placeholder
//     int risk;
// } Patient;

// Structure enum contenant les champs de la structure Patient //
// necessaire pour le remplissage des donnees dans PatientsData


// typedef enum Patients_info{
//     id = 1, age = 2, sex = 3, weight = 4, blood_pressure = 5, average_heart_rate = 6, blood_sugar = 7, cholesterol = 8,
//     physical_activity = 9, alcohol_consumption = 10, caffeine_consumption = 11, sleep_quality = 12, risk = 13
// } Patients_info;

/// Fonctions pour analyser chaque ligne du fichier et construire la structure de donnees ///


// int countLinesInFile(char file_name[]){
//     /* Retourne le nombre de lignes d'un fichier */

//     int nb_lines;

//     // corre de la fonction

//     return nb_lines;
// }

// float CharToFloat(char array[], size_t length){
//     /// Bout de code ChatGPT ===>>> a modifier ensuite

//     // Ajouter un caractère nul à la fin pour transformer en chaîne
//     char str[length + 1]; // +1 pour le '\0'
//     memcpy(str, array, length); // Copier les caractères
//     str[length] = '\0'; // Ajouter '\0' à la fin

//     // Convertir la chaîne en flottant
//     float value = strtof(str, NULL);

//     return value;
// }

// int CharToInt(char array[], size_t length){

//     char str[length + 1];
//     memcpy(str, array, length);
//     str[length] = '\0';
//     int value = strtol(str, NULL, 10);

//     return value;
// }

// int IsFloat(char value[]){
//     /* Si un des caracteres est un '.', alors il s'agit d'un float, la fonction retourne 1.
//         Sinon, elle retourne 0. */
//
//     int length = strlen(value);

//     for (int i=0; i<length; i++){
//         if (value[0] == '.'){
//             return 1;
//         }
//     }

//     return 0; // si aucun '.' n'a ete trouve, retourne 0 (ce n'est pas un float)
// }

// int BoolToInt(char value[]){
//     /* Prend en argument un booleen (chaine de caracteres "True" ou "False")
//     et renvoie 0 (False) ou 1 (True) */

//     if (value == "True"){
//         return 1;   
//     }
//     else {
//         return 0;
//     }

//}

// void AddValueToPatientData(char value[], Patient *p, Patients_info info, int/* pas le bon type */ champs){
//     /* Prend en argument une chaine de caracteres, convertie son type et l'ajoute aux donnees des patients */

//     int length = strlen(value);

//     if (isalpha(value[0])){     // si le premier caractere est un caractere alphabetique

//         if (length == 1){   // si la chaine de caracteres est composee d'un seul caractere (cas unique du sexe : 'F' ou 'M')
//             (*p).sex = value[0];
//         }
//         else {      // cas unique du risque ("True" ou "False")
//             (*p).risk = BoolToInt(value);
//         }
//     }

//     else {  // si le permier caractere est un chiffre

//         if (IsFloat(value)){    // si c'est un float
//             float val = CharToFloat(value, length);
//         }
//         else {  // si c'est un entier
//             int val = CharToInt(value, length);
//         }
//         //p.champs = val;
//     }
// }



//!\\ soit faire 2 fonctions ParseLine pour les 2 fichiers a parser, soit donner en argument les champs a remplir, soit autre chose
// void ParseLine(char line[], int i_patient, Patient patientsData[5000]){
//     /* Utilise les caracteres $ pour separer les donnees d'une ligne donnee en argument et les ajouter aux donnees des patients */

//     int length = strlen(line);
//     //char *temp;  // initialisation d'une chaine de caracteres, qui contiendra les donnees de la ligne
//     char temp[5];  // initialisation d'une chaine de caracteres, qui contiendra les donnees de la ligne

//     char *value;
//     float result = strtol(temp, &value, 10);

//     int i_line = 0;
//     int i_val = 0;
//     int i_champs = 0;   // indice du champs en train d'etre traite

//     while (i_line<length){   // analyse de chaque caractere de la ligne

//         if (line[i_line] != '$'){   // si le caractere est un $ (separateur) OU FIN DE LIGNE
//             //AddValueToPatientData(temp, &patientsData[i_patient],);
//             i_champs++;
//             char temp[5];   // reinitialisation de temp
//             i_val = 0;
//         }
//         else {      // si ce n'est pas un separateur, c'est un caractere des donnees d'un patient

//             temp[i_val] = line[i_line];     // ajouter ce caractere a temp
//             i_val++;
//         }
//         i_line++;

 
//         if (line[i_line] == '$' || line[i_line] == '\n'){    // si le caractere est un $ (separateur) ou une fin de ligne
        
//             //char *temp;      // reinitialiser la variable temp
//             char temp[5];

//             /*if (!*temp.isalpha()){

//             }*/
//         }
//     }
// }

// void BrowseFileV1(char file_name[], Patient patientsData[5000]){
//     /* Lit l'ensemble du fichier donne en argument ligne par ligne, et appelle la fonction
//     ParseLine pour analyser chaque ligne et ajouter les donnees au tableau patientsData*/
//     // Une partie de la fonction a ete recuperee sur GeeksforGeeks (https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/)

//     FILE* file = fopen(file_name, "r");

//     // Buffer to store each line of the file.
//     char line[256];

//     int i_patient = 0;

//     // Check if the file was opened successfully.
//     if (file != NULL) {
//         // Read each line from the file and store it in the
//         // 'line' buffer.
//         while (fgets(line, sizeof(line), file)) {
//             // Print each line to the standard output.
//             //printf("%s", line);
//             ParseLine(line, i_patient, patientsData);
//             i_patient ++;
//         }

//         // Close the file stream once all lines have been
//         // read.
//         fclose(file);
//     }
// }

// void AddValuesToPatientsData(Patient* p, char *tokens[]){
    // ChatGPT pour savoir qu'il faut mettre -> et pas .

    //printf("hello t'es la ouuuu ???\n");
    //printf("id : %d\n", *tokens[0]);
    // p->id = atoi(tokens[0]);
    // p->age = atoi(tokens[1]);
    // p->sex = tokens[2][0];
    // p->weight = atof(tokens[3]);
    // p->blood_pressure = atoi(tokens[4]);
    // p->average_heart_rate = atoi(tokens[5]);
    // p->blood_sugar = atof(tokens[6]);
    // p->cholesterol = atof(tokens[7]);
    // p->risk = BoolToInt(tokens[8]);
// }

// void PrintData(char* patientData){
//     printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s\n",
//             patientData[1], patientData[2], patientData[3], patientData[4], patientData[5], patientData[6], patientData[7]);
// }

// void AddValuesToPatientsData2(Patient* p, char *tokens[]){
    // p->physical_activity = atoi(tokens[1]);
    // p->alcohol_consumption = atof(tokens[2]);
    // p->caffeine_consumption = atof(tokens[3]);
    // p->sleep_quality = atof(tokens[4]);
// }


void BrowseFilePatients(char file_name[], char* PatientsData[MAX_PATIENTS][MAX_FIELDS]){

    //printf("test 1\n");

    FILE *file = fopen(file_name, "r");
    
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
    }

    int i_line = 0;
    char line[256];

    fgets(line, sizeof(line), file);    // lecture de la premiere ligne du fichier (nom des colonnes), qu'on ignore

    // Lire chaque ligne
    while (fgets(line, sizeof(line), file) && i_line < MAX_PATIENTS) {
        // Initialisation d'un nouveau patient
        //char* p[MAX_FIELDS];

        char* tokens[MAX_FIELDS];
        int field_index = 0;

        // Découper la ligne en tokens
        char *token = strtok(line, "$");
        while (token != NULL && field_index < MAX_FIELDS) {
            tokens[field_index++] = token;
            token = strtok(NULL, "$");

        }
        // if (i_line > 4995){//&& i_line < 120){
        //         //printf("length : %d\n", len)
        //         printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s\n",  tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6], tokens[7], tokens[8], tokens[9]);
        //     }

        // Ajouter le contenu de tokens au tableau de donnees
        for (int i=0; i<9; i++){
            PatientsData[i_line][i] = tokens[i+1];
        }

        //printf("Type de p[0] : %s\n", TYPE_DE_VARIABLE(p[0]));

        //if (strcmp(PatientsData[50][0], "50") == 0){
        //printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s\n",  PatientsData[i_line][0], PatientsData[i_line][1], PatientsData[i_line][2], PatientsData[i_line][3], PatientsData[i_line][4], PatientsData[i_line][5], PatientsData[i_line][6], PatientsData[i_line][7], PatientsData[i_line][8]);
        //}

        i_line++;
    }

    fclose(file);
}

void BrowseFileLivestyle(char file_name[], char* PatientsData[MAX_PATIENTS][MAX_FIELDS]){

    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
    }

    int i_line = 0;

    char line[256];

    fgets(line, sizeof(line), file);    // lecture de la premiere ligne du fichier (nom des colonnes), qu'on irgnore

    // Lire chaque ligne
    while (fgets(line, sizeof(line), file) && i_line < MAX_PATIENTS) {

        char *tokens[MAX_FIELDS];
        int field_index = 0;

        // Découper la ligne en tokens
        char *token = strtok(line, "$");
        while (token != NULL && field_index < MAX_FIELDS) {
            tokens[field_index++] = token;
            token = strtok(NULL, "$");
        }

        int i_patient = atoi(tokens[1]);
       
        // Assigner les valeurs via les indices
        for (int i=1; i<6; i++){
            PatientsData[i_patient-1][i+8] = tokens[i];
        }
        i_line++;
    }

    fclose(file);
}

/// Fonction main ///
/// Appel des fonctions declarees precedemment ///

int main(){

    // Creation du tableau PatientsData //
    // contenant toutes les informations de tous les patients //

    char* PatientsData[MAX_PATIENTS][MAX_FIELDS];
    //printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s\n",  PatientsData[0][0], PatientsData[0][1], PatientsData[0][2], PatientsData[0][3], PatientsData[0][4], PatientsData[0][5], PatientsData[0][6], PatientsData[0][7], PatientsData[0][8]);

    BrowseFilePatients("patients.pengu", PatientsData);

    //char* p = PatientsData[50];
    printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s\n",  PatientsData[50][0], PatientsData[50][1], PatientsData[50][2], PatientsData[50][3], PatientsData[50][4], PatientsData[50][5], PatientsData[50][6], PatientsData[50][7], PatientsData[50][8]);

    BrowseFileLivestyle("lifestyle.pengu",  PatientsData);
    //printf("id : %s | age : %s | sexe : %s | weight : %s | blood_pressure : %s | average_heart_rate : %s | blood_sugar : %s | cholesterol : %s | risk : %s | physical_activity : %s | alcohol_consumption : %s | caffeine_consumption : %s | sleep_quality : %s\n",  PatientsData[50][0], PatientsData[50][1], PatientsData[50][2], PatientsData[50][3], PatientsData[50][4], PatientsData[50][5], PatientsData[50][6], PatientsData[50][7], PatientsData[50][8], PatientsData[50][9], PatientsData[50][10], PatientsData[50][11], PatientsData[50][12]);
    //printf("%s\n", PatientsData[50][2]);

    return 0;
}