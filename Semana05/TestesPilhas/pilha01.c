#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100
#define NOME_MAX 100

typedef struct {
    char nome[NOME_MAX];
    char telefone[20];
}Pessoa;

typedef struct {
    Pessoa pessoas[NOME_MAX];
    int base ;
    int topo ;
    int limite ;

}Pilha;

void RESET (Pilha *p);
bool PUSH ( Pilha *p, char *pessoa, char *numero);
char** POP ( Pilha *p);

int main(){
    Pilha* agenda = NULL;
    agenda = ( Pilha *) malloc ( sizeof ( Pilha ) );
    RESET(agenda);
    printf("Pelo menos resetou");
    PUSH(agenda, "Enthony", "55 53 123442-3133");

    printf("Nome na agenda: %s \nContato: %s", agenda -> pessoas[ agenda -> topo-1].nome, agenda -> pessoas [ agenda -> topo - 1].telefone );
}

void RESET (Pilha *p){
    p -> base = 0;
    p -> topo = 0;
    p -> limite = NOME_MAX;
}

bool PUSH ( Pilha *p, char *pessoa, char* numero) {
    if ( p -> topo == p -> limite )
        return false;
    strcpy ( p -> pessoas [ p -> topo ].nome, pessoa ) ;
    strcpy ( p -> pessoas [ p -> topo ].telefone, numero ) ;
    p -> topo++;
    return true;
}

char** POP ( Pilha *p){
    char** retorno = NULL;
    retorno = (char **) malloc(sizeof(char*) * 2);

    p -> topo --;
    
    *retorno = (char*) malloc ( sizeof ( char ) * NOME_MAX);
    strcpy ( *retorno, p -> pessoas [ p -> topo + 1 ].nome ) ;
    *(retorno + 1) = ( char * ) malloc ( sizeof ( char ) * NOME_MAX ) ;
    strcpy ( *(retorno + 1), p -> pessoas [ p -> topo + 1 ].telefone ) ;

    return retorno;
}
