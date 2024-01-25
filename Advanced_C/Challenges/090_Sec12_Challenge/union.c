/*
*   Write a progarm which will define a union and then use this union to assign and access its members
*       - you must define a union named student that consists of the following three elements
*           - char  letterGrade
*           - int   roundedGrade
*           - float exactGrade
*       
*       - your program should declare two union variables inside the main method (variable 1 and variable 2)
*
*       - your program should assing random values to varaible 1
*           - you then need to display each value for each member of this union
*           - you should notice that something is wrong
*
*       - your program should then assign a value using variable 2 to its member letter grade and then print it out
*       
*       - then assign a vallue using variable 2 then assign a value to its member exact grade and then print it out
*
*       - then assign a value to var 2 rounded grade and print it out
*/

#include <stdio.h>

union Student {
    char    letter_grade;
    int     rounded_grade;
    float   exact_grade;
} variable1, variable2;

int main(void){
    union Student variable1 = {.letter_grade = 'A', .rounded_grade = 95, .exact_grade = 95.3};

    printf("Variable 1:\n");
    printf("\tLetter Grade: %c\n\tRounded Grade: %d\n\tExact Grade: %f\n", 
            variable1.letter_grade, 
            variable1.rounded_grade, 
            variable1.exact_grade
        );

    printf("Variable 2:\n");
    variable2.letter_grade = 'A';
    
    printf("\tLetter Grade: %c\n", variable2.letter_grade);

    variable2.rounded_grade = 95;

    printf("\tRounded Grade: %d\n", variable2.rounded_grade);

    variable2.exact_grade = 95.3;

    printf("\tExact Grade: %f\n", variable2.exact_grade);
}