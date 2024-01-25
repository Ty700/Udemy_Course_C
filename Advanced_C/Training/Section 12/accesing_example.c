#include <stdio.h>

union mixed{
    char c;
    float f;
    int i;
} *p_name;

//This example shows how to access both non-pointer and pointer union variables
//Also shows that you can only represent one 
int main(void){
    //Trying to show all ways of assigning values for a union
    union mixed random = {.f = 2.5};

    random.c = 'F';

    //Note: This prints 2.500017 for the float.
    //That is because the sizeof float is 4 and the sizeof char is 1.
    //When we overwrite the float data, we are only overwriting one byte of it.
    //Thus the other 3 are left untouched and still have some data attached, thus we get 

    printf("%ld %ld", sizeof(float), sizeof(char));
    printf("Float: %lf\nChar: %c\n", random.f, random.c);

    p_name = &random;
    p_name->f = 2.50;

    printf("Float: %lf\nChar: %c\n", p_name->f, p_name->c);
}