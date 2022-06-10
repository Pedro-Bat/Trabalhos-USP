#include <stdio.h>
#include <stdlib.h>


void main()
{
    int n = 0, chute = 0, nmr = 0, volta = 1;

   comeco:
    printf("Jogo de advinhacao \n\nNesse jogo voce tem que acertar um numero gerado aleatoriamente de 1 a 1000. ");
       
        n = rand () % 1000;

        do{
            printf("\nDe o seu chute: ");
             scanf("%d", &chute);

             if( chute<n)
             {
                 printf("Nao foi dessa vez, tente um numero maior\n");
                 nmr += 1;
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

            if(volta == 0)
                goto comeco;
            

}