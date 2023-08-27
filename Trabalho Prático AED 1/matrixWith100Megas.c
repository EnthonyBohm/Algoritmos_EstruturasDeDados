#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    int i, j, size =0;
    srand(time(NULL));

    int** Matriz = (int**) malloc (sizeof(int *) * 5000);

    for(int i = 0; i < 5000; i++){
        Matriz[i] = (int *) malloc(sizeof(int) * 5000);
    }



    for(i = 0; i < 5000; i++){
        for(j = 0; j < 5000; j++){
            Matriz[i][j] = rand() % 10 <= 8 ? 0 : 1;
            size += sizeof(Matriz[i][j]);
            printf("%d ", Matriz[i][j]);
        }
        printf("\n");
    } 
}