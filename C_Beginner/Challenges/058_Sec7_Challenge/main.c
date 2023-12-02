/*Create a C Program that calculates weekly pay
* - Ask user to enter # of hours worked
*Assumptions:
*   Basic Pay Rate = $12/hr
*   Overtime = $18/hr
*   Tax Rate:
*       15% of the first $300
*       20% of the next $150
*       25% of the rest
*
*   Compile: gcc main.c -lm -o main
*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define BASE_PAY 12
#define OVERTIME_PAY 18
#define STANDARD_WORK_HOURS 40

#define TAX_BRACKET1 300
#define TAX_BREAKET1_PERCENT 0.15
#define TAX_BRACKET2 150
#define TAX_BRACKET2_PERCENT 0.20
#define TAX_BRACKET3 450
#define TAX_BRAKCET3_PERCENT 0.25

int main(int argc, char *argv[]){
    double hours_work = 0;
    double amount_earned = 0;

    printf("Enter the number of hours worked: ");
        scanf("%lf", &hours_work);
        //Annoying
        char null_byte = getchar();
    
    while((hours_work <= 0) && !(isdigit(hours_work))){
        printf("Error: Invalid Entry.\n");
        printf("Enter the number of hours worked: ");
            scanf("%lf", &hours_work);
            //Annoying
            char null_byte = getchar();
    }

    if(hours_work > STANDARD_WORK_HOURS){
        amount_earned += OVERTIME_PAY * fmod(hours_work, STANDARD_WORK_HOURS);
        hours_work -= fmod(hours_work, STANDARD_WORK_HOURS);
    }

    amount_earned += BASE_PAY * hours_work;
    printf("Gross Income: %.2lf\n", amount_earned);

    double total_taxes = 0;

    //First 300
    if(amount_earned <= TAX_BRACKET1){
        total_taxes += amount_earned * TAX_BREAKET1_PERCENT;
    } else {
        total_taxes += TAX_BRACKET1 * TAX_BREAKET1_PERCENT;
        //Next 150
        if((amount_earned - TAX_BRACKET1) <= TAX_BRACKET2){
            total_taxes += (amount_earned - TAX_BRACKET1) * TAX_BRACKET2_PERCENT;
        } else {
            total_taxes += TAX_BRACKET2 * TAX_BRACKET2_PERCENT;
            //Rest
            if(amount_earned > TAX_BRACKET3){
                total_taxes += (amount_earned - (TAX_BRACKET3)) * TAX_BRAKCET3_PERCENT;
            }
        } 
    }
    printf("Taxes: %.2lf\nNet Income: %.2lf\n", total_taxes, (amount_earned - total_taxes));
} 