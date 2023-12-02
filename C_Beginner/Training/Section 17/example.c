#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE *pFile = NULL;
    char *fileName = "IDK.txt";
    pFile = fopen(fileName, "w");

    fclose(pFile);

    if(fclose == EOF){
        printf("Error Closing.");
        EXIT_FAILURE;
    }
    
    pFile = NULL;
}

//Reads file (by chars) and prints what is in it
// int main(){
//     FILE *fp = NULL;
//     int c;

//     fp = fopen("File_IO.txt", "r");

//     if(fp == NULL){
//         perror("Error in opening file");
//         EXIT_FAILURE;
//     }

//     while((c = fgetc(fp)) != EOF){
//         printf("%c", c);
//     }

//     fclose(fp);
//     fp = NULL;
//     return 0;
// }


//Reads file (by strings) and prints what is in it -- notice it doesn't find the "yo"
// int main(void){
//     FILE *fp = fopen("IDK.txt", "r");
//     char str[5];

//     if(fp == NULL){
//         perror("Error opening file\n");
//         return EXIT_FAILURE;
//     }

//     if(fgets(str, sizeof(str) - 1, fp) != NULL){
//         printf("%s", str);
//     }

//     printf("\n");

// }   

//fscanf() example
// int main(){
//     char str1[10], str2[10], str3[10];
//     int year;
//     FILE* fp = fopen("file.txt", "w+");

//     if(fp != NULL){
//         fputs("Hello how are 1000", fp);
//     }

//     rewind(fp);

//     fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

//     printf("Read String 1 |%s|\n", str1);
//     printf("Read String 2 |%s|\n", str2);
//     printf("Read String 3 |%s|\n", str3);
//     printf("Read Integer |%d|\n", year);
// }

//fputs() and fputc() example + my own sprintf example
int main(){
    FILE *fp = fopen("file.txt", "w+");
    int ch;
    
    for(ch = 33; ch <= 100; ch++){

        char str[6];
        sprintf(str, "%d: ", ch);
        fputs(str, fp);
        fputc(ch, fp);
        fputc('\n', fp);
    }

    fclose(fp);
    return 0;
}