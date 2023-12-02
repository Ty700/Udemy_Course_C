#include <stdio.h>

int main(int argc, char* argv[]){
    int numOfArgs = argc;
    
    char *nameOfProgram = argv[0];
    char *arg1 = argv[1];
    char *arg2 = argv[2];

    printf("argc: %d\nargv[0]: %s\nargv[1]: %s\nargv[2]: %s\n", argc, nameOfProgram, arg1, arg2);
}