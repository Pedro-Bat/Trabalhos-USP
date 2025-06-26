#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

// Tarefa 3 IC2
// Aluno Pedro Henrique Mendes de Lima
// Nº USP: 13823051


/*
Seja um programa que tenha três funções para a manipulação de matrizes de ponto
flutuante: i) uma que imprima a soma de duas matrizes A e B; ii) outra que calcule o
resultado da multiplicação de duas matrizes A e B, e iii) uma terceira que calcule a
soma do traço da matriz A com o traço da matriz B. Todas as matrizes são quadradas,
isto é, tem n linhas e n colunas. Pede-se

a. Implemente as 3 funções. As funções, que são chamadas no programa
principal, recebem o valor de n e as matrizes A e B. As funções devem
implementar o que foi pedido de forma eficiente em relação ao tempo de
execução.
b. Faça a análise assintótica (notação O) de cada uma das funções. Justifique
as respostas.
*/

/**********************************************************   Análise Assintótica ******************************************************************************* 
 *                                                                                                                                                              *
 *Função printaSoma é O(n^2) pois possui dois loops aninhados em função de uma variavel n, assim ignorando todas as outras operações O(1) ou O(n).              *
 *                                                                                                                                                              *
 *Função multiplicacao é O(n^3) pois possui três loops aninhados em função de uma variavel n, assim ignorando todas as outras operações O(1), O(n) ou O(n^2).   *
 *                                                                                                                                                              *   
 *Função PrintaSomaTraco é O(n) por possui somente um unico loop em função de uma variavel n, assim ignorando toas as outras operações O(1).                    *
 *                                                                                                                                                              *
 ****************************************************************************************************************************************************************/




using namespace std;
typedef vector<vector<int>> Matriz;

void printaSoma(const Matriz &matrizA, const Matriz &matrizB, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrizA[i][j] + matrizB[i][j] << " ";
        }
        cout << '\n';
    }
}

Matriz multiplicacao(const Matriz &matrizA, const Matriz &matrizB, int n) {
    Matriz resultado(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
    return resultado;
}

float printasomaTraco(const Matriz &matrizA, const Matriz &matrizB, int n) {
    float soma = 0;

    for (int i = 0; i < n; ++i) {
        soma += matrizA[i][i] + matrizB[i][i];
    }

    return soma;
}

int main(){
    srand(time(0));
    int n;

    cout << "Digite o Tamanho das matrizes para realizar as operacoes de Soma, Multiplicacao e Soma dos tracos:";

    cin >> n;

    cout << "\nAs matrizes foram preenchidas por uma funcao de forma randomica.\n\n";

    Matriz  matrizA(n, vector<int>(n));
    Matriz  matrizB(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrizA[i][j] = rand() % 100;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrizB[i][j] = rand() % 100;
        }
    }

    cout << "Soma das matrizes:" << "\n";
    printaSoma(matrizA, matrizB, n);

    cout << "\nMultiplicacao das matrizes:" << "\n";
    Matriz matrizC = multiplicacao(matrizA, matrizB, n);
    
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrizC[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nSoma dos tracos: " << printasomaTraco(matrizA, matrizB, n);

    return 0;
}
