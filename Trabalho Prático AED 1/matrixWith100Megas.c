#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    float Matriz[1024][1024];
    int i, j;
    srand(time(NULL));
    printf("\n tamanho da Matriz: %d \n", sizeof(Matriz)/1024);


    for(i = 0; i < 1024; i++){
        for(j = 0; j < 1024; j++){
            Matriz[i][j] = rand() % 2;
            printf("%.0f ", Matriz[i][j]);
        }
        printf("\n");
    }
    getchar(); 

}