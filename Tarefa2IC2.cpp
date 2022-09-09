

#include <time.h>
#include <iostream>
#include <ctime>
#include <cstdlib>


// Tarefa 2 de IC2
// Aluno Pedro Henrique Mendes de Lima
// N°USP: 13823051

// Utilizando a Lib <ctime> fazer testes de velocidade de execução de funções que calculam a média aritmética de dois 
// vetores de n tamanho e plotar os resultados em gráfico.

using namespace std;


void prefixmedia1(float *X, float *A, int n);
void prefixmedia2(float *X, float *A, int n);
void clearScreen();


int main() {

	clock_t tempo1, tempo2, tempo3, tempo4;
	double tempo_total;

	float *X, *A, a = 0;
	int n;

    inicio:
	cout << " digite o tamanho n do vetor\n";
	cin >> n;

	A = (float*)calloc(n, sizeof(float));
	X = (float*)calloc(n, sizeof(float));


	for (int i = 0; i < n; i++) {
		X[i] = rand();

        //cout << "valor " << i+1 << "= " << X[i] << "\n"; 

	}
	
	tempo1 = clock();

	

	for (int i = 0; i < n; i++) {
		prefixmedia1(X, A, n);
	}

    
    tempo2 = clock();

    tempo_total = tempo_total = difftime(tempo2, tempo1) / CLOCKS_PER_SEC;
    cout << "\nTempo da funcao 1 = " << tempo_total << " segundos\n";
    cout << "media funcao 1= " << A[n-1] << "\n\n";

	

	


	tempo3 = clock();

	

	for (int i = 0; i < 5; i++) {
		prefixmedia2(X, A, n);
	}



	
	tempo4 = clock();
	tempo_total = tempo_total = difftime(tempo4, tempo3) / CLOCKS_PER_SEC;
	cout << "Tempo da funcao 2 = " << tempo_total << " segundos\n";
        cout << "media funcao 2= " << A[n-1];


    cout << "\n\ndigite 1 para novos valores";
    cin >> a;
    if( a == 1){
        clearScreen();
        goto inicio;
    }

return 0;
}


void prefixmedia1(float *X, float *A, int n) {

	for (int i = 0; i < n; i++) {
		int a = 0;
		for (int j = 0; j <= i; j++) {
			a = a + X[j];
		}
		A[i] = a / (i+1);
		
	}
	
}

void prefixmedia2(float *X, float *A, int n) {


	int s = 0;

	for (int i = 0; i < n ; i++) {
		s = s + X[i];
		A[i] = s / (i + 1);
		

	}
	
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


