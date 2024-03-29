#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item
{
    double valor;
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
        return novoItem;
    }
}

tipodoItem inserir_Fim(double valor, tipodoItem lista)
{
    tipodoItem novoItem = criarItem(valor);

    if (novoItem == NULL)
    {
        return lista;
    }
    else
    {
        if (lista == NULL)
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
            return lista;
        }
    }
}

tipodoItem inserir_Posicao(double valor, tipodoItem lista, double posicao)
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
        return novoItem;
    }

    tipodoItem listaAuxiliar = lista;
    double indice = 0;

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

double main()
{
    tipodoItem lista = NULL;
    lista = inserirInicio(1.0, lista);

    exibir(lista);

    return 0;
}
