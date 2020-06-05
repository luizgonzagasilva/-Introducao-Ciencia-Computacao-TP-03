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
        printf("linha raiz: %s\n", linha);
        printf("linha size: %d\n", strlen(linha));
        /* Remove a nova linha (\n), caso ela tenha sido lida pelo fgets */

		/*int indiceUltimoCaractere = strlen(linha) - 1;
		if(linha[indiceUltimoCaractere] == '\n') {
			linha[indiceUltimoCaractere] = '\0';
		}*/

        int tam_linha = strlen(linha);
        for (int i=0; i<tam_linha+1; i++) {
            if(linha[i] == '\n') {
                linha[i] = '\0';
            }
        }

		//strcpy( linha, removeNewLine(linha) );
        separa_Linha(&no_linha, linha);

        //strcpy( no_linha.raiz, removeNewLine(no_linha.raiz) );
        //strcpy( no_linha.esq, removeNewLine(no_linha.esq) );
        //strcpy( no_linha.dir, removeNewLine(no_linha.dir) );

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
