#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void){
    FILE *pFile = NULL;
    char *fileName = "IDK.txt";
    pFile = fopen(fileName, "w");

    fclose(pFile);

    if(fclose == EOF){
        printf("Error Closing.");
        EXIT_FAILURE;
    }
    
    pFile = NULL;
}