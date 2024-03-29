#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item
{
    double valor;
    struct Item *anterior;
    struct Item *proximo;
} Item;

typedef Item *tipodoItem;

tipodoItem criarItem(double valor)
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
        novoItem->anterior = NULL;
        return novoItem;
    }
}

tipodoItem inserirInicio(double valor, tipodoItem lista)
{
    tipodoItem novoItem = criarItem(valor);

    if (lista == NULL)
    {
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista;
        lista->anterior = novoItem;
        return novoItem;
    }
}

tipodoItem inserir_Fim(double valor, tipodoItem lista)
{

    tipodoItem novoItem = criarItem(valor);

    if (novoItem == NULL)
    {
        return novoItem;
    }
    else
    {

        tipodoItem listaAuxiliar = lista;

        while (listaAuxiliar->proximo != NULL)
        {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->anterior = listaAuxiliar;

        return lista;
    }
}

tipodoItem inserir_Posicao(double valor, tipodoItem lista, int posicao)
{

    posicao = posicao - 1;

    tipodoItem novoItem = criarItem(valor);

    if (novoItem == NULL)
    {
        return lista;
    }

    if (posicao < 0)
    {
        printf("\nPosicao invalida!\n");
        free(novoItem);
        return lista;
    }

    if (posicao == 0 || lista == NULL)
    {
        novoItem->proximo = lista;
        if (lista != NULL)
        {
            lista->anterior = novoItem;
        }
        return novoItem;
    }

    tipodoItem listaAuxiliar = lista;
    int indice = 0;

    while (listaAuxiliar != NULL && indice < posicao - 1)
    {
        listaAuxiliar = listaAuxiliar->proximo;
        indice++;
    }

    if (listaAuxiliar == NULL)
    {
        printf("\nPosicao invalida!\n");
        free(novoItem);
        return lista;
    }

    novoItem->proximo = listaAuxiliar->proximo;
    if (listaAuxiliar->proximo != NULL)
    {
        listaAuxiliar->proximo->anterior = novoItem;
    }

    novoItem->anterior = listaAuxiliar;
    listaAuxiliar->proximo = novoItem;

    return lista;
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
            printf("[%f] ", listaAuxiliar->valor);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

int main()
{
    tipodoItem lista = NULL;
    lista = inserirInicio(1.4, lista);

    exibir(lista);

    return 0;
}
