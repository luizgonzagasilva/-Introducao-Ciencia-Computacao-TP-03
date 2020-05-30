#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"


int main()
{

    ArvBin* raiz = cria_ArvBin();

    //fgets(linha,10,stdin);
    char linha[] = "A1,B1,B2";

    int n = strlen(linha);

    //char raiz[100], esq[100], dir[100];
    Linha no_linha;
    int j=0, pos_linha=1;
    for (int i=0; i<n; i++){
        if (linha[i]!=',' && pos_linha==1){
            no_linha.raiz[j] = linha[i];
            no_linha.raiz[j+1] = "\n";
            j++;
        }
        else if (linha[i]!=',' && pos_linha==2){
            no_linha.esq[j] = linha[i];
            no_linha.esq[j+1] = "\n";
            j++;
        }
        else if (linha[i]!=',' && pos_linha==3){
            no_linha.dir[j] = linha[i];
            no_linha.dir[j+1] = "\n";
            j++;
        }
        else {
            pos_linha++;
            j=0;
        }
    }

    printf("raiz: %s\n", no_linha.raiz);
    printf("esquerda: %s\n", no_linha.esq);
    printf("direita: %s\n", no_linha.dir);

    insere_ArvBin(raiz, no_linha);


    char linha2[] = "B1,C1,X";

    n = strlen(linha2);
    Linha no_linha2;
    j=0, pos_linha=1;
    for (int i=0; i<n; i++){
        if (linha2[i]!=',' && pos_linha==1){
            no_linha2.raiz[j] = linha2[i];
            no_linha2.raiz[j+1] = "\n";
            j++;
        }
        else if (linha2[i]!=',' && pos_linha==2){
            no_linha2.esq[j] = linha2[i];
            no_linha2.esq[j+1] = "\n";
            j++;
        }
        else if (linha2[i]!=',' && pos_linha==3){
            no_linha2.dir[j] = linha2[i];
            no_linha2.dir[j+1] = "\n";
            j++;
        }
        else {
            pos_linha++;
            j=0;
        }
    }

    printf("raiz: %s\n", no_linha2.raiz);
    printf("esquerda: %s\n", no_linha2.esq);
    printf("direita: %s\n", no_linha2.dir);

    insere_ArvBin(raiz, no_linha2);


    char linha3[] = "B2,X,S1";

    n = strlen(linha3);
    Linha no_linha3;
    j=0, pos_linha=1;
    for (int i=0; i<n; i++){
        if (linha3[i]!=',' && pos_linha==1){
            no_linha3.raiz[j] = linha3[i];
            no_linha3.raiz[j+1] = "\n";
            j++;
        }
        else if (linha3[i]!=',' && pos_linha==2){
            no_linha3.esq[j] = linha3[i];
            no_linha3.esq[j+1] = "\n";
            j++;
        }
        else if (linha3[i]!=',' && pos_linha==3){
            no_linha3.dir[j] = linha3[i];
            no_linha3.dir[j+1] = "\n";
            j++;
        }
        else {
            pos_linha++;
            j=0;
        }
    }

    printf("raiz: %s\n", no_linha3.raiz);
    printf("esquerda: %s\n", no_linha3.esq);
    printf("direita: %s\n", no_linha3.dir);

    insere_ArvBin(raiz, no_linha3);


    system("Pause");

    /*
    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    printf("Dados:\n");
    emOrdem_ArvBin(raiz);

    system("Pause");

    printf("\n");
    printf("Percurso:\n");
    Exibe_emOrdem_ArvBin(raiz);

    system("Pause");
    printf("\n");

    i=0;
    Procura_preOrdem_ArvBin(raiz,45, &i);
    if (i==0) printf ("Nao Achou! \n");

    system("Pause");

    libera_ArvBin(raiz);
    */

    return 0;
}
