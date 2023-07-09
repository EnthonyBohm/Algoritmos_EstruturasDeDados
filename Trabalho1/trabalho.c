#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1. Separar as letras úteis das inúteis
2. Encontrar uma maneira de fazer com que tenha a mesma quantia ou mais letras na completionWord do que na validLetters
    2.1 Criar uma variável auxiliar que vai receber as letras validas e preenche com _ se achar a letra
    2.2 Checar em uma função se todas as 
3. 
*/

char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main(){
    char **words = {"step", "steps", "stipe", "steeple"};
    char *answer = shortestCompletingWord("1s3 PSt", words, 4);

    printf("%c", answer);
}


char * shortestCompletingWord(char * licensePlate, char ** words, int wordsSize){
    char validLetters[strlen(licensePlate)], *aux;
    int i, j, totLetters = 0;
    

    for(i = 0; licensePlate[i] != '\0'; i++){
        if(licensePlate[i] - 'a' >= 0 && licensePlate[i - 'a' < 26])
            validLetters[totLetters++] = licensePlate[i];
        else if('a' - licensePlate[i] >= 7 && 'a' - licensePlate[i]<=32)
            validLetters[totLetters++] = licensePlate[i] +32;
    }

    aux = (char *) malloc(totLetters * (sizeof(char)));
    while(words){
        
    }
    
    return 0;
}
