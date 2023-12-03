/*
*   Create a C program that shares a variable amongst two files
*       Create a source file named main.c
*           - this src file should include a global variable used as a loop counter 
*           - this file includes a main function that uses the global variable to iterate through a loop 5 times
*               - inside this loop a function should be invoked (display) that is defined in another file
*               - the display function should take no parameters
*/

#include <stdio.h>

int loop_counter = 5;

extern void display();

int main(){
    for(loop_counter > 0; loop_counter--;){
        display();
    }
}