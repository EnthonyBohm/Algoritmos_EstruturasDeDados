
#ifndef STUDENTSTACK_H
#define STUDENTSTACK_H

#define MAX_NAME_SIZE 50
#define MAX_STUDENTS 100
#define STACK_LIMIT 100

typedef struct 
{
    char name[MAX_NAME_SIZE];
    float overallAverage;
    int classMiss;
} Student;

typedef struct 
{
    Student students[MAX_STUDENTS];
    int floor;
    int ceil;
    int limit;
} stack;

void RESET(stack *studentStack)
{
    studentStack -> floor = 0;
    studentStack -> ceil = 0;
    studentStack -> limit = STACK_LIMIT;
}

bool FULL(stack *studentStack)
{
    return studentStack->ceil == studentStack->limit;
}

bool EMPTY(stack *studentStack)
{
    return studentStack->floor == studentStack->ceil;
}

bool PUSH(stack *studentStack) 
{
    if (FULL(studentStack))
        return false;

    printf("Student name: ");
    scanf("%s", studentStack -> students[studentStack -> ceil].name);
    getchar();

    printf("%s Overall Average: ", studentStack->students[studentStack->ceil].name);
    scanf("%f", &studentStack->students[studentStack->ceil].overallAverage);
    getchar();

    printf("Number of times that %s missed class", studentStack->students[studentStack->ceil].name);
    scanf("%d", &studentStack->students[studentStack->ceil].classMiss);
    getchar();

    studentStack->ceil++;
    return true;
}

bool POP(stack *studentStack) 
{
    if (EMPTY(studentStack))
        return false;
    studentStack->ceil--;
    return true;
}

void CLEAR(stack *studentStack)
{
    studentStack -> ceil = 0;
}

#endif
