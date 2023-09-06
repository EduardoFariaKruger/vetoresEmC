#include <stdio.h>
#include <unistd.h>

#define MAX 100

void preenche_vetor(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d", &vetor[i]);
    }
}

void imprime_vetor(int vetor[], int tamanho)
{
    sleep(1);
    printf("\e[1;1H\e[2J");
    printf("--------------------------------------------------------------");
    printf("\n");
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < vetor[i]; j++)
        {
            printf("==");
        }
        printf("\n");
    }
    printf("--------------------------------------------------------------");
}

void insertion_sort(int vetor[], int tamanho) {
  for (int i = 1; i < tamanho; i++) {
    int chave = vetor[i];
    int j = i - 1;
    while (chave < vetor[j] && j >= 0) {
      vetor[j + 1] = vetor[j];
      --j;
    }
    vetor[j + 1] = chave;
    imprime_vetor(vetor, tamanho);
  }
}

void selection_sort(int vetor[], int tamanho)
{
    int menor;
    for (int i = 0; i < tamanho; i ++)
    {
        menor = vetor[i];
        int aux;
        for (int j = i+1; j < tamanho; j++)
        {
            if (vetor[j] < menor)
            {
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
        imprime_vetor(vetor, tamanho);
    }
}

int main ()
{

    int tam;
    int vetor[MAX];

    

    scanf("%d", &tam);
    preenche_vetor(vetor, tam);
    selection_sort(vetor, tam);


    sleep(2);

    scanf("%d", &tam);
    preenche_vetor(vetor, tam);

    insertion_sort(vetor, tam);


    return 0;
}