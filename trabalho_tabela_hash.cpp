#include <iostream>
#include <list>
#include <string>
#include <functional>

using namespace std;

struct Livro {
    string isbn;
    string titulo;
    string autor;
    int ano;

    Livro(string i, string t, string a, int an) : isbn(i), titulo(t), autor(a), ano(an) {}
};

class BibliotecaHash {
private:
    static const int TABLE_SIZE = 10;
    list<Livro>* table[TABLE_SIZE];

    int hashFunction(string isbn) {
        hash<string> hash_fn;
        return hash_fn(isbn) % TABLE_SIZE;
    }

public:
    BibliotecaHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = new list<Livro>;
        }
    }

    ~BibliotecaHash() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            delete table[i];
        }
    }

    void inserirLivro(Livro livro) {
        int index = hashFunction(livro.isbn);
        table[index]->push_back(livro);
        cout << "Livro inserido com sucesso!\n";
    }

    void removerLivro(string isbn) {
        int index = hashFunction(isbn);
        auto& lista = *table[index];

        for (auto it = lista.begin(); it != lista.end(); ++it) {
            if (it->isbn == isbn) {
                lista.erase(it);
                cout << "Livro removido com sucesso!\n";
                return;
            }
        }
        cout << "Livro nao encontrado.\n";
    }

    void consultarLivro(string isbn) {
        int index = hashFunction(isbn);
        auto& lista = *table[index];

        for (auto& livro : lista) {
            if (livro.isbn == isbn) {
                cout << "\nISBN: " << livro.isbn
                     << "\nTitulo: " << livro.titulo
                     << "\nAutor: " << livro.autor
                     << "\nAno: " << livro.ano << "\n\n";
                return;
            }
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
                    inserirLivro(Livro(isbn, titulo, autor, ano));
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
