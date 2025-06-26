#include <stdio.h>
#include <stdlib.h>

// Trabalho Prático IC1 Segundo Exercicio.
//Aluno: Pedro Henrique Mendes de Lima Nº USP: 13823051

/*
Faça um programa para o “jogo de adivinhar um número”. O computador deve sortear
um número entre 0 e 100 e pedir para o usuário tentar adivinhar este número. O usuário
vai dizer o seu palpite, e o computador deve responder, se ele é maior ou menor que o
número que ele sorteou. O programa termina somente quando o usuário acertar
exatamente qual o número que o computador tinha sorteado, escrevendo uma mensagem
de felicitações para o nosso usuário e indicando o número total de tentativas feitas.
*/
void clearScreen();
void main()
{
    int i = 0, n = 0, chute = 0, nmr = 0, volta = 1; //Declarando variaveis

   comeco:// local onde o goto deve voltar
   
    printf("Jogo de advinhacao \n\nNesse jogo voce tem que acertar um numero gerado aleatoriamente, digite o limite desse numero: ");
       scanf("%d", &i); // scaneia o limite para gerar um numero
        nmr = 0;
        n = rand () % i;

        do{ //Estrutura de repeticao para tentar novamente caso erre o valor
            printf("\nDe o seu chute: ");
             scanf("%d", &chute); // escaneia a tentativa

             if( chute<n) // verifica se a tentativa é maior ou menor que o numero gerado
             {
                 printf("Nao foi dessa vez, tente um numero maior\n");
                 nmr += 1;//soma os numeros de tentativas
             }
              if( chute>n)
              {
                 printf("Nao foi dessa vez, tente um numero menor\n");
                 nmr += 1;
              }
        } while(chute != n); 
        nmr +=1;

        printf("\nParabens voce acertou!.\nSeu numero de tentativas foi: %d\n", nmr);
        printf("Se quiser jogar novamente aperte o numero 0\n");
         scanf("%d", &volta);

            if(volta == 0)//reinicia o jogo
            clearScreen();
                goto comeco;
            

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
