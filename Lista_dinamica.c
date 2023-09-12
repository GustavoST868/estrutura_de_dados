#include <stdio.h>
#include <stdlib.h>

int posicao = 0;
int tamanho;

struct Lista
{
    int *lista;
};
struct Lista l;

void ADD_Inicio(int valor)
{
    if (posicao == 0)
    {
        l.lista = (int *)malloc(sizeof(int));
        l.lista[posicao] = valor;
        posicao++;
    }
    else
    {
        int *nova_lista = (int *)malloc((posicao + 1) * sizeof(int));
        nova_lista[0] = valor;

        for (int i = 0; i < posicao; i++)
        {
            nova_lista[i + 1] = l.lista[i];
        }

        free(l.lista);
        l.lista = nova_lista;
        posicao++;
    }
}

void Add_fim(int valor)
{
    int tamanho_atual = posicao;

    if (tamanho_atual == 0)
    {
        ADD_Inicio(valor);
    }
    else
    {
        int *nova_lista = (int *)malloc((tamanho_atual + 1) * sizeof(int));

        for (int i = 0; i < tamanho_atual; i++)
        {
            nova_lista[i] = l.lista[i];
        }

        nova_lista[tamanho_atual] = valor;

        free(l.lista);
        l.lista = nova_lista;
        posicao++;
    }
}

int Remove_Inicio()
{
    if (posicao == 0)
    {
        printf("Lista vazia, não é possível remover do início.\n");
        return -1;
    }

    int valor_removido = l.lista[0];

    int *nova_lista = (int *)malloc((posicao - 1) * sizeof(int));

    for (int i = 1; i < posicao; i++)
    {
        nova_lista[i - 1] = l.lista[i];
    }

    free(l.lista);
    l.lista = nova_lista;
    posicao--;
}

int Remover_Fim()
{
    if (posicao == 0)
    {
        printf("Lista vazia, não é possível remover do fim.\n");
        return -1; 
    }

    int valor_removido = l.lista[posicao - 1];

    int *nova_lista = (int *)malloc((posicao - 1) * sizeof(int));

    for (int i = 0; i < posicao - 1; i++)
    {
        nova_lista[i] = l.lista[i];
    }

    free(l.lista);
    l.lista = nova_lista;
    posicao--;
}

void Mostrar()
{
    printf("\nLista:\n");
    int i = 0;
    while (i < posicao)
    {
        printf("%d ", l.lista[i]);
        i++;
    }
    printf("\n");
}


void Inserir_Posicao(int valor, int pos)
{
    if (pos < 0 || pos > posicao)
    {
        printf("Posição inválida para inserção.\n");
        return;
    }

    int tamanho_atual = posicao + 1;
    int *nova_lista = (int *)malloc(tamanho_atual * sizeof(int));

    for (int i = 0, j = 0; i < tamanho_atual; i++)
    {
        if (i == pos)
        {
            nova_lista[i] = valor;
        }
        else
        {
            nova_lista[i] = l.lista[j++];
        }
    }

    free(l.lista);
    l.lista = nova_lista;
    posicao++;
}


int main()
{
    ADD_Inicio(1);
    ADD_Inicio(2);

    Add_fim(3);
    Add_fim(4);

    Mostrar();
    
    Inserir_Posicao(4,0);
    Inserir_Posicao(3,4);
    
    Mostrar();

   

   

    return 0;
}
