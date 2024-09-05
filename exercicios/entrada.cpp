#include <iostream>
#include <any>
#include <vector>

using namespace std;

int main() {

	string nome, endereco, profissao;
	int idade;
	float salario;

	cout << "Digite seu nome:" << endl;
	cin >> nome;

	cout << "Digite seu endereco:" << endl;
	cin >> endereco;

	cout << "Digite sua profissao:" << endl;
	cin >> profissao;

	cout << "Digite sua idade:" << endl;
	cin >> idade;

	cout << "Digite seu salário:" << endl;
	cin >> salario;


	cout << "Seus Dados:" << endl;
	cout << "nome: " << nome << endl;
	cout << "profissao: " << profissao << endl;
	
	return 0;
}