/*
*   Write a program that contains the following bit fields
*       - the box can opaque or transparent
*       - a fill color is selected from the following pallete of colors:
*           - black, red, green, yellow, blue, magenta, cyan, or white
*       - a border can be shown or hidden
*       - a border color is selected from the same palette used for the fill color
*       - a border can use one of three styles - solid, dotted, or dashed
*
*   - I believe that is 10 total bits needed
*
*
*   - Wants us to set the bit fields to a default value, print it, then allow user to modify them, then print it again
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Box{
    u_int16_t transparency  :1;
    u_int16_t fillColor     :3;
    u_int16_t border        :1;
    u_int16_t borderColor   :3;
    u_int16_t borderStyle   :2;
    u_int16_t UNUSED        :6;
};

void GenerateRandBoxArgs(int arr[]){
    srandom(time(NULL));
    arr[0] = random() % 2;
    arr[1] = random() % 8;
    arr[2] = random() % 2;
    arr[3] = random() % 8;
    arr[4] = random() % 2;
}

void CollectBoxArguments(int arr[]){
    printf("For all choices, please enter the corresponding number.\n\n");

    //Transparency
    printf("Select an option for Transparency:\n");
    printf("\t1. Opaque\n\t2. Transparent\n");
        scanf("%d", &arr[0]);
        fflush(stdin);

    while(arr[0] != 1 && arr[0] != 2){
        printf("\n\nError: Input Out of Range\n\n");
        printf("For all choices, please enter the corresponding number.\n\n");
        printf("Select an option for Transparency:\n");
        printf("\t1. Opaque\n\t2. Transparent\n");
            scanf("%d", &arr[0]);
            fflush(stdin);
    }
    
    //Fill Color
    printf("\n\nSelect an option for Fill Color:\n");
    printf("\t1. Black\n\t2. Red\n\t3. Green\n\t4. Yellow\n\t5. Blue\n\t6. Magenta\n\t7. Cyan\n\t8. White\n");
        scanf("%d", &arr[1]);
        fflush(stdin);
    
    while(arr[1] != 1 && arr[1] != 2 && arr[1] != 3 && arr[1] != 4 && arr[1] != 5 && arr[1] != 6 && arr[1] != 7 && arr[1] != 8){
        printf("\n\nError: Input Out of Range\n\n");
        printf("For all choices, please enter the corresponding number.\n\n");
        printf("\n\nSelect an option for Fill Color:\n");
        printf("\t1. Black\n\t2. Red\n\t3. Green\n\t4. Yellow\n\t5. Blue\n\t6. Magenta\n\t7. Cyan\n\t8. White\n");
            scanf("%d", &arr[1]);
            fflush(stdin);
    }

    //Border
    printf("\n\nSelect an option for the Border:\n");
    printf("\n\t1. Shown\n\t2. Hidden\n");
        scanf("%d", &arr[2]);
        fflush(stdin);

    while(arr[2] != 1 && arr[2] != 2){
        printf("\n\nError: Input Out of Range\n\n");
        printf("For all choices, please enter the corresponding number.\n\n");
        printf("\n\nSelect an option for the Border:\n");
        printf("\n\t1. Shown\n\t2. Hidden\n");
            scanf("%d", &arr[2]);
            fflush(stdin);
    }

    //Border Color
    printf("\n\nSelect an option for Border Color:\n");
    printf("\t1. Black\n\t2. Red\n\t3. Green\n\t4. Yellow\n\t5. Blue\n\t6. Magenta\n\t7. Cyan\n\t8. White\n");
        scanf("%d", &arr[3]);
        fflush(stdin);
    
    while(arr[3] != 1 && arr[3] != 2 && arr[3] != 3 && arr[3] != 4 && arr[3] != 5 && arr[3] != 6 && arr[3] != 7 && arr[3] != 8){
        printf("\n\nError: Input Out of Range\n\n");
        printf("For all choices, please enter the corresponding number.\n\n");
        printf("\n\nSelect an option for Fill Color:\n");
        printf("\t1. Black\n\t2. Red\n\t3. Green\n\t4. Yellow\n\t5. Blue\n\t6. Magenta\n\t7. Cyan\n\t8. White\n");
            scanf("%d", &arr[3]);
            fflush(stdin);
    }
    
    //Border Style
    printf("\n\nSelect an option for Border Style:\n");
    printf("\t1. Solid\n\t2. Dotted\n\t3. Dashed\n");
        scanf("%d", &arr[4]);
        fflush(stdin);

    while(arr[4] != 1 && arr[4] != 2 && arr[4] != 3){
        printf("\n\nError: Input Out of Range\n\n");
        printf("For all choices, please enter the corresponding number.\n\n");
        printf("\n\nSelect an option for Border Style:\n");
        printf("\t1. Solid\n\t2. Dotted\n\t3. Dashed\n");
            scanf("%d", &arr[4]);
            fflush(stdin);
    }
}

void PrintBoxSettings(const struct Box *p_boxData){
    //black, red, green, yellow, blue, magenta, cyan, or white

    const char* colors[] = {"Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"};
    const char* borderStyle[] = {"Solid", "Dotted", "Dashed"};

    printf("Box Settings: \n\n");
    printf("Transparency: %s\n", (p_boxData->border == 0) ? "Opaque" : "Transparent");
    printf("Fill Color: %s\n", colors[p_boxData->fillColor]);
    printf("Border: %s\n", (p_boxData->border == 0) ? "Shown" : "Hidden");
    printf("Border Color: %s\n", colors[p_boxData->borderColor]);
    printf("Border Style: %s\n", borderStyle[p_boxData->borderStyle]);   
}

int main(void){
    int boxArguments[5] = {0};

    //Randomly Generated Box Args
    GenerateRandBoxArgs(boxArguments);

    struct Box box_data = { .transparency   = boxArguments[0],
                            .fillColor      = boxArguments[1],
                            .border         = boxArguments[2],
                            .borderColor    = boxArguments[3],
                            .borderStyle    = boxArguments[4],
                            .UNUSED         = 0,
                        };

    struct Box* p_box = &box_data;
    
    printf("Original ");
    PrintBoxSettings(p_box);
    printf("\n\n");

    //User Box Args
    CollectBoxArguments(boxArguments);

    /*
    * NOTE: REASON FOR DOING THIS
    *   Since I have the user enter (for example) 1-8 on border color, I can't store 8 in 3 bits.
    *   Thus, 8 really means 7 when storing the info in the bit field, hence I need to subtract 1 from the user entry.
    *   Alternatively, I could start the list from 0 but that just looks weird.
    *   Having "Select an option for Fill Color: 
    *               0. Black
    *               1. Red"
    *   Doesn't sit right with me, so doing this way instead
    */
    for(int i = 0; i < 5; i++){
        boxArguments[i] -= 1;
    }

    box_data.transparency   = boxArguments[0];
    box_data.fillColor      = boxArguments[1];
    box_data.border         = boxArguments[2];
    box_data.borderColor    = boxArguments[3];
    box_data.borderStyle    = boxArguments[4];

    printf("\nNew ");
    PrintBoxSettings(p_box);
}