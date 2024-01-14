//Example of ungetc

#include <stdio.h>
#include <ctype.h>
/* ungetc
*   - Prototype: int ungetc(int chToPushback, FILE *stream);
*   - Purpose: Pushes characters BACK into an input stream
*       - Have to read in a character first in order for it to be pushed back.
*   
*   - Returns an int that corresponds with what character was pushed back
*   - Can push a succession of characters, but only one is guarnteed.
*   - Useful for reading character by character without knowing how many characters make up a data unit
*   
*/

int main(void){
    char ch = '\0';
    FILE *fp = fopen("Example.txt", "r");

    while((ch = getc(fp)) != EOF){
        printf("%c", ch);
        while(isspace(ch = getc(fp)));

        //The first non-space character will be thrown back into the stream to be read again.
        //Since the program already read the character to evaluate if it is a space or not, it needs to be put back into the stream
        //To be reread and printed
        ungetc(ch, fp);
    }
    printf("\n");
    fclose(fp);

}