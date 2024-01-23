/*
* Write a program that creates a variadic function that will allow a programmer to add any amount of numbers
* that they would like to be added together.
* calling addingNumbers(2, 10, 20) should output 30
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define NUMBER_1 10
#define NUMBER_2 20
#define NUMBER_3 30
#define NUMBER_4 40

void AddingNumbers(int count, ...);

int main(void){

    AddingNumbers(2, NUMBER_1, NUMBER_2);
    AddingNumbers(3, NUMBER_1, NUMBER_2, NUMBER_3);
    AddingNumbers(4, NUMBER_1, NUMBER_2, NUMBER_3, NUMBER_4);
}

void AddingNumbers(int count, ...){
    __int32_t* const sum = (__int32_t *)malloc(sizeof(__int32_t) * 1);
    
    *sum = 0;
    
    __int32_t nextValue = 0;

    va_list arg;

    va_start(arg, (__int32_t)count);

    for(int i = 0; i < count; i++){
        nextValue = va_arg(arg, __int32_t);
        *sum += nextValue;
    }

    printf("Total: %d\n", *sum);

    free(sum);
    va_end(arg);
}

