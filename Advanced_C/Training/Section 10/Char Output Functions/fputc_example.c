//Example of fputc

#include <stdio.h>

/* fputc
*   - Prototype: int fputc(int char, FILE *stream);
*   - Purpose: Write a character into the file pointed to by stream at the file pointer location
*
*       - Identical to fgetc, but output
*/

//Example:

int main(void){
    FILE *fp = fopen("Example_fputc.txt", "w");

    for(char ch = 'A'; ch <= 'Z'; ch++){
        fputc(ch, fp);
        fputc(ch, stdout);
        if(ch == 'Z'){
            fputc('\n', stdout);
            fputc('\n', fp);
        }
    }

    fclose(fp);
}