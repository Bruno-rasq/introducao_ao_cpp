#include <iostream>
#include <vector>
#include "Pessoa.hpp"

using namespace std;

int main() {
    // Criação de um vetor de objetos do tipo Pessoa
    vector<Pessoa> pessoas;

    Pessoa p1, p2, p3, p4;

    // Adiciona objetos ao vetor
    pessoas.push_back(p1);
    pessoas.push_back(p2);
    pessoas.push_back(p3);
    pessoas.push_back(p4);

    // Define nomes para cada pessoa
    for (int i = 0; i < pessoas.size(); i++) {
        string nome = "nome " + to_string(i);
        pessoas[i].setNome(nome);
    }

    // Exibe os nomes das pessoas
    for (const Pessoa& pe : pessoas) {
        cout << pe.getNome() << endl;
    }

    return 0;
}