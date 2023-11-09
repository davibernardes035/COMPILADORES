#include <stdio.h>
#include <string.h>

// Tabela de simbolos

#define TAM_TAB 100

struct elemTabSimbolos {
    char id[100];   // nome do identificador
    int end;        // endereco
    int tip;        // tipo
} tabSimb[TAM_TAB], elemTab;

int posTab = 0; // indica a proxima posicao livre para inserir

int buscaSimbolo (char *s){
    int i;
    for (i = posTab - 1; strcmp(tabSimb[i].id, s) && i >= 0; i--); // strcmp(tabSimb[i].id, s) se for igual é true (1) false (0) e para

    if(i == -1){
        char msg[200];
        sprintf(msg, "Identificador [%s] não encontrado!", s);
        yyerror(msg);
    }
    return i;
}

void insereSimbolo (struct elemTabSimbolos elem){
    int i;

    if(posTab == TAM_TAB){
        yyerror ("Tabela de simbolo cheia!");
    }

    for (i = posTab - 1; strcmp(tabSimb[i].id, elem.id) && i >= 0; i--); // strcmp(tabSimb[i].id, s) se for igual é true (1) false (0) e para

    if (i != -1)
    {
        char msg[200];
        sprintf(msg, "Identificador [%s] não encontrado!", elem.id);
        yyerror(msg);
    }
    tabSimb[posTab++] = elem;
    
}

// Pilha semantica
#define TAM_PILHA 100

int pilha[TAM_PILHA];
int topo = -1;

void empilha (int valor){
    if(topo == TAM_PILHA)
        yyerror ("Pilha semantica cheia!");

    pilha[topo++] = valor;
}

int desempilha (){
    if (topo == -1)
        yyerror("Pilha vazia!");

    return pilha[topo--];
}