//Example of getchar

#include <stdio.h>

/* getchar 
*   - Prototype: int getchar(void);
*   - Purpose: Reads one character of stdin, and returns it
*   - Differs from getc b/c getc can be used for any inptut stream, getchar only reads from stdin
*
*   - Returns an int b/c characters are integers under the hood
*   - Can run it in a while loop, comparing it return value to EOF, to read entire file character by character
*   - Very similar to getc
*/

int main(){
    printf("Entered character: %c\n", getchar());

    //If you are gonna use getchar in a while loop, you must compare EOF to an int and not a char like getc
    //Not sure why since running it with char ch = 0 just fine - he said it has unpredictable results on other systems.

    //Example:
    int ch = 0;

    while((ch = getchar()) != EOF){
        printf("%c", ch);
    }
}
