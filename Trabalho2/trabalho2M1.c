/*
Enthony Gabriel Rodrigues Bohm
M1
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int fillCups            ( int* amount, int amountSize ) ;
bool empty              ( int* amount, int amountSize ) ;

int main () {
   
    int                 amount[] = {5,4,4};
    int                 result;
    
    result = fillCups(amount, 3);
    printf("%d", result);
}

/* 
======================================================================
fillCups

    Dado um array com diferentes valores,
    Onde cada valor representa a quantidade de copos a serem enchidos
    Com diferentes tipos de água
    Retornar o menor número de segundos onde é possível encher
    2 copos de diferentes tipos de agua no mesmo segundo
    1 copo de água do mesmo tipo em um segundo
=====================================================================
*/

int fillCups (int* amount, int amountSize){
    
    int                 seconds=0;
    int                 i, *first, *second;

    while (!empty(amount, amountSize)){

        first = amount;                                  
        second = NULL;

        for ( i = 1; i < amountSize; i++ ) {
            if (*first < amount[i]){
                first = &amount[i];
            }
        }
        for ( i = 0; i < amountSize; i++ ) {
            if ( (&amount[i] != first) && (second == NULL  || *second < amount[i]) ) {
                second = &amount[i];
            }
        }
        

        
        if (second != NULL && *second != 0) {
            (*first)--;
            (*second)--;
        } else {
            (*first)--;   
        }
        
        seconds++;

        if (empty (amount, amountSize)){
            break;
        }    
    }
    return seconds;
}


/* 
======================================================================
    empty

Checa e retorna se o array esta vazio, ou seja, se todos os copos
ja foram enchidos
=====================================================================
*/

bool empty ( int* amount, int amountSize ) {
    for ( int i=0; i < amountSize; i++ ) {
        if (amount[i] != 0)
            return false;
    }
    return true;
}
