#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
  Aluno: Pedro Henrique Mendes de LIma
  N° USP: 13823051

  Seja um registro (estrutura) com os campos: nome (string) e número de inscrição (int).
Pede-se
a. Faça uma função para ordenar, via QuickSort, um vetor com N registros. A
ordenação deve ser de acordo com o número de inscrição;
b. Imprima na tela o número de comparações entre chaves, movimentações de
registros e chamadas da função recursiva realizadas pelo algoritmo. Utilize
contadores para isso.
c. Mostre os números de comparações e movimentações e desenhe as respectivas
árvores de recursão para as 3 sequências a seguir (no qual apenas o número de
inscrição é apresentado):

45 56 12 43 95 19 8 67
8 12 19 43 45 56 67 95
95 67 56 45 43 19 12 8
*/

struct dados
{
    int numInscricao;
    string Nome;
};

void ordQuickSort(int *vetor, int esquerda, int direita, int *count);

int main()
{
    int n, *vetor;
    int *count = (int *)calloc(2, sizeof(int)); //count[0] é atribuicoes ou mudancas e count[1] sao as comparacoes.

    cout << "Entre com o o tamanho do vetor \n";
    cin >> n;

    dados *D1 = new dados[n];
    vetor = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {

        cout << " Coloque o numero de inscricao para o registro numero: " << i + 1 << "\n";
        cin >> D1[i].numInscricao;

        //cout << " Coloque o nome do registro numero: " << i + 1 << "\n";
        //cin >> D1[i].Nome;
    }

    for (int i = 0; i < n; i++)
    {
        vetor[i] = D1[i].numInscricao;
    }


    ordQuickSort(vetor, 0, n, count);

     cout << "\n";

    for(int i = 0; i<n; i++){
        cout << vetor[i] << ", ";
    }
    cout << "\n\n Numero de comparacoes: " << count[1] << "\n Numero de atribuicoes: " << count[0];

       return 0; 
}

void ordQuickSort(int *vetor, int esquerda, int direita, int *count)
{
    
    //int *count = (int *)calloc(2, sizeof(int)); //count[0] é atribuicoes ou mudancas e count[1] sao as comparacoes.

    int i, j, pivo, aux;

    

    i = esquerda;
    j = direita - 1;
    

    pivo = vetor[(esquerda + direita) / 2];
    count[0] +=3;

    while (i <= j)
    {
      count[1] +=1;
        while (vetor[i] < pivo && i < direita)
        {
            i++;
           count[1] +=1;
           count[0] +=1;

        }

        while (vetor[j] > pivo && j > esquerda)
        {
            j--;
           count[1] +=1;
           count[0] +=1;
        }

        if (i <= j)
        {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
           count[1] +=1;
           count[0] +=5;
        }
    }

    if(j > esquerda){
        count[1] +=1;
        ordQuickSort(vetor, esquerda, j+1, count);
    }
    if(i < direita){
        count[1] +=1;
        ordQuickSort(vetor, i, direita, count);
    }
}
