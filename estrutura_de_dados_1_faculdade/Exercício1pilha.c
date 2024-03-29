#include<stdio.h>
#include<stdlib.h>


int topo = -1;
int topovetor = -1;
char vetor[2];
int contador=0;


struct Pilha{
   char pilha[5];
};
struct Pilha p;





void Empilhar(char item){
   topo++;
   p.pilha[topo]=item;
}


void Addvetor(char item){
   topovetor++;
   vetor[topovetor]=item;
   
}



void Mostrar(){
  printf("\n\nPilha = [%c] [%c]  [%c]  [%c]  [%c]\n\n",p.pilha[0],p.pilha[1],p.pilha[2],p.pilha[3],p.pilha[4],p.pilha[5]);
}




void Mostrarvetor(){
  printf("vetor = [%c] [%c]",vetor[0],vetor[1]);
}




void Desempilhar(){



  if(topo>2){
  Addvetor(p.pilha[topo]);
  }
  
  p.pilha[topo]=0;
  topo--;
}



void Desempilharvetor(){
     vetor[topovetor]=' ';
     topovetor--;
}




void Comparar(){
   if(topo>=0){
      if((p.pilha[topo])==(vetor[topovetor])){
         contador++;
         Desempilhar();
         Desempilharvetor();
         Comparar();
      }
}}

int main(){



//aterar aqui
Empilhar('a');
Empilhar('b');
Empilhar('c');//fixo,centro
Empilhar('b');
Empilhar('a');


Desempilhar();
Desempilhar();
Desempilhar();




Comparar();



if(contador==2){
printf("\n\nDe acordo com a regra\n\n");
}else{
printf("\n\nNao esta de acordo com a regra\n\n}");
}

    return 0;
}