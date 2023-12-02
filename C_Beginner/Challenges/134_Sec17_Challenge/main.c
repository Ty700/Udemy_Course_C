/*
*   Write a program to find the total numbers of lines in a text file
*       - create a file that contains some lines of text
*       - open your test file
*       - use the fgetc function to parse characters in a chile until until you get to the EOF
*       - display as output the total number of lines in the file
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(void){
    FILE *fp = fopen("fileToRead.txt", "r");

    int counter = 0;

    if(fp == NULL){
        perror("Error: Can't open file\n");
        EXIT_FAILURE;
    }

    while(fgetc(fp) != EOF){
        if(fgetc(fp) == '\n'){
            counter +=  1;
        }
    }

    fclose(fp);
    fp = NULL;

    printf("Total lines: %d\n", counter + 1);
    
}