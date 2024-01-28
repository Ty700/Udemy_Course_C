/*
*
*   Write a program to print the values of the following predefined symbolic constants
*       - __LINE__
*       - __FILE__
*       - __DATE__
*       - __TIME__
*       - __STDC__
*
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){
    printf("%s\n", __FILE__);
    printf("%d\n", __LINE__);
    printf("%s\n", __DATE__);
    printf("%s\n", __TIME__);
    printf("%d\n", __STDC__);
}