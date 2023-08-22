#include <stdio.h>

int* kWeakestRow (int** mat, int matSize, int* matColSize, int k, int* returnSize);

int main(){
    int mat[5][5] = {
        {1,1,0,0,0},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,1,1}};

    int matColSize = 5, returnSize;
    int resullt =  kWeakestRow(mat, 5, &matColSize, 3, &returnSize);
}


int* kWeakestRow (int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int*            returnVector = (int *) malloc(sizeof(int) * (2*matSize));
    int             i, j, soldierCount;
    
    for ( i = 0; i < matSize; i++ ){
        returnVector[i] = i;
    }

    for ( i = 0; i < matSize; i++ ){
        soldierCount = 0;
        for( j = 0; j < matColSize; j++ ) {
            if (mat[i][j] == 1)
                soldierCount++;
            else
                break;
        }
        returnVector[2*i] = soldierCount;
    }
}