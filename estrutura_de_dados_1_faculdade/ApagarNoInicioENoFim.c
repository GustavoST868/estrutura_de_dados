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

tipodoItem criarItem(int *valor)
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
            novoItem->anterior = NULL;
            return novoItem;
        }
    }
}

tipodoItem inserirInicio(int *valor, tipodoItem lista)
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

tipodoItem inserir_Fim(int *valor, tipodoItem lista)
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

tipodoItem inserir_Posicao(int *valor, tipodoItem lista, int posicao)
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

tipodoItem inserir_Posicao_Direita(int *valor, tipodoItem lista, int posicao)
{

    posicao = posicao - 0;

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

tipodoItem inserir_Posicao_Esquerda(int *valor, tipodoItem lista, int posicao)
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

tipodoItem substituirElemento(tipodoItem lista, int posicao, int novoValor)
{

    tipodoItem elemento = lista;

    for (int i = 1; i < posicao; i++)
    {
        elemento = elemento->proximo;
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

tipodoItem apagarInicio(tipodoItem lista)
{
    if (lista == NULL)
    {
        printf("\nA lista está vazia!\n");
        return lista;
    }

    tipodoItem novoInicio = lista->proximo;

    if (novoInicio != NULL)
    {
        novoInicio->anterior = NULL;
    }

    free(lista);
    return novoInicio;
}


tipodoItem apagarFim(tipodoItem lista)
{
    if (lista == NULL)
    {
        printf("\nA lista está vazia!\n");
        return lista;
    }

    tipodoItem ultimoElemento = lista;

    while (ultimoElemento->proximo != NULL)
    {
        ultimoElemento = ultimoElemento->proximo;
    }

    if (ultimoElemento->anterior != NULL)
    {
        ultimoElemento->anterior->proximo = NULL;
    }
    else
    {
        lista = NULL;
    }

    free(ultimoElemento);
    return lista;
}


int main()
{
    tipodoItem lista = NULL;
    lista = inserirInicio(1, lista);
    lista = inserirInicio(1, lista);
    lista = inserirInicio(1, lista);
    lista = inserir_Fim(2,lista);
    lista = inserir_Fim(2,lista);
    lista = inserir_Fim(2,lista);
    lista = apagarFim(lista);
    

    exibir(lista);

    printf("\n");
    ;
    return 0;
}
