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

    ArvBin* raiz = cria_ArvBin();
    Linha no_linha;

    //fgets(linha,10,stdin);
    char linha1[] = "A1,B1,B2";
    char linha2[] = "B1,C1,X";
    char linha3[] = "B2,X,S1";
    //char linha4[] = "C1,D1,D2";
    char linha4[] = "C1,X,X";

    separaNodes(&no_linha, linha1);
    insere_ArvBin(raiz, no_linha);

    separaNodes(&no_linha, linha2);
    insere_ArvBin(raiz, no_linha);

    separaNodes(&no_linha, linha3);
    insere_ArvBin(raiz, no_linha);

    separaNodes(&no_linha, linha4);
    insere_ArvBin(raiz, no_linha);

    visitaNodes(raiz);

    system("Pause");

    return 0;
}
