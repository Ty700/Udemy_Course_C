/*
*   Variable Length Array Challenge
*       - Write a program to read elements in an array and find the sum of array elements
*       - Don't know in advance how many elements there will be
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sumArrayElements(const int arrToSum[], const int size){
    int total = 0;
    for(int i = 0; i < size; i++){
        total += arrToSum[i];
    }

    printf("Total of elements: %d\n", total);
}

void captureArrayElements( int arr[], const int size){
    for(int i = 0; i < size; i++){
        int element = 0;
        printf("Enter value for element %d: ", i+1);
            scanf("%d", &element);
            arr[i] = element;
            fflush(stdin);
    }
}

int main(int argc, char* argv[]){
    int size1 = 0;
    int* p_size1 = &size1;

    printf("Enter number of elements: ");
        scanf("%d", &size1);
        fflush(stdin);

    int arr[*p_size1];

    captureArrayElements(arr, *p_size1);

    sumArrayElements(arr, *p_size1);

    //2nd Run
    captureArrayElements(arr, *p_size1);

    sumArrayElements(arr, *p_size1);

}