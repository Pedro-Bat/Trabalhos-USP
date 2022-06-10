#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Trabalho Prático IC1 Primeiro Exercicio.
//Aluno: Pedro Henrique Mendes de Lima Nº USP: 13823051


int main()
{
   

    //declarando funcoes
int media(int num1, int num2, int num3, int num4, int num5);
int maior(int num1, int num2, int num3, int num4, int num5);
int menor(int num1, int num2, int num3, int num4, int num5);
float desvio_padrao(int num1, int num2, int num3, int num4, int num5);
int media_ponderada(int num1, int num2, int num3, int num4, int num5);
  
  int num1, num2, num3, num4, num5; int n;//declarando variaveis
  int media1 = 0;
  int mediaP = 0;
  int maior1 = 0;
  int menor1 = 0;
  float desvio = 0; 
  int verificacao = 1;


comeco:
printf("digite 5 valores para serem calculados \n"); //recebendo valores
printf("digite o valor para o primeiro numero:  ");
    scanf("%d", &num1);
printf("digite o valor para o segundo numero:  ");
    scanf("%d", &num2);
printf("digite o valor para o terceiro numero:  ");
    scanf("%d", &num3);
printf("digite o valor para o quarto numero:  ");
    scanf("%d", &num4);   
printf("digite o valor para o quinto numero:  ");
    scanf("%d", &num5);

printf("\n Escolha uma das seguintes opcoes de calculo\n\n"); //escolher entre as opções
printf(" Digita 1 para calcular a media dos valores\n");
printf(" Digite 2 para calcular a media ponderada dos valores \n");
printf(" Digite 3 para descobrir o menor dos valores digitados\n");
printf(" Digite 4 para descobrir o maior dos valores digitados\n");
printf(" Digite 5 para calcular o desvio padrao\n");
printf(" Digite 6 para ver os numeros digitados\n");
    scanf("%d", &n);

    switch (n) //opcoes
    {
         case 1:
          media1 = media(num1, num2, num3, num4, num5);
          printf(" A media dos valores e: %d",  media1);

          break;

         case 2:
         mediaP = media_ponderada(num1, num2, num3, num4, num5);
          printf(" A media ponderada dos valores e: %d", mediaP);

          break;

         case 3:
          menor1 = menor(num1, num2, num3, num4, num5);
          printf(" O menor numero digitado foi o: %d", menor1);

          break;

         case 4:
          maior1 = maior(num1,num2, num3, num4, num5);
          printf(" O maior numero digitado foi o: %d", maior1);

          break;

         case 5:
          desvio = desvio_padrao(num1, num2, num3, num4, num5);
          printf(" O desvio padrao calculado para os valores e: %f", desvio);

          break;

         case 6:
          printf("Os numeros digitados foram:\n");
          printf("%f\n", num1);
          printf("%f\n", num2);
          printf("%f\n", num3);
          printf("%f\n", num4);
          printf("%f\n", num5);

          break;

         default:
          printf(" opcao nao valida");

          break;
    
    }

     printf("\n\nSe quiser voltar ao inicio aperte 0\n");
    scanf("%d", &verificacao);
     
     if(verificacao == 0)
      goto comeco;

return 0;

}

int media(int num1, int num2, int num3, int num4, int num5) //funcao que calcula a media aritimetica
{
    int med = 0, soma = 0; // declaracao das variaveis
    soma = num1+num2+num3+num4+num5; // calculo da media
    med = soma/5;
  return med;
}


int media_ponderada(int num1, int num2, int num3, int num4, int num5) // funcao que calcula a media ponderada
{
int medP = 0, mult1 = 0, mult2 = 0, mult3 = 0, mult4 = 0, mult5 = 0; //declaracao de variaveis

printf("\nEscreva o valor a ser considerado para cada numero\n"); // pegando do usuario os valores a serem multiplicados
printf("digite o valor para o primeiro numero: ");
    scanf("%d", &mult1);
printf("digite o valor para o segundo numero: ");
    scanf("%d", &mult2);
printf("digite o valor para o terceiro numero: ");
    scanf("%d", &mult3);
printf("digite o valor para o quarto numero: ");
    scanf("%d", &mult4);
printf("digite ovalor para o quinto numero: ");
    scanf("%d", &mult5);

num1 *= mult1; //atribuindo os valores 
num2 *= mult2;
num3 *= mult3;
num4 *= mult4;
num5 *= mult5;

medP = (num1+num2+num3+num4+num5)/5; // calculo da media ponderada

return medP;
}


int maior(int num1, int num2, int num3, int num4, int num5) //funcao que verifica o maior entre os valores digitados
{
    int maior; //declaracao de variaveis
 if( num1>num2) //verificacoes
     maior = num1;
    else
        maior = num2;

 if(maior<num3)
     maior = num3;
 
 if(maior<num4)
     maior = num4;

 if(maior<num5)
    maior = num5;

    return maior;
}


int menor(int num1, int num2, int num3, int num4, int num5) //funcao que verifica o maior entre os valores digitados
{

    float menor; // declarando variaveis
 if(num1<num2) // verificacoes
     menor = num1;
    else 
        menor = num2;

 if(menor>num3)
    menor = num3;

 if(menor>num4)
    menor = num4;

 if(menor>num5)   
    menor = num5;   

    return menor;

    
}

float desvio_padrao(int num1, int num2, int num3, int num4, int num5) // funcao que calcula desvio padrao
{
int dif1, dif2, dif3, dif4, dif5;  // declarando variaveis
int med; float desvio;

 med = (num1+num2+num3+num4+num5)/5; // calculo da media

 //calculando as diferencas
 dif1 = num1 - med; dif2 = num2 - med; dif3 = num3 - med, dif4 = num4 - med, dif5 = num5 - med;

 // elevando ao quadrado
 dif1 *= dif1; dif2 *= dif2; dif3 *= dif3; dif4 *= dif4; dif5 *= dif5; 
 // calculando desvio
 desvio = sqrt((dif1 + dif2 + dif3 + dif4 + dif5)/5);

 return desvio;
}
