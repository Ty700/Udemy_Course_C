#include <stdio.h>

int main(){
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT};

    enum Company firstCompany = XEROX;
    enum Company secondCompany = GOOGLE;
    enum Company thirdCompany = EBAY;


    printf("XEROX: %d\nGOOGLE: %d\nEBAY: %d\n", XEROX, GOOGLE, EBAY);

}