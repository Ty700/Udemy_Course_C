/*
*   Pointer Arithmetic Challenge and Const modifier:
*       - Write a function that calculates a length of a string
*           - function should take a parameter of a const char pointer
*           - the function can only determine the length of a string using pointer arithmetic
*           - you are required to use a while loop using the value of the pointer to exit
*           - the function should subtract two pointers
*           - the function should return an int that is the length of the string passed into the function
*/

#include <stdio.h>

int customStringLength(const char* starting_location){ 
    const char* end_location = starting_location;

    while(*end_location){
        end_location += 1;
    }

    return end_location - starting_location;
}

int main(void){
    char str[] = "Tyler is a goofball";

    printf("%s has: %d characters\n", str, customStringLength(str));

    char str1[] = "";
    printf("%s has: %d characters\n", str1, customStringLength(str1));

}