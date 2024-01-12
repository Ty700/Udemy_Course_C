/* 
*   Write a program taht reads two integers from the user
*       - program will print the results of applying:
*           - ~ operator to each number
*           - the &, |, and ^ operators to the pair
*           - the << and >> operations to a specific number
*           - shows the result as binary strings (need to write a decimalToBinary function)
*           
*/

#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 2
#define SHIFT_LEFT 4
#define SHIFT_RIGHT 4

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

void CollectUserNumbers(int arr[]){
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("Enter number: ");
            scanf("%d", &arr[i]);
        fflush(stdin);
    }
    printf("\n");
}

void PrintNotOperator(int arr[]){
    for(int i = 0; i < ARRAY_SIZE; i++){
        int currentDecimal = ~arr[i];
        printf("!%d:\n\tDecimal: %d\n\tBinary:  %lld\n", arr[i], currentDecimal, decimalToBinary(currentDecimal));
    }
    printf("\n");
}

void PrintAndOperator(int arr[]){
    int currentDecimal = arr[0] & arr[1];
    //Converting to binary to make it easier to understand what it being actually being compared
    printf("%d & %d => %lld & %lld:\n\t",arr[0], arr[1], decimalToBinary(arr[0]), decimalToBinary(arr[1]));
    //Result
    printf("Decimal: %d\n\tBinary:  %lld\n\n", currentDecimal, decimalToBinary(currentDecimal));
}

void PrintOrOperator(int arr[]){
    int currentDecimal = arr[0] | arr[1];
    //Converting to binary to make it easier to understand what it being actually being compared
    printf("%d | %d => %lld | %lld:\n\t",arr[0], arr[1], decimalToBinary(arr[0]), decimalToBinary(arr[1]));
    //Result
    printf("Decimal: %d\n\tBinary:  %lld\n\n", currentDecimal, decimalToBinary(currentDecimal));
}

void PrintXorOperator(int arr[]){
    int currentDecimal = arr[0] ^ arr[1];
    //Converting to binary to make it easier to understand what it being actually being compared
    printf("%d ^ %d => %lld ^ %lld:\n\t",arr[0], arr[1], decimalToBinary(arr[0]), decimalToBinary(arr[1]));
    //Result
    printf("Decimal: %d\n\tBinary:  %lld\n\n", currentDecimal, decimalToBinary(currentDecimal));   
}

void PrintShiftOperator(int arr[]){
    for(int i = 0; i < ARRAY_SIZE; i++){
        long long currentDecAsBin = arr[i];

        long long shiftedRightDecimal = currentDecAsBin >> SHIFT_RIGHT;
        long long shiftedLeftDecimal = currentDecAsBin << SHIFT_LEFT;

        int shiftedRightBinary = decimalToBinary(shiftedRightDecimal);
        int shiftedLeftBinary = decimalToBinary(shiftedLeftDecimal);

        // printf("shiftedRightBinary: %lld\nshiftedLeftBinary: %lld\n\n", shiftedRightBinary, shiftedLeftBinary);

        printf("%d => %lld:\n", arr[i], decimalToBinary(arr[i]));
        printf("\t%lld >> %d = %d => %lld\n",   decimalToBinary(arr[i]), SHIFT_RIGHT, shiftedRightBinary, shiftedRightDecimal);
        printf("\t%lld << %d = %d => %lld\n\n", decimalToBinary(arr[i]), SHIFT_LEFT,  shiftedLeftBinary,  shiftedLeftDecimal);
    }
}

int main(){
    int arr[ARRAY_SIZE];    

    CollectUserNumbers(arr);
    //!
    PrintNotOperator(arr);
    //&
    PrintAndOperator(arr);
    //|
    PrintOrOperator(arr);
    //^
    PrintXorOperator(arr);
    //<< and >>
    PrintShiftOperator(arr);


}