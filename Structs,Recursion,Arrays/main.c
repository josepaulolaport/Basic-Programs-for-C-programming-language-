#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno{
  int matricula;
  char * nome;
  char * endereco;
  char * telefone;
};typedef struct aluno Aluno;

void imprime_string(char*string)
{
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
  int nalunos;
  
  printf("Numero de alunos:");
  scanf("%d",&nalunos);
  printf("\n");

  Aluno* array;
  
  array= (Aluno*) malloc(nalunos*sizeof(Aluno));

  if ( array == NULL ){
    printf("Erro: Alocação de memória falhou");
    exit(1);
  }
  
  for(int cont=0;cont<nalunos;cont++){
    array[cont].nome=(char*) malloc(81*sizeof(char));
    array[cont].endereco=(char*) malloc(121*sizeof(char));
    array[cont].telefone=(char*) malloc(21*sizeof(char));
  
  }
  

  for (int contador=0;contador<nalunos;contador++){
    printf("Aluno numero %d:\n\n", contador+1);
    
    printf("Matricula:");
    scanf("%d",&array[contador].matricula);

    printf("Nome do aluno:");
    scanf("%s",array[contador].nome);

    printf("Endereço do aluno:");
    scanf("%s",array[contador].endereco);

    printf("Telefone do aluno:");
    scanf("%s",array[contador].telefone);
    printf("\n");
  }

  for (int contador=0;contador<nalunos;contador++){
    printf("Dados registrados do aluno numero %d:\n\n", contador+1);
    
    printf("Matricula do aluno: %d\n", array[contador].matricula);
    printf("Nome do aluno:%s\n",array[contador].nome);
    printf("Endereço do aluno:%s\n",array[contador].endereco);
    printf("Telefone do aluno:%s\n",array[contador].telefone);
    printf("\n");
  }

  for (int contador=0;contador<nalunos;contador++){
    printf("Liberando Memoria...\n");
    
    free(array[contador].nome);
    free(array[contador].endereco);
    free(array[contador].telefone);
  }   
  
  free(array);
  printf("Memoria Liberada!\n");    

  char string[]="Hello World!";

  imprime_string(string);
  int n= comprimento_de_string(string);
  printf("\n%d", n);


}