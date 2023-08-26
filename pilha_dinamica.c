#include <stdio.h>
#include <stdlib.h>

int topo = 0;
int i = 0;

struct Pilha
{
    int *item
};

struct Pilha p;

void Empilhar(int item)
{
    if (i == 0)
    {
        p.item = (int *)malloc((topo + 1) * sizeof(int));
    }
    else
    {
        p.item = (int *)realloc(p.item, (topo + 1) * sizeof(int));
    }
    i++;

    p.item[topo] = item;
    topo++;
}

void Mostrar()
{
    for (int j = 0; j < topo; j++)
    {
        printf("%d", p.item[j]);
    }
}

int main()
{
    Empilhar(1);
    Empilhar(2);
    Empilhar(3);
    Mostrar();
    free(p.item);
}