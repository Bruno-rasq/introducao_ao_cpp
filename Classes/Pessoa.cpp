#include "Pessoa.hpp"

// Implementação do método setNome
void Pessoa::setNome(const std::string& nome) {
    this->nome = nome;
}

// Implementação do método getNome
std::string Pessoa::getNome() const {
    return this->nome;
}