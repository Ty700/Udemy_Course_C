/*
*   Write a program to convert uppercase to lowercase and vice versa in file
*       - This program can take a command-line argument for the name of the file or you can ask the user for the name of the file
*       - Will need to create a temporary file to store the result (converted character)
*           - can then rename this temp file back to the original file
*       - You will need to use the isupper(ch) to check for upper or lower case characters
*/
#include <stdio.h>
#include <ctype.h>

void InvertCase(FILE* fp, char* fileName){
    //Temp File
    FILE *p_newFile = fopen("temp.txt", "w");

    char ch = '\0';
    while((ch = fgetc(fp)) != EOF){
        if(isalpha(ch)){
            if(isupper(ch)){
                ch = tolower(ch);
                fputc(ch, p_newFile);
            } else {
                ch = toupper(ch);
                fputc(ch, p_newFile);
            }
        } else {
            fputc(ch, p_newFile);
        }
    }
    fclose(p_newFile);
}

int main(int argc, char* argv[]){
    FILE *fp = NULL;

    if(argc != 1){
        fp = fopen(argv[1], "r");
        InvertCase(fp, argv[1]);
    } else {
        char buf[100];

        printf("Enter name of the file with extension: ");
            scanf("%s", buf);

        fp = fopen(buf, "r");    

        InvertCase(fp, buf);
    }

    fclose(fp);
}