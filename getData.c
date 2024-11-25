#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/// Construction de la structure de donnees Patient ///
/// contenant toutes les informations sur un patient donne ///

        //id$age$sex$weight$blood_pressure$average_heart_rate$blood_sugar$cholesterol$risk
        //physical_activity$alcohol_consumption$caffeine_consumption$sleep_quality

typedef struct Patient{
    int id;
    int age;
    char sex[1];
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



/// Fonctions pour analyser chaque ligne du fichier et construire la structure de donnees ///


int countLinesInFile(char file_name[]){
    /* Retourne le nombre de lignes d'un fichier */

    int nb_lines;

    // corre de la fonction

    return nb_lines;
}



//!\\ soit faire 2 fonctions ParseLine pour les 2 fichiers a parser, soit donner en argument les champs a remplir, soit autre chose
void ParseLine(char line[]){
    /* Utilise les caracteres $ pour separer les donnees d'une ligne donnee en argument et les ajouter aux donnees des patients */

    int length = strlen(line);
    char *temp;  // initialisation d'une chaine de caracteres, qui contiendra les donnees de la ligne

    char *value;
    float result = strtol(temp, &value, 10);


    for (int i=0; i<length; i++){   // analyse de chaque caractere de la ligne
        if (line[i] == '$' || line[i] == '\n'){    // si le caractere est un $ (separateur) ou une fin de ligne
        
            if (*temp == "True"){
                *temp = "1";
            }
            else if (*temp == "False"){
                *temp = "0";
            }
            char *temp;      // reinitialiser la variable temp

            /*if (!*temp.isalpha()){

            }*/
        }
    }

    // corre de la fonction
}

void BrowseFile(char file_name[]){
    /* Lit l'ensemble du fichier donne en argument ligne par ligne, et appelle la fonction
    ParseLine pour analyser chaque ligne et ajouter les donnees au tableau patientsData*/
    // Une partie de la fonction a ete recuperee sur GeeksforGeeks (https://www.geeksforgeeks.org/c-program-to-read-contents-of-whole-file/)

    FILE* file = fopen(file_name, "r");

    // Buffer to store each line of the file.
    char line[256];

    // Check if the file was opened successfully.
    if (file != NULL) {
        // Read each line from the file and store it in the
        // 'line' buffer.
        while (fgets(line, sizeof(line), file)) {
            // Print each line to the standard output.
            //printf("%s", line);
            ParseLine(line);
        }

        // Close the file stream once all lines have been
        // read.
        fclose(file);
    }

}

/// Fonction main ///
/// Appel des fonctions declarees precedemment ///

int main(){

    // Creation du tableau patientsData //
    // contenant toutes les informations de tous les patients //

    Patient patientsData[5000]; // aller chercher le nombre de lignes dans patients.pengu (fonction countLinesInFile()) => -1

    BrowseFile("patients.pengu");
    BrowseFile("lifestyle.pengu");
    
    return 0;
}