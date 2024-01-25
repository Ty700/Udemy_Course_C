#include <stdio.h>

union Car{
    int i_value;
    float f_value;
} car1, car2, *car3;

//Unanonomous Union Example

struct owner{
    char socsecurity[12];
};

struct leasecompany{
    char name[40];
    char headquarters[40];
};

//The union inside car_data is an anonomyous union
//Doesn't have a tag, and only in the car_data struct
struct car_data{
    char make[15];
    int status;
    union {
        struct owner owncar;
        struct leasecompany leasecar;
    };
};

// enum symbolType {INT, FLOAT, CHAR};

// struct {
//     char *name;
//     enum symbolType type;
//     union {
//         int i;
//         float f;
//         char c;
//     } data;
// } table[entries];

int main(void){
    printf("%zu\n", sizeof(car1));
}