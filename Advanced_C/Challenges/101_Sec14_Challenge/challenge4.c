/*
*   Write a program to check whether a character is upper or lower case
*/

#include <stdio.h>
#include <ctype.h>

#define CASE_CHECK(ch) \
    if(isupper(ch)){ \
        printf("%c: Upper cased\n", ch); \
    } else { \
        printf("%c: Lower cased\n", ch); \
    }

int main(void){
    char test[10] = {'A', 'b', 'C', 'd', 'e', 'f', 'G', 'h', 'I', 'J'};

    for(int i = 0; i < 10; i++){
        CASE_CHECK(test[i]);
    }
}