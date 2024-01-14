//Example of putchar

#include <stdio.h>

/* putchar
*   - Prototype: int putchar(int char);
*   - Purpose: Write a character into the stdout and ONLY the stdout - identical to getchar
*
*   - the function putchar() enables you to write a single character to stdout
*       - takes one args:
*           - the character that is to be written into stdout
*/

//Example:

int main(void){
    char ch = '\0';

    FILE *from = fopen("From.txt", "r");

    while((ch = fgetc(from)) != EOF){
        putchar(ch);
    }

    putchar('\n');
    fclose(from);
}