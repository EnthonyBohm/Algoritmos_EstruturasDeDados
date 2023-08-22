#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "main.h"

int main()
{
    Matrix* A = matrix100Megas(1024);
    matrix_destroy(A);
    return 0;
}

/*
==============================================================
    Matrix Create
    Read the number of coluns and create a Matrix
    Readm some valluens and put it in the Matrix
==============================================================
*/
Matrix* matrix_create (void){
    int                 m, n;   //m = lines | n = columns
    float               value;  //info value
    Matrix*             matrixHead = NULL;
    Matrix*             newNode;

    printf("Size of Matrix: (line, column)");
    scanf("%d %d", &m, &n);
    matrixHead = startMatrixPointers(m, n);

    while(true){

        printf("Add value, '.' to stop (line column value): " );
        if (scanf( "%d %d %f", &m, &n, &value ) == 0)
            break;

        newNode             = (Matrix*) malloc(sizeof(Matrix));
        newNode -> info     = value;
        newNode -> line     = m;
        newNode -> column   = n;

        adjustPointer(matrixHead, newNode);
    }

    return matrixHead;
    }

/*
==============================================================
    Matrix Destroy
    Receive a matrix and free every position of it.
==============================================================
*/
void matrix_destroy (Matrix* m){
    Matrix*     aux = NULL, *deadNode = NULL;
    void        *StartAdress;

    for( StartAdress = m; m -> below!= StartAdress; m = m -> below){
        if (deadNode != NULL){
            free(deadNode);
        }
        
        deadNode = m->right;
        if (deadNode == m)
            continue;

        aux = deadNode -> right;
        if (aux == m){
            free (deadNode);
            deadNode = aux;
            continue;
        }

        while(aux != m){
            free(deadNode);
            deadNode = aux;
            aux = aux->right;
        }
        free(deadNode);
        deadNode = m;
    }
    free(deadNode);

    deadNode = StartAdress = m;
    
    deadNode = m->right;
    if(deadNode == StartAdress){
        free (deadNode);
        return;
    }
    m = m->right;
    while (m != StartAdress)
    {
        deadNode = m;
        m = m->right;
        free(deadNode);
    }
    free(StartAdress);
}

/*
==============================================================
    getelem
    Receive's a matrix, and two integer, for line and column
    then return the element in that position
==============================================================
*/
float getElem(Matrix* m, int line, int column){
    Matrix*                 startAdress;
    int                     i;

    for (i = 0; i < column; i++){
        m = m->right;
    }
    startAdress = m;
    m = m->below;
    while(m != startAdress){
        if(m->line == line)
            return m->info;
        m = m->below;
    }

    return 0;
}

/*
==============================================================
    setelem
    Receive's a Matrix, two integer for line and column
    and a float for content
    Set's the node info field with content
==============================================================
*/
void setElem(Matrix* m, int line, int column, float content){
    Matrix*             newNode;

    newNode = (Matrix*) malloc(sizeof(Matrix));
    newNode->column = column;
    newNode->line   = line;
    newNode->info   = content;

    adjustPointer ( m, newNode );
}


/*
==============================================================
    matrix_add
    add every element of 2 Matrixes and return a matrix with
    the result of the sums
==============================================================
*/
Matrix* matrix_add (Matrix *m, Matrix *n) {
    int lines, columns;
    if(getLines(m) >= getLines(n)){
        lines = getLines(m);
    }else{
        lines = getLines(n);
    }
    if(getColumns(m) >= getColumns(n)){
        columns = getColumns(m);
    }else{
        columns = getColumns(n);
    }

    Matrix*                     newMatrixHead  = startMatrixPointers(lines, columns);
    int                         i, j;
    float                       sum;

    for ( i=1; i<=lines; i++ ){
        for ( j=1; j<=columns; j++ ){
            sum = getElem(m, i, j) + getElem(n, i, j);
            if ( sum != 0 ){
                setElem(newMatrixHead, i, j, sum);
            }
        }
    }
    return newMatrixHead;
}

