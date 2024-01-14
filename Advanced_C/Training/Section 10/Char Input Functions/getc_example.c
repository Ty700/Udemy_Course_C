//Example of getc

#include <stdio.h>

/* getc
*   - Prototype: int getc(FILE *stream);
*   - Purpose: Reads one character of the stream, and returns it
*       - This should depend on where the location of the fseek is
*       - He didn't mention this but pretty sure
*   
*   - Returns an int b/c characters are integers under the hood
*   - Can run it in a while loop, comparing it return value to EOF, to read entire file character by character
*/

int main(){
    char ch = '\0';

    ch = getc(stdin);

    printf("Read in character: %c\n", ch);

    //While loop example

    FILE* fp = fopen("Example.txt", "r");

    ch = getc(fp);

    while(ch != EOF){
        printf("%c", ch);
        ch = getc(fp);
    }

    printf("\n");
    fclose(fp);
}