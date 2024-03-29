#include <stdlib.h>
#include <stdio.h>

typedef struct Item {
    int Item;
    struct Item *anterior;
    struct Item *proximo;
} Item;

typedef Item* tipodoItem;

tipodoItem criarItem(int valor) {

    if (valor < 0) {
        printf("\nErro ao criar Item!\n");
        return NULL;
    } else {
        tipodoItem novoItem = (tipodoItem) malloc(sizeof(Item));

        if (novoItem == NULL) {
            printf("\nErro ao criar Item!\n");
            return NULL;
        } else {
            novoItem->Item = valor;
            novoItem->proximo = NULL;
            novoItem->anterior = NULL;
            return novoItem;
        }
    }
}

tipodoItem inserirInicio(int valor, tipodoItem Item) {

    tipodoItem novoItem = criarItem(valor);

    if (Item == NULL) {
        return novoItem;
    } else {
        novoItem->proximo = Item;
        Item->anterior = novoItem;
        return novoItem;
    }
}

tipoLista inserirFim(int valor, tipoLista lista) {

    tipoLista novoItem = criarItem(valor);

    if (lista == NULL) {
        return novoItem;
    } else {

        tipoLista listaAuxiliar = lista;

        while (listaAuxiliar->proximo != NULL) {
            listaAuxiliar = listaAuxiliar->proximo;
        }

        listaAuxiliar->proximo = novoItem;
        novoItem->anterior = listaAuxiliar;

        return lista;
    }

}


void exibir(tipodoItem Item) {
    if (Item == NULL) {
        printf("\nVazia!\n");
    } else {

        tipodoItem ItemAuxiliar = Item;

        while (ItemAuxiliar != NULL) {
            printf("[%d] ", ItemAuxiliar->Item);
            ItemAuxiliar = ItemAuxiliar->proximo;
        }
    }
}


int main() {

    tipodoItem Item = NULL;
    Item = inserirInicio(1, Item);
    Item = inserirInicio(2, Item);
    Item = inserirInicio(3, Item);

    exibir(Item);

    return 0;
}
