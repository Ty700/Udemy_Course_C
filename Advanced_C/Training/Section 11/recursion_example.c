#include <stdlib.h>
#include <stdio.h>

#define FAC_NUM 44

long long factorial(int n){
    unsigned long long result = 0;

    if(n){
        result = n * factorial(n-1);
    } else{
        result = 1;
    }
    return result;
}

int main(void){
    printf("%lld\n", factorial(FAC_NUM));
}