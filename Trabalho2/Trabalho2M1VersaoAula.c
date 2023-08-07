#include <stdio.h>
#include <stdlib.h>
/*
Precisa Olhar a posição atual e uma posição ao lado.

    []  []  []

Se tiver pelo menos 1, encontra o próximo que também tenha 1 ou mais

Se i > i+1  trava no i
Senão trava no i+1

j = i+1
    Se j+1 > j-1  trava no j+1
    Senão trava no j-1

*/

/*
Preciso achar uma forma de impedir de subtrair o valor de algo quando este valor já for zero
*/
int fillCups(int* amount, int amountSize);


int main(){

    int *amount = NULL;
    amount = (int* ) malloc(sizeof(int));

    amount[0] = 5;  //  4   3   2   1   0   0   0   
    amount[1] = 4;  //  3   3   2   2   2   1   0
    amount[2] = 4;  //  4   3   3   3   2   1   0

    int result;

    result = fillCups(amount, 3);

    

    printf("%d", result);

}


int fillCups(int* amount, int amountSize){
    int seconds=0;
    int i = 0, j;

    while(i < amountSize ){

        printf("Amount[0]: %d\n",amount[0]);
        printf("Amount[1]: %d\n",amount[1]);
        printf("Amount[2]: %d\n",amount[2]);    
        getchar();
        while(amount[i] == 0)
            i++;
        if(i != 2){     //Não posso acessar a posição 3
            if( amount[i] > amount[i+1] ){
                j = i;

                if ( amount[j+1] > amount[j+2]){
                    amount[j]--;
                    amount[j+1]--;
                }
                else{
                    amount[j]--;
                    amount[j+2]--;
                }

                seconds++;
                continue;
            }

            else{
                j = i+1;

                if ( amount [j + 1] > amount[j-1] ){
                    amount[j]--;
                    amount[j+1]--;
                }
                else{
                    amount[j]--;
                    amount[j-1]--;
                }
                seconds++;
                continue;
            }
        }
        else{
            amount[i]--;
            seconds++;
        }
    }
    return seconds;
}