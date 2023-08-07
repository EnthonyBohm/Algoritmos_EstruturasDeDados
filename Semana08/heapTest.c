#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_NAME_SIZE 100

typedef struct{
    char name[MAX_NAME_SIZE];
    int  queueNumber;
}Person;

struct node
{
    Person* persons;
    struct node* next;
};
typedef struct node Heap;

typedef struct
{
    Heap* start;
    Heap* end;
    int size;
}Sentinel;

int queueCode = 1000;

Sentinel* queueRESET(Sentinel* sentinel);
bool queueEMPY      (Sentinel* sentinel);
void queuePUSH      (Sentinel* sentinel);
Heap* queuePOP      (Sentinel* sentinel);
Heap* queueCLEAR    (Sentinel* sentinel);


/*MAIN FUNCTION START'S HERE */
    int main(){
        Sentinel* queue = NULL;
        Heap* poppedElement;
        int user_Choice = 1;

        queue = queueRESET(queue);
        printf("sentinel Size: %d", queue ->size );

        while (user_Choice != 0){
            printf( "MENU: \n"\
                    "New Person on Queue \t(1) \n"\
                    "Remove Person of Queue \t(2)\n"\
                    "Dismiss Queue \t\t(3)\n"\
                    "End \t\t\t(0)\n");
                    
            scanf("%d", &user_Choice);

            switch(user_Choice){
                case 1:
                    queuePUSH(queue);
                    break;
                case 2:
                    poppedElement = queuePOP(queue);
                    if (poppedElement != NULL){
                        printf("\n\n=======CLIENT REMOVED FROM QUEUE======\n");
                        printf("Queue Code %d has been Served\n", poppedElement->persons->queueNumber);
                        printf("Client name= %s\n", poppedElement->persons->name);
                        printf("=======CLIENT REMOVED FROM QUEUE======\n\n");
                        free(poppedElement);
                    }
                    else{
                        printf("Queue was already Empty\n");
                    }
                    break;
                case 3:
                    queue = queueCLEAR(queue);
                    break;
                case 0:
                    printf("Goodbye");
            }
        }
    }
/*MAIN FUNCTION END'S HERE */

/*Start's the Queue*/
Sentinel* queueRESET(Sentinel* sentinel){
    sentinel = (Sentinel*) malloc(sizeof(Sentinel));
    sentinel -> start = NULL;
    sentinel -> end = NULL;
    sentinel -> size = 0;

    return sentinel;
}

/*Check if the Queue is already Empty*/
bool queueEMPTY (Sentinel* sentinel){
    return sentinel -> end == NULL;
}

/*Add and element to the Queue*/
void queuePUSH (Sentinel* sentinel){
    Heap* temp;
    temp = (Heap *) malloc(sizeof(Heap));

    temp -> persons = (Person *) malloc(sizeof(Person));

    printf("Name of the new person who entered the Heap");
    scanf("%s", temp -> persons-> name);
    temp->persons->queueNumber = queueCode++;
    temp ->next = NULL;

    if(sentinel -> size == 0){
        sentinel -> start = temp;
        sentinel -> end = temp;
    }
    else{
        sentinel -> end -> next = temp;
        sentinel -> end = temp;
    }
    sentinel ->size++;
}

/*Remove and element from Queue and return it's value*/
Heap* queuePOP  (Sentinel* sentinel){
    if(queueEMPTY(sentinel))
        return NULL;
    
    Heap *deadNode;

    deadNode = sentinel -> start;
    sentinel -> start = deadNode -> next;

    sentinel -> size--;
    return deadNode;
}

/*Clear List and Reset*/
Heap* queueCLEAR    (Sentinel* sentinel){
    Heap *i, *j;

    for ( i = sentinel -> start, j = i -> next; j == sentinel -> end; i = j, j = i -> next ) {
        free(i);
    }
    free(j);
    
    return queueRESET(sentinel);
}
