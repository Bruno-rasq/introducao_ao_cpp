#include <iostream>
#include <vector>

using namespace std;

class Pessoa {
private:
	string nome;

public:
	void setnome(string nome){
		this->nome = nome;
	}

	string getnome(){
		return this->nome;
	}
};

int main () {

	vector<Pessoa> pessoas;

	Pessoa p1, p2, p3, p4;

	pessoas.push_back(p1);
	pessoas.push_back(p2);
	pessoas.push_back(p3);
	pessoas.push_back(p4);

	for(int i=0; i<pessoas.size(); i++)
	{
		string nome = "nome " + to_string(i);
		pessoas[i].setnome(nome);
	}

	for(Pessoa pe: pessoas){
		cout << pe.getnome() << endl;
	}
}
