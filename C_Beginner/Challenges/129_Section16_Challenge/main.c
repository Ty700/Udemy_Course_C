/*
*   Struct pointer challenge
*       - write a program that creates a structure pointer and passes it to a function
*           - create a structure named item with the following members:
*               - itemName - pointer
*               - quantity - int
*               - price - float
*               - amount - float (store [quanity * price])
*
*           - create a function named readItem that takes a structure pointer of type item as a paratmeter
*               - this function should read in (from the user) a product name, price, and quanity
*               - the contents read in should be stored in the passed in structure to the function
*
*           - create a function named print item that takes a parameter a structure pointer of type item
*               - function prints the contents of the parameter
*
*           - the main function should declare an item and a pointer to an item
*               - you will need to allocate memory for the itemName pointer
*               - the item pointer should be passed into both the read and print functions
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct Item{
    char *itemName;
    int quantity;
    float price;
    float totalCost;
};

void readItem(struct Item* itemToRead);
void printItem(const struct Item* itemToPrint);

int main(void){
    struct Item firstItem;
    struct Item* firstItemPtr = &firstItem;

    firstItemPtr->itemName = (char *)malloc(100 * sizeof(char));
    
    if(firstItemPtr->itemName == NULL){
        printf("Error: Allocation Memory Failed.\n");
        EXIT_FAILURE;
    }

    readItem(firstItemPtr);
    printItem(firstItemPtr);

    free(firstItemPtr->itemName);
}

void readItem(struct Item* itemToRead){
    printf("Enter Product Name: ");
        scanf("%s", itemToRead->itemName);
        fflush(stdin);
    printf("Enter Product Quantity: ");
        scanf("%d", &itemToRead->quantity);
        fflush(stdin);
    printf("Enter Product Price: $");
        scanf("%f", &itemToRead->price);
        fflush(stdin);

    itemToRead->totalCost = itemToRead->price * itemToRead->quantity;
}

void printItem(const struct Item* itemToPrint){
    printf("\nProduct Name: %s\n", itemToPrint->itemName);
    printf("Product Price: $%.2f\n", itemToPrint->price);
    printf("Product Quantity: %d\n", itemToPrint->quantity);
    printf("Total Cost: $%.2f\n", itemToPrint->totalCost);
}