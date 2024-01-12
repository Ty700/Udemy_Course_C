/*
*   Bit Manipulation Challenge 1
*       - write a function that converts a binary number to a numeric value
*       - if you have long long bin = 01001001;
*           - you can pass bin to a function as an argument to the function and have the function
*               return an int value of 73
*/

#include <stdio.h>
#include <math.h>

int binaryToDecimal(long long bin){
    int place = 0;
    int total = 0;
    
    while(bin){
        int current_bit = bin & 1;
        int current_bit_value = 0;

        if(current_bit == 1){
            current_bit_value = pow(2, place);
            total += current_bit_value;
        }

        place += 1; //Inc Place by 1.
        bin >>= 1; //Shift it right
    }

    return total;
}

long long decimalToBinary(long long number){
    long long binaryNumber = 0;
    int remainder, i = 1;

    while(number != 0){
        remainder = number % 2;
        number /= 2;
        binaryNumber += remainder * i;
        i *= 10;
    }
    return binaryNumber;
}

int main(void){
    long long bin = 0b01001001;
    printf("%d\n",binaryToDecimal(bin));
    printf("%lld\n", decimalToBinary(73));
}