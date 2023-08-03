#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NOME_MAX 50

typedef struct {
    char nome[NOME_MAX];
    int idade;
    float tamanho;
}Pessoa;

void liberaMemoria(Pessoa** Matriz, int qtdeColunas);

int main(){
    Pessoa** pessoas = NULL;
    int qtdePessoas = 0;
    bool proceed = true; 
    char answer;

    while (proceed) {
        qtdePessoas++;
        pessoas = ( Pessoa ** ) realloc(pessoas, qtdePessoas * sizeof(Pessoa*)) ;
        pessoas[qtdePessoas - 1] = ( Pessoa* ) malloc ( NOME_MAX * sizeof ( Pessoa ) );

        printf("Qual o nome dessa pessoa? ");
        scanf("%s", pessoas[qtdePessoas - 1]->nome);
        printf("Qual a idade do %s: ", pessoas[qtdePessoas - 1]->nome);
        scanf("%d", &pessoas[qtdePessoas - 1]->idade);
        printf("Qual a altura que essa pessoa tem? ");
        scanf("%f", &pessoas[qtdePessoas - 1] -> tamanho);

        getchar();
        printf("Para não ler mais ninguem, digite N ");
        answer = getchar();
        getchar();
        if(answer == 'N' || answer == 'n')
            proceed = false;
        
        system("clear");
    }

    printf("+=+=+=+=+=+=Pessoas Cadastradas+=+=+=+=+=+=\n");
    for(int i = 0; i < qtdePessoas; i++){
        printf("%d° Pessoa: %s", i+1, pessoas[i] -> nome);
        printf("\n idade : %d  || Altura :%.2f ", pessoas[i] -> idade, pessoas[i] -> tamanho);
        printf("\n \n");
    }
    
    liberaMemoria(pessoas, qtdePessoas);
}

void liberaMemoria(Pessoa** Matriz, int qtdeColunas){
    for(int i = 0; i <  qtdeColunas; i++)
        free(Matriz[i]);
    free(Matriz);
}