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
    printf("Entre com a mat:");
    scanf("%d", &tab[i]->mat);
    printf("Entre com o nome:");
    scanf("%s", tab[i]->nome);
    printf("Entre com o end:");
    scanf("%s", tab[i]->end);
    printf("Entre com a tel:");
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

int busca_por_nome_linear(int n,Aluno**tab, char*nome){
  
  for(int cont=0;cont<n;cont++){
    
    if(strcmp(nome,tab[cont]->nome)==0){
      return cont;
    }
  }
  
  printf("Aluno nao encontrado");
  return -1;
}

int busca_bin (int n, Aluno**tab, char*nome){
  int ini = 0;
  int fim = n-1;
  int meio, cmp;
  
  while (ini <= fim) {
    meio = (ini + fim) / 2;
    cmp = strcmp(nome,tab[meio]->nome);
    
    if (cmp < 0){
      fim = meio- 1;
    }
    else if (cmp > 0){
      ini = meio + 1;
    }  
    else{
      return meio;
    }
  }
  return -1;
}

void retira(int n, Aluno** tab, int i){
  if (i<0 || i>=n){
    printf("Indice fora do limite do vetor\n");
    exit(1); 
  }
  
  if (tab[i] != NULL){
    free(tab[i]);
    tab[i] = NULL; 
    
  }
}

void atualiza(int n, Aluno** tab, int i){
  if (i < 0 || i >= n){
    printf("Indice fora do limite do vetor\n");
    exit(1);
  }

  if (tab[i]!= NULL){  
    printf("Entre com a mat:");
    scanf("%d", &tab[i]->mat);
    printf("Entre com o nome:");
    scanf("%s", tab[i]->nome);
    printf("Entre com o end:");
    scanf("%s", tab[i]->end);
    printf("Entre com a tel:");
    scanf("%s", tab[i]->tel);   
  }

  else if(tab[i]== NULL){
    printf("Espaco vazio. Use a função preenche");
  }
  
}

void imprime(int n, Aluno** tab, int i){
  if (i<0 || i>=n){
    printf("Indice fora do limite do vetor\n");
    exit(1);
  }
  
  if (tab[i] != NULL){

    printf("Matrícula: %d\n",tab[i]->mat);
    printf("Nome: %s\n",tab[i]->nome);
    printf("Endereco: %s\n",tab[i]->end);
    printf("Telefone: %s\n",tab[i]->tel);

  }
}

void imprime_tudo(int n, Aluno** tab){
  int i;
  for (i=0; i<n; i++){
    imprime(n, tab, i);
  }
} 


int main(void) {

  Aluno *tab[MAX];


  imprime_string("Hello World\n");
  int n=comprimento_de_string("Hello World");
  printf("%d\n", n);
  
  inicializa(MAX,tab);

  tab[0] = (Aluno*)malloc(sizeof(Aluno));
  tab[0]->mat = 62151578;
  strcpy(tab[0]->nome, "Antonio");

  tab[1] = (Aluno*)malloc(sizeof(Aluno));
  tab[1]->mat = 62151578;
  strcpy(tab[1]->nome, "Bruno");
  
  tab[2] = (Aluno*)malloc(sizeof(Aluno));
  tab[2]->mat = 51364125;
  strcpy(tab[2]->nome, "Joao");
  
  tab[3] = (Aluno*)malloc(sizeof(Aluno));
  tab[3]->mat = 82135123;
  strcpy(tab[3]->nome, "Julia");
  
  tab[4] = (Aluno*)malloc(sizeof(Aluno));
  tab[4]->mat = 45612681;
  strcpy(tab[4]->nome, "Maria");
  
  tab[5] = (Aluno*)malloc(sizeof(Aluno));
  tab[5]->mat = 35641215;
  strcpy(tab[5]->nome, "Pedro");

    

  
  preenche(MAX,tab,6);
  printf("%d",busca_bin(5,tab,"Bruno"));
  atualiza(MAX,tab,6);
  imprime_tudo(MAX,tab);
  busca_por_nome_linear(MAX,tab,"Julia");
  retira(MAX,tab,6);
  libera(MAX,tab);
  free(*tab);



  
}