#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include "Cifrador.hpp"

using namespace std;

// Retorna o texto descriptografado ou criptografado dependendo de qual está vazio.
string Cifrador::getEffectiveText() const {
	return this->decodedtext.empty() ? this->encodedtext : this->decodedtext;
}

// Construtor padrão, inicializa ambas as propriedades como ""
Cifrador::Cifrador() : encodedtext(""), decodedtext("") {}

// Recebe uma string e um booleano indicando se a string já está criptografada
Cifrador::Cifrador(const string txt, bool isdecoded) {
	if (isdecoded) {
		this->decodedtext = txt;
		this->encodedtext = "";
	} else {
		this->decodedtext = "";
		this->encodedtext = txt;
	}
}

// Recebe uma string, um booleano e uma chave para codificar
Cifrador::Cifrador(const string txt, bool isdecoded, int key) : Cifrador(txt, isdecoded) {
	setEncodingTable(key);
}

// Cria pares de unsigned chars: caracter original e caracter com desvio
void Cifrador::setEncodingTable(int key) {
	encodingTable.clear(); // limpa a tabela para evitar duplicatas

	for (size_t i = 0; i < 256; i++) {
		unsigned char ch = static_cast<unsigned char>(i);
		unsigned char encodedCh = static_cast<unsigned char>((i + key) % 256);
		encodingTable.emplace_back(ch, encodedCh);
	}
}

// Setters para encodedText e decodedText
void Cifrador::setEncodedText(const string txt) {
	this->encodedtext = txt;
}

void Cifrador::setDecodedText(const string txt) {
	this->decodedtext = txt;
}

// Inicializa o vetor de frequências com contadores zerados
void Cifrador::setCharFrequences() {
	charFrequences.clear();
	for (size_t i = 0; i < 256; i++) {
		charFrequences.emplace_back(static_cast<unsigned char>(i), 0);
	}
}

// Calcula a frequência de cada caracter da string
void Cifrador::countCharFrequences() {
	string text = getEffectiveText();
	if (text.empty()) return;

	for (char ch : text) {
		charFrequences.at(static_cast<unsigned char>(ch)).second++;
	}
}

// Getters para encodedText e decodedText
string Cifrador::getDecodedText() const {
	return this->decodedtext;
}

string Cifrador::getEncodedText() const {
	return this->encodedtext;
}

vector<pair<unsigned char, size_t>> Cifrador::getCharFrequences() const {
	return this->charFrequences;
}

// Método de codificação
string Cifrador::encode(const string txt) const {
	string text = txt.empty() ? this->decodedtext : txt;
	stringstream sst;

	if (text.empty() || encodingTable.empty()) return "";

	for (char ch : text) {
		bool found = false;
		for (const auto &p : encodingTable) {
			if (ch == p.first) {
				sst << p.second;
				found = true;
				break;
			}
		}
		if (!found) sst << ch; // Preserva o caracter original se não estiver na tabela
	}

	return sst.str();
}

// Método de decodificação
string Cifrador::decode(const string txt) const {
	string text = txt.empty() ? this->encodedtext : txt;
	stringstream sst;

	if (text.empty() || encodingTable.empty()) return "";

	for (char ch : text) {
		bool found = false;
		for (const auto &p : encodingTable) {
			if (ch == p.second) {
				sst << p.first;
				found = true;
				break;
			}
		}
		if (!found) sst << ch; // Preserva o caracter original se não estiver na tabela
	}

	return sst.str();
}