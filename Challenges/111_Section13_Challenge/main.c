/*
*   Pass by reference challenge
*       - write a function that square a number by itself
*           - the function should define as a parameter an int pointer
*/

#include <stdio.h>

void SquareNum(int* pNumber);

int main(void){

    int num1 = 5;
    int* pNum1 = &num1;

    SquareNum(pNum1); 

    printf("%d\n", *pNum1);

}

void SquareNum(int* pNumber){
    if(pNumber){
        *pNumber *= *pNumber;
    } else {
        printf("Error: Pointer is NULL.\n");
        return;
    }
}


// Well that doesn't work
// void SquareNum(void* pNumber){
//     if(pNumber == 0){
//         printf("Error: Pointer is Null.\n");
//         return;
//     }

//     if(sizeof(pNumber) == sizeof(int)){
//         *(int *)pNumber *= *(int *)pNumber;
//     } else if(sizeof(pNumber) == sizeof(double)){
//         *(double *)pNumber *= *(double *)pNumber;
//     } else if(sizeof(pNumber) == sizeof(float)){
//         *(float *)pNumber *= *(float *)pNumber;
//     } else {
//         printf("Error: Argument passed is not a number.");
//     }
// }