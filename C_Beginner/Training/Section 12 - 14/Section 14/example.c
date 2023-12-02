#include <stdio.h>
#include <string.h>

// int main(void){
//     char multiple[] = "a string";
//     char *p = multiple;

//     for(int i = 0; i < strlen(multiple); i++){
//         printf("multiple[%d] = %c | *(p + %d) = %c | ", i, multiple[i], i, *(p+i));
//         printf("&multiple[%d] = %p | p + %d = %p | \n", i, &multiple[i], i, p + i);
//     }
// }

// Example that copies a string using an array
//These do the same thing

void copyString(char to[], char from[]){

    int i = 0;
    for(i; from[i] != '\0'; ++i){
        to[i] = from[i];
    }

    to[i] = '\0';
}

void copyString2(char *to, char *from){
    //Don't need to declare an i since we have pointers and want to go until 
    //end of string for from
    for( ; *from != '\0'; ++from, ++to){
        *to++ = *from++;
    }
    *to = '\0';
}

//Since we didn't need to init an iterator, just make a while loop:

void copyString3(char *to, char *from){
    while(*from){ //Since NULL = 0
        *to++ = *from++;
    }
    *to = '\0';
}

int main(void){
    char string1[] = "A string to be copied.";
    char string2[50];

    copyString3(string2, string1);
    printf("%s\n", string2);

}