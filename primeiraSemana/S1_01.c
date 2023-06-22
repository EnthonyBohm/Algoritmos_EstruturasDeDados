#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[40];
    int quantidade;
    int ID;
}produto;
struct celula{
    produto conteudo;
    struct celula* prox;
};
typedef struct celula nodo;

nodo* iniciaLista();
void adicionaProduto(nodo* cabeca);
void removeProduto(nodo* cabeca);
void mostraLista(nodo* cabeca);
void carregaLista(nodo* cabeca);
void fechaLista(nodo* cabeca);

int main(){
    int decision=0;
    nodo *cabeca;

    cabeca = iniciaLista();

    while(decision != 4){
        printf( "----Lista Doméstica-----\n"
                "1. Adiciona Produto\n"
                "2. Remove Produto\n"
                "3. Mostra Lista\n"
                "4. Carrega Lista\n"
                "5. Fechar Lista\n"
                "------------------------\n");
        scanf("%d", &decision);
        
        switch(decision){
        case 1:
            adicionaProduto(cabeca);
            break;
        case 2:
            removeProduto(cabeca);
            break;
        case 3:
            mostraLista(cabeca);
            break;
        case 5:
            return 0;
        }
    }


}

nodo* iniciaLista(){
    nodo *head;

    head = (nodo*) malloc(sizeof(nodo));
    head -> prox = NULL;

    return head;
}

void adicionaProduto(nodo* cabeca){
    nodo* novo, *i, *j;

    novo = (nodo *) malloc(sizeof(nodo));

    system("cls");
    printf("\nNovo produto da despensa: ");
    scanf("%s", novo -> conteudo.nome);getchar();
    printf("ID deste produto: ");
    scanf("%d", &novo -> conteudo.ID);
    printf("Quantidade: ");
    scanf("%d", &novo -> conteudo.quantidade);

    i = cabeca ;
    j = cabeca -> prox;
    for( ; j != NULL; i = j, j = j-> prox);
    novo -> prox = j;
    i -> prox = novo;

    
}

void removeProduto (nodo* cabeca){
    int id;
    nodo *i, *j;

    system("cls");
    printf("\nID do produto a ser removido: ");
    scanf("%d", &id);

    i = cabeca ;
    j = cabeca -> prox;
    for( ; j != NULL ;i = j, j = j -> prox){
        if(j -> conteudo.ID == id){
            i -> prox = j -> prox;
            free(j);
            return;
        }
    }

    printf("ID não encontrado");
}

void mostraLista(nodo* cabeca){
    nodo *i, *j;
    char **emFalta = NULL;
    int numFalta = 0, qtdeLetras;

    system("cls");
    printf("\n");
    for(i = cabeca -> prox , j = i -> prox; j != NULL; i = j, j = j -> prox){
        printf( "Nome: %s\n"
                "ID: %d\n"
                "Quantidade: %d\n"
                ,i -> conteudo.nome, i ->conteudo.ID, i -> conteudo.quantidade);
        if(i -> conteudo.quantidade == 0){
            emFalta = realloc(emFalta, (numFalta + 1) * sizeof(char*));
            qtdeLetras = strlen(i -> conteudo.quantidade);
            emFalta[numFalta++] = (char) malloc (sizeof(char) * qtdeLetras);
            strcpy(emFalta, i ->conteudo.nome);
        }
    }
    printf("Produtos em falta: \n");
    for(int index = 0; index < numFalta; i++){
        printf("%d", index);
        puts(emFalta[index]);
    }
}