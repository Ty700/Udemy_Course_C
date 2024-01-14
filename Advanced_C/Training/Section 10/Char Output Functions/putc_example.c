//Example of putc

#include <stdio.h>

/* put 
*   - Prototype: int putc(int char, FILE *stream);
*   - Purpose: Write a character into the file pointed to by stream
*
*   - the function putc() enables you to write a single character to a file (or to stdout)
*       - takes two args:
*           - the first being the character that is to be written into the file
*           - the second being the FILE pointer
*       - must first call fopen in write or append mode
*/

//Example:
int main(void){
    char ch = '\0';
    
    FILE *copy = fopen("From.txt", "r");
    FILE *paste = fopen("Example.txt", "w");

    while((ch = fgetc(copy)) != EOF){
        putc(ch, paste);
    }

    fclose(copy);
    fclose(paste);
}