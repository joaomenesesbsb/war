#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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

void atacar(Territorio *territorio1, Territorio *territorio2){
    int t1 = (rand() % 6) + 1;
    int t2 = (rand() % 6) + 1;

    printf("O ataque inicia \n");
    printf("valor do territorio %s : (%d) \n", territorio1->nome, t1);
    printf("valor do territorio %s : (%d) \n", territorio2->nome, t2);

    if(t1 > t2){
        printf("territorio %s VENCEU", territorio1->nome);
        //vencedor ganha tropas
        territorio1->tropas = territorio1->tropas + territorio2->tropas;
        //territorio muda cor
        strcpy(territorio2->cor, territorio1->cor);
        //territorio perde tropas
        territorio2->tropas = 0;
    }
    else  if(t1 < t2){
        printf("territorio %s VENCEU", territorio2->nome);
        //vencedor ganha tropas
        territorio2->tropas = territorio1->tropas + territorio2->tropas;
        //territorio muda cor
        strcpy(territorio1->cor, territorio2->cor);
        //territorio perde tropas
        territorio1->tropas = 0;
    }
    else if(t1 == t2){
         printf("EMPATE!! Nada muda \n");
    }
}

int main() {
    srand(time(NULL));

    int tamanho;

    printf("Digite a quantidade de Territorios: ");
    scanf("%d", &tamanho);

    //Cria territorio em memoria
    Territorio *territorio = malloc(tamanho * sizeof(Territorio));

    criarTerritorio(territorio,tamanho);
    mostrarTerritorios(territorio,tamanho);

    //Pede ao usuario quem deve atacar e quem vai ser atacaado
    int a, b;
    printf("\nEscolha o território que ATACA: ");
    scanf("%d", &a);

    printf("Escolha o território que será ATACADO: ");
    scanf("%d", &b);
    atacar(&territorio[a -1], &territorio[b - 1]);

    mostrarTerritorios(territorio,tamanho);

    //Limpa memoria
    free(territorio);

    return 0;
}