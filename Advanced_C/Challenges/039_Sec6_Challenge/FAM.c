/*
*   Flexible Array Member Challenge
*       - write a program that uses a flexible array member inside a struct
*       - create a struct named myArray that has a length member and a flexible array member named array
*       - read in from the user the size of the array at runtime
*       - allocate memory for the structure based on this size read in from the user
*       - set the length member and fill the array with some dummy data
*       - print the array elements
*/

#include <stdio.h>
#include <stdlib.h>

struct FAM {
    int arraySize;
    int array[];
};

int main(void){
    struct FAM *ptr;

    int sizeOfArray = 0;

    printf("Enter size for array: ");
        scanf("%d", &sizeOfArray);
    
    ptr = malloc(sizeof(struct FAM) + sizeOfArray * sizeof(int));

    ptr->arraySize = sizeOfArray;

    //Dummy Data
    for(int i = 0; i < ptr->arraySize; i++){
        ptr->array[i] = i;
    }

    for(int i = 0; i < ptr->arraySize; i++){
        printf("Element %d: %d\n", i, ptr->array[i]);
    }
    
    free(ptr);

}