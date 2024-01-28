/*
*   Write a program to find the square and cube of a number using macros
*/

#include <stdio.h>

#define SQUARE(x) ((x) * (x))

#define CUBE(x) ((x) * (x) * (x))

int main(void){
    __int32_t x = 0;

    printf("Enter in a number: ");
        scanf("%d", &x);
        fflush(stdin);
    
    printf("%d squared: %d\n", x, SQUARE(x));
    printf("%d cubed: %d\n", x, CUBE(x));
}