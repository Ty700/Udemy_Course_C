#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int main(void){
    char *str = NULL;

    str = (char* )malloc(10 * sizeof(char));
    strcpy(str, "tyler");
    printf("String = %s, Address = %p\n", str, str);

    //Realizing 15 bytes isn't big enough
    str = (char *)realloc(str, 25 * sizeof(char));
    
    if(str){
        strcat(str, ".com");
        printf("String = %s, Address = %p\n", str, str);
    } else {
        printf("Error: Memory allocation failed\n");
    }

    free(str);
}