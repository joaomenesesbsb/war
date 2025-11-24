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

    for(int i = 0; i < 5 ; i++)
    {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Nome: ");
        scanf("%29s", territorio[i].nome);

        printf("Cor: ");
        scanf("%9s", &territorio[i].cor);

        printf("Tropas: ");
        scanf("%e", &territorio[i].tropas);
    }

   
}