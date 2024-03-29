#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
} ListaCircularEncadeada;

void inicializarLista(ListaCircularEncadeada* lista) {
    lista->cabeca = NULL;
}

int contarElementos(ListaCircularEncadeada lista) {
    if (lista.cabeca == NULL) {
        return 0;
    }

    No* atual = lista.cabeca;
    int contador = 0;

    do {
        contador++;
        atual = atual->proximo;
    } while (atual != lista.cabeca);

    return contador;
}

void inserirAEsquerda(ListaCircularEncadeada* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;

    if (lista->cabeca == NULL) {
        lista->cabeca = novoNo;
        novoNo->proximo = lista->cabeca;
    } else {
        No* temp = lista->cabeca;
        while (temp->proximo != lista->cabeca) {
            temp = temp->proximo;
        }

        novoNo->proximo = lista->cabeca;
        temp->proximo = novoNo;
        lista->cabeca = novoNo;
    }
}

void deletarElemento(ListaCircularEncadeada* lista, int valor) {
    if (lista->cabeca == NULL) {
        return;
    }

    No* atual = lista->cabeca;
    No* anterior = NULL;

    do {
        if (atual->dado == valor) {
            if (anterior == NULL) {
                No* temp = lista->cabeca;
                while (temp->proximo != lista->cabeca) {
                    temp = temp->proximo;
                }
                if (temp == lista->cabeca) {
                    free(temp);
                    lista->cabeca = NULL;
                } else {
                    temp->proximo = lista->cabeca->proximo;
                    free(lista->cabeca);
                    lista->cabeca = temp->proximo;
                }
                return;
            } else {
                anterior->proximo = atual->proximo;
                free(atual);
                return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    } while (atual != lista->cabeca);
}

void concatenarListas(ListaCircularEncadeada* lista1, ListaCircularEncadeada* lista2) {
    if (lista2->cabeca == NULL) {
        return;
    }

    if (lista1->cabeca == NULL) {
        lista1->cabeca = lista2->cabeca;
    } else {
        No* temp = lista1->cabeca;
        while (temp->proximo != lista1->cabeca) {
            temp = temp->proximo;
        }
        temp->proximo = lista2->cabeca;
    }

    No* temp = lista2->cabeca;
    while (temp->proximo != lista2->cabeca) {
        temp = temp->proximo;
    }
    temp->proximo = lista1->cabeca;
}

void intercalarListas(ListaCircularEncadeada* lista1, ListaCircularEncadeada* lista2) {
    if (lista2->cabeca == NULL) {
        return;
    }

    if (lista1->cabeca == NULL) {
        lista1->cabeca = lista2->cabeca;
    } else {
        No* temp1 = lista1->cabeca;
        No* temp2 = lista2->cabeca;
        No* temp1_proximo;
        No* temp2_proximo;

        do {
            temp1_proximo = temp1->proximo;
            temp2_proximo = temp2->proximo;

            temp1->proximo = temp2;
            temp2->proximo = temp1_proximo;

            temp1 = temp1_proximo;
            temp2 = temp2_proximo;
        } while (temp1 != lista1->cabeca && temp2 != lista2->cabeca);

        if (temp1 == lista1->cabeca) {
            No* temp = lista1->cabeca;
            while (temp->proximo != lista1->cabeca) {
                temp = temp->proximo;
            }
            temp->proximo = temp2;
        } else {
            No* temp = lista2->cabeca;
            while (temp->proximo != lista2->cabeca) {
                temp = temp->proximo;
            }
            temp->proximo = temp1;
            lista1->cabeca = lista2->cabeca;
        }
    }
}

void exibirLista(ListaCircularEncadeada lista) {
    if (lista.cabeca == NULL) {
        printf("Lista Vazia\n");
        return;
    }

    No* atual = lista.cabeca;
    do {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    } while (atual != lista.cabeca);
    printf("(início)\n");
}

int main() {
    ListaCircularEncadeada lista1, lista2, lista3;
    inicializarLista(&lista1);
    inicializarLista(&lista2);
    inicializarLista(&lista3);

    inserirAEsquerda(&lista1, 1);
    inserirAEsquerda(&lista1, 2);
    inserirAEsquerda(&lista1, 3);
    inserirAEsquerda(&lista2, 4);
    inserirAEsquerda(&lista2, 5);

    printf("Lista 1: ");
    exibirLista(lista1);
    printf("Lista 2: ");
    exibirLista(lista2);

    printf("Número de elementos na Lista 1: %d\n", contarElementos(lista1));

    deletarElemento(&lista1, 2);
    printf("Lista 1 após a remoção do elemento 2: ");
    exibirLista(lista1);

    concatenarListas(&lista1, &lista2);
    printf("Lista após concatenar Lista 2 com Lista 1: ");
    exibirLista(lista1);

    inserirAEsquerda(&lista3, 6);
    inserirAEsquerda(&lista3, 7);
    printf("Lista 3: ");
    exibirLista(lista3);

    intercalarListas(&lista1, &lista3);
    printf("Lista após intercalar Lista 3 com Lista 1: ");
    exibirLista(lista1);

    return 0;
}
