#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isBetweenIntervals(int min, int value, int max);
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes);


int main(){
    int             intervalsSize = 4;
    int             intervalsColSize = 2;
    int**           intervals = (int **)malloc(intervalsSize * sizeof(int *));
    int             **returnColumnSizes = (int**) malloc(sizeof(int*));
    int             returnSize;
    int             **returnArray;


    for (int i = 0; i < intervalsSize; i++) {
        intervals[i] = (int *)malloc(intervalsColSize * sizeof(int));
    }
    intervals[0][0] = 1;    intervals[0][1] = 3;
    intervals[1][0] = 2;    intervals[1][1] = 6;
    intervals[2][0] = 8;    intervals[2][1] = 10;
    intervals[3][0] = 15;   intervals[3][1] = 18;
    
    returnArray = merge( intervals, intervalsSize, &intervalsColSize, &returnSize, returnColumnSizes );

    for ( int i = 0; i < intervalsSize; i++ ) {
        free ( intervals[i] );
    }
    free( intervals );

    printf( "[" );
    for ( int i = 0; i < returnSize; i++ ) {
        printf ( "[%d, %d]", returnArray[i][0], returnArray[i][1] );
        free ( returnArray[i] );
    }
    printf ("]");
    free ( returnArray );
    free ( *returnColumnSizes );
    free ( returnColumnSizes );

    return 0;
}

int** merge ( int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes ){
    int         newCs = intervalsSize;
    int         aMin, aMax, bMin, bMax;
    int**       arrayRetorno;
    int *a, *b;

    for ( int i = 0; i < intervalsSize; i++ ) {
        for ( int j = 0; j < intervalsSize; j++ ){
            if (i == j) continue;

            a = intervals[i];
            b = intervals[j];
            if(a[0] == -1 || b[0] == -1) continue;

            aMin = a[0];aMax = a[1];
            bMin = b[0];bMax = b[1];

            if(isBetweenIntervals(aMin, bMin, aMax) && isBetweenIntervals (aMin, bMax, aMax)){                
                    b[0] = -1;
                    newCs--;
            }
            else if (isBetweenIntervals(aMin, bMin, aMax) && isBetweenIntervals(bMin, aMax, bMax)){         
                    a[1] = b[1];
                    b[0] = -1;
                    newCs--;
            }
            else if (isBetweenIntervals(bMin, aMin, bMax) && isBetweenIntervals(aMin, bMax, aMax)){
                    b[1] = a[1];
                    a[0] = -1;
                    newCs--;
            }
            else if (isBetweenIntervals(bMin, aMin, bMax) && isBetweenIntervals (bMin, aMax, bMax)){
                    a[0] = -1;
                    newCs--;
            }

        }
    }
    
    arrayRetorno = (int**) malloc (sizeof(int*) * newCs);
    *returnColumnSizes = (int*) malloc(sizeof(int) * newCs);
    (*returnSize) = 0;

    for(int i = 0; i < intervalsSize; i++){
    
        int *a;
        a = intervals[i];
    
        if(a[0] != -1){
            (*returnColumnSizes)[*returnSize] = 2;
            
            arrayRetorno[*returnSize] = (int*) malloc(sizeof(int) * 2);
            arrayRetorno[*returnSize][0] = a[0];
            arrayRetorno[*returnSize][1] = a[1];
            
            (*returnSize)++;   
        }
           
    }   
    return arrayRetorno;
}
bool isBetweenIntervals(int min, int value, int max){
    return (min <= value && value <= max);
}

