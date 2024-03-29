#include <stdio.h>
#include <stdlib.h>

int topo = 0;
int auxiliar = 0;
int control = 0;

struct Fila
{
    char *item;
};

struct Fila f;

void Enqueue(char item)
{
    if (control == 0)
    {
        f.item = (char *)malloc((topo + 1) * sizeof(char));
    }
    else
    {
        f.item = (char *)realloc(f.item, (topo + 1) * sizeof(char));
    }

    control++;

    f.item[topo] = item;

    topo++;
}

void Dequeue()
{
    f.item[auxiliar] = NULL;
    auxiliar++;
}

void Mostrar()
{
    if (auxiliar < topo)
    {
        printf("%c ", f.item[auxiliar]);
        auxiliar++;
        Mostrar();
    }
}

void Front()
{
    if (topo > 0)
    {
        printf("%c\n", f.item[0]);
    }
    else
    {
        printf("Fila vazia\n");
    }
}

void Rear()
{
    if (topo > 0)
    {
        printf("%c\n", f.item[topo - 1]);
    }
    else
    {
        printf("Pilha vazia\n");
    }
}

int main()
{
    Enqueue('b');
    Enqueue('c');
    Enqueue('b');

    Front();

    Rear();

    Dequeue();

    Mostrar();

    free(f.item);
    return 0;
}
