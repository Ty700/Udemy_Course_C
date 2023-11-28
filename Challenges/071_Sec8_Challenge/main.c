/*
*
*   Create a C Program that uses a 2D array
*   Program will find the total rainfall for each year, average yearly rainfall, and the avg rainfall for each month
*   Input will be a 2D array with hard-coded values for rainfall amounts for the past 5 years
*   
*/

#include <stdio.h>

#define AMOUNT_OF_YEARS 5

int main(void){
    double rain[AMOUNT_OF_YEARS][13] = {
       //Jan  Feb  Mar  Apr  May  Jun  July Aug  Sept Oct  Nov  Dec
        {2010, 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6}, //Year 1
        {2011, 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3}, //Year 2
        {2012, 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4}, //Year 3
        {2013, 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2}, //Year 4
        {2014, 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}, //Year 5
    };

    double year_rain_totals[AMOUNT_OF_YEARS];

    double yearly_total = 0.0; 

    //YEAR TOTAL
    printf("YEAR\tRAINFALL  (inches)\n");
    for(int row = 0; row < AMOUNT_OF_YEARS; row++){
        yearly_total = 0.0;
        for(int col = 1; col < 13; col++){
            yearly_total += rain[row][col];
        }
        year_rain_totals[row] = yearly_total;
        printf("%.0lf\t  %.1lf\n", rain[row][0], yearly_total);
    }

    //YEAR AVERAGES
    double sum_of_years = 0.0;
    for(int i = 0; i < AMOUNT_OF_YEARS; i++){
        sum_of_years += year_rain_totals[i];
    }
    printf("\nThe yearly average is %.1lf inches\n", sum_of_years/AMOUNT_OF_YEARS);

    //MONTHLY AVERAGES
    printf("\nMonthly Averages:\n");
    printf("\nJan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    for(int col = 1; col < 13; col++){
        double monthly_average = 0.0;
        for(int row = 0; row < AMOUNT_OF_YEARS; row++){
            monthly_average += rain[row][col];
        }
        printf("%.1lf ", monthly_average / AMOUNT_OF_YEARS);
    }
    printf("\n");
}