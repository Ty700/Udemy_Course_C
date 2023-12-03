/*
*   Storage Class Challenge - Challenge 1
*       - Our first challenge is to write a small program that declares the following variables:
*           - an int variable with block scope and temp storage - var1
*           - a global double variable that is only accessible inside the file - var2
*           - a global float varaible that is accessible wihtin the entire program - var3
*           - a float local variable with perm storage - var4
*           - a register int varaible - var5
*           - a function that is only accessible with the file it is defined in - func1
*/

static double var2 = 5;
float var3 = 10;

static float func1(void){
    static float var4 = 0;
    
    return ++var4;
}

int main(){
    int var1;
    register int var5 = 5;
}
