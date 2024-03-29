#include <stdlib.h>
#include <stdio.h>
#include <string.h>
///////////////////////////////////////////
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

////////////////////////////////////////////////////

typedef struct Item2
{
    int valor2;
    struct Item2 *anterior;
    struct Item2 *proximo;
} Item2;

typedef Item2 *tipodoItem2;

tipodoItem2 criarItem2(int *valor2)
{
    if (valor2 == NULL)
    {
        printf("\nErro ao criar Item!\n");
        return NULL;
    }
    else
    {
        tipodoItem2 novoItem = (tipodoItem)malloc(sizeof(Item));

        if (novoItem == NULL)
        {
            printf("\nErro ao criar Item!\n");
            return NULL;
        }
        else
        {
            novoItem->valor2 = valor2;
            novoItem->proximo = NULL;
            novoItem->anterior = NULL;
            return novoItem;
        }
    }
}

tipodoItem inserirInicio2(int valor2, tipodoItem2 lista2)
{

    tipodoItem2 novoItem = criarItem(valor2);

    if (lista2 == NULL)
    {
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista2;
        lista2->anterior = novoItem;
        return novoItem;
    }
}

void exibir2(tipodoItem2 lista2)
{
    if (lista2 == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        tipodoItem2 listaAuxiliar2 = lista2;

        while (listaAuxiliar2 != NULL)
        {
            printf("[%d] ", listaAuxiliar2->valor2);
            listaAuxiliar2 = listaAuxiliar2->proximo;
        }
    }
}

////////////////////////////////////////////////////

typedef struct Item3
{
    int valor3;
    struct Item3 *anterior;
    struct Item3 *proximo;
} Item3;

typedef Item3 *tipodoItem3;

tipodoItem3 criarItem3(int *valor3)
{
    if (valor3 == NULL)
    {
        printf("\nErro ao criar Item!\n");
        return NULL;
    }
    else
    {
        tipodoItem3 novoItem = (tipodoItem3)malloc(sizeof(Item3));

        if (novoItem == NULL)
        {
            printf("\nErro ao criar Item!\n");
            return NULL;
        }
        else
        {
            novoItem->valor3 = valor3;
            novoItem->proximo = NULL;
            novoItem->anterior = NULL;
            return novoItem;
        }
    }
}

tipodoItem inserirInicio3(int *valor3, tipodoItem2 lista3)
{

    tipodoItem3 novoItem = criarItem(valor3);

    if (lista3 == NULL)
    {
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista3;
        lista3->anterior = novoItem;
        return novoItem;
    }
}

void exibir3(tipodoItem3 lista3)
{
    if (lista3 == NULL)
    {
        printf("\nVazia!\n");
    }
    else
    {
        tipodoItem3 listaAuxiliar3 = lista3;

        while (listaAuxiliar3 != NULL)
        {
            printf("[%d] ", listaAuxiliar3->valor3);
            listaAuxiliar3 = listaAuxiliar3->proximo;
        }
    }
}

////////////////////////////////////////////////////

tipodoItem3 unirListas(tipodoItem lista, tipodoItem2 lista2, tipodoItem2 lista3)
{

    tipodoItem elementoLista1 = lista;
    while (elementoLista1 != NULL)
    {
        lista3 = inserirInicio3((elementoLista1->valor), lista3);
        elementoLista1 = elementoLista1->proximo;
    }

    tipodoItem2 elementoLista2 = lista2;
    while (elementoLista2 != NULL)
    {
        lista3 = inserirInicio3((elementoLista2->valor2), lista3);
        elementoLista2 = elementoLista2->proximo;
    }

    return lista3;
}

int main()
{
    tipodoItem lista = NULL;
    tipodoItem2 lista2 = NULL;
    tipodoItem3 lista3 = NULL;
    lista = inserirInicio(1, lista);
    lista = inserirInicio(2, lista);
    lista = inserirInicio(3, lista);

    lista2 = inserirInicio2(1, lista2);
    lista2 = inserirInicio2(6, lista2);
    lista2 = inserirInicio2(8, lista2);

    exibir(lista);
    printf("\n");
    exibir2(lista2);
    printf("\n");
    lista3 = unirListas(lista, lista2, lista3);
    exibir3(lista3);

    return 0;
}
