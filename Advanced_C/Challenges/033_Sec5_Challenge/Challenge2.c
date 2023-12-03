/*
*
*       Storage Class Challenge 2
*           - write a C program that finds the sum of various numbers
*           - you cannot pass any varaible representing the running total to the sum function
*           Example:
*               sum(25) => output 25
*               sum(15) => output 40
*               sum(30) => output 70
*/

#include <stdio.h>

static int sum(const int* num){
    static int total = 0;
    total += *num;
    return (total);
}

int main(){
    int x = 25;
    int y = 15;
    int z = 30;

    printf("%d\n", sum(&x));
    printf("%d\n", sum(&y));
    printf("%d\n", sum(&z));
}