/*
==============================================================
    matrix_multiply
    multiply every element of 2 Matrixes and return a matrix with
    the result of the multiplications
==============================================================
*/
Matrix* matrix_multiply (Matrix *m, Matrix *n){
    int lines, columns;
    if(getLines(m) >= getLines(n)){
        lines = getLines(m);
    }else{
        lines = getLines(n);
    }
    if(getColumns(m) >= getColumns(n)){
        columns = getColumns(m);
    }else{
        columns = getColumns(n);
    }

    Matrix*                     newMatrixHead  = startMatrixPointers(lines, columns);
    int                         i, j;
    float                       result;

    for ( i=1; i<=lines; i++ ){
        for ( j=1; j<=columns; j++ ){
            result = getElem(m, i, j) * getElem(n, i, j);
            if ( result != 0 ){
                setElem(newMatrixHead, i, j, result);
            }
        }
    }
    return newMatrixHead;
}


/*
==============================================================
    matrix_Print
    print on the Screen an matrix with the corrent identation
==============================================================
*/
void matrix_print (Matrix* m){
    int                     lines = getLines(m), columns = getColumns(m);
    int                     i, j;
    
    printf("\n");
    for ( i=1; i<=lines; i++){
        printf("|");
        for ( j=1; j<=columns; j++){
            printf("%10.3f\t", getElem(m, i, j));
        }
        printf("|\n");
    }
}



// EXTRA FUNCTIONS
/*
================================================================
    adjustPointer
    fit the new Node inside the Matrix and correct it's pointers
================================================================
*/
void adjustPointer(Matrix* m, Matrix* newNode){
    Matrix*             startAdress, *aux;
    int                 i;
    
    startAdress = m;
    for ( i = 0; i < newNode->line; i++){
        m = m->below;
    }
    aux = m;
    while (m -> right != aux){
        if(newNode->column < m->right->column)
            break;
        m = m->right;
    }
    newNode->right  = m->right;
    m->right        = newNode ;
    

    m = startAdress;
    for ( i = 0; i < newNode->column; i++){
        m = m->right;
    }
    aux = m;
    while ( m->below != aux){
        if (newNode->line < m->below->line)
            break;
        m = m->below;
    }
    newNode->below  = m->below;
    m->below        = newNode;
    
}

/*
==================================================================
    startMatrixPointers
    start all the Pointers with no value of the matrix
==================================================================
*/
Matrix* startMatrixPointers(int lines, int columns){
    Matrix*                 matrixHead, *aux;
    Matrix*                 newNode;
    int                     i;


    matrixHead              = (Matrix*) malloc(sizeof(Matrix));
    matrixHead->line        = -1;
    matrixHead->column      = -1;

    aux = matrixHead;
    for(i = 0; i < lines; i++, aux = aux->below){
        newNode             = (Matrix*) malloc (sizeof (Matrix));
        newNode->line       = -1;
        newNode->right      = newNode;
        aux->below          = newNode;
    }
    aux->below = matrixHead;
    aux = matrixHead;
    for (i = 0; i < columns; i++, aux = aux->right){
        newNode             = (Matrix*) malloc (sizeof (Matrix));
        newNode->column     = -1;
        newNode->below      = newNode;
        aux->right          = newNode;
    }
    aux->right = matrixHead;

    return matrixHead;
}

/*
==================================================================
    getLines
    return the number of lines of a Matrix
==================================================================
*/
int getLines(Matrix *m){
    int                 i;
    void*               startAdress = m;
    for ( i = 0; m->right != startAdress; i++, m = m->right);
    return i;
}

/*
==================================================================
    getColumns
    return the number of columns of a Matrix
==================================================================
*/
int getColumns(Matrix *m){
    int                 i;
    void*               startAdress = m;
    for ( i = 0; m->below != startAdress; i++, m = m->below );
    return i;
}

Matrix* matrix100Megas(unsigned int m){
    unsigned int i, j;
    int size;
    float element;
    Matrix* giantMatrix = startMatrixPointers (m , m);
    Matrix* newNode;
    Matrix* matrixHead = giantMatrix;

    
    for(i = 1; i < m; i++){
        giantMatrix = giantMatrix->below;
        giantMatrix = giantMatrix->right;
        for(j = 1; j < m; j++){
            scanf("%f",&element);
            if(element == 0){
                continue;
            } else{
                newNode             = (Matrix*) malloc(sizeof(Matrix));
                newNode -> info     = element;
                newNode -> line     = i;
                newNode -> column   = j;

                adjustPointer(matrixHead, newNode);
            }
        }
    }
    return giantMatrix;
}