#include <string.h>
#include <stdio.h>

int main(void){
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *pFound = NULL;
    pFound = strchr(str, ch); //Stores address of "quick brown fox".
    printf("%s\n", pFound);

    char text[] = "Every dog has his day.";
    char substr[] = "dog";
    char *pFound1 = NULL;
    pFound1 = strstr(text, substr);

    printf("%s\n", pFound1);

    char strToToken[] = "Hello - how are you - I am Tyler";
    const char s[] = " ";
    char *token;

    token = strtok(strToToken, s);

    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, s);
    }

    //So you can change const variables....
    const int number = 9;

    int *pNumber = &number;

    *pNumber = 10;

    printf("%d", number);
}