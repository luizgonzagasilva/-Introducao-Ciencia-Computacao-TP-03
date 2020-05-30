#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


void separaNodes(Linha *no_linha, char linha[100]){
    int n = strlen(linha);
    int j=0, pos_linha=1;
    for (int i=0; i<n; i++){
        if (linha[i]!=',' && pos_linha==1){
            no_linha->raiz[j] = linha[i];
            no_linha->raiz[j+1] = "\0";
            j++;
        }
        else if (linha[i]!=',' && pos_linha==2){
            no_linha->esq[j] = linha[i];
            no_linha->esq[j+1] = "\0";
            j++;
        }
        else if (linha[i]!=',' && pos_linha==3){
            no_linha->dir[j] = linha[i];
            no_linha->dir[j+1] = "\0";
            j++;
        }
        else {
            pos_linha++;
            j=0;
        }
    }

}


int main()
{

    FILE *pont_arq;
    ArvBin* raiz = cria_ArvBin();
    Linha no_linha;
    char linha[100];

    pont_arq = fopen("dados.txt", "r");

    while(fgets(linha, 100, pont_arq) != NULL){
        printf("%s\n",linha);
        separaNodes(&no_linha, linha);
        insere_ArvBin(raiz, no_linha);
    }

    visitaNodes(raiz);

    fclose(pont_arq);
    system("Pause");

    return 0;
}
