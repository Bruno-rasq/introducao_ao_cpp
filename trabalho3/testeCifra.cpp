#include "Cifrador.hpp"
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    // Instanciando `Cifrador` sem parâmetros
    Cifrador c1, c2;

    // Definindo o texto original e a tabela de codificação para c1
    c1.setDecodedText("texto aleatorio");
    c1.setEncodingTable(5);

    // Codificando o texto com `c1`
    string encodeText = c1.encode();
    cout << "Original: " << c1.getDecodedText() << endl;
    cout << "Criptografado: " << encodeText << endl;

    cout << "==============================" << endl;

    // Configurando `c2` para decodificar o texto criptografado
    c2.setEncodedText(encodeText);
    c2.setEncodingTable(-5);  // Usando chave reversa para decodificar

    // Decodificando o texto com `c2`
    string decodedText = c2.decode();
    cout << "Criptografado: " << c2.getEncodedText() << endl;
    cout << "Decodificado: " << decodedText << endl;

    cout << "==============================" << endl;

    // Testando frequências de caracteres com `c1`
    c1.setCharFrequences();
    c1.countCharFrequences();
    vector<pair<unsigned char, size_t>> frequences = c1.getCharFrequences();

    cout << "Frequência de caracteres no texto original:" << endl;
    for (const auto& freq : frequences) {
        if (freq.second > 0) { // Exibir apenas caracteres presentes no texto
            cout << static_cast<int>(freq.first) << " -> " << freq.first << " -> " << freq.second << endl;
        }
    }

    return 0;
}