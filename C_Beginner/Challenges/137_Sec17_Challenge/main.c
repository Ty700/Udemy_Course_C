/*
*   Write a program that converts all characters of a file to uppercase and write the results out to a temp file.
*       - Then rename the temp file to the original filename and remove the temp filename
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

#define COPY_FILE "originalFile.txt"
#define PASTE_FILE "originalFileCopy.txt"

int main(void){

    printf("Creating File: %s\n", PASTE_FILE);

    FILE *copyFilePointer = fopen(COPY_FILE, "r");
    FILE *writeFilePointer = fopen(PASTE_FILE, "w");

    if(copyFilePointer == NULL){
        perror("Error: Can't open file\n");
        EXIT_FAILURE;
    }

    if(writeFilePointer == NULL){
        perror("Error: Can't open file\n");
        EXIT_FAILURE;
    }

    int ch;

    while((ch = fgetc(copyFilePointer)) != EOF){
        if(islower(ch) && isalpha(ch)){
            ch = toupper(ch);
            fputc(ch, writeFilePointer);
        } else {
            fputc(ch, writeFilePointer);
        }
    }

    fclose(copyFilePointer);
    fclose(writeFilePointer);

    copyFilePointer = NULL;

    printf("Removing File: %s\n", COPY_FILE);
    remove(COPY_FILE);

    printf("Renaming %s to %s\n", PASTE_FILE, COPY_FILE);
    rename(PASTE_FILE, COPY_FILE);

    writeFilePointer = fopen(COPY_FILE, "r");

    printf("%s contains: ", PASTE_FILE);
    while((ch = fgetc(writeFilePointer)) != EOF){
        printf("%c", ch);
    }
    printf("\n");
}
