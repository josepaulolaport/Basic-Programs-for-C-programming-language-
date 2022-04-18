#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
struct aluno{
int mat;
char nome[81];
char end[121];
char tel[21];
};typedef struct aluno Aluno;

void libera(int n, Aluno** tab){
  int i;
  for (i=0; i<n; i++){
    free(tab[i]);
  }
}

void inicializa(int n, Aluno** tab){
  int i;
  for (i=0; i<n; i++){
    tab[i] = NULL;
  }
}

void preenche(int n, Aluno** tab, int i){
  if (i < 0 || i >= n){
    printf("Indice fora do limite do vetor\n");
    exit(1);
  }
  
  if (tab[i] == NULL){
    tab[i] = (Aluno*)malloc(sizeof(Aluno));
    printf("Entre com a matricula:");
    scanf("%d", &tab[i]->mat);
    printf("Entre com o nome:");
    scanf("%s", tab[i]->nome);
    printf("Entre com o endereco:");
    scanf("%s", tab[i]->end);
    printf("Entre com a telefone:");
    scanf("%s", tab[i]->tel);   
  }
} 

void imprime_string(char*string){
  if(*string=='\0'){
    return;
  }
  printf("%c",*string);
  imprime_string(string+1);
}

int comprimento_de_string(char*string){
  if(*string=='\0'){
    return 0;
  }

  return 1+ comprimento_de_string(string+1);
}  


int main(void) {

  Aluno *tab[MAX];

  imprime_string("Hello World\n");
  int n=comprimento_de_string("Hello World");
  printf("%d\n", n);
  
  inicializa(MAX,tab);
  preenche(MAX,tab,1);

  printf("\nDados registrados do aluno numero 1:\n");
    
  printf("Matricula do aluno: %d\n", tab[1]->mat);
  printf("Nome do aluno:%s\n",tab[1]->nome);
  printf("Endereço do aluno:%s\n",tab[1]->end);
  printf("Telefone do aluno:%s\n",tab[1]->tel);
  printf("\n");
  
  libera(MAX,tab);



  
}