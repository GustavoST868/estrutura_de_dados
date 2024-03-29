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
        novoItem->proximo = novoItem;
        novoItem->anterior = novoItem;
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista;
        novoItem->anterior = lista->anterior;
        lista->anterior->proximo = novoItem;
        lista->anterior = novoItem;
        return novoItem;
    }
}

tipodoItem inserirFim(int valor, tipodoItem lista)
{
    tipodoItem novoItem = criarItem(valor);

    if (lista == NULL)
    {
        novoItem->proximo = novoItem;
        novoItem->anterior = novoItem;
        return novoItem;
    }
    else
    {
        novoItem->proximo = lista;
        novoItem->anterior = lista->anterior;
        lista->anterior->proximo = novoItem;
        lista->anterior = novoItem;
        return lista;
    }
}

tipodoItem inserirPosicao(int valor, tipodoItem lista, int posicao)
{
    // Implemente conforme necessário
    // (similar à inserção no início, ajustando os ponteiros adequados para torná-lo circular)
}

tipodoItem substituirElemento(tipodoItem lista, int posicao, int novoValor)
{
    // Implemente conforme necessário
}

tipodoItem apagarElemento(tipodoItem lista, int valor)
{
    // Implemente conforme necessário
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

        do
        {
            printf("[%d] ", listaAuxiliar->valor);
            listaAuxiliar = listaAuxiliar->proximo;
        } while (listaAuxiliar != lista);
    }
}

int main()
{
    tipodoItem lista = NULL;
    lista = inserirInicio(1, lista);
    lista = inserirFim(2, lista);
    lista = inserirFim(3, lista);

    exibir(lista);
    printf("\n");

    return 0;
}
