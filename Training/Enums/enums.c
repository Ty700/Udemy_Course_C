

#include <stdio.h>

int main(){

    enum gender {male, female};

    enum gender myGender = male;
    enum gender herGender = female;

    // bool isMale = (myGender == herGender);

    printf("%d %d\n", myGender, herGender);

}