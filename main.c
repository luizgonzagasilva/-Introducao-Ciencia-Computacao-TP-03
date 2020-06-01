#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinaria.h"


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
