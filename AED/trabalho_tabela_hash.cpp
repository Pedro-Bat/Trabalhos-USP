#include <iostream>
#include <string>

using namespace std;

struct Livro {
    string isbn;
    string titulo;
    string autor;
    int ano;
    Livro* prox;

    Livro(string i, string t, string a, int an) : isbn(i), titulo(t), autor(a), ano(an), prox(nullptr) {}
};

class BibliotecaHash {
private:
    static const int TABLE_SIZE = 10;
    Livro* table[TABLE_SIZE];

    int hashFunction(string isbn) {
        int soma = 0;
        for (char c : isbn) {
            soma += static_cast<int>(c);
        }
        return soma % TABLE_SIZE;
    }

public:
    BibliotecaHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~BibliotecaHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Livro* atual = table[i];
            while (atual != nullptr) {
                Livro* temp = atual;
                atual = atual->prox;
                delete temp;
            }
        }
    }

    void inserirLivro(Livro* livro) {
        int index = hashFunction(livro->isbn);
        livro->prox = table[index];
        table[index] = livro;
        cout << "Livro inserido com sucesso!\n";
    }

    void removerLivro(string isbn) {
        int index = hashFunction(isbn);
        Livro* atual = table[index];
        Livro* anterior = nullptr;

        while (atual != nullptr) {
            if (atual->isbn == isbn) {
                //cout << "entrou";
                if (anterior == nullptr) {
                    table[index] = atual->prox;
                } else {
                    anterior->prox = atual->prox;
                }
                delete atual;
                cout << "Livro removido com sucesso!\n";
                return;
            }
            anterior = atual;
            atual = atual->prox;
        }
        cout << "Livro nao encontrado.\n";
    }

    void consultarLivro(string isbn) {
        int index = hashFunction(isbn);
        Livro* atual = table[index];

        while (atual != nullptr) {
            
            if (atual->isbn == isbn) {
                cout << "\nISBN: " << atual->isbn
                     << "\nTitulo: " << atual->titulo
                     << "\nAutor: " << atual->autor
                     << "\nAno: " << atual->ano << "\n\n";
                return;
            }
            atual = atual->prox;
        }
        cout << "Livro nao encontrado.\n";
    }

    void menu() {
        int opcao;
        string isbn, titulo, autor;
        int ano;

        do {
            cout << "\nSistema de Biblioteca (Tabela Hash)\n";
            cout << "1. Inserir livro\n";
            cout << "2. Remover livro\n";
            cout << "3. Consultar livro\n";
            cout << "0. Sair\n";
            cout << "Opcao: ";
            cin >> opcao;
            cin.ignore();

            switch (opcao) {
                case 1:
                    cout << "ISBN: "; getline(cin, isbn);
                    cout << "Titulo: "; getline(cin, titulo);
                    cout << "Autor: "; getline(cin, autor);
                    cout << "Ano: "; cin >> ano;
                    cin.ignore();
                    inserirLivro(new Livro(isbn, titulo, autor, ano));
                    break;
                case 2:
                    cout << "ISBN do livro a remover: ";
                    getline(cin, isbn);
                    removerLivro(isbn);
                    break;
                case 3:
                    cout << "ISBN do livro a consultar: ";
                    getline(cin, isbn);
                    consultarLivro(isbn);
                    break;
                case 0:
                    cout << "Saindo...\n";
                    break;
                default:
                    cout << "Opcao invalida!\n";
            }
        } while (opcao != 0);
    }
};

int main() {
    BibliotecaHash biblioteca;
    biblioteca.menu();
    return 0;
}
