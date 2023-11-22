//Converts mins => Years and days
/*

    Have a user input a number of minutes.

    Display the num of days and years that the mins are equivalent too

*/
#include <stdio.h>

#define DAYS_IN_MINS 1440
#define YEARS_IN_MINS 525600

int main(){
    double mins;

    printf("Enter in a number in minutes: ");
        scanf("%lf", &mins);

    printf("\n%.2lf mins is:\n", mins);
    printf("Days: %.2f\n", (mins / DAYS_IN_MINS));
    printf("Years: %.5f\n", (mins / YEARS_IN_MINS)); 
} 