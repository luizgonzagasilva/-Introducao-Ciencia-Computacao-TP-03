#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


void separaNodes(Linha *no_linha, char linha[1024]){
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

    pont_arq = fopen("dados1.txt", "r");

    while(fgets(linha, sizeof(linha), pont_arq) != NULL){
        /* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */
		int indiceUltimoCaractere = strlen(linha) - 1;
		if(linha[indiceUltimoCaractere] == '\n') {
			linha[indiceUltimoCaractere] = '\0';
		}
        separaNodes(&no_linha, linha);
        insere_ArvBin(raiz, no_linha);
    }

    int TNv=0, TSd=0, TNd=0;
    visitaNodes(raiz, &TNv, &TSd, &TNd);
    printf("TNv %d\n",TNv);
    printf("TSd %d\n",TSd);
    printf("TNd %d\n",TNd);

    fclose(pont_arq);
    system("Pause");

    return 0;

}
