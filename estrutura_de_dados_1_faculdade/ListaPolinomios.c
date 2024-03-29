#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float coeficiente;
    int expoente;
    struct Node* proximo;
} Node;

typedef struct {
    Node* cabeca;
} ListaPolinomio;

void inicializarLista(ListaPolinomio* lista) {
    lista->cabeca = NULL;
}

void inserirMonomio(ListaPolinomio* lista, float coeficiente, int expoente) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    novoNode->coeficiente = coeficiente;
    novoNode->expoente = expoente;
    novoNode->proximo = lista->cabeca;
    lista->cabeca = novoNode;
}

void exibirPolinomio(ListaPolinomio lista) {
    Node* atual = lista.cabeca;
    while (atual != NULL) {
        printf("%.2fx^%d ", atual->coeficiente, atual->expoente);
        if (atual->proximo != NULL) {
            printf("+ ");
        }
        atual = atual->proximo;
    }
    printf("\n");
}

void somarPolinomios(ListaPolinomio polinomio1, ListaPolinomio polinomio2, ListaPolinomio* resultado) {
    Node* atual1 = polinomio1.cabeca;
    Node* atual2 = polinomio2.cabeca;

    while (atual1 != NULL || atual2 != NULL) {
        float coeficiente = 0;
        int expoente = 0;

        if (atual1 != NULL && atual2 != NULL) {
            if (atual1->expoente == atual2->expoente) {
                coeficiente = atual1->coeficiente + atual2->coeficiente;
                expoente = atual1->expoente;
                atual1 = atual1->proximo;
                atual2 = atual2->proximo;
            } else if (atual1->expoente > atual2->expoente) {
                coeficiente = atual1->coeficiente;
                expoente = atual1->expoente;
                atual1 = atual1->proximo;
            } else {
                coeficiente = atual2->coeficiente;
                expoente = atual2->expoente;
                atual2 = atual2->proximo;
            }
        } else if (atual1 != NULL) {
            coeficiente = atual1->coeficiente;
            expoente = atual1->expoente;
            atual1 = atual1->proximo;
        } else if (atual2 != NULL) {
            coeficiente = atual2->coeficiente;
            expoente = atual2->expoente;
            atual2 = atual2->proximo;
        }

        inserirMonomio(resultado, coeficiente, expoente);
    }
}

void multiplicarPolinomios(ListaPolinomio polinomio1, ListaPolinomio polinomio2, ListaPolinomio* resultado) {
    Node* atual1 = polinomio1.cabeca;
    while (atual1 != NULL) {
        Node* atual2 = polinomio2.cabeca;
        while (atual2 != NULL) {
            float coeficiente = atual1->coeficiente * atual2->coeficiente;
            int expoente = atual1->expoente + atual2->expoente;
            inserirMonomio(resultado, coeficiente, expoente);
            atual2 = atual2->proximo;
        }
        atual1 = atual1->proximo;
    }
}

void derivarPolinomio(ListaPolinomio polinomio, ListaPolinomio* resultado) {
    Node* atual = polinomio.cabeca;
    while (atual != NULL) {
        if (atual->expoente > 0) {
            float coeficiente = atual->coeficiente * atual->expoente;
            int expoente = atual->expoente - 1;
            inserirMonomio(resultado, coeficiente, expoente);
        }
        atual = atual->proximo;
    }
}

void liberarLista(ListaPolinomio* lista) {
    Node* atual = lista->cabeca;
    while (atual != NULL) {
        Node* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista->cabeca = NULL;
}

int main() {
    ListaPolinomio polinomio1, polinomio2, resultadoSoma, resultadoMultiplicacao, resultadoDerivacao;
    inicializarLista(&polinomio1);
    inicializarLista(&polinomio2);
    inicializarLista(&resultadoSoma);
    inicializarLista(&resultadoMultiplicacao);
    inicializarLista(&resultadoDerivacao);

    // Exemplo de inserção de polinômios
    inserirMonomio(&polinomio1, 3.0, 2);
    inserirMonomio(&polinomio1, 2.0, 1);
    inserirMonomio(&polinomio1, 1.0, 0);

    inserirMonomio(&polinomio2, 1.0, 2);
    inserirMonomio(&polinomio2, -2.0, 1);
    inserirMonomio(&polinomio2, 1.0, 0);

    printf("Polinômio 1: ");
    exibirPolinomio(polinomio1);

    printf("Polinômio 2: ");
    exibirPolinomio(polinomio2);

    // Operações
    somarPolinomios(polinomio1, polinomio2, &resultadoSoma);
    multiplicarPolinomios(polinomio1, polinomio2, &resultadoMultiplicacao);
    derivarPolinomio(polinomio1, &resultadoDerivacao);

    // Resultados
    printf("Soma dos polinômios: ");
    exibirPolinomio(resultadoSoma);

    printf("Multiplicação dos polinômios: ");
    exibirPolinomio(resultadoMultiplicacao);

    printf("Derivada do primeiro polinômio: ");
    exibirPolinomio(resultadoDerivacao);

    // Libera memória
    liberarLista(&polinomio1);
    liberarLista(&polinomio2);
    liberarLista(&resultadoSoma);
    liberarLista(&resultadoMultiplicacao);
    liberarLista(&resultadoDerivacao);

    return 0;
}
