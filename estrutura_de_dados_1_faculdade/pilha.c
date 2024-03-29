#include <stdio.h>
#include <stdlib.h>

int topo_fila1 = -1;
int topo_fila2 = -1;
int topo_fila3 = -1;

int topo_analize1;
int topo_analize2;

int contadorfila1 = 0;
int contadorfila2 = 0;

int controle_analize1 = 0;
int controle_analize2 = 0;

int controle__;

struct Fila
{
    int itens_fila1[3];
    int itens_fila2[3];
    int itens_fila3[6];
};
struct Fila f;

void Adicionar_fila1(int i)
{
    topo_fila1++;
    f.itens_fila1[topo_fila1] = i;
}

void Adicionar_fila2(int i)
{
    topo_fila2++;
    f.itens_fila2[topo_fila2] = i;
}

void Mostrar_Fila1()
{
    printf("\nFila 1 = [%d][%d][%d]", f.itens_fila1[0], f.itens_fila1[1], f.itens_fila1[2], f.itens_fila1[3]);
}

void Mostrar_Fila2()
{
    printf("\nFila 2 = [%d][%d][%d]", f.itens_fila2[0], f.itens_fila2[1], f.itens_fila2[2], f.itens_fila2[3]);
}

void Mostrar_Fila3()
{
    printf("\nFila 3 = [%d][%d][%d][%d][%d][%d]", f.itens_fila3[0], f.itens_fila3[1], f.itens_fila3[2], f.itens_fila3[3], f.itens_fila3[4], f.itens_fila3[5]);
}

void Verificar_Fila1()
{
    if (topo_analize1 != -1)
    {
        contadorfila1++;
        topo_analize1--;
        Verificar_Fila1();
    }
}

void Atribuir()
{
    topo_analize1 = topo_fila1;
    topo_analize2 = topo_fila2;
    controle__ = contadorfila1 + contadorfila2;
}

void Verificar_Fila2()
{
    if (topo_analize2 != -1)
    {
        contadorfila2++;
        topo_analize2--;
        Verificar_Fila2();
    }
}

void IntercalaFila()
{
    if (contadorfila1 == contadorfila2)
    {
        if (topo_fila1 != -1 || topo_fila2 != -1)
        {
            if (controle_analize1 == 0)
            {
                topo_fila3++;
                f.itens_fila3[topo_fila3] = f.itens_fila1[topo_fila1];
                topo_fila1--;
                controle_analize1++;
                controle_analize2++;

                IntercalaFila();
            }
            if (controle_analize2 == 1)
            {
                topo_fila3++;
                f.itens_fila3[topo_fila3] = f.itens_fila2[topo_fila2];
                topo_fila2--;
                controle_analize1 = 0;
                controle_analize2 = 0;

                IntercalaFila();
            }
        }
    }
}

void main()
{
    Adicionar_fila1(1);
    Adicionar_fila1(1);
    Adicionar_fila1(1);

    Adicionar_fila2(2);
    Adicionar_fila2(2);
    Adicionar_fila2(2);

    Mostrar_Fila1();

    Mostrar_Fila2();

    Atribuir();

    Verificar_Fila1();
    Verificar_Fila2();

    IntercalaFila();

    Mostrar_Fila3();
}
