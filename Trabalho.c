#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Trabalho Prático IC1 Primeiro Exercicio.
//Aluno: Pedro Henrique Mendes de Lima Nº USP: 13823051

/*
  Faça um programa que leia 5 números. Este programa deve ter um menu que permita ao
 usuário escolher qual opção de cálculo ele deseja realizar: média aritmética simples,
 média ponderada (ler os pesos associados a cada nota que serão informados pelo
 usuário), desvio padrão, maior valor e menor valor. A leitura dos 5 valores também deve
 ser uma das opções do menu.
*/

void clearScreen();
int main()
{
   

    //declarando funcoes
float media(float num1, float num2, float num3, float num4, float num5);
float maior(float num1, float num2, float num3, float num4, float num5);
float menor(float num1, float num2, float num3, float num4, float num5);
float desvio_padrao(float num1, float num2, float num3, float num4, float num5);
float media_ponderada(float num1, float num2, float num3, float num4, float num5);
  
  float num1, num2, num3, num4, num5; int n;//declarando variaveis
  float media1 = 0;
  float mediaP = 0;
  float maior1 = 0;
  float menor1 = 0;
  float desvio = 0; 
  int verificacao = 9;


comeco:
printf(" Digite 5 valores para serem calculados \n\n"); //recebendo valores
printf(" Digite o valor para o primeiro numero:  ");
    scanf("%f", &num1);
printf(" Digite o valor para o segundo numero:  ");
    scanf("%f", &num2);
printf(" Digite o valor para o terceiro numero:  ");
    scanf("%f", &num3);
printf(" Digite o valor para o quarto numero:  ");
    scanf("%f", &num4);   
printf(" Digite o valor para o quinto numero:  ");
    scanf("%f", &num5);
    clearScreen();

do{
printf(" Escolha uma das seguintes opcoes de calculo\n\n"); //escolher entre as opções
printf(" Digite 1 para calcular a media dos valores\n");
printf(" Digite 2 para calcular a media ponderada dos valores \n");
printf(" Digite 3 para descobrir o menor dos valores digitados\n");
printf(" Digite 4 para descobrir o maior dos valores digitados\n");
printf(" Digite 5 para calcular o desvio padrao\n");
printf(" Digite 6 para ver os numeros digitados\n");
    scanf("%d", &n);
    clearScreen();

    switch (n) //opcoes
    {
         case 1:
          media1 = media(num1, num2, num3, num4, num5);
          printf(" A media dos valores e: %.2f",  media1);

          break;

         case 2:
         mediaP = media_ponderada(num1, num2, num3, num4, num5);
          printf("\n A media ponderada dos valores e: %.2f", mediaP);

          break;

         case 3:
          menor1 = menor(num1, num2, num3, num4, num5);
          printf(" O menor numero digitado foi o: %.2f", menor1);

          break;

         case 4:
          maior1 = maior(num1,num2, num3, num4, num5);
          printf(" O maior numero digitado foi o: %.2f", maior1);

          break;

         case 5:
          desvio = desvio_padrao(num1, num2, num3, num4, num5);
          printf(" O desvio padrao calculado para os valores e: %.2f", desvio);

          break;

         case 6:
          printf("Os numeros digitados foram:\n");
          printf("%.2f\n", num1);
          printf("%.2f\n", num2);
          printf("%.2f\n", num3);
          printf("%.2f\n", num4);
          printf("%.2f\n", num5);

          break;

         default:
          printf(" opcao nao valida");

          break;
    
    }

     printf("\n\nSe quiser fazer um novo calculo com esses valores aperte qualquer numero diferente de 0\nSe quiser novos valores aperte 0\n");
    scanf("%d", &verificacao);
    clearScreen();
         
}while(verificacao != 0);

if(verificacao == 0 )
 clearScreen();
 goto comeco;
  

return 0;

}

float media(float num1, float num2, float num3, float num4, float num5) //funcao que calcula a media aritimetica
{
    float med = 0, soma = 0; // declaracao das variaveis
    soma = num1+num2+num3+num4+num5; // calculo da media
    med = soma/5;
  return med;
}


float maior(float num1, float num2, float num3, float num4, float num5) //funcao que verifica o maior entre os valores digitados
{
    float maior; //declaracao de variaveis
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


float menor(float num1, float num2, float num3, float num4, float num5) //funcao que verifica o maior entre os valores digitados
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


float desvio_padrao(float num1, float num2, float num3, float num4, float num5) // funcao que calcula desvio padrao
{
float dif1, dif2, dif3, dif4, dif5;  // declarando variaveis
float med, desvio;

 med = (num1+num2+num3+num4+num5)/5; // calculo da media

 //calculando as diferencas
 dif1 = num1 - med; dif2 = num2 - med; dif3 = num3 - med, dif4 = num4 - med, dif5 = num5 - med;

 // elevando ao quadrado
 dif1 *= dif1; dif2 *= dif2; dif3 *= dif3; dif4 *= dif4; dif5 *= dif5; 
 // calculando desvio
 desvio = sqrt((dif1 + dif2 + dif3 + dif4 + dif5)/5);

 return desvio;
}


float media_ponderada(float num1, float num2, float num3, float num4, float num5) // funcao que calcula a media ponderada
{
float medP = 0, mult1 = 0, mult2 = 0, mult3 = 0, mult4 = 0, mult5 = 0; //declaracao de variaveis

printf(" Escreva o valor a ser considerado para cada numero\n\n"); // pegando do usuario os valores a serem multiplicados
printf(" Digite o valor para o primeiro numero: ");
    scanf("%f", &mult1);
printf(" Digite o valor para o segundo numero: ");
    scanf("%f", &mult2);
printf(" Digite o valor para o terceiro numero: ");
    scanf("%f", &mult3);
printf(" Digite o valor para o quarto numero: ");
    scanf("%f", &mult4);
printf(" Digite ovalor para o quinto numero: ");
    scanf("%f", &mult5);

num1 *= mult1; //ponderando os valores 
num2 *= mult2;
num3 *= mult3;
num4 *= mult4;
num5 *= mult5;

medP = (num1+num2+num3+num4+num5)/5; // calculo da media ponderada

return medP;
}

void clearScreen()
{
  #ifdef _WIN64
    system("cls");
  #elif __linux
    system("clear");
  #elif _WIN32
    system("cls");
  #else
  #endif

}
