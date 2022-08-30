#include <iostream>
#include <cmath>
#include <iomanip>



// Tarefa 1 IC2
// Aluno Pedro Henrique Mendes de Lima


// Escrever um programa em C++ que
// a. Possua uma estrutura chamada estudante com os seguinte elementos
// Numero USP
// Nota da primeira prova
// Nota da segunda prova
// Média final
// B. Tenha um menu que permita realizar as seguintes operações
// 1. Entrar com dados de um estudante (número USP e notas das provas)
// 2. Mostrar dados de um estudante
// 3. Mostrar a média e desvio padrão para as médias finais de todos os estudantes cadastrados
// 4. Sair



using namespace std;



struct Estudante {

    int numeroUsp;
    int notaProva1;
    int notaProva2;
    double mediaFinal;
};
     



int main (){

void clearScreen();
double desvioPadrao (double vetor[], int n);


    int opcao, n=0, m, i;
    char a;
    double desvio, vetor[100];
    Estudante aluno[100]; 


    menu:
    cout << "1- Entrar com dados de um estudante.\n";
    cout << "2- Mostrar dados de um estudante.\n";
    cout << "3- Media e Desvio Padrao.\n";
    cout << "4- Sair.\n\n ";
     cin >> opcao;
       clearScreen();


  
     switch(opcao){


        case 1:
        cout << "quantos estudantes voce quer cadastrar? limite de 100 alunos\n\n ";
        cin >> n;
        clearScreen();

            for(i = 0; i<n; i++){
                cout << " Entre com o numero USP do aluno numero: " << i+1 << "\n\n ";
                cin >> aluno[i].numeroUsp;
                clearScreen();
                cout << " Entre com a nota da primeira prova do aluno numero: "<< i+1 << "\n\n ";
                cin >> aluno[i].notaProva1;
                clearScreen();
                cout << " Entre com a nota da segunda prova do aluno numero: " << i+1 << "\n\n ";
                cin >> aluno[i].notaProva2;
                clearScreen();
                    
                    aluno[i].mediaFinal = (aluno[i].notaProva1 + aluno[i].notaProva2)/2;
             }
                    clearScreen();
         
           cout << "Agora com os alunos cadastrados pode verificar as informacoes do alunos no menu!!. \n\n";
                goto menu;


        break;

                     
    
        case 2:

        if(n == 0){
            cout << " Nao ha nenhum estudante cadastrado!!! \n\n";
            goto menu;
        }
            
            cout << "Digite o numero USP do aluno que voce quer pesquisar: \n";
            cin >> m;
               
            for( i = 0; i<n; i++){
                if( m == aluno[i].numeroUsp){
                  
                cout << " Informacoes do Aluno:\n";
                cout << " Numero Usp: " << aluno[i].numeroUsp << "\n";
                cout << " Nota da Primeira Prova: " << aluno[i].notaProva1 << "\n";
                cout << " Nota da Segunda Prova: " << aluno[i].notaProva2 << "\n";
                cout << " Media Final: " << aluno[i].mediaFinal;
                break;
             }   
            }
            
            case 3: 
            
        
        if(n == 0){
            cout << " Nao ha nenhum estudante cadastrado!!! \n\n";
            goto menu;
        }

            for(i = 0; i<n; i++){
                vetor[i] = aluno[i].mediaFinal;
            }
            desvio = desvioPadrao( vetor, n);


            cout << "Notas finais e Desvio Padrao de todos os Alunos:\n\n";
            
            for( i = 0; i<n; i++){
                cout << "Aluno: " << aluno[i].numeroUsp << " = " << aluno[i].mediaFinal << "\n";
            }

            std::cout << "Desvio Padrao dos Alunos = " << std::fixed << std::setprecision(2) << desvio <<"\n";

            break;
          
            case 4:
                break;

            default:
                cout << "digite um numero valido!!\n";
                 goto menu;
     }

return 0;

}

double desvioPadrao (double vetor[], int n){
    int i;
    double desvio, dif[n], soma2=0, media, media2, soma=0;

    for(i=0; i<n; i++){
      soma += vetor[i];
    }
  
       media = soma/n;
   

    for(i=0; i<n; i++){
        dif[i] = vetor[i] - media;
    }

    for(i=0; i<n; i++){
        dif[i] *= dif[i];
    }
    
    for(i=0; i<n; i++){
       soma2 += dif[i];
    }
  
      media2 = soma2/(n -1);

     desvio = sqrt(media2);


  return desvio;
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