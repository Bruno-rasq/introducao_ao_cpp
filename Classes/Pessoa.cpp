#include "Pessoa.hpp"

using namespace std;

// Implementação do método setNome
void Pessoa::setName(const string& name) {
    this->name = name;
}

// Implementação do método getNome
string Pessoa::getName() const {
    return this->name;
}

// Implementação do método setAdress
void Pessoa::setAdress(const string& adress){
    this->adress = adress;
}

string Pessoa::getAdress() const {
    return this->adress;
}

void Pessoa::setJob(const string& job){
    this->job = job;
}

string Pessoa::getJob() const {
    return this->job;
}