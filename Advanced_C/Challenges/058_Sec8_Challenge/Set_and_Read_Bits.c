/*
*   Write a C program to input any number from a user
*       - the program should check whether nth bit of the given number is set (1) or not
*       - the program should set nth bit of the given number as 1
*
*
*
*   Example:
*       Enter any number: 10
*       Enter nth bit to check and set (0 - 31): 2
*       The 2 bit is set to: 0
*       
*       Bit set successfully.
*       
*       Number before setting 2 bit: 10
*       Number after setting 2 bit: 14
*/

#include <stdio.h>
#include <stdlib.h>

#define bool int
#define true 1
#define false 0

//Checking 32 bits
#define TOP_BIT_LIMIT 31
#define BOTTOM_BIT_LIMIT 0

//Collects a number from the user
int* CollectNumber(void){
    int* number = (int *)malloc(sizeof(int) * 1);
    printf("Enter any number: ");
        scanf("%d", number);
        fflush(stdin);
    
    return number;
}

//Checks to make sure the bit to check is within range
bool ValidBitCheck(int* bit){
    if((*bit > TOP_BIT_LIMIT) || (*bit < BOTTOM_BIT_LIMIT)){
        return false;
    } else {
        return true;
    }
}

//Collects bit to check from user
int* CollectNthBit(void){
    int* bitToCheck = (int *)malloc(sizeof(int) * 1);

    printf("Enter nth bit to check and set (0 - 31): ");
        scanf("%d", bitToCheck);
        fflush(stdin);

    //Checking to make sure nth bit is between 0 and 31
    while(1){
        if(ValidBitCheck(bitToCheck)){
            break;
        } else {
            printf("Error: Check Bit Out of Range.\n");
            printf("Enter nth bit to check and set (0 - 31): ");
                scanf("%d", bitToCheck);
                fflush(stdin);
        }
    }
    
    return bitToCheck;

}

//Checks to see if nth bit is 1
bool CheckNthBit(int* number, int* nthBit){
    if((*number & (1 << *nthBit)) == (1 << *nthBit)){
        return true;
    } else {
        return false;
    }
}

//Sets the nth bit to 1 in a given number
void SetNthBit(int* number, int* nthBit){
    *number |= (1 << *nthBit);
}

int main(void){
    int* currentUserNumber = CollectNumber();

    int* bitToCheck = CollectNthBit();

    if(CheckNthBit(currentUserNumber, bitToCheck)){
        printf("%dth bit is set to 1.\n", *bitToCheck);
    } else {
        printf("%dth bit is set to 0.\n\n", *bitToCheck);

        printf("\nBit set succesfully.\n\n");

        printf("Number before setting %d bit: %d\n", *bitToCheck, *currentUserNumber);

        SetNthBit(currentUserNumber, bitToCheck);

        printf("Number after setting %d bit: %d\n", *bitToCheck, *currentUserNumber);
        
    }

    free(currentUserNumber);
    free(bitToCheck);
}