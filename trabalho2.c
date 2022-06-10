#include <stdio.h>
#include <stdlib.h>

// Trabalho Prático IC1 Segundo Exercicio.
//Aluno: Pedro Henrique Mendes de Lima Nº USP: 13823051

void main()
{
    int i = 0, n = 0, chute = 0, nmr = 0, volta = 1; //Declarando variaveis

   comeco:// local onde o goto deve voltar
    printf("Jogo de advinhacao \n\nNesse jogo voce tem que acertar um numero gerado aleatoriamente, digite o limite desse numero: ");
       scanf("%d", &i) // scaneia o limite para gerar um numero
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

        printf("Parabens voce acertou.\nSeu numero de tentativas foi: %d\n", nmr);
        printf("Se quiser jogar novamente aperte o numero 0\n");
         scanf("%d", &volta);

            if(volta == 0)//reinicia o jogo
                goto comeco;
            

}
