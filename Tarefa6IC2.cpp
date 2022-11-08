#include <iostream>
#include <cmath>
#include <iomanip>


//
A prefeitura de uma cidade faz uma pesquisa sobre os domicílios na área urbana. Em
cada domicilio, são coletados dados sobre renda média mensal, número total de
ocupantes, endereço e número de ocupantes em idade escolar. Faça:
a. um programa que leia estes dados, faça a ordenação por inserção direta e salve
os dados ordenados em um arquivo. Os dados devem ser ordenados de acordo
com o endereço.
b. um programa que leia o arquivo e tenha um menu que permita:
i. Listar todos os domicílios, com as respectivas informações;
ii. Buscar os dados do domicílio quando um determinado endereço é
digitado. Para a busca, deve-se utilizar busca binária;
iii. Sair.
//

using namespace std;

struct dados
{
   double rendaMensal;
   int numOcupantes;
   int endereco;
   int ocupantesEscolar;

   void printDados()
   {
      cout << " Dados do Domicilio de endereco: " << endereco << "\n\n";
      cout << " Renda Mensal : R$" << rendaMensal << "\n";
      cout << " Numero de Ocupantes : " << numOcupantes << "\n";
      cout << " Endereco : " << endereco << "\n";
      cout << " Numero de Ocupantes em idade escolar : " << ocupantesEscolar << "\n\n";
   }
};

void clearScreen();
int main()
{
   int n, m;

   cout << "quantos domicilios serao cadastrados?"
        << "\n";
   cin >> n;

   int inicio = 0, fim = n - 1, meio, valor;

   dados *domicilios = new dados[n];
   dados aux;

   for (int i = 0; i < n; i++)
   {
      cout << " Digite os dados do domicilio " << i + 1 << "\n\n";
      cout << "\n";
      cout << " Renda Mensal: ";
      cin >> domicilios[i].rendaMensal;
      cout << "\n";
      cout << " Numero de ocupantes totais: ";
      cin >> domicilios[i].numOcupantes;
      cout << "\n";
      cout << " Endereco: ";
      cin >> domicilios[i].endereco;
      cout << "\n";
   ocupantes:
      cout << " Ocupantes em idade Escolar: ";
      cin >> domicilios[i].ocupantesEscolar;
      cout << "\n";
      if (domicilios[i].ocupantesEscolar > domicilios[i].numOcupantes)
      {
         cout << "O numero de Ocupantes em idade escolar não pode ser maior que o numero de ocupantes totais! \n Digite um valor valido!"
              << "\n\n";
         goto ocupantes;
      }
      clearScreen();
   }

   // ordenacao por isercao

   for (int i = 0; i < n; i++)
   {
      if (domicilios[i].endereco > domicilios[i + 1].endereco)
      {

         aux.endereco = domicilios[i + 1].endereco;
         aux.numOcupantes = domicilios[i + 1].numOcupantes;
         aux.ocupantesEscolar = domicilios[i + 1].ocupantesEscolar;
         aux.rendaMensal = domicilios[i + 1].rendaMensal;

         domicilios[i + 1].endereco = domicilios[i].endereco;
         domicilios[i + 1].numOcupantes = domicilios[i].numOcupantes;
         domicilios[i + 1].ocupantesEscolar = domicilios[i].ocupantesEscolar;
         domicilios[i + 1].rendaMensal = domicilios[i].rendaMensal;

         domicilios[i].endereco = aux.endereco;
         domicilios[i].numOcupantes = aux.numOcupantes;
         domicilios[i].ocupantesEscolar = aux.ocupantesEscolar;
         domicilios[i].rendaMensal = aux.rendaMensal;

         int j = i - 1;

         while (j >= 0)
         {
            if (aux.endereco < domicilios[j].endereco)
            {

               domicilios[j + 1].endereco = domicilios[j].endereco;
               domicilios[j + 1].numOcupantes = domicilios[j].numOcupantes;
               domicilios[j + 1].ocupantesEscolar = domicilios[j].ocupantesEscolar;
               domicilios[j + 1].rendaMensal = domicilios[j].rendaMensal;

               domicilios[j].endereco = aux.endereco;
               domicilios[j].numOcupantes = aux.numOcupantes;
               domicilios[j].ocupantesEscolar = aux.ocupantesEscolar;
               domicilios[j].rendaMensal = aux.rendaMensal;
            }
            else
            {
               break;
            }
            j -= 1;
         }
      }
   }

   cout << "Escolha uma das opcoes:\n\n";
   cout << " Digite (1) para ver todos os dados dos domicilios.\n";
   cout << " Digite (2) para pesquisar os dados de um domicilio em especifico (o endereco e dado por numeros inteiros).\n";
   cout << " Digite (3) para sair do programa.\n\n";
   cin >> m;
   clearScreen();

   switch (m)
   {

   case 1:
      for (int i = 0; i < n; i++)
      {
         domicilios[i].printDados();
      }
      break;

   case 2:
      cout << " Digite o endereco que voce quer pesquisar: ";
      cin >> valor;

      while (inicio <= fim)
      {
         meio = (inicio + fim) / 2;

         cout << valor;
         cout << " " << domicilios[meio].endereco << " " << meio << " " << inicio << " " << fim;
         if (valor == domicilios[meio].endereco)
         {
            domicilios[meio].printDados();
            break;
         }
         else if (valor < domicilios[meio].endereco)
         {
            fim = meio - 1;
         }
         else if (valor > domicilios[meio].endereco)
         {
            inicio = meio + 1;
         }
      }

      break;

   case 3:
      system("exit");
      break;

   default:

      cout << "Escreva um numero valido";
      break;
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
