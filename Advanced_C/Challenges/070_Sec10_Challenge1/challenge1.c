/*
*   Write a program in C to count the number of words and characters in a file OR from standard input
*       - This program can take zero cmd line args, or 1
*           - If there is one arg, it is interpreted as the name of a file
*           - If there is no arg, the stdin is the be used as the input
*/
#include <stdio.h>
#include <ctype.h>

void WordCount(FILE* fp){
    char ch = fgetc(fp);

    //If first character in text is alpha, starts word count at 1, else 0
    int wordCounter = (isalpha(ch)) ? 1 : 0;

    while(ch != EOF){
            //Looks for spaces
            if(isspace(ch)){
                //Skips all sequential spaces
                while(isspace(ch)){
                    ch = fgetc(fp);
                }
                //If the character after the last skipped space is alpha, inc word counter
                if(isalpha(ch)){
                    wordCounter += 1;
                }
            }
            ch = fgetc(fp);
        }
    printf("Word Count: %d\n", wordCounter);
}

void CharacterCount(FILE* fp){
    char ch = fgetc(fp);

    int chCounter = 0;

    while(ch != EOF){
        if(ch == '\n' || isspace(ch)){
            ch = fgetc(fp);
            continue;
        }
        chCounter += 1;
        ch = fgetc(fp);
    }
    printf("Character Count: %d\n", chCounter);
}

int main(int argc, char *argv[]){
    FILE *fp = NULL;
    
    //Always one arg regardless, so checking if there is more than one
    if(argc != 1){
        fp = fopen(argv[1], "r");
    } else {
        fp = fopen("text.txt", "r");
    }

    WordCount(fp);
    rewind(fp); //Haven't learned about this yet BUT am using it anyways since I found it in the man pages
    CharacterCount(fp);
}