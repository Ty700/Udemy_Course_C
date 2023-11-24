/*
*
*   Write a function that displays a string in reverse order
*    - should read input from the keyboard
*    - need to use strlen() func
*
*   Write a function that sorts the strings of an array using a bubble sort
*       - need to use the strcmp and strcpy functions
*
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse_string(char reversed_result[], const char input[]);
void sort_strings(char *strings_to_sort[], int arr_size);

int main(void){

    char input[100];

    printf("Enter in a string: ");
        scanf("%s", input);
    
    char reversed_result[100];

    reverse_string(reversed_result, input);
    printf("%s reveresed is: %s\n", input, reversed_result);

    int arr_size = 0;
    printf("Enter number of strings to sort: ");
        scanf("%d", &arr_size);
    
    char *str_to_sort[arr_size];

    for(int i = 0; i < arr_size; i++){
        char str_to_insert[100];
        printf("Enter string #%d: ", i+1);
            scanf("%s", str_to_insert);

        str_to_sort[i] = malloc(strlen(str_to_insert) + 1);

        strncpy(str_to_sort[i], str_to_insert, strlen(str_to_insert));
    }   

    sort_strings(str_to_sort, arr_size);

    for(int i = 0; i < arr_size; i++){
        printf("%s", str_to_sort[i]);
    }
    printf("\n");
    return 0;
}

void reverse_string(char reversed_result[], const char input[]){
    for(int i = 0; i < strlen(input); i++){
        reversed_result[i] = input[(strlen(input) - 1) - i];
    }
    reversed_result[strlen(input)] = '\0';
}

void sort_strings(char *strings_to_sort[], int arr_size) {
    for (int i = 0; i < arr_size - 1; i++) {
        for (int j = 0; j < arr_size - i - 1; j++) {
            if (strcmp(strings_to_sort[j], strings_to_sort[j + 1]) > 0) {
                char *temp = strings_to_sort[j];
                strings_to_sort[j] = strings_to_sort[j + 1];
                strings_to_sort[j + 1] = temp;
            }
        }
    }
}