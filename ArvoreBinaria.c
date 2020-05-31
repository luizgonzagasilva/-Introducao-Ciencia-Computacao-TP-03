#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Protótipos

int TNv_esq=0, TNv_dir=0;

struct NO{
    char info[100];
    struct NO *esq;
    struct NO *dir;
};


ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}


int insere_ArvBin(ArvBin* raiz, Linha no_linha){
    if(raiz == NULL)
        return 0;

    // primeiro nó a ser inserido na arvore
    if(*raiz == NULL){

        struct NO* novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        strcpy(novo->info,no_linha.raiz);
        novo->esq = NULL;
        novo->dir = NULL;

        if (no_linha.esq[0] != 'X'){
            struct NO* novo_esq = (struct NO*) malloc(sizeof(struct NO));
            strcpy(novo_esq->info,no_linha.esq);
            novo_esq->dir = NULL;
            novo_esq->esq = NULL;
            novo->esq = novo_esq;
        }
        if (no_linha.dir[0] != 'X'){
            struct NO* novo_dir = (struct NO*) malloc(sizeof(struct NO));
            strcpy(novo_dir->info,no_linha.dir);
            novo_dir->dir = NULL;
            novo_dir->esq = NULL;
            novo->dir = novo_dir;
        }
        *raiz = novo;
    }
    // proximos nós a ser inserido na arvore
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;

        ArvBin* sub_esq = cria_ArvBin();
        ArvBin* sub_dir = cria_ArvBin();

        // se nao encontra valor entra em recursao
        //printf("no_linha.raiz: %s(%d), atual->info: %s(%d)\n",no_linha.raiz, strlen(no_linha.raiz), atual->info, strlen(atual->info));
        int nao_achou = strcmp(no_linha.raiz, atual->info);
        if (nao_achou){
            *sub_esq = atual->esq;
            *sub_dir = atual->dir;
            insere_ArvBin(sub_esq, no_linha);
            insere_ArvBin(sub_dir, no_linha);
        }
        else {
            if (no_linha.esq[0] != 'X'){
                struct NO* novo_esq = (struct NO*) malloc(sizeof(struct NO));
                strcpy(novo_esq->info,no_linha.esq);
                novo_esq->dir = NULL;
                novo_esq->esq = NULL;
                atual->esq = novo_esq;
            }
            if (no_linha.dir[0] != 'X'){
                struct NO* novo_dir = (struct NO*) malloc(sizeof(struct NO));
                strcpy(novo_dir->info,no_linha.dir);
                novo_dir->dir = NULL;
                novo_dir->esq = NULL;
                atual->dir = novo_dir;
            }
        }
    }

    return 1;
}


void visitaNodes(ArvBin* raiz, int *pTNv, int *pTSd, int *pTNd){
    struct NO* atual = *raiz;
    ArvBin* sub_esq = cria_ArvBin();
    ArvBin* sub_dir = cria_ArvBin();
    char node[50], esqDir[50];
    int i=0, qtd_nodes=0;

    // avalia a raiz
    if (*raiz==NULL){
        if (TNv_esq > *pTNv)
            *pTNv = TNv_esq;
        else if (TNv_dir > *pTNv)
            *pTNv = TNv_dir;

        TNv_esq=0;
        TNv_dir=0;

        return;
    }

    *pTNd = *pTNd + 1;
    strcpy(node, atual->info);
    // avalia sub-arvore esquerda
    if (atual->esq!=NULL){
        esqDir[i]='E';
        esqDir[i+1]='\0';
        i++;
        qtd_nodes++;
        *sub_esq = atual->esq;
    }
    // avalia sub-arvore direita
    if (atual->dir!=NULL){
        esqDir[i]='D';
        esqDir[i+1]='\0';
        i++;
        qtd_nodes++;
        *sub_dir = atual->dir;
    }
    // se nao possui nodes entao eh um no folha
    if (qtd_nodes==0){
        esqDir[i]='F';
    }


    // numero de nos saida("S")
    if (node[0]=='S')
        *pTSd = *pTSd + 1;

    printf("%s %d %s\n", node, qtd_nodes, esqDir);
    TNv_esq = TNv_esq + 1;
    visitaNodes(sub_esq, pTNv, pTSd, pTNd);
    TNv_dir = TNv_dir + 1;
    visitaNodes(sub_dir, pTNv, pTSd, pTNd);

    // obtem a direcao mais profunda e soma raiz




}
