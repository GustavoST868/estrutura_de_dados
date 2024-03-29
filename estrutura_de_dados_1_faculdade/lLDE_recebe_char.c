#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Item
{
    char Usuario[100];
    struct Item *anterior;
    struct Item *proximo;
} Item;

typedef Item *tipodoItem;

tipodoItem criarItem(char *Usuario)
{
    if (Usuario == NULL)
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
            strncpy(novoItem->Usuario, Usuario, sizeof(novoItem->Usuario) - 1);
            novoItem->Usuario[sizeof(novoItem->Usuario) - 1] = '\0';
            novoItem->proximo = NULL;
            novoItem->anterior = NULL;
            return novoItem;
        }
    }
}

tipodoItem inserirInicio(char *Usuario, tipodoItem lista)
{
    tipodoItem novoItem = criarItem(Usuario);

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

tipodoItem inserir_Fim(char *Usuario, tipodoItem lista)
{

    tipodoItem novoItem = criarItem(Usuario);

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

tipodoItem inserir_Posicao(char *Usuario, tipodoItem lista, int posicao)
{

    posicao = posicao - 1;

    tipodoItem novoItem = criarItem(Usuario);

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
            printf("[%s] ", listaAuxiliar->Usuario);
            listaAuxiliar = listaAuxiliar->proximo;
        }
    }
}

int main()
{
    tipodoItem lista = NULL;
    lista = inserirInicio("Gustavo", lista);
    lista = inserirInicio("Camily", lista);
    lista = inserir_Fim("Gabriel", lista);
    lista = inserir_Posicao("Guarana", lista, 1);
    lista = inserir_Posicao("Guarana", lista, 5);

    exibir(lista);
    Test(lista, "Busta");

    return 0;
}
