//
// Created by tiago on 16/04/2024.
//
#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lista.h"

struct hash{
    lista **tabela;
    int tamanho;
};

hash *criaHash(int tam){
    hash *h;
    h = (hash*)malloc(sizeof(hash));
    if(!h)
        return NULL;

    h->tabela = (lista**) malloc(tam*sizeof(lista*));
    if(!h->tabela)
        return NULL;
    for(int i=0;i<tam;i++){
        h->tabela[i]=criaLista();
        if(!h->tabela[i])
            return NULL;
    }
    h->tamanho=tam;
    return h;
}

int funcaoHash(char *palavra, int tamHash){
    int soma = 0;
    for(int i=0;i<strlen(palavra);i++){
        soma += palavra[i];
    }
    return soma%tamHash;
}

void insere(hash *h, char *palavra){
    insereLista(h->tabela[funcaoHash(palavra,h->tamanho)],palavra);
}

int encontraElemento(hash *h, char *palavra){
    if(!buscaLista(getLista(h->tabela, funcaoHash(palavra,h->tamanho)),palavra)){
        return -1;
    }else{
        return funcaoHash(palavra,h->tamanho);
        }
    }

void percorre(hash *h, int pos){
    imprimeLista(h->tabela[pos]);
}

int getTamanhoLista(hash *h, int pos){
    return getTamLista(h->tabela[pos]);
}

int removeElemento(hash *h, char *palavra){
    if(encontraElemento(h,palavra)<0)
        return -1;
    removeLista(h->tabela[encontraElemento(h,palavra)],palavra);
    return 0;
}