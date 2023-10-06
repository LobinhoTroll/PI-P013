#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Estrutura para armazenar informações do produto
struct Produto {
    string codigo;
    string nome;
    double preco;
};

const int MAX_PRODUTOS = 300;

// Função para inserir um novo produto
bool InserirProduto(Produto produtos[], int& quantidade, const string& codigo, const string& nome, double preco) {
    if (quantidade >= MAX_PRODUTOS) {
        cout << "Limite de produtos atingido." << endl;
        return false;
    }

    for (int i = 0; i < quantidade; ++i) {
        if (produtos[i].codigo == codigo || produtos[i].nome == nome) {
            cout << "Produto com o mesmo código ou nome já existe." << endl;
            return false;
        }
    }

    produtos[quantidade].codigo = codigo;
    produtos[quantidade].nome = nome;
    produtos[quantidade].preco = preco;
    quantidade++;

    cout << "Produto inserido com sucesso." << endl;
    return true;
}

// Função para excluir um produto
bool ExcluirProduto(Produto produtos[], int& quantidade, const string& codigo) {
    for (int i = 0; i < quantidade; ++i) {
        if (produtos[i].codigo == codigo) {
            // Movendo os produtos seguintes para preencher o espaço
            for (int j = i; j < quantidade - 1; ++j) {
                produtos[j] = produtos[j + 1];
            }
            quantidade--;

            cout << "Produto excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Produto não encontrado." << endl;
    return false;
}

// Função para listar todos os produtos
void ListarProdutos(const Produto produtos[], int quantidade) {
    cout << "Lista de produtos:" << endl;
    for (int i = 0; i < quantidade; ++i) {
        cout << "Código: " << produtos[i].codigo << ", Nome: " << produtos[i].nome << ", Preço: R$ " << fixed << setprecision(2) << produtos[i].preco << endl;
    }
}

// Função para consultar o preço de um produto por código
void ConsultarPreco(const Produto produtos[], int quantidade, const string& codigo) {
    for (int i = 0; i < quantidade; ++i) {
        if (produtos[i].codigo == codigo) {
            cout << "O preço do produto " << produtos[i].nome << " é R$ " << fixed << setprecision(2) << produtos[i].preco << endl;
            return;
        }
    }

    cout << "Produto não encontrado." << endl;
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade = 0;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Inserir produto" << endl;
        cout << "2. Excluir produto" << endl;
        cout << "3. Listar produtos" << endl;
        cout << "4. Consultar preço" << endl;
        cout << "5. Sair" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 5) {
            break;
        }

        switch (opcao) {
            case 1: {
                string codigo, nome;
                double preco;
                cout << "Digite o código do produto: ";
                cin >> codigo;
                cout << "Digite o nome do produto: ";
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o preço do produto: ";
                cin >> preco;

                InserirProduto(produtos, quantidade, codigo, nome, preco);
                break;
            }
            case 2: {
                string codigo;
                cout << "Digite o código do produto a ser excluído: ";
                cin >> codigo;

                ExcluirProduto(produtos, quantidade, codigo);
                break;
            }
            case 3: {
                ListarProdutos(produtos, quantidade);
                break;
            }
            case 4: {
                string codigo;
                cout << "Digite o código do produto para consultar o preço: ";
                cin >> codigo;

                ConsultarPreco(produtos, quantidade, codigo);
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}