#include <stdio.h>
#include <stdlib.h>

int topo = -1;
int i = 0;

struct Pilha
{
    int *item;
};

struct Pilha p;

void Empilhar(int item)
{
    topo++; // Increment before using, as it represents the index of the next available slot

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
}

void Desempilhar()
{
    if (topo >= 0)
    {
        topo--;
    }
}

void Mostrar()
{
    if (topo >= 0)
    {
        printf("%d ", p.item[topo]);
        Desempilhar();
        Mostrar();
    }
}

void PilhaVazia(){
    if(topo == -1){
       printf("\nPilha vazia"); 
    }else{
        printf("\nA pilha nao esta vazia");
    }
}

int main()
{
    
    
    Empilhar(1);
    Empilhar(2);
    Empilhar(3);
    
    PilhaVazia();
    
    Mostrar();
    
    PilhaVazia();

    free(p.item);
    return 0;
}
