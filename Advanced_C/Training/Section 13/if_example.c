#include <stdio.h>

#define MYDEF 5
#define OTHERDEF 2

int main(void){
    #if MYDEF == 5 && OTHERDEF == 2
        printf("Hello\n");
    #endif
}