#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da árvore
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Função para construir a árvore a partir da expressão
Node* buildExpressionTree(char expression[], int* index) {
    // Implemente a lógica para construir a árvore aqui
    // Pode ser necessário utilizar uma pilha ou recursão

    // Este é um exemplo simples, apenas para ilustração
    Node* root = createNode(expression[*index]);
    (*index)++;

    if (expression[*index] != '\0' && (expression[*index] == '+' || expression[*index] == '-' ||
                                       expression[*index] == '*' || expression[*index] == '/')) {
        (*index)++;
        root->left = buildExpressionTree(expression, index);
        (*index)++;
        root->right = buildExpressionTree(expression, index);
    }

    return root;
}

// Função para calcular a altura da árvore
int calculateHeight(Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        // A altura da árvore é o máximo entre a altura da subárvore esquerda e direita, mais 1
        return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
    }
}

// Função para mostrar a árvore em pré-ordem
void printTree(Node* root, int level) {
    if (root != NULL) {
        printf("%*c\n", 3 * level, root->data); // Ajusta o espaçamento para melhor visualização
        printTree(root->left, level + 1);
        printTree(root->right, level + 1);
    }
}

// Função para liberar a memória alocada para a árvore
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char expression[100];
    int choice, index;
    Node* root = NULL;

    do {
        printf("\n1. Digitar expressao\n");
        printf("2. Construir arvore\n");
        printf("3. Mostrar arvore\n");
        printf("4. Calcular altura\n");
        printf("5. Sair\n");
        printf("Escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a expressao: ");
                scanf("%s", expression);
                break;
            case 2:
                index = 0;
                root = buildExpressionTree(expression, &index);
                printf("Arvore construida com sucesso.\n");
                break;
            case 3:
                if (root != NULL) {
                    printf("Arvore:\n");
                    printTree(root, 0);
                } else {
                    printf("Arvore ainda nao foi construida.\n");
                }
                break;
            case 4:
                if (root != NULL) {
                    int height = calculateHeight(root);
                    printf("Altura da arvore: %d\n", height);
                } else {
                    printf("Arvore ainda nao foi construida.\n");
                }
                break;
            case 5:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (choice != 5);

    // Liberar a memória alocada para a árvore antes de encerrar o programa
    freeTree(root);

    return 0;
}
