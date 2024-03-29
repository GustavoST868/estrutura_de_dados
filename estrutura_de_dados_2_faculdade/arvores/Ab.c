#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo {
  int info;
  struct nodo *esq;
  struct nodo *dir;
} NO;

typedef NO *ARV;

int EMPTY(ARV a) { return (a == NULL); }

// Função para inserir um novo elemento 'b' na arvore 'a'
ARV insere(ARV a, int b) {
  ARV nova;
  if (EMPTY(a)) {
    nova = (ARV)malloc(sizeof(NO));
    nova->esq = NULL;
    nova->dir = NULL;
    nova->info = b;
    printf("Insercao do numero %d na AB realizada!\n", b);
    return nova;
  } else {
    if (b > a->info)
      a->dir = insere(a->dir, b);
    else
      a->esq = insere(a->esq, b); /* Repeticoes sao inseridas na esquerda! */
    return a;
  }
}

// Função para mostrar a árvore
void mostraArvore(ARV a, int nivel) {
  if (EMPTY(a))
    return;

  mostraArvore(a->dir, nivel + 1);

  for (int i = 0; i < nivel; i++)
    printf("   ");

  printf("%d\n", a->info);

  mostraArvore(a->esq, nivel + 1);
}

// Função para calcular a altura de uma árvore binária
int alturaArvore(ARV a) {
  if (EMPTY(a))
    return -1; // Árvore vazia tem altura -1
  else {
    int alturaEsq = alturaArvore(a->esq);
    int alturaDir = alturaArvore(a->dir);

    // O máximo entre a altura da subárvore esquerda e direita, mais 1 (altura
    // da raiz)
    return (alturaEsq > alturaDir) ? (alturaEsq + 1) : (alturaDir + 1);
  }
}

// Função para percorrer a árvore respeitando o critério EM ORDEM
void inOrder(ARV a) {
  if (!EMPTY(a)) {
    inOrder(a->esq);
    printf(" %d ", a->info);
    inOrder(a->dir);
  }
}

// Função para percorrer a árvore respeitando o critério PRÉ-ORDEM
void preOrder(ARV a) {
  if (!EMPTY(a)) {
    printf(" %d ", a->info);
    preOrder(a->esq);
    preOrder(a->dir);
  }
}

// Função para percorrer a árvore respeitando o critério PÓS-ORDEM
void postOrder(ARV a) {
  if (!EMPTY(a)) {
    postOrder(a->esq);
    postOrder(a->dir);
    printf(" %d ", a->info);
  }
}

int main() {
  ARV a = NULL;
  int opcao = 0;
  int num;

  while (opcao != 6) {
    system("cls");
    printf("\n\n----------------MENU PRINCIPAL----------------");
    printf("\n\n 1 - Inserir Novo Numero na AB");
    printf("\n 2 - Mostrar Arvore");
    printf("\n 3 - Calcular Altura da Arvore");
    printf("\n 4 - Percorrer em Ordem");
    printf("\n 5 - Percorrer Pré-Ordem");
    printf("\n 6 - Percorrer Pós-Ordem");
    printf("\n 7 - Encerrar");
    printf("\n\n Opcao Escolhida: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      system("cls");
      printf("\nNovo Numero: ");
      scanf("%d", &num);
      a = insere(a, num);
      printf("Pressione Enter para continuar...");
      getchar(); // Aguarda a tecla Enter
      break;

    case 2:
      system("cls");
      printf("\n\n----------------ARVORE BINARIA----------------\n\n");
      mostraArvore(a, 0);
      printf("\n\nPressione Enter para continuar...");
      getchar(); // Aguarda a tecla Enter
      break;

    case 3:
      system("cls");
      printf("\nAltura da Arvore: %d\n", alturaArvore(a));
      printf("\nPressione Enter para continuar...");
      getchar(); // Aguarda a tecla Enter
      break;

    case 4:
      system("cls");
      printf("\n\n----------------PERCORRER EM ORDEM----------------\n\n");
      inOrder(a);
      printf("\n\nPressione Enter para continuar...");
      getchar(); // Aguarda a tecla Enter
      break;

    case 5:
      system("cls");
      printf("\n\n----------------PERCORRER PRÉ-ORDEM----------------\n\n");
      preOrder(a);
      printf("\n\nPressione Enter para continuar...");
      getchar(); // Aguarda a tecla Enter
      break;

    case 6:
      system("cls");
      printf("\n\n----------------PERCORRER PÓS-ORDEM----------------\n\n");
      postOrder(a);
      printf("\n\nPressione Enter para continuar...");
      getchar(); // Aguarda a tecla Enter
      break;
    }
  }

  return 0;
}
