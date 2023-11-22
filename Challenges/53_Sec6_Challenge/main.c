//Print the byte size of the basic data types supported in c

#include <stdio.h>

int main(){

    printf("int: %zd bytes\ndouble: %zd bytes\nchar: %zd bytes\nfloat: %zd bytes\nlong: %zd bytes\nlong long: %zd bytes\nlong double: %zd bytes \n",
            sizeof(int), sizeof(double), sizeof(char), sizeof(float), sizeof(long), sizeof(long long), sizeof(long double));

    return 0;
}