#ifndef CIFRADOR_HPP
#define CIFRADOR_HPP

#include <vector>
#include <utility>
#include <string>

class Cifrador {
private:
    std::string encodedtext;
    std::string decodedtext;
    std::vector<std::pair<unsigned char, unsigned char>> encodingTable;
    std::vector<std::pair<unsigned char, size_t>> charFrequences;

    // Método auxiliar que retorna o texto a ser considerado, dependendo do estado
    std::string getEffectiveText() const;

public:
    // Construtores
    Cifrador();
    Cifrador(const std::string& txt, bool isdecoded);
    Cifrador(const std::string& txt, bool isdecoded, int key);

    // Configuração da tabela de codificação com uma chave
    void setEncodingTable(int key);

    // Setters para encodedtext e decodedtext
    void setEncodedText(const std::string& txt);
    void setDecodedText(const std::string& txt);

    // Inicialização e contagem de frequências dos caracteres
    void setCharFrequences();
    void countCharFrequences();

    // Getters para encodedtext, decodedtext e frequências de caracteres
    std::string getDecodedText() const;
    std::string getEncodedText() const;
    std::vector<std::pair<unsigned char, size_t>> getCharFrequences() const;

    // Métodos para codificar e decodificar uma string
    std::string encode(const std::string& txt = "") const;
    std::string decode(const std::string& txt = "") const;
};

#endif // CIFRADOR_HPP