#include <stdio.h>
#include <stdlib.h>

/*
Inserção (Enqueue): Novos elementos são adicionados ao final da fila, após todos os elementos existentes.
Remoção (Dequeue): A remoção ocorre no início da fila, onde o elemento mais antigo é retirado.
Frente da Fila (Front): Representa o primeiro elemento na fila, ou seja, o elemento que será removido na próxima operação.
Final da Fila (Rear): Representa o último elemento na fila, onde novos elementos são
*/

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

void Mostrar()
{
    if (auxiliar <= topo)
    {
        printf("%c", f.item[auxiliar]);
        f.item[auxiliar] = ' ';
        auxiliar++;
        Mostrar();
    }
    else
    {
    }
}

void Front()
{
    printf("%c", f.item[0]);
}

void Rear()
{
    printf("%c", f.item[topo - 1]);
}

void main()
{

    Enqueue('b');
    Enqueue('c');
    Enqueue('b');

    Front();
    Rear();
}