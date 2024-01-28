#include <stdio.h>

#define US 0
#define UK 1
#define France 2
#define Germany 3
#define COUNTRY US

int main(void){
    #if COUNTRY == US || COUNTRY == UK
        printf("Hello!\n");
    #elif COUNTRY == France
        printf("Bonjour\n");
    #elif COUNTRY == Germany
        printf("Guten Tag\n");
    #endif
}