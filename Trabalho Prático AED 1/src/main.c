#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char const *argv[])
{

    return 0;
}

/*
======================================================
    Matrix Create
    Read the number of coluns and create a Matrix
    Readm some valluens and put it in the Matrix
======================================================
*/
Matrix* matrix_create (void){
    int m, n; //m = lines | n = columns
    
    Matrix* matrix = NULL;

    printf("Size of Matrix: (line, column)");
    scanf("%d %d", &m, &n);

    matrix = (Matrix *) malloc (sizeof (matrix));
    matrix -> line = -1;
    matrix -> column = -1;

    insertHeadLines(matrix, m);
    
    }

Matrix* insertHeadLines (Matrix* head, int value){
    if(value == 0){
        return;
    }
    Matrix *newNode = NULL;
    newNode = ( Matrix * ) malloc( sizeof(Matrix) );
    newNode -> line = -1;
    head -> below = (insertHeadLines);
}