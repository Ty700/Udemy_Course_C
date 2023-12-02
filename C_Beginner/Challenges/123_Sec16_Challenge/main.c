/*
*
*   Structure Challenge
*       - write a program that creates an employee struct with 3 members
*           - name
*           - hireDate
*           - salary
*       - declare and init an instance of an employee type
*       - read in a second employee from the console and store it in a struct of type employee
*       - print out the contents of each employee
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct employee {
    char *name, *hireDate;
    float salary;
};


void printEmployeeInfo(struct employee emp){
    printf("\nEmployee Name: %s\n", emp.name);
    printf("         Hire Date: %s\n", emp.hireDate);
    printf("         Salary: $%.2f\n", emp.salary);
}

int main(int argc, char *argv[]){

    struct employee emp1 = {.name = "Tyler", .hireDate = "Nov 11, 2023", .salary = 85000};

    printEmployeeInfo(emp1);
    
    // if(argc >= 3){
    //     struct employee emp2 = {.name = argv[1], .hireDate = argv[2], .salary = atoi(argv[3])};
    //     printEmployeeInfo(emp2);
    // }

    char empName[100];
    char hireDate[100];
    float salary;

    printf("\nEnter employee name: ");
        gets(empName);
    printf("Enter employee hire date: ");
        gets(hireDate);
    printf("Enter employee salary: ");
        scanf("%f", &salary);

    struct employee emp2 = {.name = empName, .hireDate = hireDate, .salary = salary};
    printEmployeeInfo(emp2);
}