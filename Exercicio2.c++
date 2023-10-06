#include <iostream>
#include <string>

using namespace std;

struct Empregado {
    string nome;
    string sobrenome;
    int data_nas;
    string RG;
    int anoAdmissao;
    double salario;
};

void Reajusta_dez_porcento(Empregado empregados[], int quantidade) {
    for (int i = 0; i < quantidade; ++i) {
        empregados[i].salario *= 1.10; // Aumento de 10%
    }
}

int main() {
    const int capacidade = 50;
    Empregado empregados[capacidade];
    int quantidade;

    
    cout << "Formeça a quantidade de empregados (até " << capacidade << "): ";
    cin >> quantidade;

    if (quantidade <= capacidade && quantidade >= 0) {
        
        for (int i = 0; i < quantidade; ++i) {
            empregados[i].nome = "Nome" + to_string(i + 1);
            empregados[i].sobrenome = "Sobrenome" + to_string(i + 1);
            empregados[i].data_nas = 1990 + i;
            empregados[i].RG = "RG" + to_string(i + 1);
            empregados[i].anoAdmissao = 2015 + i;
            empregados[i].salario = 3000.0 + i * 500;
        }

        cout << "Salários pre reajuste:" << endl;
        for (int i = 0; i < quantidade; ++i) {
            cout << "Empregado " << i + 1 << ": " << empregados[i].salario << endl;
        }

        Reajusta_dez_porcento(empregados, quantidade);

        cout << "Salários pós reajuste:" << endl;
        for (int i = 0; i < quantidade; ++i) {
            cout << "Empregado " << i + 1 << ": " << empregados[i].salario << endl;
        }
    } else {
        cout << "Quantidade de empregados inválida." << endl;
    }

    return 0;