#include <iostream>
#include <string>

using namespace std;

struct Livro {
    string isbn;
    string titulo;
    string autor;
    int ano;
    Livro* esq;
    Livro* dir;

    Livro(string i, string t, string a, int an) 
        : isbn(i), titulo(t), autor(a), ano(an), esq(nullptr), dir(nullptr) {}
};

class BibliotecaArvore {
private:
    Livro* raiz;

    Livro* inserirNo(Livro* no, Livro livro) {
        if (no == nullptr) {
            return new Livro(livro.isbn, livro.titulo, livro.autor, livro.ano);
        }

        if (livro.isbn < no->isbn) {
            no->esq = inserirNo(no->esq, livro);
        } else if (livro.isbn > no->isbn) {
            no->dir = inserirNo(no->dir, livro);
        }

        return no;
    }

    Livro* encontrarMinimo(Livro* no) {
        while (no->esq != nullptr) {
            no = no->esq;
        }
        return no;
    }

    Livro* removerNo(Livro* no, string isbn) {
        if (no == nullptr) return nullptr;

        if (isbn < no->isbn) {
            no->esq = removerNo(no->esq, isbn);
        } else if (isbn > no->isbn) {
            no->dir = removerNo(no->dir, isbn);
        } else {
            if (no->esq == nullptr) {
                Livro* temp = no->dir;
                delete no;
                return temp;
            } else if (no->dir == nullptr) {
                Livro* temp = no->esq;
                delete no;
                return temp;
            }

            Livro* temp = encontrarMinimo(no->dir);
            no->isbn = temp->isbn;
            no->titulo = temp->titulo;
            no->autor = temp->autor;
            no->ano = temp->ano;
            no->dir = removerNo(no->dir, temp->isbn);
        }
        return no;
    }

    Livro* buscarNo(Livro* no, string isbn) {
        if (no == nullptr || no->isbn == isbn) {
            return no;
        }

        if (isbn < no->isbn) {
            return buscarNo(no->esq, isbn);
        } else {
            return buscarNo(no->dir, isbn);
        }
    }

public:
    BibliotecaArvore() : raiz(nullptr) {}

    void inserirLivro(Livro livro) {
        raiz = inserirNo(raiz, livro);
        cout << "Livro inserido com sucesso!\n";
    }

    void removerLivro(string isbn) {
        Livro* livro = buscarNo(raiz, isbn);
        if (livro == nullptr) {
            cout << "Livro nao encontrado.\n";
            return;
        }
        raiz = removerNo(raiz, isbn);
        cout << "Livro removido com sucesso!\n";
    }

    void consultarLivro(string isbn) {
        Livro* livro = buscarNo(raiz, isbn);
        if (livro == nullptr) {
            cout << "Livro nao encontrado.\n";
        } else {
            cout << "\nISBN: " << livro->isbn
                 << "\nTitulo: " << livro->titulo
                 << "\nAutor: " << livro->autor
                 << "\nAno: " << livro->ano << "\n\n";
        }
    }

    void menu() {
        int opcao;
        string isbn, titulo, autor;
        int ano;

        do {
            cout << "\nSistema de Biblioteca (Arvore Binaria)\n";
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
    BibliotecaArvore biblioteca;
    biblioteca.menu();
    return 0;
}
