#include <stdio.h>
#include <string.h>

// Definindo a estrutura territorio
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;


int main() {

    // Criando struct territorio
    Territorio territorio[5];

    //inserir os dados em cada posicao do vetor
    for(int i = 0; i < 5 ; i++)
    {
        printf("\nTerritorio %d:\n", i + 1);

        //leitor do nome
        printf("Nome: ");
        scanf("%29s", territorio[i].nome);

        //leitor da cor
        printf("Cor: ");
        scanf("%9s", &territorio[i].cor);

        //leitor de tropas
        printf("Tropas: ");
        scanf("%d", &territorio[i].tropas);
    }

    //mostrar dados
     printf("\n--- Dados dos Territorios ---\n");

        //ler todos os dados de de cada posicao do vetor
        for (int i = 0; i < 5; i++) {
            printf("Territorio %d : -- nome %s -- cor  %s -- %d tropas --\n",
                i + 1,
                territorio[i].nome,
                territorio[i].cor,
                territorio[i].tropas
    );
}
   
}