#include <stdio.h>

//#define ENABLE_DEGUGGING
#define LIMIT 4

int main(void){
    int total = 0;

    for(int i = 0; i < LIMIT; i++){
        total += 2 * i * i;
        
        #ifdef ENABLE_DEGUGGING
            printf("DEGBUG: i = %d, running total = %d\n", i, total); //DEGBUG
        #endif
    }

    printf("Grand Total: %d\n", total);
}