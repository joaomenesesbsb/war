#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definindo a estrutura territorio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

void criarTerritorio(Territorio *territorio, int tamanho){


    //inserir os dados em cada posicao do vetor
    for(int i = 0; i < tamanho ; i++)
    {
        printf("\nTerritorio %d:\n", i + 1);

        //leitor do nome
        printf("Nome: ");
        scanf("%29s", territorio[i].nome);

        //leitor da cor
        printf("Cor: ");
        scanf("%9s", territorio[i].cor);

        //leitor de tropas
        printf("Tropas: ");
        scanf("%d", &territorio[i].tropas);
    }
}

void mostrarTerritorios(Territorio *territorio, int tamanho){
    //mostrar dados
     printf("\n--- Dados dos Territorios ---\n");

    //ler todos os dados de de cada posicao do vetor
    for (int i = 0; i < tamanho; i++) {
        printf("Territorio %d : -- nome %s -- cor  %s -- %d tropas --\n",
            i + 1,
            territorio[i].nome,
            territorio[i].cor,
            territorio[i].tropas
        );
     }
}

int main() {

    int tamanho;

    printf("Digite a quantidade de Territorios: ");
    scanf("%d", &tamanho);

    Territorio *territorio = malloc(tamanho * sizeof(Territorio));

    criarTerritorio(territorio,tamanho);
    mostrarTerritorios(territorio,tamanho);

    free(territorio);

    return 0;
}