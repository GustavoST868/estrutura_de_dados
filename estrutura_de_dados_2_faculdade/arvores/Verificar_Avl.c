#include <stdio.h>
#include <stdlib.h>

typedef struct Noh {
    int valor;
    struct Noh* esquerda;
    struct Noh* direita;
    int altura;
} Noh;

int alturaNoh(Noh* noh) {
    if (noh == NULL) {
        return -1;
    } else {
        return noh->altura;
    }
}

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

Noh* criarNoh(int valor) {
    Noh* novoNoh = (Noh*)malloc(sizeof(Noh));
    if (novoNoh != NULL) {
        novoNoh->valor = valor;
        novoNoh->esquerda = NULL;
        novoNoh->direita = NULL;
        novoNoh->altura = 0;
    }
    return novoNoh;
}

Noh* rotacaoEsquerda(Noh* y) {
    Noh* x = y->direita;
    Noh* T2 = x->esquerda;

    x->esquerda = y;
    y->direita = T2;

    y->altura = maximo(alturaNoh(y->esquerda), alturaNoh(y->direita)) + 1;
    x->altura = maximo(alturaNoh(x->esquerda), alturaNoh(x->direita)) + 1;

    return x;
}

Noh* rotacaoDireita(Noh* x) {
    Noh* y = x->esquerda;
    Noh* T2 = y->direita;

    y->direita = x;
    x->esquerda = T2;

    x->altura = maximo(alturaNoh(x->esquerda), alturaNoh(x->direita)) + 1;
    y->altura = maximo(alturaNoh(y->esquerda), alturaNoh(y->direita)) + 1;

    return y;
}

int fatorBalanceamento(Noh* noh) {
    if (noh == NULL) {
        return 0;
    } else {
        return alturaNoh(noh->esquerda) - alturaNoh(noh->direita);
    }
}

Noh* inserir(Noh* noh, int valor) {
    if (noh == NULL) {
        return criarNoh(valor);
    }

    if (valor < noh->valor) {
        noh->esquerda = inserir(noh->esquerda, valor);
    } else if (valor > noh->valor) {
        noh->direita = inserir(noh->direita, valor);
    } else {
        return noh;
    }

    noh->altura = 1 + maximo(alturaNoh(noh->esquerda), alturaNoh(noh->direita));

    int balanceamento = fatorBalanceamento(noh);

    if (balanceamento > 1 && valor < noh->esquerda->valor) {
        return rotacaoDireita(noh);
    }

    if (balanceamento < -1 && valor > noh->direita->valor) {
        return rotacaoEsquerda(noh);
    }

    if (balanceamento > 1 && valor > noh->esquerda->valor) {
        noh->esquerda = rotacaoEsquerda(noh->esquerda);
        return rotacaoDireita(noh);
    }

    if (balanceamento < -1 && valor < noh->direita->valor) {
        noh->direita = rotacaoDireita(noh->direita);
        return rotacaoEsquerda(noh);
    }

    return noh;
}

int verificaAVL(Noh* raiz) {
    if (raiz == NULL) {
        return 1;
    }

    int balanceamento = fatorBalanceamento(raiz);

    return (balanceamento >= -1 && balanceamento <= 1 && verificaAVL(raiz->esquerda) && verificaAVL(raiz->direita));
}

void liberarArvore(Noh* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

void imprimirMenu() {
    printf("\n---------------- MENU ----------------\n");
    printf("1. Inserir na arvore AVL\n");
    printf("2. Verificar se a arvore e AVL\n");
    printf("3. Sair\n");
    printf("---------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Noh* raiz = NULL;
    int opcao, valor;

    do {
        imprimirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;

            case 2:
                if (verificaAVL(raiz)) {
                    printf("A arvore e AVL.\n");
                } else {
                    printf("A arvore nao e AVL.\n");
                }
                break;

            case 3:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 3);

    liberarArvore(raiz);

    return 0;
}
