#include <stdlib.h>
#include <stdio.h>

typedef struct Lista {
    int Lista;
    struct Lista *anterior;
    struct Lista *proximo;
} Lista;

typedef Lista* tipoLista;

tipoLista criarLista(int valor) {

    if (valor < 0) {
        printf("\nErro ao criar Lista!\n");
        return NULL;
    } else {
        tipoLista novoLista = (tipoLista) malloc(sizeof(Lista));

        if (novoLista == NULL) {
            printf("\nErro ao criar Lista!\n");
            return NULL;
        } else {
            novoLista->Lista = valor;
            novoLista->proximo = NULL;
            novoLista->anterior = NULL;
            return novoLista;
        }
    }
}

tipoLista inserirEsquerda(int valor, tipoLista lista) {

    tipoLista novoLista = criarLista(valor);

    if (lista == NULL) {
        return novoLista;
    } else {
        novoLista->proximo = lista;
        lista->anterior = novoLista;
        return novoLista;
    }

}

void exibir(tipoLista lista) {

    printf("\n---Lista atual---\n");

    if (lista == NULL) {
        printf("\nVazia!\n");
    } else {

        tipoLista listaAuxiliar = lista;

        while (listaAuxiliar != NULL) {
            printf("[%d] ", listaAuxiliar->Lista);
            listaAuxiliar = listaAuxiliar->proximo;
        }

    }

}

int main() {

    tipoLista lista = NULL;

    lista = inserirEsquerda(5, lista);
    lista = inserirEsquerda(4, lista);
    lista = inserirEsquerda(3, lista);
    lista = inserirEsquerda(2, lista);
    lista = inserirEsquerda(1, lista);

    exibir(lista);

    return 0;
}
