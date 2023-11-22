/*
*   Display all the prime numbers from 0 - 100
*   - No input
*
*   Create an array that stores all prime numbers
*   Print them out - for loop
*/

#include <stdio.h>

#define MIN_BOUNDARY 3
#define MAX_BOUNDARY 200 
#define SIZE_OF_ARRAY 100 //Did this for when I increase MAX_BOUNDARY, if ever

//This works only for prime numbers up to
int main(void){
    int prime_numbers[SIZE_OF_ARRAY] = {2};

    //init all values of array to be 0
    for(int i = 1; i < SIZE_OF_ARRAY; i++){
        prime_numbers[i] = 0;
    }

    int saving_index = 1;

    //prime number test
    for(int num = MIN_BOUNDARY; num < MAX_BOUNDARY; num++){
        //Skip even
        if(num % 2 == 0){
            continue;
        }
        
        for(int i = 0; i < SIZE_OF_ARRAY; i++){
            if (prime_numbers[i] == 0){
                prime_numbers[saving_index] = num;
                saving_index += 1;
                break;
            } else if ((num % prime_numbers[i] == 0) && (num / prime_numbers[i] >= prime_numbers[i])){
                break;
            }
        }
    }

    //print prime_numbers
    for(int i = 0; i < SIZE_OF_ARRAY; i++){
        if(prime_numbers[i] == 0){
            break;
        }
        printf("%d\n", prime_numbers[i]);
    }

}