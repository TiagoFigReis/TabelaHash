//
// Created by tiago on 16/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no{
    char palavra[30];
    struct  no *prox;
};

struct lista{
    struct no *inicio;
    int tam;
};

lista *criaLista(){
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    if(!l){
        return NULL;
    }
    l->inicio=NULL;
    l->tam = 0;
    return l;
}

int insereLista(lista *l, char *palavra){
    no *n;
    n = (no*)malloc(sizeof(no));
    if(!n)
        return 1;
    strcpy(n->palavra,palavra);
    if(!l->inicio){
        n->prox = NULL;
        l->inicio = n;
        l->tam++;
    }else{
        n->prox = l->inicio;
        l->inicio = n;
        l->tam++;
    }
    return 0;
}

lista *getLista(lista **vet, int pos){
    return vet[pos];
}

int getTamLista(lista *l){
    return l->tam;
}

int buscaLista(lista *l, char *palavra){
    no *aux;
    aux = l->inicio;
    while(aux){
        if(strcmp(aux->palavra,palavra)==0)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void removeLista(lista *l, char *palavra){
    no *aux,*ant;
    aux = l->inicio;
    while(aux && strcmp(aux->palavra,palavra)!=0){
        ant = aux;
        aux = aux->prox;
    }
    if(aux) {
        if (aux == l->inicio) {
            l->inicio = aux->prox;
            l->tam--;
        } else {
            ant->prox = aux->prox;
            l->tam--;
        }
    }
    free(aux);
}

void imprimeLista(lista *l){
    if(!l->tam) {
        printf("Lista Vazia\n");
        return;
    }
    no *noAux = l->inicio;
    while(noAux) {
        printf("\n%s", noAux->palavra);
        noAux = noAux->prox;
    }
}