#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


/// Construction de la structure de donnees Patient ///
/// contenant toutes les informations sur un patient donne ///

        //id, age, sex, weight, blood_pressure, average_heart_rate, blood_sugar, cholesterol, risk
        //physical_activity, alcohol_consumption, caffeine_consumption, sleep_quality

typedef struct Patient{ 
    int id;
    int age;
    char sex;
    float weight;
    int blood_pressure;
    int average_heart_rate;
    float blood_sugar;
    float cholesterol;
    int physical_activity;
    float alcohol_consumption;
    float caffeine_consumption;
    float sleep_quality;
    int risk;   // il faudra transformer les True/False en 1/0
} Patient;

// Structure enum contenant les champs de la structure Patient //
// necessaire pour le remplissage des donnees dans PatientsData


typedef enum Patients_info{
    id = 1, age = 2, sex = 3, weight = 4, blood_pressure = 5, average_heart_rate = 6, blood_sugar = 7, cholesterol = 8,
    physical_activity = 9, alcohol_consumption = 10, caffeine_consumption = 11, sleep_quality = 12, risk = 13
} Patients_info;


/// Fonctions pour analyser chaque ligne du fichier et construire la structure de donnees ///


int countLinesInFile(char file_name[]){
    /* Retourne le nombre de lignes d'un fichier */

    int nb_lines;

    // corre de la fonction

    return nb_lines;
}

float CharToFloat(char array[], size_t length){
    /// Bout de code ChatGPT ===>>> a modifier ensuite

    // Ajouter un caractère nul à la fin pour transformer en chaîne
    char str[length + 1]; // +1 pour le '\0'
    memcpy(str, array, length); // Copier les caractères
    str[length] = '\0'; // Ajouter '\0' à la fin

    // Convertir la chaîne en flottant
    float value = strtof(str, NULL);

    return value;
}

int CharToInt(char array[], size_t length){

    char str[length + 1];
    memcpy(str, array, length);
    str[length] = '\0';
    int value = strtol(str, NULL, 10);

    return value;
}

int IsFloat(char value[]){
    /* Si un des caracteres est un '.', alors il s'agit d'un float, la fonction retourne 1.
        Sinon, elle retourne 0. */

    int length = strlen(value);

    for (int i=0; i<length; i++){
        if (value[0] == '.'){
            return 1;
        }
    }

    return 0; // si aucun '.' n'a ete trouve, retourne 0 (ce n'est pas un float)
}

int BoolToInt(char value[]){
    /* Prend en argument un booleen (chaine de caracteres "True" ou "False")
    et renvoie 0 (False) ou 1 (True) */

    if (value == "True"){
        return 1;   
    }
    else {
        return 0;
    }

}

void AddValueToPatientData(char value[], Patient *p, Patients_info info, str /* pas le bon type */ champs){
    /* Prend en argument une chaine de caracteres, convertie son type et l'ajoute aux donnees des patients */

    int length = strlen(value);

    if (isalpha(value[0])){     // si le premier caractere est un caractere alphabetique

        if (length == 1){   // si la chaine de caracteres est composee d'un seul caractere (cas unique du sexe : 'F' ou 'M')
            (*p).sex = value[0];
        }
        else {      // cas unique du risque ("True" ou "False")
            (*p).risk = BoolToInt(value);
        }
    }

    else {  // si le permier caractere est un chiffre

        if (IsFloat(value)){    // si c'est un float
            float val = CharToFloat(value, length);
        }
        else {  // si c'est un entier
            int val = CharToInt(value, length);
        }
        p.champs = val;
    }
}



//!\\ soit faire 2 fonctions ParseLine pour les 2 fichiers a parser, soit donner en argument les champs a remplir, soit autre chose
void ParseLine(char line[], int i_patient, Patient patientsData[5000]){
    /* Utilise les caracteres $ pour separer les donnees d'une ligne donnee en argument et les ajouter aux donnees des patients */

    int length = strlen(line);
    //char *temp;  // initialisation d'une chaine de caracteres, qui contiendra les donnees de la ligne
    char temp[5];  // initialisation d'une chaine de caracteres, qui contiendra les donnees de la ligne

    char *value;
    float result = strtol(temp, &value, 10);

    int i_line = 0;
    int i_val = 0;
    int i_champs = 0;   // indice du champs en train d'etre traite

    while (i_line<length){   // analyse de chaque caractere de la ligne

        if (line[i_line] != '$'){   // si le caractere est un $ (separateur)
            //AddValueToPatientData(temp, &patientsData[i_patient],);
            i_champs++;
            char temp[5];   // reinitialisation de temp
        }
        else {      // si ce n'est pas un separateur, c'est un caractere des donnees d'un patient

            temp[i_val] = line[i_line];     // ajouter ce caractere a temp
            i_val++;
        }
        i_line++;

 
        if (line[i_line] == '$' || line[i_line] == '\n'){    // si le caractere est un $ (separateur) ou une fin de ligne
        
            //char *temp;      // reinitialiser la variable temp
            char temp[5];

            /*if (!*temp.isalpha()){

            }*/
        }
    }

    // corre de la fonction
}

void BrowseFile(char file_name[], Patient patientsData[5000]){
    /* Lit l'ensemble du fichier donne en argument ligne par ligne, et appelle la fonction
    ParseLine pour analyser chaque ligne et ajouter les donnees au tableau patientsData*/
    // Une partie de la fonction a ete recuperee sur GeeksforGeeks (https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/)

    FILE* file = fopen(file_name, "r");

    // Buffer to store each line of the file.
    char line[256];

    int i_patient = 0;

    // Check if the file was opened successfully.
    if (file != NULL) {
        // Read each line from the file and store it in the
        // 'line' buffer.
        while (fgets(line, sizeof(line), file)) {
            // Print each line to the standard output.
            //printf("%s", line);
            ParseLine(line, i_patient, patientsData);
            i_patient ++;
        }

        // Close the file stream once all lines have been
        // read.
        fclose(file);
    }

}

/// Fonction main ///
/// Appel des fonctions declarees precedemment ///

int main(){

    const char *info[] = {"id", "age", "sex", "weight", "blood_pressure", "average_heart_rate", "blood_sugar", "cholesterol",
                        "physical_activity", "alcohol_consumption", "caffeine_consumption", "sleep_quality", "risk"};


    // Creation du tableau patientsData //
    // contenant toutes les informations de tous les patients //

    Patient patientsData[5000]; // aller chercher le nombre de lignes dans patients.pengu (fonction countLinesInFile()) => -1

    //BrowseFile("patients.pengu");
    //BrowseFile("lifestyle.pengu");
    
    return 0;
}