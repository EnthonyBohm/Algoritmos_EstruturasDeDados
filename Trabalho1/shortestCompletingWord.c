/*
Enthony Gabriel Rodrigues Bohm
M1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *ShortestCompletingWord(char * licensePlate, char ** words, int wordsSize);

int main(){
    char *words[] = {
        "nice","idea","hard","statement","money","later","interesting","which","purpose","evening"
    };
    char *answer = ShortestCompletingWord("Im806", words, 10);

    puts(answer);
}

/* 
======================================================================
ShortestCompletingWord

    Dado um conjunto de palavras acha a menor e primeira palavra,
    que contem todos os valores de uma string "LicensePlate"
=====================================================================
*/

char * ShortestCompletingWord( char * licensePlate, char ** words, int wordsSize ) {
    char validLetters[strlen ( licensePlate ) + 1], word[16];
    int  i, j, k, totLetters = 0, indexAceptedWord = 0, lenghtAceptedWord = 21;
    bool invalidWord;
    

    for ( i = 0; licensePlate[i] != '\0'; i++ ) {

        if ( ( ( licensePlate[i] - 'a' ) >= 0) && ( ( licensePlate[i] - 'a' ) < 26 ) )
            validLetters[totLetters++] = licensePlate[i] ;
        else if ( ( ( 'a' - licensePlate[i] ) >= 7 ) && ( ( 'a' - licensePlate[i] ) <= 32 ) )
            validLetters[totLetters++] = licensePlate[i] +32 ;    
    }
    validLetters[totLetters] = '\0';

    for ( k = 0; k < wordsSize; k++ ) {

        invalidWord = false;
        strcpy ( word, words[k] ) ;
        
        for ( i = 0;validLetters[i] != '\0'; i++ ){

            for ( j=0; ; j++ ) {

                if ( word[j] == '\0' ) {
                    invalidWord = true;
                    break;
                }
                if ( word[j] == validLetters[i] ) {
                    word[j] = '_';
                    break;
                }

            }

            if ( invalidWord == true ) {
                break;
            }

        }

        if ( !invalidWord && ( ( int ) strlen ( words[k] ) ) < lenghtAceptedWord ) {
            indexAceptedWord = k;
            lenghtAceptedWord = (int) strlen ( words[k] ) ; 
        }

    }

    return words[indexAceptedWord];
}