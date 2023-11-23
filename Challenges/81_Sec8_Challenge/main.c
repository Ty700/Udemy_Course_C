/*
*   Make Tic Tac Toe - okay.
*   I did a lot more than what was asked... nothing abnormal.
*   Cool thing is that it took me forever to do this in C++ when I was first starting out.
*   The logic I used back then was not the best to say the least and I can see how far I've come :D
*   Still not perfect but still cool.
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RED  "\x1B[31m"
#define BLU  "\x1B[34m"
#define WHT  "\x1B[37m"
#define GRN  "\x1B[32m"

//FUNCTION DECLARATIONS
void print_title(void);
void print_board(const char moves[]);
char* color_individual_piece(char move_piece);
int get_player_move(int player_num);
bool valid_player_response(const char moves[], int player_response);
bool check_for_winner(const char moves[], int turn_counter);
void print_winner(int turn_counter);

int main(){
    bool gameOver = false;
    char moves[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int turn_counter = 0;


    print_title();
    print_board(moves);

    do{
        int current_player = (turn_counter % 2) + 1;

        char current_player_piece = (current_player == 1) ? 'X' : 'O';

        int player_response = get_player_move(current_player);

        while(!(valid_player_response(moves, player_response))){
            printf("Error: Spot Taken\n");
            player_response = get_player_move(current_player);
        }

        moves[player_response] = current_player_piece;

        gameOver = check_for_winner(moves, turn_counter);

        print_board(moves);
        
        turn_counter += 1;

    }while(!gameOver);
}

void print_title(void){
    printf("\tTic Tac Toe\n\n");
    printf("Player 1: %sX%s\nPlayer 2: %sO%s\n\n", RED, WHT, BLU, WHT);
}

void print_board(const char moves[]){
    printf("     |     |      \n");
    printf("  %s  |  %s  |  %s\n", color_individual_piece(moves[0]), color_individual_piece(moves[1]), color_individual_piece(moves[2]));
    printf("_____|_____|______\n");
    printf("     |     |      \n");
    printf("  %s  |  %s  |  %s\n", color_individual_piece(moves[3]), color_individual_piece(moves[4]), color_individual_piece(moves[5]));
    printf("_____|_____|______\n");
    printf("     |     |      \n");
    printf("  %s  |  %s  |  %s\n", color_individual_piece(moves[6]), color_individual_piece(moves[7]), color_individual_piece(moves[8]));
    printf("     |     |      \n\n\n");
}

//Took me so long to figure this out...
char* color_individual_piece(char move_piece) {
    char* colored_piece = (char*)malloc(12 * sizeof(char)); 
    if (move_piece == 'X') {
        strcpy(colored_piece, "\x1B[31mX\x1B[37m");
    } else if (move_piece == 'O') {
        strcpy(colored_piece, "\x1B[34mO\x1B[37m");
    } else {
        colored_piece[0] = move_piece;
        colored_piece[1] = '\0'; 
    }
    return colored_piece;
}

int get_player_move(int player_num){
    int new_move;

    printf("Player %d, enter a number: ", player_num);
        scanf("%d", &new_move);

    while((new_move > 9) || (new_move < 1)){
        printf("Error: Invalid Move.\n");
        printf("Player %d, enter a number: ", player_num);
            scanf("%d", &new_move);
    }

    return (new_move - 1);
}

bool valid_player_response(const char moves[], int player_response){
    if(moves[player_response] == 'X' || moves[player_response] == 'O'){
        return false;
    } else {
        return true;
    }
}

bool check_for_winner(const char moves[], int turn_counter){
    //Rows
    for(int i = 0; i < 9; i = i + 3){
        if(moves[i] == moves[i+1] && moves[i] == moves[i + 2]){
            print_winner(turn_counter);
            return true;
        }
    }

    //Cols
    for(int i = 0; i < 3; i = i + 1){
        if(moves[i] == moves[i+3] && moves[i] == moves[i + 6]){
            print_winner(turn_counter);
            return true;
        }
    }

    //Diagonal - Top Left to Bottom Right
    if(moves[0] == moves[4] && moves[0] == moves[8]){
        print_winner(turn_counter);
        return true;
    }

    //Diagonal - Top Right to Bottom Left
    if(moves[2] == moves[4] && moves[2] == moves[6]){
        print_winner(turn_counter);
        return true;
    } 

    if(turn_counter == 8){
        printf("%sIt's a draw!\n", RED);
        return true;
    }

    return false;
}

void print_winner(int turn_counter){
    char *color = (((turn_counter % 2) + 1) == 1) ? RED : BLU;
    printf("%sPlayer %d wins!%s\n", color, (turn_counter % 2) + 1, WHT);
}