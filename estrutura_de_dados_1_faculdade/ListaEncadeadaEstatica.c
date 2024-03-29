#include <stdio.h>



#define TAMANHO_MAXIMO 100 



typedef struct {
    int dado;
    int proximo; 
} No;



typedef struct {
    No nos[TAMANHO_MAXIMO];
    int cabeca; 
    int listaLivre; 
} ListaEncadeadaEstatica;




void inicializarLista(ListaEncadeadaEstatica *lista) {
    lista->cabeca = -1;
    lista->listaLivre = 0;

    for (int i = 0; i < TAMANHO_MAXIMO - 1; ++i) {
        lista->nos[i].proximo = i + 1;
    }

    lista->nos[TAMANHO_MAXIMO - 1].proximo = -1;
}




int inserirElemento(ListaEncadeadaEstatica *lista, int dado) {
    if (lista->listaLivre == -1) {
        printf("Lista está cheia. Não é possível inserir mais elementos.\n");
        return -1;
    }

    int novoIndice = lista->listaLivre;
    lista->listaLivre = lista->nos[novoIndice].proximo;

    lista->nos[novoIndice].dado = dado;
    lista->nos[novoIndice].proximo = lista->cabeca;
    lista->cabeca = novoIndice;

    return novoIndice; 
}




void exibirLista(ListaEncadeadaEstatica lista) {
    int indiceAtual = lista.cabeca;
    while (indiceAtual != -1) {
        printf("[%d]", lista.nos[indiceAtual].dado);
        indiceAtual = lista.nos[indiceAtual].proximo;
    }
    printf("\n");
}




int main() {
    ListaEncadeadaEstatica lista;
    inicializarLista(&lista);

    inserirElemento(&lista, 1);
    inserirElemento(&lista, 2);
    inserirElemento(&lista, 3);

    printf("Lista encadeada estática: ");
    exibirLista(lista);

    return 0;
}
