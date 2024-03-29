#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int valor;
    struct Item *proximo;
} Item;

typedef Item *tipodoItem;

tipodoItem criarItem(int valor)
{
    if (valor == NULL)
    {
        printf("\nErro ao criar Item!\n");
        return NULL;
    }
    else
    {
        tipodoItem novoItem = (tipodoItem)malloc(sizeof(Item));

        if (novoItem == NULL)
        {
            printf("\nErro ao criar Item!\n");
            return NULL;
        }
        else
        {
            novoItem->valor = valor;
            novoItem->proximo = NULL;
            return novoItem;
        }
    }
}

tipodoItem inserirInicio(int valor, tipodoItem lista)
{
    tipodoItem novoItem = criarItem(valor);

    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista;
        return novoItem;
    }
}

void exibir(tipodoItem lista)
{
    if (lista == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        tipodoItem listaAuxiliar = lista;

        while (listaAuxiliar != NULL)
        {
            printf("[%d] ", listaAuxiliar->valor);
            listaAuxiliar = listaAuxiliar->proximo;
        }
        printf("\n");
    }
}

void MoveMenor(tipodoItem Lista)
{
    if (Lista == NULL || Lista->proximo == NULL)
    {
        // Se a lista estiver vazia ou tiver apenas um elemento, não há nada para fazer
        return;
    }

    tipodoItem menorAnterior = NULL;
    tipodoItem menor = Lista;
    tipodoItem anterior = Lista;
    tipodoItem atual = Lista->proximo;

    while (atual != NULL)
    {
        if (atual->valor < menor->valor)
        {
            menor = atual;
            menorAnterior = anterior;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    if (menor != Lista)
    {
        // Remove o menor elemento de sua posição original
        menorAnterior->proximo = menor->proximo;

        // Move o menor elemento para o início da lista
        menor->proximo = Lista;
        Lista = menor;
    }
}

int main()
{
    tipodoItem lista = NULL;

    // Adicione elementos à lista conforme necessário
    lista = inserirInicio(3, lista);
    lista = inserirInicio(1, lista);
    lista = inserirInicio(2, lista);
    lista = inserirInicio(5, lista);
    
    printf("Lista original: ");
    exibir(lista);

    // Chame a função para mover o menor elemento para o início da lista
    MoveMenor(lista);

    printf("Lista após mover o menor elemento para o início: ");
    exibir(lista);

    // Libere a memória alocada para a lista, se necessário

    return 0;
}
