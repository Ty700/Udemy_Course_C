//Example of fgetc

#include <stdio.h>

/* fgetc
*   - Prototype: int fgetc(FILE *stream);
*   - Purpose: Reads one character from a file, and returns it
*       - AND moves the fp location to the next character to read from
*       - Does getc not?
*   
*   - Returns an int b/c characters are integers under the hood
*   - Can run it in a while loop, comparing it return value to EOF, to read entire file character by character
*/

int main(void){
    FILE *fp = fopen("Example.txt", "r");

    char ch = '\0';

    printf("Reading the file Example.txt\n");

    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    
    printf("\n");
    fclose(fp);
}