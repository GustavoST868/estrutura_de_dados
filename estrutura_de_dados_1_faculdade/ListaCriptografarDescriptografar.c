#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char caractere;
    struct Node* proximo;
} Node;

typedef struct {
    Node* cabeca;
} ListaEncadeada;

void inicializarLista(ListaEncadeada* lista) {
    lista->cabeca = NULL;
}

void inserirCaractere(ListaEncadeada* lista, char caractere) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->caractere = caractere;
    novoNode->proximo = lista->cabeca;
    lista->cabeca = novoNode;
}

void inverterLista(ListaEncadeada* lista) {
    Node* prev = NULL;
    Node* current = lista->cabeca;
    Node* next = NULL;

    while (current != NULL) {
        next = current->proximo;
        current->proximo = prev;
        prev = current;
        current = next;
    }

    lista->cabeca = prev;
}

void descriptografarMensagem(ListaEncadeada* lista) {
    inverterLista(lista);

    Node* current = lista->cabeca;
    Node* prev = NULL;
    while (current != NULL) {
        if (!isalpha(current->caractere) || strchr("aeiouAEIOU", current->caractere) == NULL) {
            inverterLista(prev);
        }
        prev = current;
        current = current->proximo;
    }

    inverterLista(prev);
}

void exibirLista(ListaEncadeada lista) {
    Node* current = lista.cabeca;
    while (current != NULL) {
        printf("%c", current->caractere);
        current = current->proximo;
    }
    printf("\n");
}

int main() {
    ListaEncadeada lista;
    inicializarLista(&lista);

    // Inserir caracteres na lista (codificados)
    char mensagemCodificada[] = "L.AGE LOTIU MÉS ODA DES DARUTUSTRE";
    for (int i = 0; mensagemCodificada[i] != '\0'; i++) {
        inserirCaractere(&lista, mensagemCodificada[i]);
    }

    printf("Mensagem codificada: ");
    exibirLista(lista);

    // Descriptografar a mensagem
    descriptografarMensagem(&lista);

    printf("Mensagem original: ");
    exibirLista(lista);

    // Liberar memória da lista
    Node* current = lista.cabeca;
    while (current != NULL) {
        Node* temp = current;
        current = current->proximo;
        free(temp);
    }

    return 0;
}
