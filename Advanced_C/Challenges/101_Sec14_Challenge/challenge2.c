/*
*   Write a program that defines a macro that accepts two parameters and returns the sum of the given numbers
*/

#include <stdio.h>

#define ADD_NUMS(a, b) \ 
    ((a) + (b))

int main(void){
    __int32_t x, y;
    printf("Enter in a number: ");
        scanf("%d", &x);
        fflush(stdin);
    
    printf("Enter in another number: ");
        scanf("%d", &y);
        fflush(stdin);
    
    printf("Total: %d\n", ADD_NUMS(x,y));
}