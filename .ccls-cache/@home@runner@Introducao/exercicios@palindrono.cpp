#include <iostream>

using namespace std;

int main() {

	int contador = 0;
	string palavra, resultado = "nao";
	
	cout << "Digite uma palavra para verificar se trata de um palindromo: \n";
	cin >> palavra;

	for(int i = 0; i < palavra.length(); i++){
		if(palavra[i] == palavra[palavra.length() - i - 1]){
			contador++;
		}
	}

	if(contador == palavra.length())
		resultado = "sim";

	cout << "Palavra " << palavra << " é um palidromo = " << resultado << endl;
	
	return 0;
}