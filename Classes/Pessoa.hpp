#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa {
private:
    std::string nome;

public:
    // Métodos públicos
    void setNome(const std::string& nome);
    std::string getNome() const;
};

#endif