#include <stdio.h>

#define PRNT(a, b) \
    printf("Value 1 = %d\n", a); \
    printf("Value 2 = %d\n", b); 

#define PI 3.14
#define CIRCLE_AREA(X) ((PI) * (X) * (X))

int main(){
    PRNT(1,2);

    printf("Area: %.2f\n",CIRCLE_AREA(5));

}