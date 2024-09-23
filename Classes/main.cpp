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
        string nome, adre, job;
        nome = "nome " + to_string(i + 1);
        adre = "rua 0" + to_string(i + 1);
        job = "programador";
        
        pessoas[i].setName(nome);
        pessoas[i].setAdress(adre);
        pessoas[i].setJob(job);
    }

    // Exibe os nomes das pessoas
    for (const Pessoa& pe : pessoas) {
        cout << pe.getName() << endl;
        cout << pe.getAdress() << endl;
        cout << pe.getJob() << endl << endl;
    }

    return 0;
}