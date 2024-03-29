#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item
{
    int valor;
    struct Item *anterior;
    struct Item *proximo;
} Item;

typedef Item *tipodoItem;

tipodoItem criarItem(int valor)
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
        lista->anterior = novoItem;
        return novoItem;
    }
}

tipodoItem inserirFim(int valor, tipodoItem lista)
{
    tipodoItem novoItem = criarItem(valor);

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
        novoItem->anterior = listaAuxiliar;

        return lista;
    }
}

tipodoItem inserirPosicao(int valor, tipodoItem lista, int posicao)
{
    if (posicao < 0)
    {
        printf("\nPosicao invalida!\n");
        return lista;
    }

    tipodoItem novoItem = criarItem(valor);

    if (novoItem == NULL)
    {
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

tipodoItem substituirElemento(tipodoItem lista, int posicao, int novoValor)
{
    tipodoItem elemento = lista;

    for (int i = 1; i < posicao; i++)
    {
        elemento = elemento->proximo;
        if (elemento == NULL)
        {
            printf("\nPosicao invalida!\n");
            return lista;
        }
    }

    elemento->valor = novoValor;

    return lista;
}

tipodoItem apagarElemento(tipodoItem lista, int valor)
{
    tipodoItem listaAuxiliar = lista;

    while (listaAuxiliar != NULL)
    {
        if (listaAuxiliar->valor == valor)
        {
            if (listaAuxiliar->anterior != NULL)
            {
                listaAuxiliar->anterior->proximo = listaAuxiliar->proximo;
            }
            if (listaAuxiliar->proximo != NULL)
            {
                listaAuxiliar->proximo->anterior = listaAuxiliar->anterior;
            }

            if (lista == listaAuxiliar)
            {
                lista = listaAuxiliar->proximo;
            }

            free(listaAuxiliar);
        }

        listaAuxiliar = listaAuxiliar->proximo;
    }

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
            printf("[%d] ", listaAuxiliar->valor);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

int main()
{
    tipodoItem lista = NULL;
    lista = inserirInicio(1, lista);
    lista = inserirInicio(2, lista);
    lista = inserirInicio(3, lista);

    exibir(lista);
    printf("\n");

    return 0;
}
