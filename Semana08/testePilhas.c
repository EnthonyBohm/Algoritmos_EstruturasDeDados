#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "studentStacks.h"
#define MAX_NAME_SIZE 50



//MAIN STARTS HERE
int main()
{
    stack  *studentStack = NULL;
    int user_Choice;

    studentStack = (stack *) malloc(sizeof(stack));
    RESET(studentStack);
    
    while (user_Choice != 0){
        printf( "MENU: \n"\
                "Add a new student \t\t(1) \n"\
                "Remove last added student \t(2)\n"\
                "Clear all student's list \t(3)\n"\
                "End \t\t\t\t(0)\n");
                
        scanf("%d", &user_Choice);

        switch(user_Choice){
            case 1:
                if (PUSH(studentStack))
                    printf("Student Added Sucessfully");
                else
                    printf("Error Adding Student!");
                break;
            case 2:
                if (POP(studentStack))
                    printf("Student deleted sucessfully");
                else
                    printf("Error removing student");
                break;
            case 3:
                CLEAR(studentStack);
                break;
            case 0:
                printf("Goodbye");
        }
    }
}
//MAIN END's HERE

