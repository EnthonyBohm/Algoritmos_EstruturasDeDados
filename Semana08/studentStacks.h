
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

struct node
{
    Student* students;
    struct node* ceil;
    struct node* floor;
    int size;
};

typedef struct node StudentStack;


void RESET(StudentStack* studentStack)
{   
    studentStack = (StudentStack *) malloc(sizeof(StudentStack));
    studentStack -> students = (Student*) malloc (sizeof(Student));
    studentStack -> ceil = studentStack -> students;
    studentStack -> floor = studentStack -> students;
}

bool EMPTY(StudentStack *studentStack)
{
    return studentStack->floor == studentStack->ceil;
}

void PUSH(StudentStack *studentStack ) 
{    
    studentStack -> size++;
    studentStack -> students = (Student *) realloc (sizeof (Student) * studentStack -> size);
    
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
