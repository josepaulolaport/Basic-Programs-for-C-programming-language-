#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct aluno{
  int mat;
  char nome[81];
  char end[121];
  char tel[21];
  struct aluno *prox;
  
};typedef struct aluno Aluno;

Aluno* lista_cria (void){
  return NULL;
}

Aluno* lista_insere (Aluno* lista){
  Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
  printf("Entre com a mat:");
  scanf("%d", &novo->mat);
  printf("Entre com o nome:");
  scanf("%s", novo->nome);
  printf("Entre com o end:");
  scanf("%s", novo->end);
  printf("Entre com a tel:");
  scanf("%s", novo->tel);   
  novo->prox = lista;
  return novo;
}

Aluno* lista_insere_ordenado (Aluno* lista, int matricula){
  Aluno* novo;
  Aluno* a = NULL; 
  Aluno* p = lista;
  while (p != NULL && p->mat < matricula){
    a = p; 
    p = p->prox;
  }
 
  novo = (Aluno*) malloc(sizeof(Aluno));
  novo->mat = matricula;
  printf("Entre com o nome:");
  scanf("%s", novo->nome);
  printf("Entre com o end:");
  scanf("%s", novo->end);
  printf("Entre com a tel:");
  scanf("%s", novo->tel);   
  novo->prox = lista;
  
  if (a == NULL){
    novo->prox = lista; 
    lista = novo;
  } 
  else {
    novo->prox = a->prox; 
    a->prox = novo;
  }
  return lista;
}

Aluno* busca (Aluno* lista, char*nome){
  Aluno* p;
  
  for (p = lista; p != NULL; p = p-> prox){
  
    if (strcmp(p->nome,nome)==0){
      return p; 
    }
    
  }
  return NULL;
}

Aluno* lista_retira (Aluno* lista, int matricula){
  Aluno* a = NULL; 
  Aluno* p = lista;
  
  while (p != NULL && p->mat != matricula) {
    a = p;
    p = p->prox;
  }
  
  if (p == NULL){
    return lista; 
  }
  if (a == NULL){
    lista = p->prox;
  }
  else{
    a->prox = p->prox;
  }
  free(p);
  return lista;
}

Aluno* lista_atualiza_ordenado (Aluno* lista, int matricula){
  lista=lista_retira (lista, matricula);
  lista=lista_insere_ordenado (lista, matricula);
  return lista;
}

void lista_imprime (Aluno* lista){
  Aluno* p;
  for (p = lista; p != NULL; p = p->prox){
    printf("\nMatricula:%d\n",p->mat);
    printf("\nNome:%s\n",p->nome);
    printf("\nEndereco:%s\n",p->end);
    printf("\nTelefone:%s\n",p->tel);    
  }
}

int lista_vazia (Aluno* lista){
  if (lista == NULL){
    return 1;
  }
  else{
    return 0;
  }
}

void lista_libera (Aluno* lista){
  Aluno* p = lista;
  Aluno* t;
  while (p != NULL){
    t = p->prox;
    free(p);
    p = t; 
  }
}

int lista_igual(Aluno* lista1, Aluno* lista2){
  Aluno* p1; 
  Aluno* p2; 
  for (p1=lista1, p2=lista2; p1 != NULL && p2 != NULL;p1 = p1->prox, p2 = p2->prox) {
    if ((p1->mat != p2->mat) && (p1->nome != p2->nome) && (p1->end != p2->end) && (p1->tel != p2-> tel)){
     return 0; 
    }
  }
  if (p1 == p2){
    return 1;
  }
  else{
    return 0;
  }
}

int main(void) {
  Aluno * tab=lista_cria();
  tab=lista_insere(tab);
}