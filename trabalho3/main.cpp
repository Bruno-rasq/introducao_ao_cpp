#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

bool myfunction (size_t p1, size_t p2) { 
    return (p1 > p2);
}

bool myfunction2 (const pair<unsigned char, size_t> &e1, const pair<unsigned char, size_t> &e2){
    return (e1.second > e2.second);
}

int main(){

    cout << "Enter a manuscript to read:" << endl;      //solicita a entrada de um path(caminho para o arquivo).
    string filepath;
    cin >> filepath;

    ifstream fileReader(filepath);                      //recebe o path do arquivo que será lido
    if(!fileReader.is_open()){                          //verifica se o arquivo foi encontrado e pode ser aberto.
        cout << "Error, file not found!" << endl; 
        return 1;
    }

    char ch;                                            //instancia uma variavel char
    stringstream sst;                                   //variavel que recebera o conteudo de entro do arquivo.
    while(fileReader.get(ch)){                          //itera sobre cada caracter do arquivo
        sst << ch;                                      //adiciona o char para a string
    }

    //unsigned char armazena valores de 0 a 255
    //size_t melhor opcao para armazenar iteracao;
    vector<pair<unsigned char, size_t>> charFrequen;    //vetor de pares.
    for(size_t i = 0; i < 256; i++){

        pair<unsigned char, size_t> p(i, 0);            //criar um vetor parar cada valor de 0 a 255 com o size_t 0.
        charFrequen.push_back(p);
    }

    string text = sst.str();                            //converte a variavel sst para string
    for(size_t i = 0; i < text.size(); i++){            //itera sobre cada caracter de text

        char ch = text.at(i);                           //captura o caracter da text na posicao de i.
        charFrequen.at(ch).second++;                    //incrementa o contador do caracter no vetor.
    }


    //parar cada caracter no vetor de frequencias, exibe o valor ASCII do caracter, o caracter e sua frequencia.
    //TODO: ordenar em ordem decrescente de caracter.
    for(size_t i = 0; i < charFrequen.size(); i++){

        cout << (int) charFrequen.at(i).first << " -> "
        << (char) charFrequen.at(i).first << " -> "
        << charFrequen.at(i).second << endl;
    }

    //elimina todas os caracteres que possuem frequencia 0.
    //TODO: eliminar todas os caracteres da tabela ASCII que não possuem frequencia.
    size_t pos = 0;
    while(pos < charFrequen.size()){
        if(charFrequen.at(pos).second == 0){
            charFrequen.erase(charFrequen.begin() + pos);
        } else {
            pos++;
        }
    }


    for(size_t i = 0; i < charFrequen.size(); i++){

        cout << (int) charFrequen.at(i).first << " -> "
        << (char) charFrequen.at(i).first << " -> "
        << charFrequen.at(i).second << endl;
    }
    

    //ordena os caracteres em ordem crescente.
    stable_sort(charFrequen.begin(), charFrequen.end(), myfunction2);


    for(size_t i = 0; i < charFrequen.size(); i++){

        cout << (int) charFrequen.at(i).first << " -> "
        << (char) charFrequen.at(i).first << " -> "
        << charFrequen.at(i).second << endl;
    }

     stable_sort(charFrequen.begin(), charFrequen.end(), myfunction2);

    cout << "---------------------------------" << endl;
    for(size_t i = 0; i < charFrequen.size(); i++){

        cout << (int) charFrequen.at(i).first << " -> "
        << (char) charFrequen.at(i).first << " -> "
        << charFrequen.at(i).second << endl;
    }


    //cria um vetor tabela que recebe o caracter e o caracter criptografado
    vector<pair<unsigned char, unsigned char>> encondingTable(charFrequen.size());
    for(size_t i = 0; i < charFrequen.size(); i++){
        encondingTable.at(i).first = charFrequen.at(i).first;
        encondingTable.at(i).second = charFrequen.at(i).first + 5;
    }

    cout << "---------------------------------" << endl;
    for(size_t i = 0; i < encondingTable.size(); i++){
        cout << "Original char: " << encondingTable.at(i).first << " -> " << encondingTable.at(i).second << endl;
    }


    //codificando o texto original:
    cout << "---------------------------------" << endl;
    cout << text << endl;
    cout << "---------------------------------" << endl;
    for(size_t i = 0; i < text.size(); i++){
        char ch = text.at(i);

        for(size_t j = 0; j < encondingTable.size(); j++){
            if(ch == encondingTable.at(j).first){
                cout << encondingTable.at(j).second << endl;
                break;
            }
        }
    }

    cout << endl;

    return 0;
}