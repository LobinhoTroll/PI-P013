#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

//Representação do passageiro
struct Passageiro{
    string cpf;
    string nome;
    int idade;
};

//Representação da passagem
struct Passagem{
    Passageiro passageiro;
    int assento;
    string data_hora;
    double preco;
};

//Representação da viagem
struct Viagem{
    vector<Passagem> passagens;
    string origem;
    string destino;
    string horario;
};


double mediaIdades(const Viagem& viagem){

    int totalIdade = 0;
    for (const Passagem& passagem : viagem.passagens) {
        totalIdade += passagem.passageiro.idade;
    }
    return static_cast<double>(totalIdade) / viagem.passagens.size();

}

int main(){

    vector<Viagem> viagens;
    for (int i = 0; i < 5; i++) {
        Viagem ida;
        ida.origem = "Ilhéus";
        ida.destino = "Salvador";
        ida.horario = "09:30"; 
        viagens.push_back(ida);

        Viagem volta;
        volta.origem = "Salvador";
        volta.destino = "Ilhéus";
        volta.horario = "22:00"; 
        viagens.push_back(volta);
    }

    srand(time(0));

    for (Viagem& viagem : viagens) {
        for (int assento = 1; assento <= 40; assento++) {
            Passagem passagem;
            passagem.assento = assento;
            passagem.data_hora = "2023-09-30 " + viagem.horario; // Data fictícia para simulação
            passagem.passageiro.nome = "Passageiro " + to_string(rand() % 1000);
            passagem.passageiro.cpf = "CPF" + to_string(rand() % 1000000000);
            passagem.passageiro.idade = 18 + rand() % 60; // Idade aleatória entre 18 e 77 anos
            passagem.preco = 80.0; // Valor fixo por passagem

            viagem.passagens.push_back(passagem);
        }
    }

    // Exemplo de uso das funcionalidades
    // 1. Qual o total arrecadado para uma determinada viagem.
    double totalArrecadadoViagem = 0.0;
    for (const Passagem& passagem : viagens[0].passagens) {
        totalArrecadadoViagem += passagem.preco;
    }
    cout << "Total arrecadado para a primeira viagem: R$" << totalArrecadadoViagem << endl;

    // 2. Qual o total arrecadado em um determinado mês (simulação em setembro).
    double totalArrecadadoMes = 0.0;
    for (const Viagem& viagem : viagens) {
        for (const Passagem& passagem : viagem.passagens) {
            if (passagem.data_hora.find("2023-09") != string::npos) {
                totalArrecadadoMes += passagem.preco;
            }
        }
    }
    cout << "Total arrecadado em setembro: R$" << totalArrecadadoMes << endl;

    // 3. Qual o nome do passageiro de uma determinada poltrona P de uma determinada viagem.
    int poltronaDesejada = 5;
    string nomePassageiroPoltronaP = "Não encontrado";
    for (const Passagem& passagem : viagens[2].passagens) {
        if (passagem.assento == poltronaDesejada) {
            nomePassageiroPoltronaP = passagem.passageiro.nome;
            break;
        }
    }
    cout << "Nome do passageiro da poltrona " << poltronaDesejada << " na terceira viagem: " << nomePassageiroPoltronaP << endl;

    // 4. Qual o horário de viagem mais rentável.
    double maiorArrecadacao = 0.0;
    string horarioMaisRentavel;
   
    for (const Viagem& viagem : viagens) {
        double arrecadacaoViagem = 0.0;
        for (const Passagem& passagem : viagem.passagens) {
            arrecadacaoViagem += passagem.preco;
        }
        if (arrecadacaoViagem > maiorArrecadacao) {
            maiorArrecadacao = arrecadacaoViagem;
            horarioMaisRentavel = viagem.horario;
        }
    }
    cout << "Horário de viagem mais rentável: " << horarioMaisRentavel << endl;

    // 5. Qual a média de idade dos passageiros.
    double mediaIdadePassageiros = mediaIdades(viagens[0]); // Usando a primeira viagem como exemplo
    cout << setprecision(3) << "Média de idade dos passageiros na primeira viagem: " << mediaIdadePassageiros << " anos" << endl;

    
    return 0;

}
