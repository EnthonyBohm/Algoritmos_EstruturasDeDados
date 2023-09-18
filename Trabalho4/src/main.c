/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int getMin(int* matrix);
int getMax(int* matrix);
bool isBetweenIntervals(int min, int value, int max);

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int newCs = intervalsSize;
    int aMin, aMax, bMin, bMax;
    int** returnArray;
    returnArray = (int**) malloc (sizeof(int*));

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
    intervals = (int**) malloc (sizeof(int*) * newCs);
    returnColumnSizes = (int**) malloc(sizeof(int*) * newCs);

    (*returnSize) = 0;

    for(int i = 0; i < intervalsSize; i++){
        int *a;
        a = intervals[i];
        printf("\n a[0] : %d", intervals[i][0]);
        if(a[0] != -1){
            returnColumnSizes = (int**) malloc(sizeof(int));
            returnColumnSizes[*returnSize][0] = 2;
            intervals[*returnSize] = (int*) malloc (sizeof(int) * 2);
            intervals[*returnSize][0] = a[0];
            intervals[*returnSize][1] = a[1];
            (*returnSize)++;
        }
    }

    return intervals;
}


int getMin (int* matrix){
    return matrix[0];
}
int getMax (int* matrix) {
    return matrix[1];
}

bool isBetweenIntervals(int min, int value, int max){
    return (min <= value && value <= max);
}