#include <stdio.h>
#include <stdlib.h>
#define MAX 50 

struct pilha {
int topo;
int vet[MAX]; 

};typedef struct pilha Pilha ;

Pilha* pilha_cria (){
  Pilha* p = (Pilha*) malloc(sizeof(Pilha));
  if (p==NULL) {
    exit (1);
  }
  
  p->topo = 0; 
  return p;
}

int pilha_vazia (Pilha* p){
  if(p->topo == 0){
    return 1;
  }
  return 0;
}

void pilha_push (Pilha* p, int v){
  if (p->topo == MAX) { 
    printf("Capacidade da pilha estourou.\n");
    exit(1);
  }
  /* insere elemento na próxima posição livre */
  p->vet[p->topo] = v;
  p->topo++;
}

float pilha_pop (Pilha* p){
  float v;
  
  if (pilha_vazia(p)){
    printf("Pilha vazia.\n");
    exit(1);
  }

  p->vet[p->topo-1]=0;
  p->topo--;
  return v;
}

  free(p);
}

int mover(Pilha * origem, Pilha * destino){
  pilha_push(destino,origem->vet[origem->topo-1]);
  pilha_pop(origem);
  return 1;
}

int inicializar(Pilha * pino1, int discos){
  if(discos>=MAX){
    printf("Capacidade da pilha é menor que numero de discos.\n");
    return 0;
  }
  
  for(int n=0;discos>n;n++){
    pino1->vet[n]=(discos-n);

    pino1->topo++;
  }
  return 1;
}

void imprime_pino(Pilha*pino){
  int n=0;
  printf("\npino=[ %d", pino->vet[0]);
  n++;
  for(;n<(pino->topo);n++){
    printf(", %d",pino->vet[n]);
  }
  printf(" ]");
}

void mostrarPinos(Pilha * pino1, Pilha * pino2, Pilha * pino3){
  printf("Pinos 1-3:");
  imprime_pino(pino1);
  imprime_pino(pino2);
  imprime_pino(pino3);
  printf("\n\n");
  
  
}

void terminar(Pilha * pino1, Pilha * pino2, Pilha * pino3){
  pilha_libera(pino1);
  pilha_libera(pino2);
  pilha_libera(pino3);
}

int main(void) {
  Pilha*pino1=pilha_cria();
  Pilha*pino2=pilha_cria();
  Pilha*pino3=pilha_cria();
  
  inicializar(pino1,4);

  mostrarPinos(pino1,pino2,pino3);
  
  mover(pino1,pino2);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino3);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino2,pino3);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino2);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino3,pino1);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino3,pino2);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino2);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino3);
  mostrarPinos(pino1,pino2,pino3);  
  mover(pino2,pino1);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino2,pino3);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino2);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino3,pino1);
  mostrarPinos(pino1,pino2,pino3); 
  mover(pino2,pino1);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino2,pino3);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino2);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino1,pino3);
  mostrarPinos(pino1,pino2,pino3);
  mover(pino2,pino3);
  mostrarPinos(pino1,pino2,pino3);
}
