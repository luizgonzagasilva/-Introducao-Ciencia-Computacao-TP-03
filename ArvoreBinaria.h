
typedef struct NO* ArvBin;

typedef struct{
    char raiz[100], esq[100], dir[100];
} Linha;

ArvBin* cria_ArvBin();
void libera_ArvBin(ArvBin *raiz);
int insere_ArvBin(ArvBin* raiz, Linha no_linha);
int remove_ArvBin(ArvBin *raiz, int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, int valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);

