/*
*
* Write a function to count the number of characters in a string
*   - can't use strlength()
*       - rather making strlength really

* Write a function to concat two strings
*   - can't use strcat()
*   - 3 parameters, result[], str1[], str2[]
*
* Write a function that compares two strings to see if they're equal
*   - returns a bool if T/F if equal/NotEqual
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int string_length(const char str[]);
char *string_cat(const char str1[], const char str2[]);
bool are_string_equal(const char str1[], const char str2[]);

int main(void){
    char str1[] = "Hello!";
    char str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!";
    char str1Copy[] = "Hello!";
    char result[100];
    char *allStrings[] = {str1, str2, str1Copy};

    //String Lenght
    for(int i = 0; i < 3; i++){
        printf("%s has %d characters!\n", allStrings[i], string_length(allStrings[i]));
    }

    //Cat
    printf("%s\n", string_cat(str1, str2));

    //Equality
    printf("%s and %s are equal: %s\n", str1, str2, (are_string_equal(str1, str2) == true) ? "true" : "false");
    printf("%s and %s are equal: %s\n", str1, str1Copy, (are_string_equal(str1, str1Copy) == true) ? "true" : "false");

    return 0;
}

int string_length(const char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i += 1;
    }
    return i;
}

char *string_cat(const char str1[], const char str2[]){
    const int STR1_LENGTH = string_length(str1);
    const int STR2_LENGTH = string_length(str2);

    char* result = (char*)malloc((STR1_LENGTH + STR1_LENGTH)); 

    int i = 0;
    
    while(i < STR1_LENGTH + STR2_LENGTH){
        if(i < STR1_LENGTH){
            result[i] = str1[i];
        } else {
            result[i] = str2[i - STR1_LENGTH];
        }
        i += 1;
    }
    return result;
}

bool are_string_equal(const char str1[], const char str2[]){
    if(string_length(str1) != string_length(str2)){
        return false;
    }

    for(int i = 0; i < string_length(str1); i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }

    return true;
}