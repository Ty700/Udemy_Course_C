/*
*   Guess a number game
*       - Generate a number 1 - 20
*       - Ask user to guess it
*       - Tell user if their guess is too high/low
*       - Can only guess 5 times
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_NUM_BOUNDARY 0
#define MAX_NUM_BOUNDARY 20
#define LIVES 5

int main(){
    //Random number
    time_t random_time;
    srand((unsigned)time(&random_time)); //This doesn't seem to be the best srand() but it works.

    int num_to_guess = rand() % (MAX_NUM_BOUNDARY + 1);
    int user_guess = 0;
    int lives_left = LIVES;

    // printf("%d\n", num_to_guess); //DEBUG

    while(lives_left){
        //Input
        printf("Enter in an integer between: %d and %d\n", MIN_NUM_BOUNDARY, MAX_NUM_BOUNDARY);
            scanf("%d", &user_guess);
        char annoying = getchar();

        //Guess Logic Check
        while((user_guess > MAX_NUM_BOUNDARY) || (user_guess < MIN_NUM_BOUNDARY)){
            printf("Error: Guess Out of Range\n");
            printf("Enter in an integer between: %d and %d\n", MIN_NUM_BOUNDARY, MAX_NUM_BOUNDARY);
            scanf("%d", &user_guess);
            char annoying = getchar();
        }

        //Basic Guess Logic
        if(user_guess > num_to_guess){
            printf("Too high.\n");
            lives_left -= 1;
        } else if (user_guess < num_to_guess) {
            printf("Too low.\n");
            lives_left -= 1;
        } else {
            printf("You got it!\n");
            break;
        }
        printf("Lives Left: %d\n", lives_left);
    }

    if(!lives_left){
        printf("You've lost.\n");
    }
}