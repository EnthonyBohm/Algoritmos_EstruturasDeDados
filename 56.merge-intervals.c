/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isBetweenIntervals(int min, int value, int max);

int main(){
    int intervals[4][2]= {{1,3}, {2,6}, {8,10}, {15,18}};
}


int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int newCs = intervalsSize;
    int aMin, aMax, bMin, bMax;
    int** arrayRetorno;
    arrayRetorno = (int**) malloc (sizeof(int*));

    for (int i = 0; i < intervalsSize; i++) {
        for (int j = 0; j < intervalsSize; j++){
            if (i == j) continue;
            int *a, *b;
            a = intervals[i];
            b = intervals[j];
            if(a[0] == -1 || b[0] == -1) continue;

            aMin = a[0];aMax = a[1];
            bMin = b[0];bMax = b[1];

            //printf("\nAmin : %d / Amax %d || Bmin : %d / Bmax: %d   Case: ", aMin, aMax, bMin, bMax);

            
            // Caso onde b esta contido em a aMin < bMin < bMax < aMax

            if(isBetweenIntervals(aMin, bMin, aMax) && isBetweenIntervals (aMin, bMax, aMax)){                
            //        printf("1");
                    b[0] = -1;
                    newCs--;
            }
            // Segundo caso, amin < bmin < amax < bmax 
            else if (isBetweenIntervals(aMin, bMin, aMax) && isBetweenIntervals(bMin, aMax, bMax)){         
            //        printf("2");
                    a[1] = b[1];
                    b[0] = -1;
                    newCs--;
            }
            // Terceiro caso, bmin < amin < bmax < amax
            else if (isBetweenIntervals(bMin, aMin, bMax) && isBetweenIntervals(aMin, bMax, aMax)){
            //        printf("3");
                    b[1] = a[1];
                    a[0] = -1;
                    newCs--;
            }
            // Terceiro caso, Bmin < Amin < Amax < Bmax B c A
            else if (isBetweenIntervals(bMin, aMin, bMax) && isBetweenIntervals (bMin, aMax, bMax)){
            //        printf("\n4");
                    a[0] = -1;
                    newCs--;
            }
        }
    }

    arrayRetorno = (int**) malloc (sizeof(int*) * newCs);
    returnColumnSizes = (int**) malloc(sizeof(int*) * newCs);

    (*returnSize) = 0;

    for(int i = 0; i < intervalsSize; i++){
    
        int *a;
        a = intervals[i];
    
        if(a[0] != -1){

            returnColumnSizes[*returnSize] = (int*) malloc(sizeof(int));
            returnColumnSizes[*returnSize][0] = 2;
            
            arrayRetorno[*returnSize] = (int*) malloc (sizeof(int) * (returnColumnSizes[*returnSize][0]));
            arrayRetorno[*returnSize][0] = a[0];
            arrayRetorno[*returnSize][1] = a[1];
            
            printf("\n\nreturnArray[%d][%d] = %d", *returnSize, 0, arrayRetorno[*returnSize][0]);
            printf("\nreturnArray[%d][%d] = %d", *returnSize, 1, arrayRetorno[*returnSize][1]);
            printf("\nReturnColumnSizes[%d][0] = %d",*returnSize , returnColumnSizes[*returnSize][0]);

            (*returnSize)++;   
        }   
    }
    
    printf("\n\nIntervalsColSize : %d    ||  returnColsSize : %d",*intervalsColSize, **returnColumnSizes);
    printf("\nreturnArray[%d][%d] = %d", 0, 0, arrayRetorno[0][0]);
    printf("\nreturnArray[%d][%d] = %d", 0, 1, arrayRetorno[0][1]);
    printf("\n\nReturn Size: %d", *returnSize);
    
    return arrayRetorno;
}

bool isBetweenIntervals(int min, int value, int max){
    return (min <= value && value <= max);
}

