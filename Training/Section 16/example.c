#include <stdio.h>


int main(void){
    struct date{
        int month, day, year;
    };

    struct date today;

    today.year = 2023;
    today.month = 11;
    today.day = 25;

    printf("Current Date: %d %d, %d\n", today.month, today.day, today.year);
}