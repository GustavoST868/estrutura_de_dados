#include <stdio.h>
#include <stdlib.h>

int topo = -1;
int quantidade;

struct Pilha
{
    int *pilha;
};
struct Pilha p;

void Empilhar(int item)
{
    if (topo < quantidade - 1)
    {
        topo++;
        p.pilha[topo] = item;
    }
    else
    {
        printf("Pilha cheia! Não é possível empilhar mais.\n");
    }
}

void Desempilhar()
{
    if (topo >= 0)
    {
        p.pilha[topo] = 0;
        topo--;
    }
    else
    {
        printf("Pilha vazia! Não é possível desempilhar.\n");
    }
}

void MostrarRecursivamente()
{
    if (topo >= 0)
    {
        printf("%d", p.pilha[topo]);
        p.pilha[topo] = 0;
        topo--;
        MostrarRecursivamente();
    }
    else
    {
        printf("\n\n");
    }
}

int main()
{
    int escolha = 0;
    int item;

    printf("Tamanho da pilha: ");
    scanf("%d", &quantidade);

    p.pilha = (int *)malloc(quantidade * sizeof(int));

    while (escolha != 3)
    {

        printf("\n\n\nInforme a opcao desejada:\n1-Empilhar\n2-Desempilhar\n4-Mostrar\n3-Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {

        case 1:
            printf("Informe o item: ");
            scanf("%d", &item);
            Empilhar(item);
            break;

        case 2:
            Desempilhar();
            break;

        case 3:
            printf("Saindo...\n");
            break;

        case 4:
            printf("\n\n");
            printf("Pilha:\n");
            MostrarRecursivamente(topo);
            printf("\n\n");
            break;

        default:
            printf("Opcao inválida!\n");
            break;
        }
    }
    free(p.pilha);
    return 0;
}
