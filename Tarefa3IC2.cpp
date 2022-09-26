#include <iostream>
#include <cstdlib>
#include <ctime>

// Tarefa 3 IC2
// Aluno Pedro Henrique Mendes de Lima
// Nº USP: 13823051

/* Seja uma função (subrotina) que, dado um vetor v com n inteiros e um inteiro x
(chave de busca), retorne o índice da primeira ocorrência de x em v; caso não
encontre x no vetor v, a função deve retornar o valor -1. O número de operações
primitivas desta função deve ser constante para o melhor caso, enquanto que para
o pior caso, o número de operações primitivas deve ser linear em n. Pede-se:
a) Implemente a função em C++.
b) Faça a análise por operações primitivas da função.   */

//--------------------------------------------ATENÇÃO--------------------------------------------------------------
//-----------------------Fiz a Contagem por operações primitivas nos comentários ao Lado da Função ------------------------------------------

using namespace std;

int funcBusca(int *Vetor, int x, int n);

int main()
{

    int n, x, result, i;

    cout << "Escreva um valor para o x\n";
    cin >> x;

    cout << "\nEscreva o tamanho do vetor n\n";
    cin >> n;

    int *vetor = (int *)calloc(n, sizeof(int));

    for (i = 0; i < n; i++)
    {
        vetor[i] = rand();
        // cout << vetor[i] << "\n";
    }

    cout << "\n O valor de x foi encontrado no indice:" << funcBusca(vetor, x, n) << " do vetor.";

    return 0;
}

int funcBusca(int *vetor, int x, int n)
{                                         //  pior caso                   | melhor caso
    for (int i = 0; i < n; i++)           //  1 + n + 2(n)                | 1 + 1
    {                                     //                              |
        if (vetor[i] == x)                //  2(n)                        | 2
        {                                 //                              |
            return i;                     //                              | 1
        }                                 //                              |
                                          //                              |
        else if (i + 1 == n)              // 2(n)                         |
        {                                 //                              |
            return -1;                    // 1                            |
        }                                 // total: 4 + 7n                | total: 5
    }
}
