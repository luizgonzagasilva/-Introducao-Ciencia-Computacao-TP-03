#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NO* ArvBin;

typedef struct{
    char raiz[100], esq[100], dir[100];
} Linha;

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Linha no_linha);
void visitaNodes(ArvBin* raiz, int *pTNv, int *pTSd, int *pTNd);

int TNv_esq=0, TNv_dir=0, TNv=0;

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

void visita_ArvBin(ArvBin* raiz, int *pTNv, int *pTSd, int *pTNd){
    struct NO* atual = *raiz;
    ArvBin* sub_esq = cria_ArvBin();
    ArvBin* sub_dir = cria_ArvBin();
    char node[50], esqDir[50];
    int i=0, qtd_nodes=0;

    // avalia a raiz
    if (*raiz==NULL){
        if (TNv>*pTNv)
            *pTNv = TNv;
        return;
    }

    // numero total de nos
    *pTNd = *pTNd + 1;
    strcpy(node, atual->info);

    if (atual->esq!=NULL || atual->dir!=NULL){
        TNv = TNv + 1;
        // avalia sub-arvore esquerda
        if (atual->esq!=NULL){
            TNv_esq = TNv_esq + 1;
            esqDir[i]='E';
            esqDir[i+1]='\0';
            i++;
            qtd_nodes++;
            *sub_esq = atual->esq;
        }
        // avalia sub-arvore direita
        if (atual->dir!=NULL){
            TNv_dir = TNv_dir + 1;
            esqDir[i]='D';
            esqDir[i+1]='\0';
            i++;
            qtd_nodes++;
            *sub_dir = atual->dir;
        }
    }
    // se nao possui nodes entao eh um no folha
    if (qtd_nodes==0){
        esqDir[i]='F';
    }

    // numero de nos saida("S")
    if (node[0]=='S')
        *pTSd = *pTSd + 1;

    printf("%s %d %s\n", node, qtd_nodes, esqDir);
    visita_ArvBin(sub_esq, pTNv, pTSd, pTNd);
    visita_ArvBin(sub_dir, pTNv, pTSd, pTNd);

}

void separa_Linha(Linha *no_linha, char linha[1024]){
    int n = strlen(linha);
    int j=0, pos_linha=1;
    for (int i=0; i<n; i++){
        if (linha[i]!=',' && pos_linha==1){
            no_linha->raiz[j] = linha[i];
            no_linha->raiz[j+1] = '\0';
            j++;
        }
        else if (linha[i]!=',' && pos_linha==2){
            no_linha->esq[j] = linha[i];
            no_linha->esq[j+1] = '\0';
            j++;
        }
        else if (linha[i]!=',' && pos_linha==3){
            no_linha->dir[j] = linha[i];
            no_linha->dir[j+1] = '\0';
            j++;
        }
        else {
            pos_linha++;
            j=0;
        }
    }

}


int main(){

    FILE *pont_arq;
    ArvBin* raiz = cria_ArvBin();
    Linha no_linha;
    char linha[1024];

    pont_arq = fopen("dados.txt", "r");

    while(fgets(linha, sizeof(linha), pont_arq) != NULL){
        /* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */
		int indiceUltimoCaractere = strlen(linha) - 1;
		if(linha[indiceUltimoCaractere] == '\n') {
			linha[indiceUltimoCaractere] = '\0';
		}
        separa_Linha(&no_linha, linha);
        insere_ArvBin(raiz, no_linha);
    }

    int TNv=0, TSd=0, TNd=0;
    visita_ArvBin(raiz, &TNv, &TSd, &TNd);
    printf("TNv %d\n",TNv);
    printf("TSd %d\n",TSd);
    printf("TNd %d\n",TNd);

    fclose(pont_arq);
    libera_ArvBin(raiz);
    system("Pause");

    return 0;

}