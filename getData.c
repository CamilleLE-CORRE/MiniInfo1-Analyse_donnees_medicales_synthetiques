#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>




int main(){
    
    FILE* file = fopen("test.txt", "r");

    // Buffer to store each line of the file.
    char line[256];

    // Check if the file was opened successfully.
    if (file != NULL) {
        // Read each line from the file and store it in the
        // 'line' buffer.
        while (fgets(line, sizeof(line), file)) {
            // Print each line to the standard output.
            printf("%s", line);
        }

        // Close the file stream once all lines have been
        // read.
        fclose(file);
    }
    return 0;
}