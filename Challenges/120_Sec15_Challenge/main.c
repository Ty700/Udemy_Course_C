/*
*
*   Dynamic Memory Allocation Challenge
*       - write a program that allows user to input a text string.
*       - The program will print the text that was inputted.
*       - The program will utilize dynamic memory allocation.
*       - The user can enter the limit of string they are entering
*           - use this for malloc
*       - the program should create a char pointer only, no character arrays
*
*/

#include <stdio.h>
#include <stdlib.h>

//Says gets is dangerous. Not sure why :(
int main(void){
    int buffer = 0;

    printf("Enter the string length: ");
        gets(&buffer);
    
    char* strInputPtr = (char *)malloc(buffer * sizeof(char));
    
    if(strInputPtr != NULL){
        printf("Enter string: ");
            gets(strInputPtr);
            
        printf("Input: %s\n", strInputPtr);
    } else {
        printf("Error: Memory Allocation failed.\n");
    }

    free(strInputPtr);

    return 0;        
}