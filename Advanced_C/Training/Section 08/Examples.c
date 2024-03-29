/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: tyler
 */

#define AMOUNT_OF_NUMBERS 5

#include <stdio.h>

int main(void){
	float number, total = 0;

	for(int i = 0; i < AMOUNT_OF_NUMBERS; i++){
		printf("Enter number %d: ", i+1);
			scanf("%f", &number);
			total += number;
			fflush(stdin);
	}

	printf("Total: %f\n", total/3);

	getchar(); //Wait until user clicks on program to exit

	return 0;
}
