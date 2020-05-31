
typedef struct NO* ArvBin;

typedef struct{
    char raiz[100], esq[100], dir[100];
} Linha;

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Linha no_linha);
void visitaNodes(ArvBin* raiz, int *pTNv, int *pTSd, int *pTNd);



