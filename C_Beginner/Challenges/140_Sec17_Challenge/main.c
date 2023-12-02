/*
*   Write a program that will print the contents of a file in reverse order
*       - use the fseek function to seek to the end of the file
*       - use the ftell function to get the position of the file pointer
*       - display as output the file in reverse order
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int main(){
    FILE *filePointer = fopen("file.txt", "r+");

    fseek(filePointer, 0, SEEK_END);

    size_t filePointerSize = ftell(filePointer);
    size_t i = 0;

    while(i < filePointerSize){
        i += 1;
        fseek(filePointer, -i, SEEK_END);
        printf("%c", fgetc(filePointer));
    }
    
    printf("\n");

    fclose(filePointer);
}