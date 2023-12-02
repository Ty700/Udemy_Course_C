/*
*   Pointer Challenge
*       - Create, init, assign, and access a pointer
*       - Create an int var with a hard-coded value
*       - Assign that var's address to a pointer
*       - display as output the address of the pointer, the value of the pointer,
*           and the value of what the pointer is pointing to
*/

#include <stdio.h>
#include <stddef.h>

int main(void){

    // int *pNumber = NULL;
    // pNumber = &number;

    int number = 25;
    int *pNumber = &number;

    printf("Number: %d\n", number);
    printf("Number's address: %p\n", &number);
    printf("pNumber's address: %p\n", &pNumber);
    printf("pNumber value: %p\n", pNumber);
    printf("Value @ pNumber value: %d\n", *pNumber);

}