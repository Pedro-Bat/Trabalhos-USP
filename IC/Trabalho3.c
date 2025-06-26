#include <stdio.h>
#include<stdlib.h>

// Trabalho Prático IC1 Terceiro Exercicio.
// Aluno: Pedro Henrique Mendes de Lima Nº USP: 13823051

/*
- Crie e leia um vetor de inteiros de n posições;
- Crie e leia um vetor de inteiros de m posições;
- Crie e construa um vetor de inteiros que seja a interseção entre os dois
vetores anteriores, ou seja, que contém apenas os números que estão em
ambos os vetores. Não deve conter números repetidos.
*/
void clearScreen();
int main()
{  
   //Declarando variaveis 
  int n, m , intrs , i = 0, j = 0, voltar = 1;
  
  comeco:// onde o goto aponta
  printf("Escreva os tamanhos para os dois vetores:\n\n");//pedindo o tamanho dos vetores
    scanf(" %d", &n);
    scanf(" %d", &m);

    cleaScreen();
    
    //Determinando o tamanho do vetor interseccao
    if(m>n) 
     intrs = n;
     else 
      intrs = m;

   //Declarando ponteiros/vetores e alocando memória nescessária 
  int *vetor1 = (int *) calloc(n, sizeof(int)); 
  int *vetor2 = (int *) calloc(m, sizeof(int)); 
  int *vetor3 = (int *) calloc(intrs, sizeof(int));
  
   //obtendo valores do vetor
  printf("Escreva os valores para o primeiro vetor de tamanho %d\n\n", n);
  for(i=0 ; i<n; i++)
    scanf(" %d", &vetor1[i]);

  clearScreen();

  printf("Escreva os valores para o segundo vetor de tamanho %d\n\n", m);
  for(i=0; i<m; i++)
    scanf(" %d", &vetor2[i]);

  clearScreen();
    //Achando interseccao entre vetores
  for( i=0; i<n; i++){
    for(j=0; j<m; j++){
        if(vetor1[i] == vetor2[j]) 
         if(vetor3[i] != vetor1[j])
           vetor3[i] = vetor1[i];
    }
 }

   //Eliminando valores iguais
for(i= 0; i<intrs; i++)
 for(j=i+1; j<intrs; j++)
   if(vetor3[i] == vetor3[j])
      vetor3[j] = 0;
  
   
   // Printando valores do vetor interseccao 
printf(" Interseccao: {");
  for(i=0; i<intrs; i++){
    if(vetor3[i]!= 0)
      printf(" %d ", vetor3[i]);
  
  }
   printf("}\n");
   
   //comando goto para retornar ao comeco
  printf("\nse quiser voltar ao comeco aperte 0\n\n");
  scanf(" %d", &voltar);
  if(voltar == 0){

   clearScreen();
      goto comeco;
  }

return 0;
}

void clearScreen()
{
  #ifdef _WIN64
    system("cls");
  #elif __linux
    system("clear");
  #else
  #endif

}
